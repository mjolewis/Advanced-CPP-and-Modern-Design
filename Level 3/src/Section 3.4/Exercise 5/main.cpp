//
// Illustrate parallel processing features (include newer C++20 features such as transform, find, sort)
// and evaluate their performance relative to sequential algos.
// Note - In many cases on my machine, the sequential algos performed faster. This could be, in part,
// due to the additional overheads in creating and managing threads relative to the number of cores
// available on my machine.
//
// Created by Michael Lewis on 7/3/23.
//

#include <array>
#include <execution>
#include <future>
#include <chrono>
#include <iostream>
#include <functional>
#include <numeric>
#include <thread>
#include <random>
#include <vector>

#include <omp.h>

// A template function that can be used to sum all the elements in a container
// This function uses a combination of serial and async to sum the elements.
template<typename T>
T asyncSum(typename std::vector<T>::const_iterator begin, typename std::vector<T>::const_iterator end)
{
    T distance = (end - begin);  // Determine whether or not we've reached the base condition
    if (distance < 1000)
    {
        return std::accumulate(begin, end, 0l);
    }
    else
    {
        auto newEnd = (begin + distance / 2);

        // LHS = recursive and RHS = async task
        return asyncSum<T>(begin, newEnd) + std::async(std::launch::async, asyncSum<T>, newEnd, end).get();
    }
}

// A template function that can be used to sum all the elements in a container
// This function uses a combination of serial and threads to sum the elements.
// Note, since a thread doesn't return or hold a value, we use a global variable per
// https://quantnet.com/threads/3-4-5-e-f-clarification-of-the-requirements.29454/post-198302
long tSum = 0;
template<typename T>
void threadSum(typename std::vector<T>::const_iterator begin, typename std::vector<T>::const_iterator end)
{
    T distance = (end - begin);  // Determine whether or not we've reached the base condition
    if (distance < 1000)
    {
        tSum += std::accumulate(begin, end, 0l);
    }
    else
    {
        auto newEnd = (begin + distance / 2);

        // LHS = recursive and RHS = thread
        threadSum<T>(begin, newEnd);
        std::thread t1(threadSum<T>, newEnd, end);
        t1.join();
    }
}

// A template function that can be used to accumulate the values in a container
// using any generic binary operation
template<typename T>
T generalizedAccumulate(typename std::vector<T>::const_iterator begin, typename std::vector<T>::const_iterator end,
                        const T& identity, const std::multiplies<> op)
{
    T distance = (end - begin);  // Determine whether or not we've reached the base condition
    if (distance < 1000)
    {
        return std::accumulate(begin, end, identity, op);
    }
    else
    {
        auto newEnd = (begin + distance / 2);

        // LHS = recursive and RHS = async task
        return generalizedAccumulate<T>(begin, newEnd, identity, op) +
                std::async(std::launch::async, generalizedAccumulate<T>, newEnd, end, identity, op).get();
    }
}

// Calculate the sum of all elements in a vector and track the processing time
void test_PartA()
{
    std::vector<long> vector(100'000'000, 1);

    // Track the runtime of the program
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    long sum = std::accumulate(vector.cbegin(), vector.cend(), 0l);

    // Track the runtime of the program
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time - Serial Accumulate: " << elapsedTime.count() << " millis. Sum=" << sum << std::endl;
}


// Parallelize the code in part a) by splitting the index space into two halves.
// The LHS should recursively call itself serially, while the RHS should
// recursively call itself asynchronously within a std::async task.
// Base condition is when the size of the container is 1000 which is when we will
// side-track parallel processing by calling std::accumulate() directly.
void test_PartB()
{
    std::vector<long> vector(100'000'000, 1);
    // Track the runtime of the program
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    long result = asyncSum<long>(vector.cbegin(), vector.cend());
    // Track the runtime of the program
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time -  Async Accumulate: " << elapsedTime.count() << " millis. Sum=" << result << std::endl;
}

// Use OpenMP to compare the difference in speed between Part A, B, and C.
// OpenMP is an open source implementation of multithreading. From my testing
// OpenMp was significantly faster than the serial or async implementation.
void test_PartD()
{
    std::vector<long> v(100'000'000, 1);
    long sumParallel = 0;
    omp_set_num_threads(2);

    // Track the runtime of the program
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    omp_set_num_threads(2);
    #pragma omp parallel for reduction (+:sumParallel)
    for (long i = 0; i < v.size(); ++i)
    {
        sumParallel += v[i];
    }

    // Track the runtime of the program
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time -  OpenMP Accumulate: " << elapsedTime.count() << " millis. Sum=" << sumParallel << std::endl;
}

// Parallelize the code in part a) by splitting the index space into two halves.
// The LHS should recursively call itself serially, while the RHS should
// recursively call itself asynchronously within a std::thread task.
// Base condition is when the size of the container is 1000 which is when we will
// side-track parallel processing by calling std::accumulate() directly.
void test_PartE()
{
    std::vector<long> vector(100'000'000, 1);
    // Track the runtime of the program
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    threadSum<long>(vector.cbegin(), vector.cend());
    // Track the runtime of the program
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time - Thread Accumulate: " << elapsedTime.count() << " millis. Sum=" << tSum << std::endl;
}

// Test a generic function that accumulates elements using any generic binary function.
// For example purposes, we will test the function using std::multiply.
// Note - The range of values being tested is small because the product can very quickly run into overlow
// issues.
void test_PartF()
{
    using MAX_TYPE = unsigned long long;
    std::vector<MAX_TYPE> vector;
    for (int i = 0; i < 10; ++i)
    {
        vector.push_back(i + 1);
    }

    // Track the runtime of the program
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    auto result = generalizedAccumulate<MAX_TYPE>(vector.cbegin(), vector.cend(), 1, std::multiplies<>());
    // Track the runtime of the program
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time -  Generic Accumulate: " << elapsedTime.count() << " millis. Product=" << result << std::endl;
}

// Compare performance improvements by using the new parallel features in C++.
// We focus on three STL algorithms (or algorithms of your choice) as applied
// to std::vector, namely: std::transform, std::sort, std::find.
void test_PartG_Par()
{
    // *** TRANSFORM ***
    std::vector<std::uint64_t> v(10'000'000);
    std::mt19937 gen {std::random_device{}()};
    std::ranges::generate(v, gen);

    // Track the runtime of the program
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::transform(std::execution::par, v.cbegin(), v.cend(), v.cbegin(), v.begin(), std::plus<>{});
    // Track the runtime of the program
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time - Par Transform: " << elapsedTime.count() << " millis." << std::endl;

    // *** SORT ***
    std::ranges::generate(v, gen);
    // Track the runtime of the program
    start = std::chrono::steady_clock::now();
    std::sort(std::execution::par, v.begin(), v.end());
    // Track the runtime of the program
    end = std::chrono::steady_clock::now();
    // Log the running time
    elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time - Par Sort: " << elapsedTime.count() << " millis." << std::endl;

    // *** FIND ***
    std::ranges::generate(v, gen);
    // Track the runtime of the program
    start = std::chrono::steady_clock::now();
    auto find = std::find(std::execution::par, v.begin(), v.end(), 12);
    // Track the runtime of the program
    end = std::chrono::steady_clock::now();
    // Log the running time
    elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time - Par Find: " << elapsedTime.count() << *find << " millis." << std::endl;
}

// Compare performance improvements by using the new sequential features in C++.
// We focus on three STL algorithms (or algorithms of your choice) as applied
// to std::vector, namely: std::transform, std::sort, std::find.
void test_PartG_Seq()
{
    // *** TRANSFORM ***
    std::vector<std::uint64_t> v(10'000'000);
    std::mt19937 gen {std::random_device{}()};
    std::ranges::generate(v, gen);

    // Track the runtime of the program
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::transform(std::execution::seq, v.cbegin(), v.cend(), v.cbegin(), v.begin(), std::plus<>{});
    // Track the runtime of the program
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time - Seq Transform: " << elapsedTime.count() << " millis." << std::endl;

    // *** SORT ***
    std::ranges::generate(v, gen);
    // Track the runtime of the program
    start = std::chrono::steady_clock::now();
    std::sort(std::execution::seq, v.begin(), v.end());
    // Track the runtime of the program
    end = std::chrono::steady_clock::now();
    // Log the running time
    elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time - Seq Sort: " << elapsedTime.count() << " millis." << std::endl;

    // *** FIND ***
    std::ranges::generate(v, gen);
    // Track the runtime of the program
    start = std::chrono::steady_clock::now();
    auto find = std::find(std::execution::seq, v.begin(), v.end(), 12);
    // Track the runtime of the program
    end = std::chrono::steady_clock::now();
    // Log the running time
    elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time - Seq Find: " << elapsedTime.count() << *find << " millis." << std::endl;
}

int main()
{
    test_PartA();
    test_PartB();

    // Part C - Measure the speed up of Part B relative to Part A.
    // Response: I actually find that Part B is roughly 5-6 times slower than Part A.
    // This seems to be related to the additional overhead costs associated all the additional
    // threads. This also may be impacted by the number of cores that the source machine has.
    // Perhaps, in my case, my machine doesn't have enough cores to handle all the threads
    // fast enough.

    test_PartD();
    test_PartE();
    test_PartF();
    test_PartG_Par();
    test_PartG_Seq();

    return 0;
}
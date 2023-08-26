//
// Template Method Pattern based on Universal Function Wrappers
//
// Illustrates how to use universal function wrappers to implement a next generation
// version of the Template Method Pattern.
//
// Created by Michael Lewis on 8/23/23.
//

#include <chrono>
#include <iostream>
#include <future>

#include "TmpProcessor.hpp"

// Simulates std::accumulate using Gauss summation technique
void test_Gauss_Summation()
{
    auto factoryFunction = []() { return 100; };

    auto computeFunction = [](const int& data) { return (data * (data + 1) / 2); };

    auto dispatchFunction = [](int& data) -> void {
        std::cout << "Gauss Summation of all numbers from 1 to 100 = " << data << std::endl;
    };

    TmpProcessor<int> tmpProcessor{factoryFunction, computeFunction, dispatchFunction};
    tmpProcessor.algorithm();
}

// Calculate the Fibonacci sequence sequentially using recursion to simulate a compute intensive task
// Note - To illustrate the difference between sequential and parallel processing, I am taking a
// relatively large number of 43 to calculate the sequence. This will take roughly 120 seconds on
// my machine when performed serially.
void test_Fibonacci_Sequential()
{
    std::cout << "\n*** Calculating Fibonacci Sequence Serial ***" << std::endl;
    // Measure the processing time
    auto start = std::chrono::steady_clock::now();

    // Setup functions
    auto factoryFunction = []() { return 43L; };

    auto computeFunction = [](const long& num) {
        std::function<long (const long)> fib = [&fib](const long& num)
        {
            if ((num == 1) || (num == 0)) return (num);
            else return (fib(num - 1) + fib(num - 2));
        };

        return fib(num) + fib(num);
    };

    auto dispatchFunction = [](long& result) -> void {
        std::cout << "Fib(43) + Fib(43). Expected Result 866988874 vs Actual Result = " << result << std::endl;
    };

    TmpProcessor<long> tmpProcessor{factoryFunction, computeFunction, dispatchFunction};
    tmpProcessor.algorithm();

    // Stop the clock
    auto stop = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();
    std::cout << "Total serial processing time in seconds: " << elapsedTime << std::endl;
}

// Calculate the Fibonacci sequence sequentially using recursion to simulate a compute intensive task
// Note - To illustrate the difference between sequential and parallel processing, I am taking a
// relatively large number of 43 to calculate the sequence. This will take roughly 65 seconds on
// my machine when performed asynchronously.
void test_Fibonacci_Parallelized()
{
    std::cout << "\n*** Calculating Fibonacci Sequence Parallel ***" << std::endl;
    // Measure the processing time
    auto start = std::chrono::steady_clock::now();

    // Setup functions
    auto factoryFunction = []() { return 43L; };

    auto computeFunction = [](const long& num) {
        std::function<long (const long)> fib = [&fib](const long& num)
        {
            if ((num == 1) || (num == 0)) return (num);
            else return (fib(num - 1) + fib(num - 2));
        };

        std::future<long> resultOne = std::async(std::launch::async, fib, num);
        std::future<long> resultTwo = std::async(std::launch::async, fib, num);
        return resultOne.get() + resultTwo.get();
    };

    auto dispatchFunction = [](long& result) -> void {
        std::cout << "Fib(43) + Fib(43). Expected Result 866988874 vs Actual Result = " << result << std::endl;
    };

    TmpProcessor<long> tmpProcessor{factoryFunction, computeFunction, dispatchFunction};
    tmpProcessor.algorithm();

    // Stop the clock
    auto stop = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();
    std::cout << "Total parallel processing time in seconds: " << elapsedTime << std::endl;
}

int main()
{
    test_Gauss_Summation();
    test_Fibonacci_Sequential();
    test_Fibonacci_Parallelized();

    /*
     * Dependency Graphs
     *
     * Sequential Fibonacci
     * A -> B -> C where A is the first sequence, B is the second sequence, and C is the final result
     *
     * Parallelized Fibonacci, where A and B can run in parallel but the final result is still dependent on both
     * A
     *   \
     *    |-> C
     *   /
     * B
     */
    return 0;
}
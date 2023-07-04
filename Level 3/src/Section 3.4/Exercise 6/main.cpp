//
// Implement serial and parallel versions of a task graph where each node in the task graph
// depends on the output from the computation performed by the prior node. Note that this
// simple illustration is specialized for a numeric type.
//
// Created by Michael Lewis on 7/4/23.
//

#include <execution>
#include <future>
#include <chrono>
#include <iostream>
#include <functional>
#include <thread>

// 12 user-defined literals that represent hours, minutes, seconds, milliseconds, milliseconds, and nanoseconds
// Will be used to set minimum duration to block for when attempting to acquire a lock
using namespace std::chrono_literals;

// A simple helper class to measure running time of each node in the task graph
class StopWatch
{
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point stop;

    // Base condition for variadic function that calculates time for any number of specified args
    static auto TotalTime(auto arg) { return arg; }

public:
    void Start() {  start = std::chrono::steady_clock::now(); }
    void Stop() { stop = std::chrono::steady_clock::now(); }
    auto ElapsedTime()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    }

    // Variadic function used to calculate total running time for any number of specified arguments
    static auto TotalTime(auto arg, auto... args) { return arg + TotalTime(args...); }
};

double fib(double n)
{
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// Simple function to illustrate both serial and parallel processing of a task graph
double F1(double arg, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    double result = fib(arg);
    watch.Stop();
    return result;
}

// Simple function to illustrate both serial and parallel processing of a task graph
double F2(double arg, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    double result = fib(arg);
    watch.Stop();
    return result;
}

// Simple function to illustrate both serial and parallel processing of a task graph
double F3(double arg, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    double result = fib(arg);
    watch.Stop();
    return result;
}

// Simple function to illustrate both serial and parallel processing of a task graph
double F4(double lhs, double rhs, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    double result = lhs + rhs;
    watch.Stop();
    return result;
}

// *** Define the same set of functions to that can be used Futures and Promises ***

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F1_Threaded(T arg, std::promise<T>& promise, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    T result = fib(arg);
    watch.Stop();
    promise.set_value(result);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F2_Threaded(T arg, std::promise<T>& promise, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    T result = fib(arg);
    watch.Stop();
    promise.set_value(result);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F3_Threaded(T arg, std::promise<T>& promise, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    T result = fib(arg);
    watch.Stop();
    promise.set_value(result);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F4_Threaded(T lhs, T rhs, std::promise<T>& promise, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    T result = lhs + rhs;
    watch.Stop();
    promise.set_value(result);
}

// *** Define a similar set of functions for the task graph that are capable of supporting vectors ***

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F1_Vec(std::vector<T> arg, std::promise<T>& promise, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    promise.set_value(std::accumulate(arg.begin(), arg.end(), 1.0));
    watch.Stop();
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F2_Vec(std::vector<T> arg, std::promise<T>& promise, StopWatch& watch)
{
    // Simulate a long running computation
    watch.Start();
    promise.set_value(std::accumulate(arg.begin(), arg.end(), 1.0));
    watch.Stop();
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F3_Vec(T arg, std::promise<T>& promise, StopWatch& watch)
{
    // Set the value for the future to get
    watch.Start();
    promise.set_value(arg + 1.0);
    watch.Stop();
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F4_Vec(T lhs, T rhs, std::promise<T>& promise, StopWatch& watch)
{
    // Set the value for the future to get
    watch.Start();
    promise.set_value(lhs + rhs);
    watch.Stop();
}

// *** Define a similar set of functions for the task graph that are capable of supporting vectors ***

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F1_Matrix(const std::vector<std::vector<double>>& arg, std::promise<T>& promise, StopWatch& watch)
{
    T result = 0;

    // Simulate a long running computation
    watch.Start();
    for (const auto& outer : arg)
    {
        for (const auto& inner : outer)
        {
            result += inner;
        }
    }

    watch.Stop();
    // Set the value for the future to get
    promise.set_value(result);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F2_Matrix(const std::vector<std::vector<double>>& arg, std::promise<T>& promise, StopWatch& watch)
{
    T result = 0;

    // Simulate a long running computation
    watch.Start();
    for (const auto& outer : arg)
    {
        for (const auto& inner : outer)
        {
            result += inner;
        }
    }

    watch.Stop();
    // Set the value for the future to get
    promise.set_value(result);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F3_Matrix(T arg, std::promise<T>& promise, StopWatch& watch)
{
    watch.Start();
    promise.set_value(arg + 1.0);
    watch.Stop();
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F4_Matrix(T lhs, T rhs, std::promise<T>& promise, StopWatch& watch)
{
    watch.Start();
    promise.set_value(lhs + rhs);
    watch.Stop();
}

// Implement a serial version of a task graph where each node in the task graph depends
// on the output from the computation performed by the prior node.
void test_PartA()
{
    double a = 9.0;

    StopWatch&& watch1{};
    double b = F1(a, watch1);

    StopWatch&& watch2{};
    double c = F2(a, watch2);

    StopWatch&& watch3{};
    double d = F3(c, watch3);

    StopWatch&& watch4{};
    double e = F4(b, d, watch4);

    // Get elapsed time after threads are done working
    auto bTime = watch1.ElapsedTime();
    auto cTime = watch2.ElapsedTime();
    auto dTime = watch3.ElapsedTime();
    auto eTime = watch4.ElapsedTime();

    std::cout << "Serial Task Graph Result = " << e << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (StopWatch::TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a parallel version of a task graph using Async where each node in the task graph depends
// on the output from the computation performed by the prior node.
void test_PartB()
{
    double a = 9.0;

    StopWatch&& watch1{};
    std::future<double> b = std::async(std::launch::async, F1, a, std::ref(watch1));

    StopWatch&& watch2{};
    std::future<double> c = std::async(std::launch::async, F2, a, std::ref(watch2));

    StopWatch&& watch3{};
    std::future<double> d = std::async(std::launch::async, F3, c.get(), std::ref(watch3));

    StopWatch&& watch4{};
    std::future<double> e = std::async(std::launch::async, F4, b.get(), d.get(), std::ref(watch4));

    double total = e.get();

    // Get elapsed time after threads are done working
    auto bTime = watch1.ElapsedTime();
    auto cTime = watch2.ElapsedTime();
    auto dTime = watch3.ElapsedTime();
    auto eTime = watch4.ElapsedTime();

    std::cout << "\nAsync Task Graph Result = " << total << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (StopWatch::TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a parallel version of a task graph using Threads where each node in the task graph depends
// on the output from the computation performed by the prior node.
void test_PartC()
{
    using T = double;

    T a = 9.0;

    std::promise<T> p1;
    std::future<T> f1 = p1.get_future();
    StopWatch&& watch1{};
    std::thread t1(F1_Threaded<T>, a, std::ref(p1), std::ref(watch1));

    std::promise<T> p2;
    std::future<T> f2 = p2.get_future();
    StopWatch&& watch2{};
    std::thread t2(F2_Threaded<T>, a, std::ref(p2), std::ref(watch2));

    std::promise<T> p3;
    std::future<T> f3 = p3.get_future();
    StopWatch&& watch3{};
    std::thread t3(F3_Threaded<T>, f2.get(), std::ref(p3), std::ref(watch3));

    std::promise<T> p4;
    std::future<T> f4 = p4.get_future();
    StopWatch&& watch4{};
    std::thread t4(F4_Threaded<T>, f1.get(), f3.get(), std::ref(p4), std::ref(watch4));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    T total = f4.get();

    // Get elapsed time after threads are done working
    auto bTime = watch1.ElapsedTime();
    auto cTime = watch2.ElapsedTime();
    auto dTime = watch3.ElapsedTime();
    auto eTime = watch4.ElapsedTime();

    std::cout << "\nPromise Task Graph Result = " << total << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (StopWatch::TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a parallel version of a task graph using Packaged Tasks where each node in the task graph depends
// on the output from the computation performed by the prior node.
void test_PartD()
{
    double a = 9.0;

    // Wrap the task
    std::packaged_task<double (double, StopWatch&)> b(F1);
    // Associate the future with the task
    std::future<double> f1 = b.get_future();

    // Wrap the task
    std::packaged_task<double (double, StopWatch&)> c(F2);
    // Associate the future with the task
    std::future<double> f2 = c.get_future();

    // Wrap the task
    std::packaged_task<double (double, StopWatch&)> d(F3);
    // Associate the future with the task
    std::future<double> f3 = d.get_future();

    // Wrap the task
    std::packaged_task<double (double, double, StopWatch&)> e(F4);
    // Associate the future with the task
    std::future<double> f4 = e.get_future();;

    StopWatch&& watch1{};
    b(a, std::ref(watch1));

    StopWatch&& watch2{};
    c(a, std::ref(watch2));

    StopWatch&& watch3{};
    d(f2.get(), std::ref(watch3));

    StopWatch&& watch4{};
    e(f1.get(), f3.get(), std::ref(watch4));

    double total = f4.get();

    // Get elapsed time after threads are done working
    auto bTime = watch1.ElapsedTime();
    auto cTime = watch2.ElapsedTime();
    auto dTime = watch3.ElapsedTime();
    auto eTime = watch4.ElapsedTime();

    std::cout << "\nPackaged Task Graph Result = " << total << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (StopWatch::TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a vector based algorithm for the task graph to illustrate the additional
// complexity of computation by determining the total running time
void test_Vec()
{
    using T = double;

    std::vector<T> a(10'000'000, 1);

    std::promise<T> p1;
    std::future<T> f1 = p1.get_future();
    StopWatch&& watch1{};
    std::thread t1(F1_Vec<T>, a, std::ref(p1), std::ref(watch1));

    std::promise<T> p2;
    std::future<T> f2 = p2.get_future();
    StopWatch&& watch2{};
    std::thread t2(F2_Vec<T>, a, std::ref(p2), std::ref(watch2));
    std::promise<T> p3;
    std::future<T> f3 = p3.get_future();
    StopWatch&& watch3{};
    std::thread t3(F3_Vec<T>, f2.get(), std::ref(p3), std::ref(watch3));

    std::promise<T> p4;
    std::future<T> f4 = p4.get_future();
    StopWatch&& watch4{};
    std::thread t4(F4_Vec<T>, f1.get(), f3.get(), std::ref(p4), std::ref(watch4));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // Get elapsed time after threads are done working
    auto bTime = watch1.ElapsedTime();
    auto cTime = watch2.ElapsedTime();
    auto dTime = watch3.ElapsedTime();
    auto eTime = watch4.ElapsedTime();

    std::cout << "\nVector Test" << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (StopWatch::TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a matrix based algorithm for the task graph to illustrate the additional
// complexity of computation by determining the total running time
void test_Matrix()
{
    using T = double;

    std::vector<std::vector<T>> a;
    for (int i = 0; i < 10'000; ++i)
    {
        a.emplace_back(10'000, 1);
    }

    std::promise<T> p1;
    std::future<T> f1 = p1.get_future();
    StopWatch&& watch1{};
    std::thread t1(F1_Matrix<T>, a, std::ref(p1), std::ref(watch1));

    std::promise<T> p2;
    std::future<T> f2 = p2.get_future();
    StopWatch&& watch2{};
    std::thread t2(F2_Matrix<T>, a, std::ref(p2), std::ref(watch2));

    std::promise<T> p3;
    std::future<T> f3 = p3.get_future();
    StopWatch&& watch3{};
    std::thread t3(F3_Matrix<T>, f2.get(), std::ref(p3), std::ref(watch3));

    std::promise<T> p4;
    std::future<T> f4 = p4.get_future();
    StopWatch&& watch4{};
    std::thread t4(F4_Matrix<T>, f1.get(), f3.get(), std::ref(p4), std::ref(watch4));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // Get elapsed time after threads are done working
    auto bTime = watch1.ElapsedTime();
    auto cTime = watch2.ElapsedTime();
    auto dTime = watch3.ElapsedTime();
    auto eTime = watch4.ElapsedTime();

    std::cout << "\nMatrix Test" << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (StopWatch::TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

int main()
{
    test_PartA();
    test_PartB();
    test_PartC();
    test_PartD();
    test_Vec();
    test_Matrix();
    return 0;
}

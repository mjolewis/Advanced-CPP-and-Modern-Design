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
    auto TotalTime(auto arg) { return arg; }

public:
    void Start() {  start = std::chrono::steady_clock::now(); }
    void Stop() { stop = std::chrono::steady_clock::now(); }
    auto ElapsedTime()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    }

    // Variadic function used to calculate total running time for any number of specified arguments
    auto TotalTime(auto arg, auto... args) { return arg + TotalTime(args...); }
};

// Simple function to illustrate both serial and parallel processing of a task graph
double F1(double arg)
{
    // Simulate a long running computation
    std::this_thread::sleep_for(1s);
    return arg + 1.0;
}

// Simple function to illustrate both serial and parallel processing of a task graph
double F2(double arg)
{
    // Simulate a long running computation
    std::this_thread::sleep_for(1s);
    return arg + 2.0;
}

// Simple function to illustrate both serial and parallel processing of a task graph
double F3(double arg)
{
    // Simulate a long running computation
    std::this_thread::sleep_for(1s);
    return arg + 3.0;
}

// Simple function to illustrate both serial and parallel processing of a task graph
double F4(double lhs, double rhs)
{
    // Simulate a long running computation
    std::this_thread::sleep_for(1s);
    return lhs + rhs;
}

// *** Define the same set of functions to that can be used Futures and Promises ***

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F1_Threaded(T arg, std::promise<T>& promise)
{
    // Simulate a long running computation
    std::this_thread::sleep_for(1s);
    promise.set_value(arg + 1.0);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F2_Threaded(T arg, std::promise<T>& promise)
{
    // Simulate a long running computation
    std::this_thread::sleep_for(1s);
    promise.set_value(arg + 2.0);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F3_Threaded(T arg, std::promise<T>& promise)
{
    // Simulate a long running computation
    std::this_thread::sleep_for(1s);
    promise.set_value(arg + 3.0);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F4_Threaded(T lhs, T rhs, std::promise<T>& promise)
{
    // Simulate a long running computation
    std::this_thread::sleep_for(1s);
    promise.set_value(lhs + rhs);
}

// *** Define a similar set of functions for the task graph that are capable of supporting vectors ***

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F1_Vec(std::vector<T> arg, std::promise<T>& promise)
{
    // Simulate a long running computation
    promise.set_value(std::accumulate(arg.begin(), arg.end(), 1.0));
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F2_Vec(std::vector<T> arg, std::promise<T>& promise)
{
    // Simulate a long running computation
    promise.set_value(std::accumulate(arg.begin(), arg.end(), 1.0));
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F3_Vec(T arg, std::promise<T>& promise)
{
    // Set the value for the future to get
    promise.set_value(arg + 1.0);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F4_Vec(T lhs, T rhs, std::promise<T>& promise)
{
    // Set the value for the future to get
    promise.set_value(lhs + rhs);
}

// *** Define a similar set of functions for the task graph that are capable of supporting vectors ***

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F1_Matrix(const std::vector<std::vector<double>>& arg, std::promise<T>& promise)
{
    T result = 0;

    // Simulate a long running computation
    for (const auto& outer : arg)
    {
        for (const auto& inner : outer)
        {
            result += inner;
        }
    }

    // Set the value for the future to get
    promise.set_value(result);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F2_Matrix(const std::vector<std::vector<double>>& arg, std::promise<T>& promise)
{
    T result = 0;

    // Simulate a long running computation
    for (const auto& outer : arg)
    {
        for (const auto& inner : outer)
        {
            result += inner;
        }
    }

    // Set the value for the future to get
    promise.set_value(result);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F3_Matrix(T arg, std::promise<T>& promise)
{
    promise.set_value(arg + 1.0);
}

// Simple function to illustrate both serial and parallel processing of a task graph
template<typename T>
void F4_Matrix(T lhs, T rhs, std::promise<T>& promise)
{
    promise.set_value(lhs + rhs);
}

// Implement a serial version of a task graph where each node in the task graph depends
// on the output from the computation performed by the prior node.
void test_PartA()
{
    double a = 1.0;

    StopWatch watch;
    watch.Start();
    double b = F1(a);
    watch.Stop();
    auto bTime = watch.ElapsedTime();

    watch.Start();
    double c = F2(a);
    watch.Stop();
    auto cTime = watch.ElapsedTime();

    watch.Start();
    double d = F3(c);
    watch.Stop();
    auto dTime = watch.ElapsedTime();

    watch.Start();
    double e = F4(b, d);
    watch.Stop();
    auto eTime = watch.ElapsedTime();

    std::cout << "Serial Task Graph Result = " << e << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (watch.TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a parallel version of a task graph using Async where each node in the task graph depends
// on the output from the computation performed by the prior node.
void test_PartB()
{
    double a = 1.0;

    StopWatch watch;
    watch.Start();
    std::future<double> b = std::async(std::launch::async, F1, a);
    watch.Stop();
    auto bTime = watch.ElapsedTime();

    watch.Start();
    std::future<double> c = std::async(std::launch::async, F2, a);
    watch.Stop();
    auto cTime = watch.ElapsedTime();

    watch.Start();
    std::future<double> d = std::async(std::launch::async, F3, c.get());
    watch.Stop();
    auto dTime = watch.ElapsedTime();

    watch.Start();
    std::future<double> e = std::async(std::launch::async, F4, b.get(), d.get());
    watch.Stop();
    auto eTime = watch.ElapsedTime();

    std::cout << "\nAsync Task Graph Result = " << e.get() << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (watch.TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a parallel version of a task graph using Threads where each node in the task graph depends
// on the output from the computation performed by the prior node.
void test_PartC()
{
    using T = double;

    double a = 1.0;

    std::promise<T> p1;
    std::future<T> f1 = p1.get_future();
    StopWatch watch;
    watch.Start();
    std::thread t1(F1_Threaded<T>, a, std::ref(p1));
    watch.Stop();
    auto bTime = watch.ElapsedTime();

    std::promise<T> p2;
    std::future<T> f2 = p2.get_future();
    watch.Start();
    std::thread t2(F2_Threaded<T>, a, std::ref(p2));
    watch.Stop();
    auto cTime = watch.ElapsedTime();

    std::promise<T> p3;
    std::future<T> f3 = p3.get_future();
    watch.Start();
    std::thread t3(F3_Threaded<T>, f2.get(), std::ref(p3));
    watch.Stop();
    auto dTime = watch.ElapsedTime();

    std::promise<T> p4;
    std::future<T> f4 = p4.get_future();
    watch.Start();
    std::thread t4(F4_Threaded<T>, f1.get(), f3.get(), std::ref(p4));
    watch.Stop();
    auto eTime = watch.ElapsedTime();

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "\nPromise Task Graph Result = " << f4.get() << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (watch.TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a parallel version of a task graph using Packaged Tasks where each node in the task graph depends
// on the output from the computation performed by the prior node.
void test_PartD()
{
    double a = 1.0;

    // Wrap the task
    std::packaged_task<double (double)> b(F1);
    // Associate the future with the task
    std::future<double> f1 = b.get_future();

    // Wrap the task
    std::packaged_task<double (double)> c(F2);
    // Associate the future with the task
    std::future<double> f2 = c.get_future();

    // Wrap the task
    std::packaged_task<double (double)> d(F3);
    // Associate the future with the task
    std::future<double> f3 = d.get_future();

    // Wrap the task
    std::packaged_task<double (double, double)> e(F4);
    // Associate the future with the task
    std::future<double> f4 = e.get_future();;

    StopWatch watch;
    watch.Start();
    b(a);
    watch.Stop();
    auto bTime = watch.ElapsedTime();

    watch.Start();
    c(a);
    watch.Stop();
    auto cTime = watch.ElapsedTime();

    watch.Stop();
    d(f2.get());
    watch.Stop();
    auto dTime = watch.ElapsedTime();

    watch.Start();
    e(f1.get(), f3.get());
    watch.Stop();
    auto eTime = watch.ElapsedTime();


    std::cout << "\nAsync Task Graph Result = " << f4.get() << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (watch.TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
}

// Implement a vector based algorithm for the task graph to illustrate the additional
// complexity of computation by determining the total running time
void test_Vec()
{
    using T = double;

    std::vector<T> a(10'000'000, 1);

    std::promise<T> p1;
    std::future<T> f1 = p1.get_future();
    StopWatch watch;
    watch.Start();
    std::thread t1(F1_Vec<T>, a, std::ref(p1));
    watch.Stop();
    auto bTime = watch.ElapsedTime();

    std::promise<T> p2;
    std::future<T> f2 = p2.get_future();
    watch.Start();
    std::thread t2(F2_Vec<T>, a, std::ref(p2));
    watch.Stop();
    auto cTime = watch.ElapsedTime();

    std::promise<T> p3;
    std::future<T> f3 = p3.get_future();
    watch.Start();
    std::thread t3(F3_Vec<T>, f2.get(), std::ref(p3));
    watch.Stop();
    auto dTime = watch.ElapsedTime();

    std::promise<T> p4;
    std::future<T> f4 = p4.get_future();
    watch.Start();
    std::thread t4(F4_Vec<T>, f1.get(), f3.get(), std::ref(p4));
    watch.Stop();
    auto eTime = watch.ElapsedTime();

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "\nVector Test" << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (watch.TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
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
    StopWatch watch;
    watch.Start();
    std::thread t1(F1_Matrix<T>, a, std::ref(p1));
    watch.Stop();
    auto bTime = watch.ElapsedTime();

    std::promise<T> p2;
    std::future<T> f2 = p2.get_future();
    watch.Start();
    std::thread t2(F2_Matrix<T>, a, std::ref(p2));
    watch.Stop();
    auto cTime = watch.ElapsedTime();

    std::promise<T> p3;
    std::future<T> f3 = p3.get_future();
    watch.Start();
    std::thread t3(F3_Matrix<T>, f2.get(), std::ref(p3));
    watch.Stop();
    auto dTime = watch.ElapsedTime();

    std::promise<T> p4;
    std::future<T> f4 = p4.get_future();
    watch.Start();
    std::thread t4(F4_Matrix<T>, f1.get(), f3.get(), std::ref(p4));
    watch.Stop();
    auto eTime = watch.ElapsedTime();

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "\nMatrix Test" << std::endl;
    std::cout << "Running time b=" << bTime << std::endl;
    std::cout << "Running time c=" << cTime << std::endl;
    std::cout << "Running time d=" << dTime << std::endl;
    std::cout << "Running time e=" << eTime << std::endl;
    std::cout << "Total time (b + c + d + e)=" << (watch.TotalTime(bTime, cTime, dTime, eTime)) << std::endl;
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

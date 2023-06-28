//
// A simple illustration of using threads and how they can cause race conditions if shared
// variables are updated in a non-atomic manner.
//
// Note - Each function that calls a thread will sleep to simulate some intensive algorithm
// such that non-atomic operations are possible for illustration purpose.
//
// Created by Michael Lewis on 6/27/23.
//

#include <iostream>
#include <functional>
#include <thread>

// Global variable used to illustrate a race condition
int globalCount = 0;

// A shared interface used to print data from various competing threads to illustrate a race condition
void Iprint(const std::string& s, int count)
{
    std::cout << s << ": Count: " << count << std::endl;
}

// A global function that will call the shared IPrint interface from a thread
void globalFunction(int iterations)
{
    for (int i = 0; i < iterations; ++i)
    {
        Iprint("Global Function", ++globalCount);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

// A function object that will call the shared IPrint interface from a thread
class FunctionObject
{
private:
    int iterations;

public:
    explicit FunctionObject(int iterations) : iterations{iterations} {};

    // Called by the thread
    void operator()() const
    {
        for (int i = 0; i < iterations; ++i)
        {
            Iprint("Function Object", ++globalCount);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
};

// A class with a static function that will call the shared IPrint interface from a thread
class Static
{
public:
    // Called by the thread
    static void StaticFunction(int iterations)
    {
        for (int i = 0; i < iterations; ++i)
        {
            Iprint("Static Function", ++globalCount);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
};

// A stored lambda function that will call the shared IPrint interface from a thread
auto storedLambda = [](int iterations) -> void {
    for (int i = 0; i < iterations; ++i)
    {
        Iprint("Stored Lambda", ++globalCount);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};

// A class with a function that gets bounded using std::bind
class BindClass
{
public:
    static void print(const std::string& s, int iterations)
    {
        for (int i = 0; i < iterations; ++i)
        {
            Iprint(s, ++globalCount);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
};

// A std::bind function that will call the shared IPrint interface from a thread
auto bindFunction = std::bind(&BindClass::print, std::placeholders::_1, std::placeholders::_2);

int main()
{
    int iterations = 5;
    std::thread t1(globalFunction, iterations);
    FunctionObject fo(iterations);
    std::thread t2(fo);
    std::thread t3(Static::StaticFunction, iterations);
    std::thread t4(bindFunction, std::string("Bind Function"), iterations);
    std::thread t5(storedLambda, iterations);
    std::thread t6([&]() -> void {
        for (int i = 0; i < iterations; ++i)
        {
            Iprint("Temporary Lambda", ++globalCount);
            std::this_thread::sleep_for((std::chrono::milliseconds(5)));
        }
    });

    // Join can throw a system error, so wrap it in a try catch
    // Note for illustration purpose, we are calling join before joinable
    try
    {
        // Join threads - Blocks the main thread until t1 - t6 finish executing
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
    }
    catch (const std::system_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
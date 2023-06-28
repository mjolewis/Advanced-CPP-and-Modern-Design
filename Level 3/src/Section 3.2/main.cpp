//
// A simple illustration of how to control thread execution by synchronizing access to shared resources
//
// Note - Each function that calls a thread will sleep to simulate some intensive algorithm
// such that non-atomic operations are possible for illustration purpose.
//
// Created by Michael Lewis on 6/27/23.
//

#include <chrono>
#include <iostream>
#include <functional>
#include <mutex>
#include <thread>

// Create a mutex around the console
std::mutex console;

// A shared interface used to print data from various competing threads to illustrate arace condition
void Iprint(const std::string& s, int count)
{
    console.lock();
    for (int i = 0; i < count; ++i)
    {
        std::cout << s << ": ThreadId: " << std::this_thread::get_id() << " : Iteration: " << i << std::endl;
    }
    console.unlock();
}

// A global function that will call the shared IPrint interface from a thread
void globalFunction(int iterations)
{
    Iprint("Global Function", iterations);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
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
        Iprint("Function Object", iterations);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};

// A class with a static function that will call the shared IPrint interface from a thread
class Static
{
public:
    // Called by the thread
    static void StaticFunction(int iterations)
    {
        Iprint("Static Function", iterations);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};

// A stored lambda function that will call the shared IPrint interface from a thread
auto storedLambda = [](int iterations) -> void {
    Iprint("Stored Lambda", iterations);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
};

// A class with a function that gets bounded using std::bind
class BindClass
{
public:
    static void print(const std::string& s, int iterations)
    {
        Iprint(s, iterations);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};

// A std::bind function that will call the shared IPrint interface from a thread
auto bindFunction = std::bind(&BindClass::print, std::placeholders::_1, std::placeholders::_2);

int main()
{
    int iterations = 5;

    // Track the runtime of the program
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    std::thread t1(globalFunction, iterations);
    FunctionObject fo(iterations);
    std::thread t2(fo);
    std::thread t3(Static::StaticFunction, iterations);
    std::thread t4(bindFunction, std::string("Bind Function"), iterations);
    std::thread t5(storedLambda, iterations);
    std::thread t6([&]() -> void {
        Iprint("Temporary Lambda", iterations);
        std::this_thread::sleep_for((std::chrono::milliseconds(5)));
    });

    // Joinable identifies A thread that has finished executing code but has not yet been joined.
    // Threads that are joinable won't throw an exception when joined
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    if (t3.joinable()) t3.join();
    if (t4.joinable()) t4.join();
    if (t5.joinable()) t5.join();
    if (t6.joinable()) t6.join();

    // For illustration purposes, join a thread even if it's not joinable - This should log an error
    try
    {
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

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\n*** Elapsed time: " << elapsedTime.count() << " micros ***" << std::endl;

    return 0;
}
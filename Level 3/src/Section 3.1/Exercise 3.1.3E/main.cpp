//
// Illustrate the functionality of std::unique_lock::unlock to unlock the associated mutex and
// releases ownership.
//
// Created by Michael Lewis on 6/27/23.
//

#include <chrono>
#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <system_error>

// 12 user-defined literals that represent hours, minutes, seconds, milliseconds, milliseconds, and nanoseconds
// Will be used to set minimum duration to block for when attempting to acquire a lock
using namespace std::chrono_literals;

// Global variable used to illustrate a race condition
int globalCount = 0;

// Create a mutex around the console
std::mutex console;

// A shared interface used to print data from various competing threads to illustrate a race condition
void Iprint(const std::string& s, int count)
{
    std::unique_lock<std::mutex> lock(console);
    std::cout << s << ": ThreadId: " << std::this_thread::get_id()<< ": Count: " << count << std::endl;
    lock.unlock(); // Unlocks (i.e., releases ownership of) the associated mutex and releases ownership.
}

// A global function that will call the shared IPrint interface from a thread
void globalFunction(int iterations)
{
    for (int i = 0; i < iterations; ++i)
    {
        try
        {
            Iprint("Global Function", ++globalCount);
        }
        catch (const std::system_error& e)
        {
            std::cerr << e.what() << std::endl;
        }
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
            try
            {
                Iprint("Function Object", ++globalCount);
            }
            catch (const std::system_error& e)
            {
                std::cerr << e.what() << std::endl;
            }
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
            try
            {
                Iprint("Static Function", ++globalCount);
            }
            catch (const std::system_error& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
};

// A stored lambda function that will call the shared IPrint interface from a thread
auto storedLambda = [](int iterations) -> void {
    for (int i = 0; i < iterations; ++i)
    {
        try
        {
            Iprint("Stored Lambda", ++globalCount);
        }
        catch (const std::system_error& e)
        {
            std::cerr << e.what() << std::endl;
        }
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
            try
            {
                Iprint(s, ++globalCount);
            }
            catch (const std::system_error& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
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
        for (int i = 0; i < iterations; ++i)
        {
            try
            {
                Iprint("Temporary Lambda", ++globalCount);
            }
            catch (const std::system_error& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    });

    // Joinable identifies A thread that has finished executing code but has not yet been joined.
    // Threads that are joinable won't throw an exception when joined
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    if (t3.joinable()) t3.join();
    if (t4.joinable()) t4.join();
    if (t5.joinable()) t5.join();
    if (t6.joinable()) t6.join();

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "\n*** Elapsed time: " << elapsedTime.count() << " millis ***" << std::endl;

    return 0;
}
//
// Illustrate the functionality std::unique_lock::try_lock_until that tries to lock
// a mutex that blocks until a specific time has been reached or the lock has been acquired.
//
// Created by Michael Lewis on 6/27/23.
//

#include <chrono>
#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <system_error>

// 12 user-defined literals that represent hours, minutes, seconds, milliseconds, microseconds, and nanoseconds
// Will be used to set minimum duration to block for when attempting to acquire a lock
using namespace std::chrono_literals;

// Global variable used to illustrate a race condition
int globalCount = 0;

// Create a mutex around the console
std::timed_mutex console;

// A shared interface used to print data from various competing threads to illustrate a race condition
void Iprint(const std::string& s, int count)
{
    std::cout << s << ": ThreadId: " << std::this_thread::get_id()<< ": Count: " << count << std::endl;
}

// A global function that will call the shared IPrint interface from a thread
void globalFunction(int iterations)
{
    int i = 0;
    while (i < iterations)
    {
        // Any exception thrown by clock, time_point, or duration during the execution
        // (clocks, time points, and durations provided by the standard library never throw)
        try
        {
            // Tries to lock the mutex. Blocks until at most 100ms from now
            if (console.try_lock_until(std::chrono::system_clock::now() + 100ms))
            {
                ++i;
                Iprint("Global Function", ++globalCount);
                console.unlock();
            }
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
        int i = 0;
        while (i < iterations)
        {
            // Any exception thrown by clock, time_point, or duration during the execution
            // (clocks, time points, and durations provided by the standard library never throw)
            try
            {
                // Tries to lock the mutex. Blocks until at most 100ms from now
                if (console.try_lock_until(std::chrono::system_clock::now() + 100ms))
                {
                    ++i;
                    Iprint("Function Object", ++globalCount);
                    console.unlock();
                }
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
        int i = 0;
        while (i < iterations)
        {
            // Any exception thrown by clock, time_point, or duration during the execution
            // (clocks, time points, and durations provided by the standard library never throw)
            try
            {
                // Tries to lock the mutex. Blocks until at most 100ms from now
                if (console.try_lock_until(std::chrono::system_clock::now() + 100ms))
                {
                    ++i;
                    Iprint("Static Function", ++globalCount);
                    console.unlock();
                }
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
    int i = 0;
    while (i < iterations)
    {
        // Any exception thrown by clock, time_point, or duration during the execution
        // (clocks, time points, and durations provided by the standard library never throw)
        try
        {
            // Tries to lock the mutex. Blocks until at most 100ms from now
            if (console.try_lock_until(std::chrono::system_clock::now() + 100ms))
            {
                ++i;
                Iprint("Stored Lambda", ++globalCount);
                console.unlock();
            }
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
        int i = 0;
        while (i < iterations)
        {
            // Any exception thrown by clock, time_point, or duration during the execution
            // (clocks, time points, and durations provided by the standard library never throw)
            try
            {
                // Tries to lock the mutex. Blocks until at most 100ms from now
                if (console.try_lock_until(std::chrono::system_clock::now() + 100ms))
                {
                    ++i;
                    Iprint(s, ++globalCount);
                    console.unlock();
                }
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
        int i = 0;
        while (i < iterations)
        {
            // Any exception thrown by clock, time_point, or duration during the execution
            // (clocks, time points, and durations provided by the standard library never throw)
            try
            {
                // Tries to lock the mutex. Blocks until at most 100ms from now
                if (console.try_lock_until(std::chrono::system_clock::now() + 100ms))
                {
                    ++i;
                    Iprint("Temporary Lambda", ++globalCount);
                    console.unlock();
                }
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
    auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\n*** Elapsed time: " << elapsedTime.count() << " micros ***" << std::endl;

    return 0;
}

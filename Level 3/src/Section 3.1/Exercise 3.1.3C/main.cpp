//
// Illustrate the functionality of std::unique_lock, which is a general-purpose mutex
// ownership wrapper allowing deferred locking, time-constrained attempts at locking,
// recursive locking, transfer of lock ownership, and use with condition variable.
//
// Created by Michael Lewis on 6/27/23.
//

#include <chrono>
#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <system_error>

// Global variable used to illustrate a race condition
int globalCount = 0;

// Create a mutex around the console
std::mutex console;

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
        // defer locking until calling try_lock. This allows the lock to be non-blocking
        std::unique_lock<std::mutex> lock{console, std::defer_lock};
        if (console.try_lock())
        {
            ++i;
            Iprint("Global Function", ++globalCount);
            console.unlock();
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
            // defer locking until calling try_lock. This allows the lock to be non-blocking
            std::unique_lock<std::mutex> lock{console, std::defer_lock};
            if (console.try_lock())
            {
                ++i;
                Iprint("Function Object", ++globalCount);
                console.unlock();
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
            // defer locking until calling try_lock. This allows the lock to be non-blocking
            std::unique_lock<std::mutex> lock{console, std::defer_lock};
            if (console.try_lock())
            {
                ++i;
                Iprint("Static Function", ++globalCount);
                console.unlock();
            }
        }
    }
};

// A stored lambda function that will call the shared IPrint interface from a thread
auto storedLambda = [](int iterations) -> void {
    int i = 0;
    while (i < iterations)
    {
        // defer locking until calling try_lock. This allows the lock to be non-blocking
        std::unique_lock<std::mutex> lock{console, std::defer_lock};
        if (console.try_lock())
        {
            ++i;
            Iprint("Stored Lambda", ++globalCount);
            console.unlock();
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
            try
            {
                // defer locking until calling try_lock. This allows the lock to be non-blocking
                std::unique_lock<std::mutex> lock{console, std::defer_lock};
                if (console.try_lock())
                {
                    ++i;
                    Iprint(s, ++globalCount);
                    console.unlock();
                }
                else
                {
                    // Simulate an exception per the conversation that occurred in this thread
                    // https://quantnet.com/threads/3-1-3-c-lock-an-associated-mutex-without-locking.47242/post-320636
                    throw std::system_error(make_error_code(std::errc::operation_in_progress), "Simulated error");
                }
            }
            catch (const std::system_error& e)
            {
                std::cerr << e.what() << ":" << e.what() << std::endl;
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
        // Use a std::unique_lock with no associated mutex, to simulate an exception
        std::unique_lock<std::mutex> lock{};
        try
        {
            if (lock.try_lock())
            {
                Iprint("Temporary Lambda", ++globalCount);
                lock.unlock();
            }
        }
        catch (const std::system_error& e)
        {
            std::cerr << e.what() << std::endl;
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
        std::cerr << e.what() << std::endl;
    }

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Log the running time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "\n*** Elapsed time: " << elapsedTime.count() << " millis ***" << std::endl;

    return 0;
}
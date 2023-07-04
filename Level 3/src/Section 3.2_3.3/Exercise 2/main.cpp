//
// Created by Michael Lewis on 7/1/23.
//

#include <array>
#include <iostream>
#include <functional>
#include <random>
#include <thread>
#include <memory>

// Example struct provide by lecture material
struct X
{
    double val;

    X() : val(0.0) {}
    void operator ()() const
    {
        std::cout << "An X " << val << std::endl;
    }
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

// Part A -  Create a function that accepts a smart pointer and a new value for its state:
void Modify(PointerType& p, double newVal)
{
    // A uniformly-distributed integer random number generator that produces non-deterministic random numbers.
    std::random_device rd;

    // Random number engine seeded with rd
    std::mt19937 gen(rd());

    // Create a uniform distribution for which to bound the random number
    std::uniform_int_distribution<> delay(1, 100);

    // Sleep for some random amount of time
    std::this_thread::sleep_for(std::chrono::milliseconds(delay(gen)));
    p->val = newVal;
    p->operator()();
}

int main()
{
    // Part B - Create an array of 100 threads, that modifies the value of x->val
    PointerType p{new X};

    std::array<std::thread, 100> threads;
    for (int i = 0; i < threads.size(); ++i)
    {
        threads[i] = std::thread(Modify, std::ref(p), i);
    }

    // Join the threads to block main until threads complete
    for (auto& thread : threads)
    {
        if (thread.joinable()) thread.join();
    }

    // Part C - Explain the results
    // When running this program, you will notice data races between the threads. As an example, there can
    // situations where the same newVal is output to the console more than once, meaning different threads
    // were operating on X concurrently. Additionally, you might notice that some expected values of
    // i are not printed to the console, which also indicates a race condition where multiple threads were
    // operating on X concurrently.

    return 0;
}

//
// Created by Michael Lewis on 7/1/23.
//

#include <iostream>

#include "ActiveObject.hpp"

// Part A - Create a thread and a function that will be its thread function.
void counter(int iterations)
{
    for (int i = 0; i < iterations; ++i)
    {
        std::cout << "Function Counter=" << i << std::endl;
    }
}

// A function object that will act as a thread function for an ActiveObject
class FunctionObject
{
private:
    int iterations;

public:
    explicit FunctionObject(int iterations) : iterations{iterations} {}

    // Called by a thread
    void operator()() const
    {
        for (int i = 0; i < iterations; ++i)
        {
            std::cout << "Function Object Counter=" << i << std::endl;

        }
    }
};

// Test helper that invokes ActiveObject with the give std::thread
void ActiveObjectTester(std::thread& t)
{
    try
    {
        ActiveObject AO{t};
    }
    catch (const std::logic_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    // Part A - Create a thread and a function that will be its thread function.
    std::thread t1(std::ref(counter), 10);

    // Part B - Create an active object based on a thread with no associated thread function.
    std::thread t2;
    ActiveObjectTester(t2);

    // Part C - Implement thread functions using function objects and lambda functions.
    std::thread t3([]() -> void {
        for (int i = 0; i < 10; ++i)
        {
            std::cout << "Lambda Counter=" << i << std::endl;
        }});

    FunctionObject fo(10);
    std::thread t4(fo);

    // Part D - Test the code
    ActiveObjectTester(t1);
//    ActiveObjectTester(t2); Tested in Part B above
    ActiveObjectTester(t3);
    ActiveObjectTester(t4);
}
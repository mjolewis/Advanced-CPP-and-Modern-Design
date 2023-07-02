//
// Illustrate simple test programs that show how to run Functions asynchronously
//
// Created by Michael Lewis on 7/2/23.
//

#include <future>
#include <iostream>

// Simple function used to illustrate that a future doesn't have to return a value
void func1()
{
    std::cout << "Hi, I am like a voided check. I give you nothing back\n" << std::endl;
}

// Simple function used to illustrate getting a value from a future
double func2(double a, double b)
{
    return a * b;
}

// Use std::async (default settings) to launch func1 and func2 and get the results when appropriate
// Get the results of the computations and print them when applicable.
// Check the validity of the associated future before and after getting the result.
void test_PartB()
{
    std::cout << "\n*** Start Part A" << std::endl;

    // Showcase both the use of auto and std::future explicitly.
    auto f1 = std::async(func1);
    std::future<double> f2 = std::async(func2, 5, 5);

    std::cout << std::boolalpha << "F1 valid = " << f1.valid() << std::endl;
    std::cout << std::boolalpha << "F2 valid = " << f2.valid() << std::endl;

//    auto f1Result = f1.get(); return type is void, so you can't get anything from it
    auto f2Result = f2.get();
    std::cout << "f2.get()=" << f2Result << std::endl;

    std::cout << std::boolalpha << "F1 valid = " << f1.valid() << std::endl;  // Valid still because get isn't called
    std::cout << std::boolalpha << "F2 valid = " << f2.valid() << std::endl;
}

// Illustrate what happens when getting the result of a std::future more than once. (e.g. a seg fault).
void test_PartC()
{
    std::cout << "\n*** Start Part C" << std::endl;

    std::future<double> f = std::async(func2, 5, 5);

    std::cout << "f2.get() = " << f.get() << std::endl;

    // Calling get on a future more than once would cause a SIGSEGV
//    std::cout << "f2.get() = " << f.get() << std::endl;
}

// Now test the same code using the launch parameter std::launch::async. Do you notice any differences?
// Response:
// Behavior is undefined when no policy is set per CPP Reference. However, when std::launch::async is set,
// then the task is executed on a different thread, meaning the main thread can continue executing before
// the async task is completed.
void test_PartD()
{
    std::cout << "\n*** Start Part D" << std::endl;
    auto f1 = std::async(std::launch::async, func1);
    std::future<double> f2 = std::async(std::launch::async, func2, 5, 5);

    std::cout << std::boolalpha << "F1 valid = " << f1.valid() << std::endl;
    std::cout << std::boolalpha << "F2 valid = " << f2.valid() << std::endl;

    auto f2Result = f2.get();
    std::cout << "f2.get()=" << f2Result << std::endl;
}

// We now wish to asynchronously call a function at some time later in the
// client code (deferred/lazy evaluation). Get the result of the function and
// check that it is the same as before.
void test_PartE()
{
    std::cout << "\n*** Start Part E" << std::endl;
    auto f1 = std::async(std::launch::deferred, func1);
    std::future<double> f2 = std::async(std::launch::deferred, func2, 5, 5);

    std::cout << "Back on the main thread" << std::endl;

    // The task is executed on the calling thread only after the first time its result is requested
    f1.get();
    auto f2Result = f2.get();
    std::cout << "f2.get()=" << f2Result << std::endl;
}

int main()
{
    test_PartB();
    test_PartC();
    test_PartD();
    test_PartE();
    return 0;
}

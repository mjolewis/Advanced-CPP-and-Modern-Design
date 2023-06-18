//
// Created by Michael Lewis on 6/3/23.
//

#include <functional>
#include <iostream>
#include <cmath>

#include "Utils.hpp"


// Free function to demonstrate assignment to a function wrapper
template<typename T>
constexpr T root(T value)
{
    return sqrt(value);
}

// Struct to represent a function object
template<typename T>
struct functionObject
{
    double operator()(T value) { return sqrt(value); };
};

// Alias for a function wrapper
template<typename T>
using FunctionType = std::function<T (const T& t)>;

/**
 * General purpose function wrapper to print args to the console
 */
void test_functionWrapper_freeFunction()
{
    std::cout << "square root for the free function=";

    // Assign a free function to a function wrapper
    FunctionType<double> f = root<double>;

    // Log the square root
    Utils::print(f, 9.0);
    assert(3 == f(9.0));
}

void test_functionWrapper_lambda()
{
    std::cout << "square root for the lambda=";

    // Assign a lambda to a function wrapper
    FunctionType<double> f = [] (double value) -> double { return sqrt(value); };

    // Log the square root
    Utils::print(f, 16.0);
    assert(4 == f(16.0));
}

void test_functionWrapper_functionObject()
{
    std::cout << "square root for the function object=";

    // Assign a function object to a function wrapper
    FunctionType<double> f = functionObject<double>();

    // Log the square root
    Utils::print(f, 25.0);
    assert(5 == f(25.0));
}

int main()
{
    test_functionWrapper_freeFunction();
    test_functionWrapper_lambda();
    test_functionWrapper_functionObject();
    return 0;
}
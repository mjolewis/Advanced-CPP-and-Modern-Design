//
// Created by Michael Lewis on 6/3/23.
//

#include <functional>
#include <iostream>

#include "C.hpp"

// using assignment to simply code base
template<typename T>
using FunctionType = std::function<T (const T& arg)>;

// using namespace to make code more readable when binding to the placeholders
using namespace std::placeholders;

/**
 * Tests binding to a static function using std::function
 */
void test_bindToStaticFunction()
{
    FunctionType<double> f = C::Square;
    auto actual = f(2);
    assert(4 == actual);
}

/**
 * Tests binding to a member function using std::bind and std::placeholder
 */
void test_translate()
{
    C c(2);
    auto translate = std::bind(c, _1);
    auto actual = c.translate(2);
    std::cout << "translate(2)=" << actual << std::endl;
    assert(4 == actual);
}

void test_translate2()
{
    C c(2);
    auto translate = std::bind(c, _2, _1);
    auto actual = c.translate2(2, 1); // equates to translate(1, 2);
    std::cout << "translate2(1, 2)=" << actual << std::endl;
    assert(5 == actual);
}

void test_functionObject()
{
    C c(2);
    auto functionObject = std::bind(c, _1);
    auto actual = c(2);
    std::cout << "function object=2" << std::endl;
    assert(4 == actual);
}

int main()
{
    test_translate();
    test_translate2();
    test_functionObject();
    return 0;
}
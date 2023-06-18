//
// Created by Michael Lewis on 6/3/23.
//

#include <functional>
#include <iostream>

// 3-arity Free function to illustrate std::bind use cases
double freeFunction3(double x, double y, double z)
{
    return x+y+z;
}

// using namespace to make code more readable when binding to the placeholders
using namespace std::placeholders;

/**
 * Test free function of arity three.
 */
void test_freeFunction3()
{
    // _1, _2, _3 represent future arguments
    auto bind = std::bind(&freeFunction3, _2, _1, _3);
    auto actual = bind(1, 2, 3); // Equivalent to invoking freeFunction3(2, 1, 3)
    std::cout << actual << std::endl;
    assert(6 == actual);
}

/**
 * Test free function of arity two.
 */
void test_freeFunction2()
{
    // _1 and _2 represent future arguments
    // _3 represents a bound argument
    auto bind = std::bind(freeFunction3, 100, _1, _2);
    auto actual = bind(1, 2); // 1 is bound to _1. 2 is bound to _2. Equivalent to invoking freeFunction(100, 1, 2)
    std::cout << actual << std::endl;
    assert(103 == actual);
}

/**
 * Test free function of arity one
 */
void test_freeFunction1()
{
    // _1 represents a future argument
    // _2 and _3 represent bounded arguments
    auto bind = std::bind(&freeFunction3, 10, _1, 11);
    auto actual = bind(4); // 4 is bound to _1. Equivalent to invoking freeFunction(10, 4, 11)
    std::cout << actual << std::endl;
    assert(25 == actual);
}

/**
 * Test free function of arity zero
 */
void test_freeFunction0()
{
    // _1, _2, and _3 represent bounded arguments
    auto bind = std::bind(&freeFunction3, 10, 11, 4);
    auto actual = bind();
    std::cout << actual << std::endl;
    assert(25 == actual);
}

int main()
{
    test_freeFunction3();
    test_freeFunction2();
    test_freeFunction1();
    test_freeFunction0();
    return 0;
}


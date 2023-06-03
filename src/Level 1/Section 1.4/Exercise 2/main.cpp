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
    auto bind = std::bind(&freeFunction3, _1, _2, _3);
    auto actual = bind(1, 2, 3);
    std::cout << actual << std::endl;
    assert(6 == actual);
}

/**
 * Test free function of arity two.
 */
void test_freeFunction2()
{
    // _1 and _2 represent future arguments
    // _3 represents a current argument
    auto bind = std::bind(freeFunction3, _1, _2, 100);
    auto actual = bind(1, 2);
    std::cout << actual << std::endl;
    assert(103 == actual);
}

/**
 * Test free function of arity one
 */
void test_freeFunction1()
{
    // _1 represents a future argument
    // _2 and _3 represent current arguments
    auto bind = std::bind(&freeFunction3, _1, 10, 11);
    auto actual = bind(4); // 1000 and 77 should be unused
    std::cout << actual << std::endl;
    assert(25 == actual);
}

/**
 * Test free function of arity zero
 */
void test_freeFunction0()
{
    // _1, _2, and _3 represent current arguments
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


//
// Created by Michael Lewis on 6/3/23.
//

#include <functional>
#include <iostream>

#include "NextGenPolymorphism.hpp"

// using alias to simply readability of function wrapper
template<typename T>
using FunctionType = std::function<T (const T& t)>;

/**
 * Test next generation design patterns to square a number using a composed function wrapper
 */
void test_square()
{
    NextGenPolymorphism<double> ng{[] (double value) -> double { return value * value; }, 1.0 };
    auto actual = ng.execute(2);
    std::cout << "NextGenPolymorphism::execute=" << actual << std::endl;
    assert(4 == actual);
}

/**
 * Calculate the sum of all integers for [1,N] using Gauss' method
 */
void test_gauss_summation()
{
    NextGenPolymorphism<int> ng{[] (int n) -> int { return (n * (n + 1)) / 2; }, 1 };
    auto actual = ng.execute(100);
    std::cout << "NextGenPolymorphism::execute=" << actual << std::endl;
    assert(5050 == actual);
}

/**
 * Scale a number by a factor of 10 using next generation design patterns
 */
void test_scaleValueByTen()
{
    NextGenPolymorphism<int> ng{[] (int value) -> int { return value; }, 10 };
    auto actual = ng.execute(10);
    std::cout << "NextGenPolymorphism::execute=" << actual << std::endl;
    assert(100 == actual);
}

int main()
{
    test_square();
    test_gauss_summation();
    test_scaleValueByTen();
    return 0;
}

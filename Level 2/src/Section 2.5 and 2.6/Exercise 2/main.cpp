//
// Machine epsilon gives an upper bound on the relative error due to rounding in floating point arithmetic.
// In C++11, epsilon is the difference between 1.0 and the next representable value of the given floating-point type.
//
// This exercise, is therefor, to test the functionality of epsilon in C++
//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>
#include <limits>

// Course provided example of how to calculate epsilon for double types
double doubleEpsilon()
{
    double epsilon = 1.0;
    while ((1.0 + 0.5*epsilon) != 1.0)
    {
        epsilon *= 0.5;
    }

    return epsilon;
}

// Generalized function to calculate epsilon for the specified type
template<typename T>
T epsilon(T&& epsilon)
{
    while ((1.0 + 0.5*epsilon) != 1.0)
    {
        epsilon *= 0.5;
    }

    return epsilon;
}

int main()
{
    // Part A - Double epsilon
    double d = doubleEpsilon();
    auto result = std::numeric_limits<double>::epsilon();

    int i = epsilon(10);
    auto result1 = std::numeric_limits<int>::epsilon();

    float f = epsilon(1.0f);
    auto result2 = std::numeric_limits<float>::epsilon();

    short s = epsilon((short) 1.0);
    auto result3 = std::numeric_limits<short>::epsilon();

    long double l = epsilon(1.0L);
    auto result4 = std::numeric_limits<long double>::epsilon();

    std::cout << "double epsilon = " <<  d << std::endl;
    std::cout << "double numeric limit epsilon = " << result << std::endl;
    std::cout << "integer epsilon = " <<i << std::endl;
    std::cout << "integer numeric limit epsilon = " << result1 << std::endl;
    std::cout << "float epsilon = " << f << std::endl;
    std::cout << "float numeric limit epsilon = " << result2 << std::endl;
    std::cout << "short epsilon = " << s << std::endl;
    std::cout << "short numeric limit epsilon = " << result3 << std::endl;
    std::cout << "long double epsilon = " << l << std::endl;
    std::cout << "long double numeric limit epsilon = " << result4 << std::endl;
    return 0;
}
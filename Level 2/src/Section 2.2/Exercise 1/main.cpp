//
// Test cases for a simple number library built on type traits
//
// Created by Michael Lewis on 6/19/23.
//

#include <array>
#include <complex>
#include <iostream>
#include <vector>

#include "Numerics.hpp"

/**
 * Tests vector space addition on container types
 */
void test_vectorSpace_addition()
{
    std::cout << "\n***Vector Addition ***" << std::endl;
    std::vector<double> vec1 = {1.0, 2.0, 3.0};
    std::vector<double> vec2 = {1.0, 2.0, 3.0};
    auto result1 = Numerics::Addition(vec1, vec2);
    std::for_each(result1.cbegin(), result1.cend(), [&] (double element) -> void {std::cout << element << ", ";});

    std::cout << "\n*** Array Addition ***" << std::endl;
    std::array<double, 3> arr1 = {1.0, 2.0, 3.0};
    std::array<double, 3> arr2 = {1.0, 2.0, 3.0};
    auto result2 = Numerics::Addition(arr1, arr2);
    std::for_each(result2.cbegin(), result2.cend(), [&] (double element) -> void {std::cout << element << ", ";});

}

/**
 * Tests scalar addition
 */
void test_scalar_addition()
{
    auto result = Numerics::Addition(1.0, 2.0);

    std::cout << "\n*** Scalar Addition ***" << std::endl;
    std::cout << "Input= (1,2), Output=" << result << std::endl;
}

/**
 * Tests vector space additive inverse on container types
 */
void test_vectorSpace_additiveInverse()
{
    std::cout << "\n*** Vector Additive Inverse ***" << std::endl;
    std::vector<double> vec1 = {1.0, 2.0, 3.0};
    Numerics::AdditiveInverse(vec1);
    std::for_each(vec1.cbegin(), vec1.cend(), [&] (double element) -> void {std::cout << element << ", ";});

    std::cout << "\n*** Array Additive Inverse ***" << std::endl;
    std::array<double, 3> arr1 = {1.0, 2.0, 3.0};
    Numerics::AdditiveInverse(arr1);
    std::for_each(arr1.cbegin(), arr1.cend(), [&] (double element) -> void {std::cout << element << ", ";});
}

/**
 * Tests scalar additive inverse
 */
void test_scalar_additiveInverse()
{
    double input = 1.0;
    Numerics::AdditiveInverse(input);

    std::cout << "\n*** Scalar Additive Inverse ***" << std::endl;
    std::cout << "Input= 1, Output= " << input << std::endl;
}

/**
 * Tests vector space multiplication on container types
 */
void test_vectorSpace_multiplication()
{
    std::cout << "\n***Vector Multiplication ***" << std::endl;
    std::vector<double> vec1 = {1.0, 2.0, 3.0};
    std::vector<double> vec2 = {1.0, 2.0, 3.0};
    auto result1 = Numerics::Multiplication(vec1, vec2);
    std::for_each(result1.cbegin(), result1.cend(), [&] (double element) -> void {std::cout << element << ", ";});

    std::cout << "\n*** Array Multiplication ***" << std::endl;
    std::array<double, 3> arr1 = {1.0, 2.0, 3.0};
    std::array<double, 3> arr2 = {1.0, 2.0, 3.0};
    auto result2 = Numerics::Multiplication(arr1, arr2);
    std::for_each(result2.cbegin(), result2.cend(), [&] (double element) -> void {std::cout << element << ", ";});
}

/**
 * Tests scalar multiplication
 */
void test_scalar_multiplication()
{
    auto result = Numerics::Multiplication(1.0, 2.0);

    std::cout << "\n*** Scalar Multiplication ***" << std::endl;
    std::cout << "Input= (1,2), Output=" << result << std::endl;
}

// Using declaration to improve code readability
using Complex = std::complex<double>;
using ComplexVector = std::vector<Complex>;
using ComplexArray = std::array<Complex, 3>;

/**
 * Tests vector space addition on complex container types
 */
void test_vectorSpace_addition_complex()
{
    std::cout << "\n*** Complex Vector Addition ***" << std::endl;
    ComplexVector vec1 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    ComplexVector vec2 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    auto result1 = Numerics::Addition(vec1, vec2);
    std::for_each(result1.cbegin(), result1.cend(), [&] (Complex element) -> void {std::cout << element << ", ";});

    std::cout << "\n*** Complex Array Addition ***" << std::endl;
    ComplexArray arr1 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    ComplexArray arr2 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    auto result2 = Numerics::Addition(arr1, arr2);
    std::for_each(result2.cbegin(), result2.cend(), [&] (Complex element) -> void {std::cout << element << ", ";});

}

/**
 * Tests vector space additive inverse on complex container types
 */
void test_vectorSpace_additiveInverse_complex()
{
    std::cout << "\n*** Complex Additive Inverse ***" << std::endl;
    ComplexVector vec1 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    Numerics::AdditiveInverse(vec1);
    std::for_each(vec1.cbegin(), vec1.cend(), [&] (Complex element) -> void {std::cout << element << ", ";});

    std::cout << "\n*** Complex Array Additive Inverse ***" << std::endl;
    ComplexArray arr1 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    Numerics::AdditiveInverse(arr1);
    std::for_each(arr1.cbegin(), arr1.cend(), [&] (Complex element) -> void {std::cout << element << ", ";});
}

/**
 * Tests vector space multiplication on complex container types
 */
void test_vectorSpace_multiplication_complex()
{
    std::cout << "\n*** Complex Vector Multiplication ***" << std::endl;
    ComplexVector vec1 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    ComplexVector vec2 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    auto result1 = Numerics::Multiplication(vec1, vec2);
    std::for_each(result1.cbegin(), result1.cend(), [&] (Complex element) -> void {std::cout << element << ", ";});

    std::cout << "\n*** Complex Array Multiplication ***" << std::endl;
    ComplexArray arr1 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    ComplexArray arr2 = {Complex(1.0, 2.0), Complex(3.0, 4.0), Complex(5.0, 6.0)};
    auto result2 = Numerics::Multiplication(arr1, arr2);
    std::for_each(result2.cbegin(), result2.cend(), [&] (Complex element) -> void {std::cout << element << ", ";});
}

int main()
{
    test_vectorSpace_addition();
    test_scalar_addition();
    test_vectorSpace_additiveInverse();
    test_scalar_additiveInverse();
    test_vectorSpace_multiplication();
    test_scalar_multiplication();
    test_vectorSpace_addition_complex();
    test_vectorSpace_additiveInverse_complex();
    test_vectorSpace_multiplication_complex();
    return 0;
}
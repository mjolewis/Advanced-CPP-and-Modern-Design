//
// Created by Michael Lewis on 7/11/23.
//

#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

using ComplexDouble = std::complex<double>;

// Alias for BinaryFunction lambda's used by the inner_products
template <typename T>
using BinaryFunction = std::function < T (const T& t1, const T& t2)>;

// Stored lambda to multiply elements in a vector
template<typename T>
BinaryFunction<T> MUL = [](const T& lhs, const T& rhs) { return lhs * rhs; };

// Stored lambda to add elements in a vector
template<typename T>
BinaryFunction<T> ADD = [](const T& lhs, const T& rhs) { return lhs + rhs; };

// Calculate the inner product between two vectors
template <typename T, size_t N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue)
{
    return std::inner_product(v1.cbegin(), v1.cend(), v2.cbegin(), initValue);
}

// Calculate the inner product between two vectors using the specified binary functions
template <typename T, size_t N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue,
                const BinaryFunction<T>& op1,
                const BinaryFunction<T>& op2)
{
    return std::inner_product(v1.cbegin(), v1.cend(), v2.cbegin(), initValue, op1, op2);
}

// Calculate the outer product between two vectors
template<typename T, size_t NR, size_t NC>
Matrix<T, NR, NC> outer_product(const Vector<T, NR>& v1, const Vector<T, NC>& v2)
{
    Matrix<T, NR, NC> matrix;
    for (auto outer = v1.cbegin(); outer != v1.cend(); ++outer)
    {
        for (auto inner = v2.cbegin(); inner != v2.cend(); ++inner)
        {
            matrix(std::distance(v1.cbegin(), outer), std::distance(v2.cbegin(), inner)) = *outer * *inner;
        }
    }

    return matrix;
}

// Specialized outer product for complex numbers that takes the complex conjugate transpose
// of vector v into account: u⨂v=uv
template<size_t NR, size_t NC>
Matrix<ComplexDouble, NR, NC> outer_product(const Vector<ComplexDouble, NR>& v1, const Vector<ComplexDouble, NC>& v2)
{
    Matrix<ComplexDouble, NR, NC> matrix;
    Vector<ComplexDouble, NC> conjugate;

    // Complex conjugate of v2
    for (auto it = v2.cbegin(); it != v2.cend(); ++it)
    {
        conjugate[std::distance(v2.cbegin(), it)] = std::conj(*it);
    }

    for (auto outer = v1.cbegin(); outer != v1.cend(); ++outer)
    {
        for (auto inner = v2.cbegin(); inner != v2.cend(); ++inner)
        {
            matrix(std::distance(v1.cbegin(), outer), std::distance(v2.cbegin(), inner)) = *outer * *inner;
        }
    }

    return matrix;
}

// Calculates the inner product of two vectors
void test_InnerProduct()
{
    const Vector<int, 5>& vec1{0, 1, 2, 3, 4};
    const Vector<int, 5>& vec2{5, 4, 2, 3, 1};

    auto innerProduct = inner_product(vec1, vec2, 0);

    std::cout << "Inner product of vec1 and vec2: " << innerProduct << '\n';
    assert(21 == innerProduct);
}

// Calculates the inner product of two vectors and then multiplies each element in the resulting vector
void test_Product_Of_Products()
{
    const Vector<int, 4>& vec1{1, 1, 2, 3};
    const Vector<int, 4>& vec2{5, 4, 2, 3};

    auto productOfProduct = inner_product(vec1, vec2, 1, MUL<int>, MUL<int>);
    std::cout << "Inner product of product for vec1 and vec2: " << productOfProduct << '\n';
    assert(720 == productOfProduct);
}

// Calculates the inner product of two vectors and then adds each element in the resulting vector
void test_Product_Of_Sums()
{
    const Vector<int, 4>& vec1{1, 1, 2, 3};
    const Vector<int, 4>& vec2{5, 2, 2, 1};

    auto productOfSum = inner_product(vec1, vec2, 1, MUL<int>, ADD<int>);
    std::cout << "Inner product of sum for vec1 and vec2: " << productOfSum << '\n';
    assert(288 == productOfSum);
}

// Calculates the inner summation of two vectors
void test_Inner_Sum()
{
    const Vector<int, 4>& vec1{5, 5, 5, 5};
    const Vector<int, 4>& vec2{5, 5, 5, 5};

    auto sumOfSum = inner_product(vec1, vec2, 0, ADD<int>, ADD<int>);
    std::cout << "Inner summation for vec1 and vec2: " << sumOfSum << '\n';
    assert(40 == sumOfSum);
}

// Calculates the sum of products between two vectors
void test_Sum_Of_Product()
{
    const Vector<int, 4>& vec1{5, 5, 5, 5};
    const Vector<int, 4>& vec2{5, 5, 5, 5};

    auto sumOfSum = inner_product(vec1, vec2, 0, ADD<int>, MUL<int>);
    std::cout << "Inner sum of products for vec1 and vec2: " << sumOfSum << '\n';
    assert(100 == sumOfSum);
}

// Print each element in this BitMap
template<typename T, size_t NR, size_t NC>
void print(const Matrix<T, NR, NC>& matrix)
{
    for (int i = 0; i < NR; ++i)
    {
        std::cout << "[";
        for (int j = 0; j < NC; ++j)
        {
            std::cout << matrix(i, j) << ", ";
        }
        std::cout << "]\n";
    }
}

void test_Outer_Product()
{
    const Vector<int, 4>& vec1{3, 4, 1, 4};
    const Vector<int, 3>& vec2{3, 7, 5};

    auto outerProduct = outer_product(vec1, vec2);
    std::cout << "Outer product of vec1 and vec:\n";
    print(outerProduct);
}

void test_Outer_Product_Complex()
{
    ComplexDouble c1{1.0, 2.0};
    ComplexDouble c2{2.0, 1.0};
    ComplexDouble c3{4.0, 2.0};
    ComplexDouble c4{0.0, 2.0};
    const Vector<ComplexDouble, 4> vec1{c1, c2, c3, c4};

    ComplexDouble c5{1.0, 2.0};
    ComplexDouble c6{2.0, 1.0};
    ComplexDouble c7{4.0, 2.0};
    ComplexDouble c8{0.0, 2.0};
    const Vector<ComplexDouble, 4> vec2{c5, c6, c7, c8};

    auto outerProduct = outer_product(vec1, vec2);
    std::cout << "Outer product for complex vec1 and vec:\n";
    print(outerProduct);
}

int main()
{
    test_InnerProduct();
    test_Product_Of_Products();
    test_Product_Of_Sums();
    test_Inner_Sum();
    test_Sum_Of_Product();
    test_Outer_Product();
    test_Outer_Product_Complex();
    return 0;
}

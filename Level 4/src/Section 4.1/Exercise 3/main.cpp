//
// Illustrate basic use cases of a compile time Matrix adapter.
//
// Created by Michael Lewis on 7/8/23.
//

#include <algorithm>
#include <cassert>
#include <iostream>
#include <array>

#include "Matrix.hpp"

// Test default ctor of the Matrix adapter
void test_DefaultCtor()
{
    Matrix<double, 3, 2> matrix{};
    std::cout << "*** Default ctor ***" << std::endl;
    matrix.print();

    // Row 0
    assert(0 == matrix(0, 0));
    assert(0 == matrix(0, 1));

    // Row 1
    assert(0 == matrix(1, 0));
    assert(0 == matrix(1, 1));

    // Row 2
    assert(0 == matrix(2, 0));
    assert(0 == matrix(2, 1));
}

// Test initializer list ctor of the Matrix adapter
void test_InitializerList()
{
    Matrix<double, 3, 2> matrix{9, 4, 3, 2, 11, 6};
    std::cout << "\n *** Initializer list ***" << std::endl;
    matrix.print();

    // Row 0
    assert(9 == matrix(0, 0));
    assert(4 == matrix(0, 1));

    // Row 1
    assert(3 == matrix(1, 0));
    assert(2 == matrix(1, 1));

    // Row 2
    assert(11 == matrix(2, 0));
    assert(6 == matrix(2, 1));
}

// Test default value initialization of the Matrix adapter
void test_DefaultValue()
{
    Matrix<double, 3, 4> matrix(11);
    std::cout << "\n *** Value Initialization ***" << std::endl;
    matrix.print();

    // Row 0
    assert(11 == matrix(0, 0));
    assert(11 == matrix(0, 1));
    assert(11 == matrix(0, 2));
    assert(11 == matrix(0, 3));

    // Row 1
    assert(11 == matrix(1, 0));
    assert(11 == matrix(1, 1));
    assert(11 == matrix(1, 2));
    assert(11 == matrix(1, 3));

    // Row 2
    assert(11 == matrix(2, 0));
    assert(11 == matrix(2, 1));
    assert(11 == matrix(2, 2));
    assert(11 == matrix(2, 3));
}

// Test copy ctor of the Matrix adapter
void test_CopyCtor()
{
    Matrix<double, 3, 4> matrix1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Matrix<double, 3, 4> matrix2{matrix1};
    std::cout << "\n *** Copy ctor ***" << std::endl;
    matrix2.print();

    // Row 0
    assert(0 == matrix1(0, 0));
    assert(1 == matrix1(0, 1));
    assert(2 == matrix1(0, 2));
    assert(3 == matrix1(0, 3));

    // Row 1
    assert(4 == matrix1(1, 0));
    assert(5 == matrix1(1, 1));
    assert(6 == matrix1(1, 2));
    assert(7 == matrix1(1, 3));

    // Row 2
    assert(8 == matrix1(2, 0));
    assert(9 == matrix1(2, 1));
    assert(10 == matrix1(2, 2));
    assert(11 == matrix1(2, 3));
}

// Test Matrix addition across this Matrix and that Matrix
void test_MatrixAddition()
{
    Matrix<double, 2, 3> matrix1{1, 2, 3, 4, 5, 6};
    Matrix<double, 2, 3> matrix2{1, 2, 3, 4, 5, 6};
    auto add = matrix1.operator+(matrix2);
    std::cout << "\n *** Matrix addition ***" << std::endl;
    add.print();

    // Row 0
    assert(2 == add(0, 0));
    assert(4 == add(0, 1));
    assert(6 == add(0, 2));

    // Row 1
    assert(8 == add(1, 0));
    assert(10 == add(1, 1));
    assert(12 == add(1, 2));
}

// Test Matrix subtraction across this Matrix and that Matrix
void test_MatrixSubtraction()
{
    Matrix<double, 2, 3> matrix1{2, 4, 6, 8, 10, 12};
    Matrix<double, 2, 3> matrix2{1, 2, 3, 4, 5, 6};
    auto subtract = matrix1.operator-(matrix2);
    std::cout << "\n *** Matrix subtraction ***" << std::endl;
    subtract.print();

    // Row 0
    assert(1 == subtract(0, 0));
    assert(2 == subtract(0, 1));
    assert(3 == subtract(0, 2));

    // Row 1
    assert(4 == subtract(1, 0));
    assert(5 == subtract(1, 1));
    assert(6 == subtract(1, 2));
}

// Test unary negation of a Matrix. This modifies the current objects state
void test_UnaryNegation()
{

    Matrix<double, 2, 3> matrix{2, 4, 6, 8, 10, 12};
    matrix.operator-();
    std::cout << "\n *** Unary negation ***" << std::endl;
    matrix.print();

    // Row 0
    assert(-2 == matrix(0, 0));
    assert(-4 == matrix(0, 1));
    assert(-6 == matrix(0, 2));

    // Row 1
    assert(-8 == matrix(1, 0));
    assert(-10 == matrix(1, 1));
    assert(-12 == matrix(1, 2));
}

// Test Matrix multiplication across this Matrix and that Matrix
void test_Multiplication()
{
    Matrix<double, 2, 3> matrix{2, 4, 6, 8, 10, 12};
    double scalar{3.0};
    auto result = scalar * matrix;
    std::cout << "\n *** Pre-multiplication ***" << std::endl;
    result.print();

    // Row 0
    assert(6 == result(0, 0));
    assert(12 == result(0, 1));
    assert(18 == result(0, 2));

    // Row 1
    assert(24 == result(1, 0));
    assert(30 == result(1, 1));
    assert(36 == result(1, 2));
}

// Test Matrix modification using std::function
void test_Modify()
{
    Matrix<double, 2, 3> matrix{2, 4, 6, 8, 10, 12};
    std::function<double (double)> f = [](double element) -> double { return element * 3; };
    matrix.modify<double>(f);
    std::cout << "\n *** Modify ***" << std::endl;
    matrix.print();

    // Row 0
    assert(6 == matrix(0, 0));
    assert(12 == matrix(0, 1));
    assert(18 == matrix(0, 2));

    // Row 1
    assert(24 == matrix(1, 0));
    assert(30 == matrix(1, 1));
    assert(36 == matrix(1, 2));
}

int main()
{
    test_DefaultCtor();
    test_InitializerList();
    test_DefaultValue();
    test_CopyCtor();
    test_MatrixAddition();
    test_MatrixSubtraction();
    test_UnaryNegation();
    test_Multiplication();
    test_Modify();

    return 0;
}
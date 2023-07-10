//
// Created by Michael Lewis on 7/8/23.
//

#include <algorithm>
#include <cassert>
#include <iostream>
#include <array>

#include "Vector.hpp"

// Test default ctor of the Vector adapter
void test_DefaultCtor()
{
    Vector<double, 5> vec1{};
    vec1.print();
    assert(0 == vec1[0]);
    assert(0 == vec1[1]);
    assert(0 == vec1[2]);
    assert(0 == vec1[3]);
    assert(0 == vec1[4]);
}

// Test initializer list ctor of the Vector adapter
void test_InitializerList()
{
    Vector<double, 5> vec1{9, 4, 3, 2, 11};
    vec1.print();
    assert(9 == vec1[0]);
    assert(4 == vec1[1]);
    assert(3 == vec1[2]);
    assert(2 == vec1[3]);
    assert(11 == vec1[4]);
}

// Test default value initialization of the Vector adapter
void test_DefaultValue()
{
    Vector<double, 5> vec1(11);
    vec1.print();
    assert(11 == vec1[0]);
    assert(11 == vec1[1]);
    assert(11 == vec1[2]);
    assert(11 == vec1[3]);
    assert(11 == vec1[4]);
}

// Test copy ctor of the Vector adapter
void test_CopyCtor()
{
    Vector<double, 5> vec1{9, 4, 3, 2, 11};
    Vector<double, 5> vec2{vec1};
    vec2.print();
    assert(9 == vec1[0]);
    assert(4 == vec1[1]);
    assert(3 == vec1[2]);
    assert(2 == vec1[3]);
    assert(11 == vec1[4]);
}

// Test vector addition across this vector and that vector
void test_VectorAddition()
{
    Vector<double, 5> vec1{1, 2, 3, 4, 5};
    Vector<double, 5> vec2{1, 2, 3, 4, 5};
    auto add = vec1.operator+(vec2);
    add.print();
    assert(2 == add[0]);
    assert(4 == add[1]);
    assert(6 == add[2]);
    assert(8 == add[3]);
    assert(10 == add[4]);
}

// Test vector subtraction across this vector and that vector
void test_VectorSubtraction()
{
    Vector<double, 5> vec1{2, 4, 6, 8, 10};
    Vector<double, 5> vec2{1, 2, 3, 4, 5};
    auto add = vec1.operator-(vec2);
    add.print();
    assert(1 == add[0]);
    assert(2 == add[1]);
    assert(3 == add[2]);
    assert(4 == add[3]);
    assert(5 == add[4]);
}

// Test vector multiplication across this vector and that vector
void test_Multiplication()
{
    Vector<double, 2> vec1{2.0, 4.0};
    double scalar{2.0};
    auto result = scalar * vec1;
    vec1.print();

    // Initial vector should not be modified
    assert(2 == vec1[0]);
    assert(4 == vec1[1]);

    // New vector holds modified values
    assert(4 == result[0]);
    assert(8 == result[1]);
}

// Test vector modification using std::function
void test_Modify()
{
    Vector<double, 3> vec1{2.0, 4.0, 6.0};
    std::function<double (double)> f = [](double element) -> double { return element * 3; };
    vec1.modify<double>(f);
    vec1.print();
    assert(6 == vec1[0]);
    assert(12 == vec1[1]);
    assert(18 == vec1[2]);
}

int main()
{
    test_DefaultCtor();
    test_InitializerList();
    test_DefaultValue();
    test_CopyCtor();
    test_VectorAddition();
    test_VectorSubtraction();
    test_Multiplication();
    test_Modify();

    return 0;
}
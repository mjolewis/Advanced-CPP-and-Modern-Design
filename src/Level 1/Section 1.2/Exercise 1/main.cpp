//
// A simple test program to demonstrate new C++ language features
// Concepts under test include:
// noexcept -> default functions -> deleted functions -> explicit
//
// Created by Michael Lewis on 5/30/23.
//

#include "C.hpp"

/**
 * Question: What is the resulting behavior of a defaulted function
 * Answer: The compiler generates a trivial constructor that initializes members to default values.
 * In this case, the std::vector is initialized with its size = 0.
 */
void test_defaultedFunctions()
{
    auto myClass = C<int>();
    assert(0 == myClass.getSize());
}

/**
 * Question: What is the resulting behavior of a deleted function
 * Answer: Explicitly deleted functions cannot be used. Their use results in a compilation error.
 */
void test_deletedFunctions()
{
    auto myClass = C<int>();

    // Copy constructor is deleted, so it can't be used. Any attempt to use it results in a compilation error
    // auto copy = C<int>(myClass);

    // Assign data
    auto assigment = C<int>();

    // Copy constructor is deleted, so it can't be used. Any attempt to use it results in a compilation error
    // assigment.operator=(myClass);
}

/**
 * Test that illustrates the use of constexpr
 */
void test_sumArray()
{
    auto myClass = C<int>();
    assert(15 == myClass.sumArray());
}

/**
 * Test core logic of setting and summing data in a container
 */
void test_setAndSumArray()
{
    auto myClass = C<int>();

    // Set new array
    for (int i = 0; i < 5; ++i) myClass.setArray(i, i);

    // Assert new sum equals 10
    assert(10 == myClass.sumArray());
}

/**
 * Test core logic of setting and summing data in a container
 */
void test_setAndSumVector()
{
    auto myClass = C<int>();

    // Set new vector
    for (int i = 0; i < 5; ++i) myClass.setVec(i, i);

    // Assert new sum equals 10
    assert(10 == myClass.sumVector());
}

/**
 * Test that illustrates the use of constexpr
 */
void test_constExpr()
{
    auto myClass = C<int>();

    // Publish frequency is a compile time constant
    assert(1000 == myClass.getPublishFrequency());
}

/**
 * Utility test to ensure all functions from previous lectures continue to compile
 */
void test_backwardCompatibility()
{
    // Test constructors
    auto source = C<double>();
    for (int i = 0; i < 5; ++i) source.setVec(i, i);

    // Test accessor and mutators for vector
    source.insert(5);
    source.insert(6);
    assert(21 == source.sumVector());
    source.print();
    auto& vec = source.getVec();

    // Test accessors and mutators for array
    for (int i = 0; i < 5; ++i) source.setArray(i, i);
    assert(10 == source.sumArray());
    auto& array = source.getArray();
}

int main()
{
    test_defaultedFunctions();
    test_deletedFunctions();
    test_sumArray();
    test_setAndSumArray();
    test_setAndSumVector();
    test_constExpr();
    test_backwardCompatibility();
    return 0;
}
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

    // Create the underlying data using uniform initialization
    for (int i = 0; i < 6; ++i)
    {
        myClass.insert(i);
    }

    // Log the data
    myClass.print();
}

/**
 * Question: What is the resulting behavior of a deleted function
 * Answer: Explicitly deleted functions cannot be used. Their use results in a compilation error.
 */
void test_deletedFunctions()
{
    auto myClass = C<int>();

    // Create the underlying data using uniform initialization
    for (int i = 0; i < 6; ++i)
    {
        myClass.insert(i);
    }

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

    // Create new array
    constexpr std::array<int, 5> array = {6, 7, 8, 9, 10};

    // Use array setter
    myClass.setArray(array);

    // Assert new sum equals 40
    assert(40 == myClass.sumArray());
}

/**
 * Test core logic of setting and summing data in a container
 */
void test_setAndSumVector()
{
    auto myClass = C<int>();

    // Create new vector
    std::vector<int> vector = {6, 7, 8, 9, 10};

    // Use array setter
    myClass.setVec(vector);

    // Assert new sum equals 40
    assert(40 == myClass.sumVector());
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

int main()
{
    test_defaultedFunctions();
    test_deletedFunctions();
    test_sumArray();
    test_setAndSumArray();
    test_setAndSumVector();
    test_constExpr();
    return 0;
}
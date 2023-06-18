//
// A simple test program to demonstrate move semantics
//
// Created by Michael Lewis on 5/31/23.
//

#include "C.hpp"

/**
 * Illustrate move assignment constructor.
 * Question: How can you ensure the move constructor is called instead of the copy constructor
 * Answer: You can pass the object in using std::move.
 */
void test_moveConstructor()
{
    // Initialize test object
    auto source = C<double>(5);
    for (int i = 0; i < 5; ++i) source.setVec(i, i);

    // Move constructor
    auto target = C<double>(std::move(source));
    assert(nullptr == source.getVec());
    assert(0 == target.getVec()->at(0));
    assert(1 == target.getVec()->at(1));
    assert(2 == target.getVec()->at(2));
    assert(3 == target.getVec()->at(3));
    assert(4 == target.getVec()->at(4));
}

/**
 * Illustrate move assignment operator.
 *
 * Question: What happens when you use an lvalue reference as the source of a move operation
 * Answer: This isn't possible unless you force lvalue binding to rvalue references using std::move()
 */
void test_moveAssignment()
{
    // Initialize test object
    auto source = C<double>(5);
    for (int i = 0; i < 5; ++i) source.setVec(i, i);

    auto target = C<double>(5);

    // Move assignment
    auto&& moveAssignment = target.operator=(std::move(source));
    assert(nullptr == source.getVec());
    assert(0 == target.getVec()->at(0));
    assert(1 == target.getVec()->at(1));
    assert(2 == target.getVec()->at(2));
    assert(3 == target.getVec()->at(3));
    assert(4 == target.getVec()->at(4));
}

/**
 * Utility test to ensure all functions from previous lectures continue to compile
 */
void test_backwardCompatibility()
{
    // Test constructors
    auto source = C<double>();
    auto copy = C<double>(source);
    auto&& move = C<double>(std::move(copy));

    // Test assignment operators
    auto copyAssignment = move.operator=(source);
    auto&& moveAssignment = move.operator=(std::move(source));
    for (int i = 0; i < 5; ++i) move.setVec(i, i);

    // Test accessor and mutators
    move.insert(5);
    move.insert(6);
    assert(21 == move.sumVector());
    move.print();
    auto& vec = move.getVec();

    // Test swaps
    std::vector<double> vec1 = {1, 2};
    std::vector<double> vec2 = {3, 4};
    move.swapCopyStyle(vec1, vec2);
    assert(1 == vec2.at(0));
    assert(2 == vec2.at(1));
    assert(3 == vec1.at(0));
    assert(4 == vec1.at(1));

    move.swapMoveStyle(std::move(vec1), std::move(vec2));
    assert(3 == vec2.at(0));
    assert(4 == vec2.at(1));
    assert(1 == vec1.at(0));
    assert(2 == vec1.at(1));
}

int main()
{
    test_moveConstructor();
    test_moveAssignment();
    test_backwardCompatibility();
    return 0;
}
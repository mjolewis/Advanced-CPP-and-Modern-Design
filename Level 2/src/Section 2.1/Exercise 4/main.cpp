//
// Illustrate simple use cases of supported operations on type traits
//
// Created by Michael Lewis on 6/19/23.
//

#include <iostream>
#include <type_traits>

#include "Shape.hpp"
#include "Point.hpp"

/**
 * Checks if the Point type has a virtual destructor.
 */
void test_hasVirtualDestructor()
{
    std::cout << std::boolalpha;  // Minor developer productivity optimization

    std::cout << "Does Point have a virtual destructor?" << std::has_virtual_destructor<Point>::value << std::endl;
}

/**
 * Checks if the Point has a default, copy, or move ctor
 */
void test_hasConstructorTypes()
{
    std::cout << std::boolalpha;  // Minor developer productivity optimization

    std::cout << "Does Point have a default ctor?" << std::is_default_constructible<Point>::value << std::endl;
    std::cout << "Does Point have a copy ctor?" << std::is_copy_constructible<Point>::value << std::endl;
    std::cout << "Does Point have a move ctor?" << std::is_move_assignable<Point>::value << std::endl;
}

/**
 * Checks if the Point is copy or move assignable
 */
void test_isCopyOrMoveAssignable()
{
    std::cout << std::boolalpha;  // Minor developer productivity optimization

    std::cout << "Is Point copy assignable?" << std::is_copy_assignable<Point>::value << std::endl;
    std::cout << "Is Point move assignable?" << std::is_move_assignable<Point>::value << std::endl;
}

/**
 * Note - To run this test, you must activate the deleted ctor and deleted copy assigment operator in Point.
 * The first parts of B and C require us to not delete these functions and, as a result, I have commented them out
 * for homework submission purposes.
 */
void test_deleted_CopyCtor_CopyAssignmentOperator()
{
    test_hasConstructorTypes();
    test_isCopyOrMoveAssignable();
}

void test_AddMoveCtor_And_MoveAssignmentOperator()
{
    // Note, this test doesn't actually perform anything. The purpose of this test was to add a move ctor and a
    // move assignment operator to determine if adding these explicit functions changed any behavior.
    // The answer is that we get different results when adding these functions explicitly.

    // The C++ standard has defined specific rules for when user defined special member functions are explicitly
    // declared. For example, explicitly declared move semantics disables copy semantics. Therefore, when you
    // explicitly declare move semantics, you should very likely also provide explicitly declarations for copy semantics

    // Note, to see this behavior in action, please uncomment move semantics in Point.hpp.
}

int main()
{
    test_hasVirtualDestructor();
    test_hasConstructorTypes();
    test_isCopyOrMoveAssignable();
    test_deleted_CopyCtor_CopyAssignmentOperator();
    return 0;
}
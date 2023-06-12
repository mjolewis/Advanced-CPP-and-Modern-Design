//
// Created by Michael Lewis on 6/11/23.
//

#include <cassert>

#include "Point.hpp"
#include "S.hpp"

/**
 * Demonstrate default initialization.
 *
 * Note - the x and y coordinate are initialized with indeterminate values
 */
void test_DefaultInitialization()
{
    Point point;
}

/**
 * Demonstrate default initialization.
 *
 * Note - the x and y coordinate are initialized with a zero value
 */
void test_ValueInitialization()
{
    Point point{};
    assert(0 == point.getXcoordinate());
    assert(0 == point.getYcoordinate());
}

/**
 * Demonstrate direct initialization with an overloaded constructor.
 */
void test_DirectInitialization()
{
    Point point{1, 2};
    assert(1 == point.getXcoordinate());
    assert(2 == point.getYcoordinate());
}

/**
 * Demonstrate direct initialization with an copy constructor.
 */
void test_CopyInitialization()
{
    Point pointOrig{1, 2};
    Point pointCopy{pointOrig};
    assert(1 == pointCopy.getXcoordinate());
    assert(2 == pointCopy.getYcoordinate());
}

/**
 * Demonstrate direct initialization by setting a point as an argument in a direct initialization
 */
void test_ListInitialization()
{
    Point point;
    point.setPoint(Point{1, 2});
    assert(1 == point.getXcoordinate());
    assert(2 == point.getYcoordinate());
}

/**
 * Aggregate initialization is a form of list initialization for arrays or class types
 * (often structs or unions)
 */
void test_AggregateInitialization()
{
    int array[3] = {1, 2, 3};
    assert(1 == array[0]);
    assert(2 == array[1]);
    assert(3 == array[2]);
}

/**
 * Demonstrate direct initialization with an copy constructor.
 *
 * Variables of reference type must be initialized with an object of
 * the type from which the reference type is derived,
 */
void test_ReferenceInitialization()
{
    Point pointOrig{1, 2};
    Point& pointRef = pointOrig;
    assert(1 == pointRef.getXcoordinate());
    assert(2 == pointRef.getYcoordinate());
}

/**
 * Test different initialization techniques in an attempt to find one that doesn't compile for Struct S
 */
void test_illFormedInitialization()
{
    S defaultInitialization; // compiles
    S directInitialization{}; // compiles
    S valueInitialization{1, {1, 2}}; // compiles
    S copyInitialization(valueInitialization); // compiles
    copyInitialization.b.i = 1; // compiles
    copyInitialization.b.j = 1; // compiles
//    copyInitialization.b.a = {1, 2, 3}; does not compile
    S listInitialization{1, {1, 2, {3, 4, 5}}}; // compiles
    S aggregateInitialization1{1, {1, 2, {3, 4, 5}}}; // compiles
    S& referenceInitialization = listInitialization; // compiles
}

int main()
{
    test_DefaultInitialization();
    test_ValueInitialization();
    test_DirectInitialization();
    test_CopyInitialization();
    test_ListInitialization();
    test_AggregateInitialization();
    test_ReferenceInitialization();
    test_illFormedInitialization();
    return 0;
}
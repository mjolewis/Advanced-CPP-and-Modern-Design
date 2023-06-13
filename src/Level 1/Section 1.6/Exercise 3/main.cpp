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
 * Demonstrate copy initialization with an copy constructor.
 */
void test_CopyInitialization()
{
    Point pointOrig{1, 2};
    Point pointCopy{pointOrig};
    assert(1 == pointCopy.getXcoordinate());
    assert(2 == pointCopy.getYcoordinate());
}

/**
 * Demonstrate list initialization by setting a point as an argument in a direct initialization
 */
void test_ListInitialization()
{
    Point point;
    point.setPoint(Point{1, 2});
    assert(1 == point.getXcoordinate());
    assert(2 == point.getYcoordinate());
}

/**
 * Aggregate initialization is a form of list initialization
 * for arrays or class types (often structs or unions)
 */
void test_AggregateInitialization()
{
    S aggregateInitialization{1, {2, 3, {4, 5, 6}}};
    assert(1 == aggregateInitialization.x);
    assert(2 == aggregateInitialization.b.i);
    assert(3 == aggregateInitialization.b.j);
    assert(4 == aggregateInitialization.b.a[0]);
    assert(5 == aggregateInitialization.b.a[1]);
    assert(6 == aggregateInitialization.b.a[2]);
}

/**
 * Demonstrate reference initialization.
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
 * Test different initialization techniques in an attempt to find one that doesn't compile.
 *
 * @Avi - I interpreted this exercise as an open ended type of question where I could simply find
 * a way to make any class initialization not compile. As a result, the test below can't compile
 * because the move ctor has been explicitly deleted.
 */
void test_illFormedInitialization()
{
//    auto&& point1 = Point{1, 2};
//    Point point2{std::move(point1)};
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
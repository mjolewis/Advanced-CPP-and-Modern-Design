//
// Test Shapes and their inheritance hierarchy. Note, Shape is pure virtual, so this class is only tested
// via it's derived classes.
//
// Created by Michael Lewis on 8/4/23.
//

#include <cassert>
#include <iostream>

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

// Create a default point and validate via the polymorphic print function and overloaded ostream operator
void test_defaultPoint()
{
    std::cout << "Default Point" << std::endl;
    Point p1{};
    p1.print();
    std::cout << p1 << std::endl;
}

// Create a custom point and validate via the polymorphic print function and overloaded ostream operator
void test_customPoint()
{
    std::cout << "Overloaded Point" << std::endl;
    Point p1{1, 2};
    p1.print();
    std::cout << p1 << std::endl;
}

// Create a copy of a point and validate via the polymorphic print function and overloaded ostream operator
void test_copyPoint()
{
    std::cout << "Copy Point" << std::endl;
    Point p1{1, 2};
    Point p2{p1};
    p1.print();
    p2.print();
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
}

// Assign a point and validate via the polymorphic print function and overloaded ostream operator
void test_assignPoint()
{
    std::cout << "Assign Point" << std::endl;
    Point p1{1, 2};
    Point p2 = p1;
    p1.print();
    p2.print();
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
}

// Modify a point and validate via the polymorphic print function and overloaded ostream operator
void test_modifyPoint()
{
    std::cout << "Modify Point" << std::endl;
    Point p1{1, 2};
    p1.X(3);
    p1.Y(4);
    p1.print();
    std::cout << p1 << std::endl;
}

// Create a default line and validate via the polymorphic print function and overloaded ostream operator
void test_defaultLine()
{
    std::cout << "Default Line" << std::endl;
    Line l1{};
    l1.print();
    std::cout << l1 << std::endl;
}

// Create a custom line and validate via the polymorphic print function and overloaded ostream operator
void test_customLine()
{
    std::cout << "Overloaded Line" << std::endl;
    Point p1{1, 2};
    Point p2{3, 4};
    Line l1{p1, p2};
    l1.print();
    std::cout << l1 << std::endl;
}

// Create a copy of a line and validate via the polymorphic print function and overloaded ostream operator
void test_copyLine()
{
    std::cout << "Copy Line" << std::endl;
    Point p1{1, 2};
    Point p2{3, 4};
    Line l1{p1, p2};
    Line l2{l1};
    l1.print();
    l2.print();
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
}

// Assign a line and validate via the polymorphic print function and overloaded ostream operator
void test_assignLine()
{
    std::cout << "Assign Line" << std::endl;
    Point p1{1, 2};
    Point p2 = p1;
    Line l1{p1, p2};
    Line l2 = l1;
    l1.print();
    l2.print();
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
}

// Modify a line and validate via the polymorphic print function and overloaded ostream operator
void test_modifyLine()
{
    std::cout << "Modify Point" << std::endl;
    Line l1{};
    Point p1{1, 2};
    Point p2{3, 4};
    l1.p1(p1);
    l1.p2(p2);
    l1.print();
    std::cout << l1 << std::endl;
}

// Create a default circle and validate via the polymorphic print function and overloaded ostream operator
void test_defaultCircle()
{
    std::cout << "Default Circle" << std::endl;
    Circle c;
    c.print();
    std::cout << c << std::endl;
}

// Create a custom circle and validate via the polymorphic print function and overloaded ostream operator
void test_customCircle()
{
    std::cout << "Overloaded Circle" << std::endl;
    Point p1{1, 2};
    Circle c{p1, 4};
    c.print();
    std::cout << c << std::endl;
}

// Create a copy of a circle and validate via the polymorphic print function and overloaded ostream operator
void test_copyCircle()
{
    std::cout << "Copy Circle" << std::endl;
    Point p1{1, 2};
    Circle c1{p1, 4};
    Circle c2{c1};
    c1.print();
    c2.print();
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
}

// Assign a circle and validate via the polymorphic print function and overloaded ostream operator
void test_assignCircle()
{
    std::cout << "Assign Circle" << std::endl;
    Point p1{1, 2};
    Circle c1{p1, 4};
    Circle c2 = c1;
    c1.print();
    c2.print();
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
}

// Modify a circle and validate via the polymorphic print function and overloaded ostream operator
void test_modifyCircle()
{
    std::cout << "Modify Circle" << std::endl;
    Point p1{1, 2};
    Circle c1{p1, 4};
    Point p2{3, 4};
    c1.CenterPoint(p2);
    c1.Radius(5);
    c1.print();
    std::cout << c1 << std::endl;
}

int main()
{
    test_defaultPoint();
    test_customPoint();
    test_copyPoint();
    test_assignPoint();
    test_modifyPoint();

    test_defaultLine();
    test_customLine();
    test_copyLine();
    test_assignLine();
    test_modifyLine();

    test_defaultCircle();
    test_customCircle();
    test_copyCircle();
    test_assignCircle();
    test_modifyCircle();

    return 0;
}

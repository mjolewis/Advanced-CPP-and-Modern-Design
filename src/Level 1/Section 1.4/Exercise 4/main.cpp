//
// Created by Michael Lewis on 6/3/23.
//

#include <iostream>

#include "Circle.hpp"
#include "Shape.hpp"

/**
 * Tests the rotate function using function wrappers as arguments to the base class
 */
void test_shapeRotate_lambda()
{
    Shape<double> shape([] (double value) -> void { std::cout << "Shape::rotate=" << value << std::endl; });
    shape.rotate(2);
}

void test_circleRotate_lambda()
{
    Circle<int> circle([] (int value) -> void { std::cout << "Circle::rotate=" << value << std::endl; });
    circle.rotate(4);
}

int main()
{
    test_shapeRotate_lambda();
    test_circleRotate_lambda();
    return 0;
}
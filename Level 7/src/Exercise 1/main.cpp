//
// Simplifies the Factory Pattern interface by returning a tuple of shapes.
// Maintains flexibility by allowing a client to specify the parameters of shapes.
//
// Created by Michael Lewis on 8/19/23.
//

#include <iostream>
#include <tuple>

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "ConsoleShapeFactory.hpp"

int main()
{
    ConsoleShapeFactory factory;
    Circle circle;
    Line line;
    Point point;
    std::tie(circle, line, point) = factory.createShapes();

    std::cout << "Circle: " << circle << std::endl;
    std::cout << "Line: " << line << std::endl;
    std::cout << "Point: " << point << std::endl;

    /*
     * Part C
     * Compare the GOF solution with the new solution. For example, how much effort
     * is needed with both design if we wish to a new product (for example, a
     * class that models rectangles)?
     *
     * Response:
     * The redesigned interface is much simpler particularly as the number of objects
     * increases. For example, we may have a scenario where there are 50 shapes and
     * the interface explodes. However, you may also end up creating objects that
     * you don't need. We might create 50 shapes, but only need 1 of them, so there
     * is a trade-off in terms of performance.
     */

    return 0;
}
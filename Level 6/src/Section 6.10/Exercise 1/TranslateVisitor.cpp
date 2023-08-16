//
// Created by Michael Lewis on 8/15/23.
//

#include "TranslateVisitor.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "ShapeComposite.hpp"

/**
 * Overloaded ctor whose distance argument will be used to translate the incoming shape visitors
 * @param distance The distance as an offset for the points in a given shape
 */
TranslateVisitor::TranslateVisitor(const int distance) : ShapeVisitor(), distance{distance}
{

}

/**
 * Sends the specified object to the console out object
 * @param circle The object to be printed
 */
void TranslateVisitor::visit(Circle &circle)
{
    Point centerPoint = circle.CenterPoint();
    double x = centerPoint.X() + distance;
    double y = centerPoint.Y() + distance;
    Point newCenterPoint = Point{x, y};
    circle.CenterPoint(newCenterPoint);
}

/**
 * Sends the specified object to the console out object
 * @param point The object to be printed
 */
void TranslateVisitor::visit(Line &line)
{
    Point startX = line.p1();
    Point startY = line.p1();
    Point newStart = Point{startX.X() + distance, startY.Y() + distance};

    Point endX = line.p2();
    Point endY = line.p2();
    Point newEnd = Point{endX.X() + distance, endY.Y() + distance};

    line.p1(newStart);
    line.p2(newEnd);
}

/**
 * Sends the specified object to the console out object
 * @param point The object to be printed
 */
void TranslateVisitor::visit(Point &point)
{
    point.X(point.X() + distance);
    point.Y(point.Y() + distance);
}

/**
 * Sends the specified object to the console out object
 * @param shapeComposite The object to be printed
 * @note Function is silent. The composite acceptor dispatches individual shapes to their respective
 * acceptors, which subsequently dispatch to the object to the correct visit
 */
void TranslateVisitor::visit(ShapeComposite &shapeComposite)
{
    // silent
}

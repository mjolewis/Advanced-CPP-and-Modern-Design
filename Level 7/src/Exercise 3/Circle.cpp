//
// A derived Shape object that represents a Circle with a center point and a radius
//
// Created by Michael Lewis on 8/4/23.
//

#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>

#include "Circle.hpp"
#include "Point.hpp"

/**
 * Default ctor
 */
Circle::Circle() : Shape(), center(), radius{0}
{

}

/**
 * Overloaded ctor
 * @param c An instance of Point that will be come the center Point of this Circle
 * @param r The radius of this Circle
 */
Circle::Circle(const Point &pt, double r) : Shape(), center(pt), radius{r}
{

}

/**
 * Copy ctor
 * @param c The source Circle whose data members will be deeply copied into this Circle
 */
Circle::Circle(const Circle & c) : Shape(), center(c.center), radius{c.radius}
{
    // Delegate to Point
}

/**
 * Assignment operator that deeply copies the data members of the source Circle into this Circle.
 * @param pt
 * @return
 */
Circle &Circle::operator=(const Circle &c)
{
    // Avoid self assignment
    if (this == &c) return *this;

    center = c.center;   // Delegate to the Point assignment operator
    radius = c.radius;

    return *this;
}

/**
 * Mutator that sets the center Point of this Circle
 * @param _center The new center Point of this Circle
 */
void Circle::CenterPoint(const Point& _center)
{
    center = _center;
}

/**
 * Accessor for this Circles center Point
 * @return This Circles center Point
 */
Point Circle::CenterPoint()
{
    return center;
}

/**
 * Mutator that sets the radius of this Circle
 * @param _radius The radius of this Circle
 */
void Circle::Radius(double _radius)
{
    radius = _radius;
}

/**
 * Accessor for this Circles radius
 * @return This Circles radius
 */
double Circle::Radius() const
{
   return radius;
}

/**
 * Create a string representation of this Circle.
 */
void Circle::print() const
{
    std::stringstream radiusStream;
    radiusStream << radius;

    std::cout << "\nCircle: Center ";
    center.print();
    std::cout << ", Radius: " + radiusStream.str();
}

// ******************** Friend Functions ********************

/**
 * Send a Circle directly to the ostream object.
 * @param ostream The std::ostream object that receives the Circle.
 * @param circle The Circle to send to the ostream.
 * @return An ostream representation of the specified Circle.
 */
std::ostream& operator<<(std::ostream& ostream, const Circle& circle)
{
    ostream << "Circle:" << circle.center << ", radius=" << circle.radius;
    return ostream;
}
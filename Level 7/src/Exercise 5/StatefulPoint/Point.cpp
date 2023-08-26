//
// A derived Shape object that represents a single Point with x and y coordinates
//
// Created by Michael Lewis on 8/4/23.
//

#include <cmath>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>

#include "Point.hpp"

using StrategyFunction = std::function<double (const Point& p1, const Point& p2)>;

// ********** Static Data Initialization **********
std::shared_ptr<StrategyFunction> Point::distanceStrategy{};

/**
 * Default ctor
 */
Point::Point() : Shape(), x{0}, y{0}
{

}

/**
 * Overloaded ctor that provides initial values for this Points x and y coordinates
 * @param xs The x coordinate of the new Point
 * @param ys The y coordinate of the new Point
 */
Point::Point(double xs, double ys) : Shape(), x{xs}, y{ys}
{

}

/**
 * Copy ctor
 * @param pt The source Point whose data members will be deeply copied into this Point
 */
Point::Point(const Point &pt) : Shape(), x{pt.x}, y{pt.y}
{

}

/**
 * Copy assignment that will deeply copy the data members of the source Point into this Point
 * @param pt A source Point whose data members will be deeply copied into this Point
 * @return This Point whose data members have been assigned values from the source Point
 */
Point &Point::operator=(const Point &pt)
{
    // Avoid self assignment
    if (this == &pt) return *this;

    x = pt.x;
    y = pt.y;

    return *this;
}

/**
 * Returns the value of this Points x coordinate
 * @return The current value of this Points x coordinate
 */
double Point::X() const
{
    return x;
}

/**
 * Returns the value of this Points y coordinate
 * @return The current value of this Points y coordinate
 */
double Point::Y() const
{
    return y;
}

/**
 * Provides a new value for this Points x coordinate
 * @param ys The new value of this Points x coordinate
 */
void Point::X(double xs)
{
    x = xs;
}

/**
 * Provides a new value for this Points y coordinate
 * @param ys The new value of this Points y coordinate
 */
void Point::Y(double ys)
{
    y = ys;
}

/**
 * Calculate and return the distance between the X and Y coordinates of this Point and the X and Y coordinates
 * contained within the Point passed as an argument.
 * @note This uses the Strategy Pattern, which delegates the distance calculation to a specific DistanceStrategy
 */
double Point::distance(const Point &p) const
{
    ++DistanceStrategy::counter;
    return Point::distanceStrategy.get()->operator()(*this, p);
}

/**
 * Create a string representation of this Point.
 */
void Point::print() const
{
    std::stringstream xCoordinateStream;
    std::stringstream yCoordinateStream;

    xCoordinateStream << x;
    yCoordinateStream << y;

    std::cout << "Point(" + xCoordinateStream.str() + "," +  yCoordinateStream.str() + ")";
}

/**
 * Implements the Prototype pattern by creating a deep clone of this Point
 * @return A deep clone of this Point wrapped in a Shared Pointer
 */
std::shared_ptr<Shape> Point::clone() const
{
    return std::make_shared<Point>(*this);
}

// ******************** Friend Functions ********************

/**
 * Send a Point directly to the ostream object.
 * @param ostream The std::ostream object that receives the Point.
 * @param point The Point to send to the ostream.
 * @return An ostream that represents the specified Point.
 */
std::ostream& operator<<(std::ostream& ostream, const Point& point)
{
    ostream << "Point(" << point.x << "," << point.y << ")";
    return ostream;
}

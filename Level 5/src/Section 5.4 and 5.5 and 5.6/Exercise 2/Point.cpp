//
// Simple point class to help illustrate use cases of hash_value functions
//
// Created by Michael Lewis on 7/15/23.
//

#include <cmath>
#include <cstddef>
#include <ostream>

#include <boost/functional/hash.hpp>

#include "Point.hpp"

/**
 * Overloaded ctor to set the coordinates of this point
 * @param xCoordinate The x-coordinate of this point
 * @param yCoordinate The y-coordinate of this point
 */
Point::Point(const double &xCoordinate, const double &yCoordinate) : xCoordinate{xCoordinate}, yCoordinate{yCoordinate}
{

}

/**
 * Comparator for this point and another point. This comparator will use the x-coordinate to determine
 * if this point is less than another point
 * @param other The point to compare against
 * @return True if this points x coordinate is less than the other points x coordinate.
 */
bool Point::operator<(const Point &other) const
{
    return xCoordinate < other.xCoordinate;
}

/**
 *
 * Calculates the distance between this point and another point
 * @param other The other point
 * @return The distance between this point and another point
 */
double Point::distance(const Point &other) const
{
    double xDistance = pow(other.xCoordinate - xCoordinate, 2);
    double yDistance = pow(other.yCoordinate - yCoordinate, 2);
    return sqrt(xDistance + yDistance);
}

/**
 * Mutates the value of the x-coordinate
 * @param x The new value of this points x coordinate
 */
void Point::X(const double &x)
{
    xCoordinate = x;
}

/**
 * Mutates the value of the y-coordinate
 * @param x The new value of this points y coordinate
 */
void Point::Y(const double& y)
{
    yCoordinate = y;
}

/**
 * Accessor for this points x-coordinate
 * @return The value of this points x-coordinate
 */
double Point::X() const noexcept
{
    return xCoordinate;
}

/**
 * Accessor for this points y-coordinate
 * @return The value of this points y-coordinate
 */
double Point::Y() const noexcept
{
    return yCoordinate;
}

// ********** Friend Functions **********

/**
 * Determines if two points are equal by comparing the x and y coordinates
 * @param p1 A Point
 * @param p2 Another Point
 * @return True if the two Points have the same x and y coordinates
 */
bool equal(const Point& p1, const Point& p2)
{
    return ((p1.xCoordinate == p2.xCoordinate) && (p1.yCoordinate == p2.yCoordinate));
}

/**
 * Injects a into the console output stream
 * @param ostream Console output stream
 * @param point A Point that will be written to the console
 * @return AN output stream with a Point put into it
 */
std::ostream& operator<<(std::ostream& ostream, const Point& point)
{
    ostream << "(" << point.xCoordinate << ", " << point.yCoordinate << ")";
    return ostream;
}

/**
 * Calculates the hash_value of two points using the X and Y coordinates of both
 * @param point A Point whose coordinates will be used to determine the hash_value
 * @return A std::size_t representing the hash_value of the specified point
 */
std::size_t hash_value(const Point& point)
{
    std::size_t seed = 0;
    boost::hash_combine(seed, point.X());
    boost::hash_combine(seed, point.Y());
    return seed;
}

/**
 * Calculates the hash_value of two points using the X and Y coordinates of both
 * @param lhs A Point whose coordinates will be used to determine the hash_value
 * @param rhs A Point whose coordinates will be used to determine the hash_value
 * @return A std::size_t representing the hash_value of two points
 */
std::size_t hash_value(const Point& lhs, const Point& rhs)
{
    std::size_t seed = 0;
    boost::hash_combine(seed, lhs.X());
    boost::hash_combine(seed, lhs.Y());
    boost::hash_combine(seed, rhs.X());
    boost::hash_combine(seed, rhs.Y());
    return seed;
}
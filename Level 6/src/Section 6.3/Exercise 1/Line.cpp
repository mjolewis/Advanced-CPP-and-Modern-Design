//
// A derived Shape object that represents a Line with a start and end Point
//
// Created by Michael Lewis on 8/4/23.
//

#include <iostream>
#include <ostream>
#include <sstream>

#include "Line.hpp"
#include "Point.hpp"

/**
 * Default ctor
 */
Line::Line() : Shape(), start(), end()
{

}

/**
 * Overloaded ctor that provides initial values for this Line start and end points
 * @param pt1s The new start Point for this Line
 * @param pt2s The new end Point for this Line
 */
Line::Line(const Point &pt1s, const Point &pt2s) : Shape(), start(pt1s), end(pt2s)
{
    // Delegate to Point
}

/**
 * Copy ctor
 * @param pt The source Line whose data members will be deeply copied into this Line
 */
Line::Line(const Line &line) : Shape(), start(line.start), end(line.end)
{
    // Delegate to Point
}

/**
 * Assignment operator that will deeply copy the data members of the source Line into this Line
 * @param pt The source Line whose data members will be deeply copied into this Line
 * @return This Line whose data members have been assigned new values provided by the source Line
 */
Line& Line::operator=(const Line &pt)
{
    // Avoid self assignment
    if (this == &pt) return *this;

    // Delegate assignment to Point
    start = pt.start;
    end = pt.end;

    return *this;
}

/**
 * Returns the start Point of this Line
 * @return The start Point of this Line
 */
Point Line::p1() const
{
    return start;
}

/**
 * Returns the end Point of this Line
 * @return The end Point of this Line
 */
Point Line::p2() const
{
    return end;
}

/**
 * Mutator that provides new x and y coordinates for this Lines start Point
 * @param ps A Point that provides new values for this Lines start Point x and y coordinates
 */
void Line::p1(const Point &ps)
{
    // Delegate to Point
    start = ps;
}

/**
 * Mutator that provides new x and y coordinates for this Lines end Point
 * @param ps A Point that provides new values for this Lines end Point x and y coordinates
 */
void Line::p2(const Point &ps)
{
    // Delegate to Point
    end = ps;
}

/**
 * Calculates and returns the length of this Line.
 * @return The length of this Line.
 */
double Line::length() const
{
    // Delegate the line length calculation to the Point class
    return start.distance(end);
}

/**
 * Create a string representation of this Line and return it.
 * @note This function delegates the string creation of it's Point objects to the Point class.
 */
void Line::print() const
{
    std::cout << "\nLine: Start ";
    start.print();
    std::cout << " and End ";
    end.print();
}

// ******************** Friend Functions ********************

/**
 * Send a Line directly to the ostream object.
 * @param ostream The std::ostream object that receives the Line.
 * @param line The Line to send to the ostream.
 * @return A description of this Line containing the start point, end point.
 */
std::ostream& operator<<(std::ostream& ostream, const Line& line)
{
    ostream << line.start << ", " << line.end;
    return ostream;
}
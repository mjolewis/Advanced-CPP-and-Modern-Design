//
// A derived Shape object that represents a single Point with x and y coordinates
//
// Created by Michael Lewis on 8/4/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include <ostream>
#include <string>

#include "Shape.hpp"

class Point : public Shape
{
private:
    double x;
    double y;

public:
    Point();
    Point(double xs, double ys);  // Constructor with coordinates
    Point(const Point& pt);  // Copy constructor
    ~Point() override = default;

    // Operator overloads
    Point& operator=(const Point& pt);  // Assignment operator

    // Accessor and Mutators
    double X() const;  // Return x coordinate
    double Y() const;  // Return y coordinate
    void X(double xs);  // Set x coordinate
    void Y(double ys);  // Set y coordinate

    // Calculates the distance between two points.
    double distance() const;
    double distance(const Point& p) const;

    // Overridden Functions
    std::string toString() const override;

    // Friends
    friend std::ostream& operator<<(std::ostream& ostream, const Point& point);
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

//
// A derived Shape object that represents a single Point with x and y coordinates
//
// Created by Michael Lewis on 8/4/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include <functional>
#include <memory>
#include <ostream>
#include <string>

#include "Shape.hpp"
#include "DistanceStrategy.hpp"

// Forward Declaration
class DistanceStrategy;

class Point : public Shape
{
private:
    friend class DistanceStrategy;

    using StrategyFunction = std::function<double (const Point& p1, const Point& p2)>;
    static std::shared_ptr<StrategyFunction> distanceStrategy;

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
    double X() const;   // Return x coordinate
    double Y() const;   // Return y coordinate
    void X(double xs);  // Set x coordinate
    void Y(double ys);  // Set y coordinate

    // Distance Between Points
    double distance(const Point& p) const;

    // Overridden Functions
    void print() const override;
    std::shared_ptr<Shape> clone() const override;

    // Friends
    friend std::ostream& operator<<(std::ostream& ostream, const Point& point);
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

//
// A derived Shape object that represents a Circle with a center point and a radius
//
// Created by Michael Lewis on 8/4/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP

#include <memory>
#include <ostream>

#include "Shape.hpp"
#include "Line.hpp"

class Circle : public Shape
{
private:
    Point center;
    double radius;

public:
    Circle();  // Default constructor
    Circle(const Point& pt, double r);  // Constructor point and radius
    Circle (const Circle & c);  // Copy constructor
    ~Circle() override = default;

    // Operator overloads
    Circle & operator=(const Circle & c);  // Assignment operator

    // Accessors and Mutators
    Point CenterPoint();  // Return center point
    double Radius() const;  // Return radius
    void CenterPoint(const Point& center);  // Set center point
    void Radius(double _radius);  // Set radius

    // Overridden Functions
    void print() const override;
    std::shared_ptr<Shape> clone() const override;

    // Friend Functions
    friend std::ostream& operator<<(std::ostream& ostream, const Circle& circle);
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CIRCLE_HPP

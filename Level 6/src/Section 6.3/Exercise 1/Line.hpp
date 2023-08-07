//
// A derived Shape object that represents a Line with a start and end Point
//
// Created by Michael Lewis on 8/4/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP

#include "Shape.hpp"
#include "Point.hpp"

class Line : public Shape
{
private:
    Point start;
    Point end;

public:
    Line();  // Default constructor
    Line(const Point& pt1s, const Point& pt2s);  // Constructor with points
    Line (const Line & pt);  // Copy constructor
    ~Line() override = default;

    // Operator overloads
    Line & operator=(const Line & pt);  // Assignment operator

    // Accessors and Mutators
    Point p1() const;  // Return point 1
    Point p2() const;  // Return point 2
    void p1(const Point& ps);  // Set point 1
    void p2(const Point& ps);  // Set point 2

    // Returns the length of a line
    double length() const;

    void print() const override;

    // Friends
    friend std::ostream& operator<<(std::ostream& ostream, const Line& line);
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_LINE_HPP

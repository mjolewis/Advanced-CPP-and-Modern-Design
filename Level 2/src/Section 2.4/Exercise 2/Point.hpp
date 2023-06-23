//
// User defined Point to illustrate the functionality of shared_ptr
//
// Created by Michael Lewis on 6/22/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include <iostream>
#include <memory>
#include <utility>

class Point
{
private:
    std::shared_ptr<Point> p;
    double xCoordinate{};
    double yCoordinate{};
public:
    Point() = default;
    Point(const Point& source) = default;
    explicit Point(std::shared_ptr<Point> point) : p(std::move(point)) {};
    Point(const double& xCoordinate, const double& yCoordinate) : xCoordinate{xCoordinate}, yCoordinate{yCoordinate} {}
    ~Point() { std::cout << "Point destroyed" << std::endl; }

    void print() const { std::cout <<"Point(" << p->xCoordinate << ", " << p->yCoordinate << ")" << std::endl ; }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include <utility>

/**
 * A simple Point object used to demonstrate different types of initialization
 */
class Point
{
private:
    int xCoordinate;
    int yCoordinate;

public:
    constexpr Point() = default;
    explicit Point(int x, int y) : xCoordinate{x}, yCoordinate{y} {};
    Point(const Point& source) : xCoordinate{source.xCoordinate}, yCoordinate{source.yCoordinate} {};
    Point(Point&& source) = delete;
    virtual ~Point() = default;

    int getXcoordinate() const noexcept { return xCoordinate; }
    int getYcoordinate() const noexcept { return yCoordinate; }

    void setPoint(const Point& source) { xCoordinate = source.xCoordinate; yCoordinate = source.yCoordinate; };
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

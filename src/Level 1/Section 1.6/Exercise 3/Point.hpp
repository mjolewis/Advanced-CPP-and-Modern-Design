//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

#include <utility>

class Point
{
private:
    int xCoordinate;
    int yCoordinate;

public:
    constexpr Point() = default;
    explicit Point(int x, int y) : xCoordinate{x}, yCoordinate{y} {};
    Point(const Point& source) : xCoordinate{source.xCoordinate}, yCoordinate{source.yCoordinate} {};
    Point(Point&& source)  noexcept : xCoordinate{std::move(source.xCoordinate)}, yCoordinate{std::move(source.yCoordinate)} {};
    virtual ~Point() = default;

    int getXcoordinate() noexcept { return xCoordinate; }
    int getYcoordinate() noexcept { return yCoordinate; }

    void setPoint(const Point& source) {};
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINT_HPP

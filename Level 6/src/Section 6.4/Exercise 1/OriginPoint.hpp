//
// OriginPoint is a class that derives from Singleton<Point>. It is used to illustrate the singleton pattern.
//
// Created by Michael Lewis on 8/7/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_ORIGINPOINT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_ORIGINPOINT_HPP

#include "Singleton.hpp"
#include "Point.hpp"

class OriginPoint : public Singleton<Point>
{
public:
    OriginPoint() = default;
    OriginPoint(const OriginPoint & source) = delete;    // copy constructor
    ~OriginPoint() = default;

    // Assignment operator
    OriginPoint & operator = (const OriginPoint& source) = delete;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_ORIGINPOINT_HPP

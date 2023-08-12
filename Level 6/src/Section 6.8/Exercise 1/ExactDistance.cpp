//
// A distance strategy object that calculates exact distance using Phytagoras distance
//
// Note - This Strategy is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/10/23.
//

#include <cmath>

#include "Point.hpp"
#include "ExactDistance.hpp"
#include "DistanceStrategy.hpp"

/**
 * Default ctor
 */
ExactDistance::ExactDistance() : DistanceStrategy()
{

}

/**
 * Calculate and returns the exact distance between two Points using Phytagoras distance
 * @param p1 A point on the line
 * @param p2 A point on the line
 * @return The exact distance between two Points.
 */
double ExactDistance::distance(const Point &p1, const Point &p2)
{
    return std::sqrt(std::pow(p2.X() - p1.X(), 2) + std::pow(p2.Y() - p1.Y(), 2));
}
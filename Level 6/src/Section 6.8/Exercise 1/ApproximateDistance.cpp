//
// A distance strategy object that calculates approximate distance using the fast, but less accurate,
// taxicab distance formula
//
// Note - This Strategy is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/10/23.
//

#include <cmath>

#include "Point.hpp"
#include "ApproximateDistance.hpp"
#include "DistanceStrategy.hpp"

/**
 * Default ctor
 */
ApproximateDistance::ApproximateDistance() : DistanceStrategy()
{

}

/**
 * Calculate and return an approximate distance between two Points using the fast,
 * but less accurate, taxicab distance formula
 * @param p1 A point on the line
 * @param p2 A point on the line
 * @return The exact distance between two Points.
 */
double ApproximateDistance::distance(const Point &p1, const Point &p2)
{
    return std::abs(p2.X() - p1.X()) + std::abs(p2.Y() - p1.Y());
}

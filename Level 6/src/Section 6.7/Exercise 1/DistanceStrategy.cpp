//
// A base strategy pattern class that will be used by derived classes to implement different
// techniques for calculating the distance between two points.
//
// Note - This class is abstract, so copy and move ctors have been deleted and copy and move assignment
// has also been deleted
//
// Created by Michael Lewis on 8/10/23.
//

#include <functional>
#include <memory>

#include "Point.hpp"
#include "DistanceStrategy.hpp"

/**
 * Sets the concrete Strategy that determines how the distance between two points will be calculated
 * @param strategy A shared pointer wrapping a concrete Strategy that determines how the distance
 * between two points is calculated
 */
void DistanceStrategy::setStrategy(const std::shared_ptr<DistanceStrategy>& strategy)
{
    Point::distanceStrategy = strategy;
}



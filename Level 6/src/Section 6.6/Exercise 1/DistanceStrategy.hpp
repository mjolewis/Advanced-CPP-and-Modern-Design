//
// A base strategy pattern class that will be used by derived classes to implement different
// techniques for calculating the distance between two points.
//
// Note - This class is abstract, so copy and move ctors have been deleted and copy and move assingment
// has also been deleted
//
// Created by Michael Lewis on 8/10/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DISTANCESTRATEGY_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_DISTANCESTRATEGY_HPP

#include <string>

// Forward Declarations
class Point;

class DistanceStrategy
{
private:

public:
    DistanceStrategy() = default;
    DistanceStrategy(const DistanceStrategy& other) = delete;
    DistanceStrategy(DistanceStrategy&& other) = delete;
    virtual ~DistanceStrategy() = default;

    // Operator Overloads
    DistanceStrategy& operator=(const DistanceStrategy& other) = delete;
    DistanceStrategy& operator=(DistanceStrategy&& other) = delete;

    virtual double distance(const Point& p1, const Point& p2) = 0;

    static void setStrategy(const std::shared_ptr<DistanceStrategy>& distanceStrategy);
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DISTANCESTRATEGY_HPP

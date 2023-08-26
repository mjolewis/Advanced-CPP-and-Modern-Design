//
// Modern C++ Strategy Pattern
//
// Uses universal function wrappers instead of traditional inheritance associated with GOF Strategy Pattern.
// This modern technique reduces boilerplate code as well as having a large number of small Strategy classes
// that only vary in some small component of the algorithm.
//
// Created by Michael Lewis on 8/24/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DISTANCESTRATEGY_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_DISTANCESTRATEGY_HPP

#include <functional>
#include <memory>

// Forward Declarations
class Point;

// Alias
using StrategyFunction = std::function<double (const Point& p1, const Point& p2)>;

class DistanceStrategy
{
private:
    friend class Point;  // Point is my friend so it can access my counter

    static int counter;

    StrategyFunction strategyFunction;

public:
    DistanceStrategy();
    DistanceStrategy(const DistanceStrategy& other) = delete;
    DistanceStrategy(DistanceStrategy&& other) = delete;
    virtual ~DistanceStrategy() = default;

    static void setStrategy(const std::shared_ptr<StrategyFunction>& strategy);
    static int getCounter();
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DISTANCESTRATEGY_HPP

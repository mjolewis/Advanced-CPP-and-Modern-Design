//
// Modern C++ Strategy Pattern
//
// Uses universal function wrappers instead of traditional inheritance associated with GOF Strategy Pattern.
// This modern technique reduces boilerplate code as well as having a large number of small Strategy classes
// that only vary in some small component of the algorithm.
//
// Created by Michael Lewis on 8/24/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DistanceStrategy_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_DistanceStrategy_HPP

#include <functional>

// Forward Declarations
class Point;

// Alias
using StrategyFunction = std::function<double (const Point& p1, const Point& p2)>;

class DistanceStrategy
{
private:
    static int counter;

    StrategyFunction strategyFunction;

public:
    DistanceStrategy();
    DistanceStrategy(const StrategyFunction& strategy);
    DistanceStrategy(const DistanceStrategy& other);
    DistanceStrategy(DistanceStrategy&& other);
    virtual ~DistanceStrategy() = default;

    double execute(const Point& p1, const Point& p2) const;
    void setStrategy(const StrategyFunction& strategy);

    static int getCounter();
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DistanceStrategy_HPP

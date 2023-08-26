//
// Modern C++ Strategy Pattern
//
// Uses universal function wrappers instead of traditional inheritance associated with GOF Strategy Pattern.
// This modern technique reduces boilerplate code as well as having a large number of small Strategy classes
// that only vary in some small component of the algorithm.
//
// Created by Michael Lewis on 8/24/23.
//

#include "DistanceStrategy.hpp"
#include "Point.hpp"

/**
 * Default ctor
 */
DistanceStrategy::DistanceStrategy() : strategyFunction{}
{

}

/**
 * Setter that allows clients to update the Strategy logic
 * @note The Strategy is statically set onto the Point
 * @param strategy A universal function wrapper that contains a new Strategy
 */
void DistanceStrategy::setStrategy(const std::shared_ptr<StrategyFunction> &strategy)
{
    Point::distanceStrategy = strategy;
}

// ********** Static Data **********
int DistanceStrategy::counter{};

int DistanceStrategy::getCounter()
{
    return DistanceStrategy::counter;
}

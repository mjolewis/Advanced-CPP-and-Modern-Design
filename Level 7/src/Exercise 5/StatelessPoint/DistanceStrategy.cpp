//
// Modern C++ Strategy Pattern
//
// Uses universal function wrappers instead of traditional inheritance associated with GOF Strategy Pattern.
// This modern technique reduces boilerplate code as well as having a large number of small Strategy classes
// that only vary in some small component of the algorithm.
//
// Created by Michael Lewis on 8/24/23.
//

#include <future>

#include "DistanceStrategy.hpp"
#include "Point.hpp"

/**
 * Default ctor
 */
DistanceStrategy::DistanceStrategy() : strategyFunction{}
{

}

/**
 * Overloaded ctor
 * @param strategy The specific Strategy
 */
DistanceStrategy::DistanceStrategy(const StrategyFunction &strategy) : strategyFunction{strategy}
{

}

/**
 * Copy ctor
 * @param strategy The specific Strategy
 */
DistanceStrategy::DistanceStrategy(const DistanceStrategy& other)
:  strategyFunction{other.strategyFunction}
{

}

/**
 * Move ctor
 * @param strategy The specific Strategy
 */
DistanceStrategy::DistanceStrategy(DistanceStrategy&& other)
    : strategyFunction{other.strategyFunction}
{

}

/**
 * Executes the Strategy by invoking the call operator on the universal function wrapper
 * @param p1 A Point with an X and Y coordinate
 * @param p2 A Point with an X and Y coordinate
 * @return The distance between the two Points as determined by the specific Strategy supplied by the client
 */
double DistanceStrategy::execute(const Point &p1, const Point &p2) const
{
    ++DistanceStrategy::counter;
    return strategyFunction(p1, p2);
}

/**
 * Setter that allows clients to update the Strategy logic
 * @param strategy A universal function wrapper that contains a new Strategy
 */
void DistanceStrategy::setStrategy(const StrategyFunction &strategy)
{
    strategyFunction = strategy;
}

// ********** Static Data **********
int DistanceStrategy::counter{};

int DistanceStrategy::getCounter()
{
    return DistanceStrategy::counter;
}

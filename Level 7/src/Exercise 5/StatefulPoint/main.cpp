//
// Modern C++ Strategy Pattern
//
// Uses universal function wrappers instead of traditional inheritance associated with GOF Strategy Pattern.
//
// Created by Michael Lewis on 8/24/23.
//

#include <cmath>
#include <future>
#include <iostream>

#include "DistanceStrategy.hpp"
#include "Point.hpp"

// Alias
using StrategyFunction = std::function<double (const Point& p1, const Point& p2)>;

// Supplies a generic Strategy to a Point via a universal function wrapper
// that calculates exact distance between two points
void test_ExactDistance_StatefulPoint()
{
    auto exactStrategy = [](const Point& p1, const Point& p2)
    {
        return std::sqrt(std::pow(p2.X() - p1.X(), 2) + std::pow(p2.Y() - p1.Y(), 2));
    };

    DistanceStrategy distanceStrategy{};
    distanceStrategy.setStrategy(std::make_shared<StrategyFunction>(exactStrategy));

    Point p1{1, 1};
    Point p2{4, 5};

    double exactDistance = p1.distance(p2);

    std::cout << "Stateful Point : Exact Distance = " << exactDistance << std::endl;
}

// Supplies a generic Strategy to a Point via a universal function wrapper
// that calculates approximate distance between two points
void test_ApproximateDistance_StatefulPoint()
{
    auto approximateStrategy = [](const Point& p1, const Point& p2)
    {
        return std::abs(p2.X() - p1.X()) + std::abs(p2.Y() - p1.Y());
    };

    DistanceStrategy distanceStrategy{};
    distanceStrategy.setStrategy(std::make_shared<StrategyFunction>(approximateStrategy));

    Point p1{1, 1};
    Point p2{4, 5};

    double approximateDistance = p1.distance(p2);

    std::cout << "Stateful Point : Approximate Distance = " << approximateDistance << std::endl;
}

// Illustrate how to implement generic strategies as concurrent tasks. This approach is for illustration
// purposes given the simplistic nature of the distance algorithm; however, it would be a very effective
// solution for more complicated strategies such as sorting, n-dimensional poly-types or others.
// Note - Point could have been responsible for spinning up separate threads for the Strategy; however,
// that is a more limiting approach. Instead, the approach belows gives control to the client. Meaning the
// client gets to decide when to use concurrency vs when not to. To do this, the client can simply wrap
// the strategy inside an async task (or another mechanism such as a packaged task). This approach is
// beneficial because some Strategies perform faster without concurrency. For example a simple distance
// calculation. While others benefit greatly from concurrency. For example, sorting strategies. Thus,
// the client gets to choose the best approach for their desired Strategy.
void test_Concurrent_Strategies()
{
    std::cout << "*** Running Concurrent Strategies ***" << std::endl;

    // Exact distance strategy. Implemented using std::bind to construct a callable out of Point::distance
    auto exactStrategy = [](const Point& p1, const Point& p2)
    {
        return std::sqrt(std::pow(p2.X() - p1.X(), 2) + std::pow(p2.Y() - p1.Y(), 2));
    };

    DistanceStrategy distanceStrategy1{};
    distanceStrategy1.setStrategy(std::make_shared<StrategyFunction>(exactStrategy));

    Point p1{1, 1};
    Point p2{4, 5};

    auto deferredExactStrategy = std::bind(&Point::distance, &p1, p2);
    std::future<double> exactFuture = std::async(std::launch::async, deferredExactStrategy);

    // Approximate distance strategy. Implemented using std::bind to construct a callable out of Point::distance
    auto approximateStrategy = [](const Point& p1, const Point& p2)
    {
        return std::abs(p2.X() - p1.X()) + std::abs(p2.Y() - p1.Y());
    };

    DistanceStrategy distanceStrategy2{};
    distanceStrategy2.setStrategy(std::make_shared<StrategyFunction>(approximateStrategy));

    Point p3{1, 1};
    Point p4{4, 5};

    // Creates a callable object bound to p4 that can used in an async task
    auto deferredApproximateStrategy = std::bind(&Point::distance, &p3, p4);
    std::future<double> approximateFuture = std::async(std::launch::async, deferredApproximateStrategy);

    std::cout << "Stateless Point : Exact Distance = " << exactFuture.get() << std::endl;
    std::cout << "Stateless Point : Approximate Distance = " << approximateFuture.get() << std::endl;
}

int main()
{
    test_ExactDistance_StatefulPoint();
    test_ApproximateDistance_StatefulPoint();
    test_Concurrent_Strategies();

    std::cout << "Distance Strategy was invoked " << DistanceStrategy::getCounter() << " times" << std::endl;
    return 0;
}
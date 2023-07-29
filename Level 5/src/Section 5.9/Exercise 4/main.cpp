//
// Illustrate core functionality of Boost Signal and Slots 2 with a custom combiner
// Note: In general, a combiner is a function object
//
// Created by Michael Lewis on 7/29/23.
//

#include <cassert>
#include <iostream>

#include <boost/signals2.hpp>

#include "SumCombiner.hpp"

int main()
{
    boost::signals2::signal<double (double x, double y), SumCombiner<double>> sig;

    // Part A - Create a number of slots, each of which takes two numeric arguments
    // as input and combines them in some way to produce another numeric value as output.
    auto slotA = [](double lhs, double rhs) -> double { return lhs + rhs; };
    auto slotB = [](double lhs, double rhs) -> double { return lhs * rhs; };
    auto slotC = [](double lhs, double rhs) -> double { return lhs - rhs; };

    // Part B - See the SumCombiner.hpp and SumCombiner.cpp files

    // Part C - Test your code and check that the output is correct.
    sig.connect(boost::ref(slotA));
    sig.connect(boost::ref(slotB));
    sig.connect(boost::ref(slotC));

    // Expected = (5 + 3) + (5 * 3) + (5 - 3) == 25
    auto result = sig(5, 3);
    assert(25 == result);
    std::cout << result << std::endl;

    // Expected = (10 + 10) + (10 * 10) + (10 - 10) == 120
    result = sig(10, 10);
    assert(120 == result);
    std::cout << result << std::endl;

    return 0;
}
//
// Illustrate basic functionality of Boost random to see how it differs from C++11 random
// Created by Michael Lewis on 7/18/23.
//

#include <algorithm>
#include <list>

#include <chrono>
#include <iostream>

#include <boost/random.hpp>
#include <boost/random/generate_canonical.hpp>

// Part A - Create a variate of the triangle distribution with lagged Fibonacci as random number engine.
void test_triangle_distribution()
{
    // Choose the seed
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Choose the engine
    boost::lagged_fibonacci44497 engine(seed);

    // Default params: RealType = 0.0, RealType = 0.5, RealType = 1.0
    boost::triangle_distribution dist;

    std::cout << dist(engine) << std::endl;
}

// Part B - Use Boost function template generate_canonical() to generate a value uniformly
// in the range [0,1) with at least bits random bits:
// Experiment with various values of bits (for example, 8,16,32).
void test_generate_canonical()
{
    // Choose the seed
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Choose the engine
    boost::lagged_fibonacci44497 engine(seed);

    // See thread to understand why lagged_fibonacci generates very small numbers for a small number of bits
    // https://quantnet.com/threads/4-3-6-b-weird-result-with-lagged_fibonacci.49848/post-300372
    std::cout << boost::random::generate_canonical<double, 8, boost::lagged_fibonacci44497>(engine) << std::endl;
    std::cout << boost::random::generate_canonical<double, 16, boost::lagged_fibonacci44497>(engine) << std::endl;
    std::cout << boost::random::generate_canonical<double, 32, boost::lagged_fibonacci44497>(engine) << std::endl;
    std::cout << boost::random::generate_canonical<double, 64, boost::lagged_fibonacci44497>(engine) << std::endl;
}

int main()
{
    test_triangle_distribution();
    test_generate_canonical();
    return 0;
}
//
// Additional illustration of a generic function that works with any distribution and random number engine.
// The variates of the distribution will be stored in a map.
//
// Created by Michael Lewis on 7/18/23.
//

#include <iomanip>
#include <iostream>
#include <map>
#include <random>

// Part A - Generic function that works with any distribution and random number engine
template<typename Dist, typename Eng>
void GenerateRandomNumbers(Dist d, Eng eng, int nTrials, const std::string& s)
{
    // Key = bucket/value; Value = number of occurrences
    std::map<long long, int> counter;
    for (int i = 0; i < nTrials; ++i)
    {
        // Start the engine
        auto randomNum = d(eng);
        if (counter.contains(randomNum)) counter.at(randomNum)++;
        else (counter.emplace(std::make_pair(randomNum, 1)));
    }

    std::cout << "\n\n" << s << ": " << std::endl;
    for (auto entry : counter)
    {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << entry.first << " : " << std::string(entry.second / 100, '*') << '\n';
    }
}

// Part B - Test the code by choosing the geometric distribution.
void test_geometric_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose and seed the engine
    std::mt19937_64 engine(rd());

    // Choose the distribution
    std::geometric_distribution<int> dist;

    // Trials
    int numTrials = 1'000'000;

    GenerateRandomNumbers<std::geometric_distribution<int>, std::mt19937_64>(dist, engine, numTrials, "geometric distribution");
}

// Part B - Test the code by choosing the uniform distribution.
void test_uniform_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose and seed the engine
    std::mt19937_64 engine(rd());

    // Choose the distribution
    int A = 0;
    int B = 15;
    std::uniform_int_distribution<int> dist(A, B);

    // Trials
    int numTrials = 1'000'000;

    GenerateRandomNumbers<std::uniform_int_distribution<int>, std::mt19937_64>(dist, engine, numTrials, "uniform distribution");
}

// Part B - Test the code by choosing the poisson distribution.
void test_poisson_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose and seed the engine
    std::mt19937_64 engine(rd());

    // Choose the distribution - Event occurs 7 times per minute on average
    std::poisson_distribution<int> dist(7);

    // Trials
    int numTrials = 1'000'000;

    GenerateRandomNumbers<std::poisson_distribution<int>, std::mt19937_64>(dist, engine, numTrials, "poisson distribution");
}

// Part C - Examine the generated output in each case; does it look like the probability of these distributions?
// Response: Yes, per the documentation on CPP Reference, the results of the unit tests above look
// like the probability of the specified distributions:
//
// Geometric: https://en.cppreference.com/w/cpp/numeric/random/geometric_distribution
// Uniform: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
// Poisson: https://en.cppreference.com/w/cpp/numeric/random/poisson_distribution

int main()
{
    test_geometric_distribution();
    test_uniform_distribution();
    test_poisson_distribution();
    return 0;
}

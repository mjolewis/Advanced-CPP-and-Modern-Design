//
// Created by Michael Lewis on 7/18/23.
//

#include <iomanip>
#include <iostream>
#include <map>
#include <random>

// Generic function that works with any distribution and random number engine
template<typename Dist, typename Eng>
void GenerateRandomNumbers(Dist d, Eng eng, int nTrials, int degreesOfFreedom, const std::string& s)
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

    std::cout << "\n\n" << s << " - DOF= " << degreesOfFreedom << std::endl;
    for (auto entry : counter)
    {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << entry.first << " : " << std::string(entry.second / 100, '*') << std::endl;
    }
}

// Part A - Test the code by choosing the poisson distribution.
void test_poisson_chi_squared_distribution(int degreesOfFreedom)
{
    // Choose the seed
    std::random_device rd;

    // Choose and seed the engine
    std::mt19937_64 engine(rd());

    // Generate chi squared random variates
    std::chi_squared_distribution<double> dist(degreesOfFreedom);

    // Trials
    const int norm = 1'00'00;

    GenerateRandomNumbers<std::chi_squared_distribution<double>,
            std::mt19937_64>(dist, engine, norm, degreesOfFreedom, "chi-squared distribution");
}

// Part B - per the documentation provided at https://en.cppreference.com/w/cpp/numeric/random/chi_squared_distribution
// the results of these tests match the expected results.

// Part C Notes
// Per https://quantnet.com/threads/7-clarification-of-requirement.33844/post-322127
// Per https://quantnet.com/threads/7-clarification-of-requirement.33844/post-322168
// As long as our plots match expected results as outlined on CPP Reference (See link on line 57 above)
// then we are good to advance through this exercise. Meaning no need to compute chi squared statistic
// manually with Σ((O - E)² / E).

int main()
{
    test_poisson_chi_squared_distribution(1);
    test_poisson_chi_squared_distribution(2);
    test_poisson_chi_squared_distribution(3);
    test_poisson_chi_squared_distribution(4);
    test_poisson_chi_squared_distribution(6);
    test_poisson_chi_squared_distribution(9);

    return 0;
}
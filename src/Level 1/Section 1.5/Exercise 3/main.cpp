//
// Created by Michael Lewis on 6/6/23.
//

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <vector>

// Alias for statistics return types
using Stats = std::tuple<double, double, double, double, double>;

/**
 * A generic calculator that recursively operates on the data in a tuple
 */
template<typename T, typename Container>
struct Calculator
{
    static T sum(const Container& pack)
    {
        T sum = 0;
        for (auto element : pack)
        {
            sum += element;
        }
        return sum;
    }

    static T deviation(const T& mean, const Container& pack)
    {
        T sum = 0;
        for (auto element : pack)
        {
            sum += std::abs(mean - element);
        }
        return sum / (T) pack.size();
    }

    static T range(const Container& pack)
    {
        T min = DBL_MAX;
        T max = -DBL_MAX;
        for (auto element : pack)
        {
            if (element < min) min = element;
            if (element > max) max = element;
        }
        return std::abs(max - min);
    }

    static T variance(const T& mean, const Container& pack)
    {
        int sumOfSquares = 0;
        for (auto element : pack)
        {
            sumOfSquares += std::pow(element - mean, 2);
        }
        return sumOfSquares / (T) (pack.size() - 1);
    }

    static T median(Container& pack)
    {
        std::sort(pack.begin(), pack.end());
        int size = pack.size();
        if (size % 2 == 0) return (pack.at((size - 1) / 2) + (pack.at(size / 2))) / 2.0;
        return pack.at(size/2);
    }

    static T mode(Container& pack)
    {
        std::sort(pack.begin(), pack.end());

        T currentNum = pack.at(0);
        T mode = currentNum;
        int freq = 1;
        int modeFreq = 1;

        // Minor optimization to create the end iterator outside the loop
        const auto& end = pack.cend();

        // Already read the first value, so start the iterator and the second value
        for (auto it = pack.cbegin() + 1; it < end; ++it)
        {
            if (*it == currentNum)
            {
                ++freq;
            }
            else
            {
                // Mode is the smaller of two values that have the same frequency
                if (*it > currentNum && freq > modeFreq)
                {
                    mode = currentNum;
                    modeFreq = freq;
                }

                // Reset the state
                freq = 1;
                currentNum = *it;
            }
        }

        return mode;
    }
};

/**
 * Calculate the statistics of a dataset and return the stats in a tuple
 */
template<typename T, typename Container>
struct Statistics
{
    static Stats calculate(const Container& pack)
    {
        auto mean = Calculator<T, Container>::sum(pack) / pack.size();
        auto meanDeviation = Calculator<T, Container>::deviation(mean, pack);
        auto range = Calculator<T, Container>::range(pack);
        auto variance = Calculator<T, Container>::variance(mean, pack);
        auto std = std::sqrt(variance);
        return {mean, meanDeviation, range, std, variance};
    }
};

/**
 * Show use case to return multiple values in a tuple and tie them to informative variables
 */
void test_statistics()
{
    double mean, meanDeviation, range, std, variance;
    std::vector<int> vec{1, 2, 3, 4, 4, 4, 3};
    std::tie(mean, meanDeviation, range, std, variance) = Statistics<double, std::vector<int>>::calculate(vec);
    assert(3 == mean);
    assert(0.8571428571428571 == meanDeviation);
    assert(3 == range);
    assert(1.1547005383792515 == std);
    assert(1.3333333333333333 == variance);
}

/**
 * Calculate the median for both even and odd sized containers
 */
void test_median()
{
    // even sized vector
    std::vector<int> vec1{4, 3, 1, 2};
    auto median1 = Calculator<double, std::vector<int>>::median(vec1);
    assert(2.5 == median1);

    // odd sized vector
    std::vector<int> vec2{4, 3, 6, 1, 2};
    auto median2 = Calculator<double, std::vector<int>>::median(vec2);
    assert(3 == median2);
}

/**
 * Calculate the mode for containers.
 * When there are two or more values that are candidates to be the mode,
 * then the smallest value will be chosen
 */
void test_mode()
{
    std::vector<int> vec1{1, 1, 10, 4, 2, 27, 14, 10};
    auto mode1 = Calculator<int, std::vector<int>>::mode(vec1);
    assert(1 == mode1);

    std::vector<int> vec2{1, 10, 4, 2, 27, 14, 10};
    auto mode2 = Calculator<int, std::vector<int>>::mode(vec2);
    assert(10 == mode2);
}

int main()
{
    test_statistics();
    test_median();
    test_mode();
    return 0;
}
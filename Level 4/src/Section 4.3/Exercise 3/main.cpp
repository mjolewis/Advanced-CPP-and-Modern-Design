//
// Illustrate basic use cases of std::shuffle using both user defined and C++11 random engines.
//
// Created by Michael Lewis on 7/18/23.
//

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Part A - Create a large vector of integers
// Note the size is purposefully kept relatively small so it's easier to examine the console output
std::vector<int> getVector(int size)
{
    std::vector<int> vec;
    for (int i = 0; i < size; ++i)
    {
        vec.push_back(i);
    }

    return vec;
}

// Part B - Implement the C++11 shuffle using user defined random engine to shuffle the values
void test_shuffle_user_defined_engine()
{
    std::vector<int> vec = getVector(100);

    // Choose the seed
    std::random_device rd;

    // Choose and seed the engine
    int seed = 1;
    int multiplier = 13; // K=1 super prime
    int modulo = 29; // K=1 super prime
    auto engine = [&](int num) {
        for (int j = 0; j < num; ++j)
        {
            seed = (seed * multiplier + 1) % modulo;
        }

        return seed;
    };

    std::cout << "\nBefore shuffle - user defined Engine: ";
    for (const auto& num : vec)
    {
        std::cout << num << ", ";
    }

    std::cout << "\nAfter shuffle - user defined Engine: ";
    std::random_shuffle(vec.begin(), vec.end(), engine);
    for (const auto& num : vec)
    {
        std::cout << num << ", ";
    }
}

// Part B - Implement the C++11 shuffle using mt19937 engine to shuffle the values
void test_shuffle_mt19937_engine()
{
    std::vector<int> vec = getVector(100);

    // Choose the seed
    std::random_device rd;

    // Choose and seed the engine
    std::mt19937 engine(rd());

    std::cout << "\nBefore shuffle - mt19937 Engine: ";
    for (const auto& num : vec)
    {
        std::cout << num << ", ";
    }

    std::cout << "\nAfter shuffle - mt19937 Engine: ";
    std::shuffle(vec.begin(), vec.end(), engine);
    for (const auto& num : vec)
    {
        std::cout << num << ", ";
    }
}

// Part B - Implement the C++11 shuffle using default_random_engine to shuffle the values
// Note, this was removed in C++17
void test_shuffle_default_random_engine()
{
    std::vector<int> vec = getVector(100);

    std::cout << "\nBefore shuffle - default random Engine: ";
    for (const auto& num : vec)
    {
        std::cout << num << ", ";
    }

    std::cout << "\nAfter shuffle - default random Engine: ";
    std::random_shuffle(vec.begin(), vec.end());
    for (const auto& num : vec)
    {
        std::cout << num << ", ";
    }
}

// Part B - Implement the C++11 shuffle using linear_congruential_engine to shuffle the values
void test_shuffle_linear_congruential_engine()
{
    std::vector<int> vec = getVector(100);

    // Choose the seed
    std::random_device rd;

    // Choose and seed the engine
    std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> engine(rd());

    std::cout << "\nBefore shuffle - linear congruential Engine: ";
    for (const auto& num : vec)
    {
        std::cout << num << ", ";
    }

    std::cout << "\nAfter shuffle - linear congruential Engine: ";
    std::shuffle(vec.begin(), vec.end(), engine);
    for (const auto& num : vec)
    {
        std::cout << num << ", ";
    }
}

int main()
{
    test_shuffle_user_defined_engine();
    test_shuffle_mt19937_engine();
    test_shuffle_default_random_engine();
    test_shuffle_linear_congruential_engine();
    return 0;
}

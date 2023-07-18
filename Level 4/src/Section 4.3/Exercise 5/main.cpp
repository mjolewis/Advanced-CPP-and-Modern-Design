//
// Illustrate the functionality of independent_bits_engine to automatically generate bitsets
//
// Created by Michael Lewis on 7/18/23.
//

#include <bitset>
#include <chrono>
#include <iostream>
#include <random>

// Helper function to print the results of the independent bit engine
void print(const std::string& id, auto engine, int count)
{
    std::cout << id << ": ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << static_cast<unsigned>(engine()) << ' ';
    }
    std::cout << '\n';
};

// Part A - Create an instance of independent_bits_engine with a given random number engine,
// number of desired bits and integer types. Display the generated value as an integer and as a bitset.
// Per https://quantnet.com/threads/5-wierd-conversion-warning.33838/post-222081
// We should use the independent_bits_engine from the standard libary instead of creating out own.
void test_independent_bits_engine()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine and display the result as a integer value
    std::independent_bits_engine<std::mt19937_64, 4, unsigned int> engine1(rd());
    print("engine_1", engine1, 1);

    // Choose the engine and display result as a bitset
    std::independent_bits_engine<std::mt19937_64, /*bits*/ 1, unsigned int> engine2(rd());
    print("engine_2", engine2, 8);
}

// Part B - Create a function to test this functionality in the following way; take the width = 2,
// generate a random number using independent_bits_engine and then use this number to create a bitset.
// Determine how many bits have been set in this bitset (use member function count()) and add the
// number to a running counter. Then call the function a large number of times.
// Do you get a value in the region of 50%?
void test_engine_to_bitset_width_2(double trials)
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine and display result as a bitset
    std::independent_bits_engine<std::mt19937_64, /*bits*/ 2, unsigned long long> engine(rd());
    size_t counter = 0;
    for (int i = 0; i < trials; ++i)
    {
        unsigned long long value = engine();
        std::bitset<2> bitset{value};
        counter += bitset.count();
    }

    double total = 2.0 * trials; // number of bits
    double tol = 0.01;
    double ratio = counter / total;
    bool isInTolerance = ((.50 - tol) < ratio) && (ratio < (.50 + tol));
    std::cout << "Part B - 2 bits - Ratio of bits set: " << ratio
    << std::boolalpha << " : Is in tolerance: " << isInTolerance << std::endl;
}

// Part C - Experiment with width = 8,16 and 64. How many trials are needed to arrive at 50% of outcomes equal to 1?
void test_engine_to_bitset_width_8(double trials)
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine and display result as a bitset
    std::independent_bits_engine<std::mt19937_64, /*bits*/ 8, unsigned long long> engine(rd());
    size_t counter = 0;
    for (int i = 0; i < trials; ++i)
    {
        unsigned long long value = engine();
        std::bitset<8> bitset{value};
        counter += bitset.count();
    }

    double total = 8.0 * trials; // number of bits
    double tol = 0.01;
    double ratio = counter / total;
    bool isInTolerance = ((.50 - tol) < ratio) && (ratio < (.50 + tol));
    std::cout << "Part C - 8 bits - Ratio of bits set: " << ratio
    << std::boolalpha << " : Is in tolerance: " << isInTolerance << std::endl;
}

// Part C - Experiment with width = 16. How many trials are needed to arrive at 50% of outcomes equal to 1?
void test_engine_to_bitset_width_16(double trials)
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine and display result as a bitset
    std::independent_bits_engine<std::mt19937_64, /*bits*/ 16, unsigned long long int> engine(rd());
    size_t counter = 0;
    for (int i = 0; i < trials; ++i)
    {
        unsigned long long value = engine();
        std::bitset<16> bitset{value};
        counter += bitset.count();
    }

    double total = 16.0 * trials; // number of bits
    double tol = 0.01;
    double ratio = counter / total;
    bool isInTolerance = ((.50 - tol) < ratio) && (ratio < (.50 + tol));
    std::cout << "Part C - 16 bits - Ratio of bits set: " << ratio
              << std::boolalpha << " : Is in tolerance: " << isInTolerance << std::endl;
}

// Part C - Experiment with width = 64. How many trials are needed to arrive at 50% of outcomes equal to 1?
void test_engine_to_bitset_width_64(double trials)
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine and display result as a bitset
    std::independent_bits_engine<std::mt19937_64, /*bits*/ 64, unsigned long long int> engine(rd());
    size_t counter = 0;
    for (int i = 0; i < trials; ++i)
    {
        unsigned long long value = engine();
        std::bitset<64> bitset{value};
        counter += bitset.count();
    }

    double total = 64.0 * trials; // number of bits
    double tol = 0.01;
    double ratio = counter / total;
    bool isInTolerance = ((.50 - tol) < ratio) && (ratio < (.50 + tol));
    std::cout << "Part C - 64 bits - Ratio of bits set: " << ratio
              << std::boolalpha << " : Is in tolerance: " << isInTolerance << std::endl;
}

int main()
{
    test_independent_bits_engine();
    test_engine_to_bitset_width_2(10'000.0);
    test_engine_to_bitset_width_8(10'000.0);
    test_engine_to_bitset_width_16(10'000.0);
    test_engine_to_bitset_width_64(10'000.0);

    // Note for Part C - Depending on the tolerance I've specified, the number of trials can either decrease or
    // or would need to increase. For example, if I increase my tolerance, the number of trials can decrease. If I
    // reduce the tolerance then the number of trials must increase.
    return 0;
}

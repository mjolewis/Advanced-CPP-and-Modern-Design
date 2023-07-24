//
// Illustrate how to create and use generic hash functions for an std::unordered_map
//
// Created by Michael Lewis on 7/24/23.
//

#include <cstddef>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <limits>

#include "BoostHasher.hpp"
#include "Hasher.hpp"

// Part B - Use generic hash functions to create and test unordered_map
void test_hash_functions()
{
    std::cout << "\n*** Test Hashing using STL ***" << std::endl;

    // integers
    std::unordered_map<int, int, Hasher> int_map = {
            {1, 2},
            {3, 4},
            {5, 6}
    };
    for (const auto& entry : int_map) std::cout << "{" << entry.first << ", " << entry.second << "}, ";
    std::cout << "\n";

    // strings,
    std::unordered_map<std::string, std::string, Hasher> string_map = {
            {"1", "2"},
            {"3", "4"},
            {"5", "6"}
    };
    for (const auto& entry : string_map) std::cout << "{" << entry.first << ", " << entry.second << "}, ";
    std::cout << "\n";

    // pointers,
    std::unordered_map<const char*, const char*, Hasher> pointer_map = {
            {"1", "2"},
            {"3", "4"},
            {"5", "6"}
    };
    for (const auto& entry : pointer_map) std::cout << "{" << entry.first << ", " << entry.second << "}, ";
    std::cout << "\n";

    // std::numeric_limits<long>::max()
    std::unordered_map<long, long, Hasher> limits_map = {
            {std::numeric_limits<long>::max(), std::numeric_limits<long>::max()}
    };
    for (const auto& entry : limits_map) std::cout << "{" << entry.first << ", " << entry.second << "}, ";
    std::cout << "\n";

    std::cout << "\n*** Test Hashing using Boost ***" << std::endl;
    // integers
    std::unordered_map<int, int, BoostHasher> int_map_boost = {
            {1, 2},
            {3, 4},
            {5, 6}
    };
    for (const auto& entry : int_map_boost) std::cout << "{" << entry.first << ", " << entry.second << "}, ";
    std::cout << "\n";

    // strings,
    std::unordered_map<std::string, std::string, BoostHasher> string_map_boost = {
            {"1", "2"},
            {"3", "4"},
            {"5", "6"}
    };
    for (const auto& entry : string_map_boost) std::cout << "{" << entry.first << ", " << entry.second << "}, ";
    std::cout << "\n";

    // pointers,
    std::unordered_map<const char*, const char*, BoostHasher> pointer_map_boost = {
            {"1", "2"},
            {"3", "4"},
            {"5", "6"}
    };
    for (const auto& entry : pointer_map_boost) std::cout << "{" << entry.first << ", " << entry.second << "}, ";
    std::cout << "\n";

    // std::numeric_limits<long>::max()
    std::unordered_map<long, long, BoostHasher> limits_map_boost = {
            {std::numeric_limits<long>::max(), std::numeric_limits<long>::max()}
    };
    for (const auto& entry : limits_map_boost) std::cout << "{" << entry.first << ", " << entry.second << "}, ";
    std::cout << "\n";
}

// Part C - Create two hashes h1 and h2 of two strings and then compute h1 ^ (h2 << 1)
void test_compute_hash()
{
    std::cout << "\n*** Computing Hash Value ***" << std::endl;
    Hasher hasher;

    size_t h1 = hasher.operator()<std::string>("7");
    size_t h2 = hasher.operator()<std::string>("9");

    std::size_t key = h1 ^ (h2 << 1);
    std::cout << "h1 ^ (h2 << 1)=" <<  key << std::endl;
}

int main()
{
    test_hash_functions();
    test_compute_hash();
    return 0;
}
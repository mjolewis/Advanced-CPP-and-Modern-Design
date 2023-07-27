//
// Created by Michael Lewis on 7/26/23.
//

#include <cstddef>
#include <iostream>
#include <string>

#include <boost/functional/hash.hpp>

#include "Order.hpp"
#include "Point.hpp"

int counter = 0;

// Generic hash function
template<typename T>
void hash_value(std::size_t& seed, const T& val)
{
    boost::hash_combine(seed, val);
}

// Generic variadic hash function
template<typename T, typename... Types>
void hash_value(std::size_t& seed, const T& val, const Types&... args)
{
    boost::hash_combine(seed, val);
    hash_value(seed, args...);
}

// Generic variadic auxiliary function that initializes its own seed
template<typename... Types>
std::size_t hash_value(const Types&... args)
{
    std::size_t seed = 0;
    hash_value(seed, args...);

    return seed;
}

// Part A - Test generic hash functions
void test_hash_functions()
{
    std::cout << "\n*** Generic variadic hash function ***" << std::endl;
    std::string s1{"One"};
    std::string s2{"Two"};
    std::string s3{"Three"};
    std::size_t seed = 0;
    hash_value(seed, s1, s2, s3);
    std::cout << "Hash value:" << seed << std::endl;
}

// Part B - Test variadic auxiliary hash function using composite objects
void test_variadic_auxiliary_hash()
{
    std::cout << "\n*** Generic variadic auxiliary hash function ***" << std::endl;

    // Composite objects and other values to test the variadic hash functions
    Point point(1, 1);
    Order order{1l, 'D', 1, 173.43, 1000.0};
    std::string s1{"HFT"};
    int num = 100;

    std::size_t seed = hash_value(point, order, s1, num);
    std::cout << "Hash value:" << seed << std::endl;
}

int main()
{
    test_hash_functions();
    test_variadic_auxiliary_hash();
    return 0;
}
//
// Created by Michael Lewis on 6/2/23.
//

#ifndef UTILS_CPP
#define UTILS_CPP

#include <iostream>

#include "Utils.hpp"

/**
 * Tail condition for variadic print function
 */
template<typename T>
constexpr void Utils::print(const T &arg)
{
    std::cout << arg << std::endl;
}

/**
 * Variadic template function that prints args to the console
 */
template<typename T, typename... Types>
constexpr void Utils::print(const T &arg, const Types &... args)
{
    std::cout << arg << std::endl;
    print(args...);
}

#endif

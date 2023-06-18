//
// Created by Michael Lewis on 6/2/23.
//

#ifndef UTILS_CPP
#define UTILS_CPP

#include <functional>
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
constexpr void Utils::print(const T& arg, const Types &... args)
{
    std::cout << arg << std::endl;
    print(args...);
}

/**
 * Tail condition for variadic rotate function
 */
template<typename T>
constexpr void Utils::rotate(double factor, const T& arg)
{
    arg.rotate(factor);
}

/**
 * Variadic template function to simulate rotating an object. Currently only prints to the console.
 */
template<typename T, typename... Types>
constexpr void Utils::rotate(double factor, const T& arg, const Types&... args)
{
    arg.rotate(factor);
    rotate(factor, args...);
}

/**
 * General purpose function wrapper to print args to the console
 */
template<typename T>
constexpr void Utils::print(const FunctionType<T>& f, T t)
{
    std::cout << f(t) << '\n';
}

#endif

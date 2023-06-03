//
// Created by Michael Lewis on 6/2/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_UTILS_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_UTILS_HPP

#include "functional"

// Alias for a global function wrapper
template<typename T>
using FunctionType = std::function<T (const T& t)>;

/**
 * Utility struct for common functions
 */
struct Utils
{
    template<typename T>
    constexpr static void print(const FunctionType<T>& f, T t);

    template<typename T>
    constexpr static void print(const T& arg);

    template<typename T, typename... Types>
    constexpr static void print(const T& arg, const Types&... args);

    template<typename T>
    constexpr static void rotate(double factor, const T& arg);

    template<typename T, typename... Types>
    constexpr static void rotate(double factor, const T& arg, const Types&... args);
};

//*** Start Template definitions ***//
#ifndef UTILS_CPP
#include "Utils.cpp"
#endif
//*** End Template definitions ***//

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_UTILS_HPP

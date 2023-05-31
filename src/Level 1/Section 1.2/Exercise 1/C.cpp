//
// Created by Michael Lewis on 5/29/23.
//

#ifndef C_CPP
#define C_CPP

#include <algorithm>
#include <iostream>
#include <vector>

#include "C.hpp"

/**
 * Default dtor
 * @tparam T
 */
template<typename T>
C<T>::~C()
{
    std::cout << "Default dtor" << std::endl;
}

/**
 * Print all elements in the member container
*  @tparam T A generic type for this objects data member
 */
template<typename T>
void C<T>::print() const
{
    std::for_each(vec.begin(), vec.end(), [&] (T value) {std::cout << value << std::endl;});
}

/**
 * Insert a new value into the member container
*  @tparam T A generic type for this objects data member
 * @param value A value representing the generic type that will be inserted into the container
 */
template<typename T>
void C<T>::insert(T value)
{
    if (vec.size() >= 0) vec.push_back(value);
}

/**
 * Accessor for the member vector
 */
template<typename T>
std::vector<T>& C<T>::getVec() const noexcept
{
    return vec;
}

/**
 * Setter for the source vector
 */
template<typename T>
void C<T>::setVec(const std::vector<T>& source) noexcept
{
    vec = source;
}

/**
 * Accessor for the member array
 */
template<typename T>
std::array<int, 5>& C<T>::getArray() noexcept
{
    return array;
}

/**
 * Setter for the member array
 */
template<typename T>
void C<T>::setArray(const std::array<int, 5> &source) noexcept
{
    array = source;
}

/**
 * Calculate the sum of the member array
 */
template<typename T>
int C<T>::sumArray() noexcept
{
    int sum = 0;
    for (int element : array)
    {
        sum += element;
    }

    return sum;
}

/**
 * Calculate the sum of the member vector
 */
template<typename T>
T C<T>::sumVector() noexcept
{
    T sum = 0;
    for (int element : vec)
    {
        sum += element;
    }

    return sum;
}

/**
 * Simple example to illustrate a use case for constexpr. This could represent
 * a timer that publishes an object over multicast at a pre-defined rate.
 *
 * Note - This object might have deferred publishing so it doesn't overload the system
 * for non-latency sensitive messages.
 * @return The publishing frequency in millis
 */
template<typename T>
constexpr int C<T>::getPublishFrequency() noexcept
{
    return PUBLISH_FREQ_MILLIS;
}

#endif
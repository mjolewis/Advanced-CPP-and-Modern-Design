//
// Created by Michael Lewis on 5/29/23.
//

#ifndef C_CPP
#define C_CPP

#include <algorithm>
#include <iostream>
#include <vector>

#include "C.hpp"
#include "../Exercise 3/C.hpp"

/**
 * Overloaded ctor
 * @param size Initial size of the member vector
 */
template<typename T>
C<T>::C(int size) : size{size}
{
    std::cout << "Overloaded ctor" << std::endl;
    vec = std::make_unique<std::vector<T>>(size);
}

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
    std::for_each(vec->begin(), vec->end(), [&] (T value) {std::cout << value << std::endl;});
}

/**
 * Insert a new value into the member container
*  @tparam T A generic type for this objects data member
 * @param value A value representing the generic type that will be inserted into the container
 */
template<typename T>
void C<T>::insert(const T& value)
{
    if (vec->size() > 0) vec->push_back(value);
}

/**
 * Accessor for the member vector
 */
template<typename T>
const std::unique_ptr<std::vector<T>>& C<T>::getVec() const noexcept
{
    return vec;
}

/**
 * Setter for the source vector
 */
template<typename T>
void C<T>::setVec(int index, T element) noexcept
{
    if (index < 0 || index >= vec->size()) return;
    vec->at(index) = element;
}

/**
 * Accessor for the member array
 */
template<typename T>
const std::array<int, 5>& C<T>::getArray() noexcept
{
    return array;
}

/**
 * Setter for the member array
 */
template<typename T>
void C<T>::setArray(int index, int element) noexcept
{
    if (index < 0 || index >= array.size()) return;
    array.at(index) = element;
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
    auto end = vec->cend();
    for (auto it = vec->begin(); it != end; ++it)
    {
        sum += *it;
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

/**
 * Size accessor
 */
template<typename T>
int C<T>::getSize() const noexcept
{
    return size;
}

#endif
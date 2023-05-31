//
// Created by Michael Lewis on 5/29/23.
//

#ifndef C_CPP
#define C_CPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <type_traits>

#include "C.hpp"

template<typename T>
constexpr C<T>::C()
{
    vec = std::vector<T>();
}

/**
 * Copy ctor
 */
template<typename T>
C<T>::C(const C<T> &source)
{
    std::cout << "copy ctor" << std::endl;

    vec = std::vector<T>(source.vec.size());

    // Deep copy of the source vector
    for (int i = 0; i < source.vec.size(); ++i)
    {
        vec.at(i) = source.vec.at(i);
    }
}

/**
 * Move ctor
 */
template<typename T>
C<T>::C(const C<T> &&source) noexcept
{
    std::cout << "Move ctor" << std::endl;
    vec = std::move(source.vec);
}

/**
 * Default dtor
 */
template<typename T>
C<T>::~C()
{
    std::cout << "Default dtor" << std::endl;
}

template<typename T>
C<T>& C<T>::operator=(const C<T>& source)
{
    std::cout << "Assignment operator" << std::endl;
    // Avoid self assignment
    if (this == &source) return *this;

    // Avoid memory leaks
    delete vec;

    // Reallocate container
    vec = new std::vector(source.vec.size());

    // Deep copy of the source vector
    for (int i = 0; i < source.vec.size(); ++i)
    {
        vec.at(i) = source.vec.at(i);
    }
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
 * Calculate the sum of the member vector
 */
template<typename T>
T C<T>::sumVector() noexcept
{
    T sum = 0;
    for (T element : vec)
    {
        sum += element;
    }

    return sum;
}

/**
 * Swap copy style
 */
template<typename T>
template<typename U>
void C<T>::swapCopyStyle(U &a, U &b) noexcept
{
    std::cout << "swap copy style" << std::endl;

    // Swap a and b in copying way; temporary object needed
    U tmp(a); // Copy constructor
    a = b; // Copy all elements from b to a
    b = tmp; // Copy all elements from tmp to b
}

/**
 * Swap move style
 */
template<typename T>
template<typename U>
void C<T>::swapMoveStyle(U&& a, U&& b) noexcept
{
    std::cout << "swap move style" << std::endl;

    U&& tmp = std::move(a);
    a = std::move(b);
    b = tmp;
}

#endif
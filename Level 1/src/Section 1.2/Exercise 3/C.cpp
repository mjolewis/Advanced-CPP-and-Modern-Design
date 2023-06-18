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

/**
 * Default ctor
 */
template<typename T>
constexpr C<T>::C() : size{DEFAULT_SIZE}
{
    std::cout << "Default ctor" << std::endl;
    vec = std::make_unique<std::vector<T>>(DEFAULT_SIZE);
}

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
 * Copy ctor
 */
template<typename T>
C<T>::C(const C<T> &source) : size{source.size}
{
    std::cout << "copy ctor" << std::endl;

    vec = std::make_unique<std::vector<T>>(size);

    // Deep copy of the source vector
    for (int i = 0; i < source.vec->size(); ++i)
    {
        vec->at(i) = source.vec->at(i);
    }
}

/**
 * Move ctor
 */
template<typename T>
C<T>::C(C<T> &&source) noexcept
{
    std::cout << "Move ctor" << std::endl;
    size = std::move(source.size);
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

/**
 * Copy assignment operator
 */
template<typename T>
C<T>& C<T>::operator=(const C<T>& source)
{
    std::cout << "Copy Assignment operator" << std::endl;
    // Avoid self assignment
    if (this == &source) return *this;

    // Avoid memory leaks
    vec = nullptr;

    // Reallocate container
    vec = std::make_unique<std::vector<T>>(size);

    // Deep copy of the source vector
    for (int i = 0; i < source.vec->size(); ++i)
    {
        vec->at(i) = source.vec->at(i);
    }

    return *this;
}

/**
 * Move assignment operator
 */
template<typename T>
C<T>& C<T>::operator=(C<T>&& source) noexcept
{
    std::cout << "Move assignment operator" << std::endl;

    // Avoid self move
    if (this == &source) return *this;

    vec = std::move(source.vec);

    return *this;
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

    U tmp = std::move(a);
    a = std::move(b);
    b = tmp;
}

#endif
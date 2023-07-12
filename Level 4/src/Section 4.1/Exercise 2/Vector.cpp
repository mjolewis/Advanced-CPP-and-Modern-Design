//
// A compile-time Vector adapter that wraps a std::array.
//
// Created by Michael Lewis on 7/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_VECTOR_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_VECTOR_CPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>

#include "Vector.hpp"

/**
 * Default ctor, which constructs this Vector with a default size
 * @tparam T The type of element that will be stored in this Vector
 * @tparam N The size of this Vector.
 */
template<typename T, size_t N>
Vector<T, N>::Vector() : size{N}
{
    array = std::array<T, N>();
}

/**
 * Copy ctor
 * @tparam T The type of element that will be stored in this Vector
 * @tparam N The size of this Vector
 * @param other A Vector whose elements will be deeply copied into this Vector
 */
template<typename T, size_t N>
Vector<T, N>::Vector(const Vector<T, N> &other) : size{other.size}
{
    if (size != other.size) throw std::invalid_argument("Vectors must be equal size");

    // Reallocate this vector
    array = std::array<T, N>();
    for (int i = 0; i < size; ++i)
    {
        array[i] = other[i];
    }
}

/**
 * Overloaded ctor that populates each index in this vector with a default value
 * @tparam T The type of element that will be stored in this Vector
 * @tparam N The size of this Vector
 * @param args A list of values to fill this Vector
 */
template<typename T, size_t N>
Vector<T, N>::Vector(const T& defaultValue) : size{N}
{
    array = std::array<T, N>();
    array.fill(defaultValue);
}

/**
 * Overloaded ctor
 * @tparam T The type of element that will be stored in this Vector
 * @tparam N The size of this Vector
 * @param args A list of values to fill this Vector
 */
template<typename T, size_t N>
Vector<T, N>::Vector(const std::initializer_list<T>& args) : size{N}
{
    array = std::array<T, N>();
    int idx = 0;
    for (const T& element : args)
    {
        array[idx++] = element;
    }
}

/**
 * Returns a reference to the element at specified location index. No bounds checking is performed
 * @tparam T Data type of the elements stored in this std::vector
 * @tparam N The size of this Vector
 * @param index position of the element to return
 * @return Reference to the requested element.
 */
template<typename T, size_t N>
const T& Vector<T, N>::operator[](size_t index) const
{
    return array[index];
}

/**
 * Returns a reference to the element at specified location index. No bounds checking is performed
 * @tparam T Data type of the elements stored in this std::vector
 * @tparam N The size of this Vector
 * @param index position of the element to return
 * @return Reference to the requested element.
 */
template<typename T, size_t N>
T& Vector<T, N>::operator[](size_t index)
{
    return array[index];
}

/**
 * Performs vector addition. Uses STL transform to perform vector addition
 * @tparam T Data type of the elements stored in this std::vector
 * @tparam N The size of this Vector
 * @param other Another Vector that will be added with the elements from this Vector
 * @return A new stack based memory object.
 */
template<typename T, size_t N>
Vector<T, N> Vector<T, N>::operator+(const Vector<T, N> &other) const
{
    if (size != other.size) throw std::invalid_argument("Vectors must be equal size");

    Vector<T, N> result{};
    std::transform(array.cbegin(), array.cend(),
                   other.array.cbegin(),
                   result.array.begin(), // Write to a new Vector
                   std::plus<T>());
    return result;
}

/**
 * Performs vector subtraction. Uses STL transform to perform vector subtraction
 * @tparam T Data type of the elements stored in this std::vector
 * @tparam N The size of this Vector
 * @param other Another Vector that will be subtracted from the elements from this Vector
 * @return A new stack based memory object.
 */
template<typename T, size_t N>
Vector<T, N> Vector<T, N>::operator-(const Vector<T, N> &other) const
{
    if (size != other.size) throw std::invalid_argument("Vectors must be equal size");

    Vector<T, N> result{};
    std::transform(array.cbegin(), array.cend(),
                   other.array.cbegin(),
                   result.array.begin(), // Write to a new Vector
                   std::minus<T>());
    return result;
}

/**
 * Performs unary negation of this Vector. Uses STL transform to perform negation
 * @tparam T Data type of the elements stored in this std::vector
 * @tparam N The size of this Vector
 * @return A new stack based memory object.
 */
template<typename T, size_t N>
Vector<T, N> Vector<T, N>::operator-()
{
    std::transform(array.cbegin(), array.cend(),
                   array.begin(), // Write to the current Vector
                   [](double element) -> double {return -element;});
    return *this;
}

/**
 * Injects a std::function that can be used to modify this Vector.
 * @tparam T Data type of the elements stored in this std::vector
 * @tparam N The size of this Vector
 * @tparam Type Data type of the incoming function that is used to transform this Vector
 * @param function
 */
template<typename T, size_t N>
template<typename Type>
void Vector<T, N>::modify(const std::function<Type(Type &)> &function)
{
    std::transform(array.begin(), array.end(),
                   array.begin(), // Write to this vector
                   function);
}

/**
 * Utility method to print each element in this Vector
 * @tparam T Data type of the elements stored in this std::vector
 * @tparam N The size of this Vector
 */
template<typename T, size_t N>
void Vector<T, N>::print() const
{
    std::for_each(array.cbegin(), array.cend(), [](T element) -> void { std::cout << element << ", "; });
    std::cout << "\n";
}

// ********** Friend Functions *********

/**
 * Pre-multiplication by a scalar quantity. Implemented as a friend function because
 * scalar multiplication is left associative
 * @tparam Type Data type of the elements stored in the incoming vector
 * @tparam N_ The size of this Vector
 * @tparam F Scalar type used to multiply with this Vector
 * @param a The scalar multiplier
 * @param pt The source vector that will be scaled
 * @return The scaled Vector
 */
template<typename Type, size_t N_, typename F>
Vector<Type, N_> operator*(const F& a, const Vector<Type, N_>& pt)
{
    Vector<Type, N_> scaled;
    for (int i = 0; i < N_; ++i)
    {
        scaled[i] = a * pt[i];
    }

    return scaled;
}

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_VECTOR_CPP
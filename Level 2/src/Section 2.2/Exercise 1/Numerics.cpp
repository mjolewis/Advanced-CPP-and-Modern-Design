//
// Created by Michael Lewis on 6/19/23.
//

#ifndef NUMERICS_CPP
#define NUMERICS_CPP

#include <type_traits>

#include "Numerics.hpp"

/**
 * A generic library function that leverages type traits to determine
 * the addition mechanics required for the specified argument
 */
template<typename T>
T Numerics::Addition(const T& t1, const T& t2)
{
    return AdditionImpl(t1, t2, std::is_compound<T>());
}

/**
 * A specific implementation that performs addition on compound types such as vectors
 */
template<typename T>
T Numerics::AdditionImpl(const T& t1, const T& t2, std::true_type)
{
    // Hint: T can be (among other things) a std::vector or std::array. This complicates things because a vector and
    // array are initialized with a size differently. Therefore, it's best to use the copy ctor of the given T. This
    // allows us to have the compiler determine how to construct a new T result instead of having the developer
    // perform this task manually for an unknown type.
    T result = T(t1);
    for (int i = 0; i < t1.size(); ++i)
    {
        result[i] = t1[i] + t2[i];
    }

    return result;
}

/**
 * A specific implementation that performs addition on fundamental types
 */
template<typename T>
T Numerics::AdditionImpl(const T& t1, const T& t2, std::false_type)
{
    return t1 + t2;
}

/**
 * A generic library function that leverages type traits to determine
 * the addition mechanics required for the specified argument
 */
template<typename T>
void Numerics::AdditiveInverse(T& t1)
{
    AdditiveInverseImpl(t1, std::is_compound<T>());
}

/**
 * A specific implementation that performs additive inverse on compound types
 */
template<typename T>
void Numerics::AdditiveInverseImpl(T& t1, std::true_type)
{
    for (auto it = t1.begin(); it != t1.end(); ++it)
    {
        *it = -*it;
    }
}

/**
 * A specific implementation that performs additive inverse on fundamental types
 */
template<typename T>
void Numerics::AdditiveInverseImpl(T& t1, std::false_type)
{
    t1 = -t1;
}

/**
 * A generic library function that leverages type traits to determine
 * the multiplication mechanics required for the specified argument
 */
template<typename T>
T Numerics::Multiplication(const T& t1, const T& t2)
{
    return MultiplicationImpl(t1, t2, std::is_compound<T>());
}

/**
 * A specific implementation that performs multiplication on compound types
 */
template<typename T>
T Numerics::MultiplicationImpl(const T& t1, const T& t2, std::true_type)
{
    // Hint: T can be (among other things) a std::vector or std::array. This complicates things because a vector and
    // array are initialized with a size differently. Therefore, it's best to use the copy ctor of the given T. This
    // allows us to have the compiler determine how to construct a new T result instead of having the developer
    // perform this task manually for an unknown type.
    T result = T(t1);
    for (int i = 0; i < t1.size(); ++i)
    {
        result[i] = t1[i] * t2[i];
    }

    return result;
}

/**
 * A specific implementation that performs multiplication on fundamental types
 */
template<typename T>
T Numerics::MultiplicationImpl(const T& t1, const T& t2, std::false_type)
{
    return t1 * t2;
}

#endif
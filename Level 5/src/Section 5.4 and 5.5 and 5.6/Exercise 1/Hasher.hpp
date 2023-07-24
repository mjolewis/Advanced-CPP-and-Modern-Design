//
// Part A - Create generic functions to hash arbitrary data types using C++11
// Note - Hash functions must provide an implementation of the call operator
// to calculate the hash of the argument
//
// Created by Michael Lewis on 7/24/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_HASHER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_HASHER_HPP

#include <cstddef>

class Hasher
{
public:
    template<typename T>
    std::size_t operator()(const T& key) const
    {
        return std::hash<T>()(key);
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_HASHER_HPP

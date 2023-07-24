//
// Part A - Create generic functions to hash arbitrary data types using Boost
// Note - Hash functions must provide an implementation of the call operator
// to calculate the hash of the argument
//
// Created by Michael Lewis on 7/24/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BOOSTHASHER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BOOSTHASHER_HPP

#include <cstddef>

#include <boost/functional/hash.hpp>

class BoostHasher
{
public:
    template<typename T>
    std::size_t operator()(const T& key) const
    {
        std::size_t seed = 0;
        boost::hash_combine(seed, key);
        return seed;
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_BOOSTHASHER_HPP

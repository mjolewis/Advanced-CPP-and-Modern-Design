//
// Create and return a hash value
//
// Created by Michael Lewis on 7/25/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINTHASH_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINTHASH_HPP

#include <cstddef>
#include <functional>

#include "Point.hpp"

struct PointHash : std::unary_function<Point, std::size_t>
{
    std::size_t operator() (const Point& pt) const
    {
        std::size_t seed = 0;
        boost::hash_combine(seed, pt.X());
        boost::hash_combine(seed, pt.Y());
        return seed;
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINTHASH_HPP

//
// Utility structure used to create and return a hash value and test equality of points
// using std::hash
//
// Created by Michael Lewis on 7/25/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POINTHASHER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POINTHASHER_HPP

#include <cstddef>
#include <functional>

#include "Point.hpp"

struct PointHasher
{
    std::size_t operator()(const Point& point) const noexcept
    {
        std::size_t h1 = std::hash<double>{}(point.X());
        std::size_t h2 = std::hash<double>{}(point.Y());
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }

    bool operator()(const Point& lhs, const Point& rhs) const noexcept
    {
        return (lhs.X() == rhs.X()) && (lhs.Y() == rhs.Y());
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POINTHASHER_HPP

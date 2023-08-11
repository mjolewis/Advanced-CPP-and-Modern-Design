//
// A distance strategy object that calculates exact distance using Phytagoras distance
//
// Note - This Strategy is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/10/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_EXACTDISTANCE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_EXACTDISTANCE_HPP

#include "Point.hpp"
#include "DistanceStrategy.hpp"

class ExactDistance : public DistanceStrategy
{
public:
    ExactDistance();
    ExactDistance(const ExactDistance& other) = delete;
    ExactDistance(ExactDistance&& other) = delete;
    ~ExactDistance() override = default;

    // Operator Overloads
    ExactDistance& operator=(const ExactDistance& other) = delete;
    ExactDistance& operator=(ExactDistance&& other) = delete;

    // Core Functionality
    double distance(const Point& p1, const Point& p2) override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_EXACTDISTANCE_HPP

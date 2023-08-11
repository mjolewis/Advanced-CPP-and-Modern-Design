//
// A distance strategy object that calculates approximate distance using the fast, but less accurate,
// taxicab distance formula
//
// Note - This Strategy is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/10/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_APPROXIMATEDISTANCE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_APPROXIMATEDISTANCE_HPP

#include "Point.hpp"
#include "DistanceStrategy.hpp"

class ApproximateDistance : public DistanceStrategy
{
public:
    ApproximateDistance();
    ApproximateDistance(const ApproximateDistance& other) = delete;
    ApproximateDistance(ApproximateDistance&& other) = delete;
    ~ApproximateDistance() override = default;

    // Operator Overloads
    ApproximateDistance& operator=(const ApproximateDistance& other) = delete;
    ApproximateDistance& operator=(ApproximateDistance&& other) = delete;

    double distance(const Point& p1, const Point& p2) override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_APPROXIMATEDISTANCE_HPP

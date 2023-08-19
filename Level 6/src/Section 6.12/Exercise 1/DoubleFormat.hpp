//
// Unlike the Observer Pattern, the Propagator Pattern allows for standalone observer classes.
// DoubleFormat is one such standalone observer.
//
// Created by Michael Lewis on 8/16/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DOUBLEFORMAT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_DOUBLEFORMAT_HPP

#include "Propagator.hpp"

class DoubleFormat
{
public:
    DoubleFormat() = default;
    DoubleFormat(const DoubleFormat& other) = default;
    DoubleFormat(DoubleFormat&& other) = default;
    ~DoubleFormat() = default;

    // Operator Overloads
    DoubleFormat& operator=(const DoubleFormat& other) = default;
    DoubleFormat& operator=(DoubleFormat&& other) = default;
    void operator()(const Propagator &observable) const;

    void update(const Propagator& counter) const;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DOUBLEFORMAT_HPP

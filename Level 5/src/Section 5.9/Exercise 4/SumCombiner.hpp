//
// A custom Combiner that accumulates slots into a single number
// Note: In general, a combiner is a function object
//
// Created by Michael Lewis on 7/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SUMCOMBINER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SUMCOMBINER_HPP

template<typename T>
struct SumCombiner
{
    typedef T result_type;

    template<typename InputIterator>
    T operator()(InputIterator first, InputIterator last) const;
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SUMCOMBINER_CPP
#include "SumCombiner.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SUMCOMBINER_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SUMCOMBINER_HPP

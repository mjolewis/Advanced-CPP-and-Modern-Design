//
// A Combiner that iterates in slots and return first 'false' value; otherwise, 'true'
// Note: In general, a combiner is a function object
//
// Created by Michael Lewis on 7/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BOOTSTRAPCHECK_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BOOTSTRAPCHECK_HPP

struct BootstrapCheck
{
    typedef bool result_type;
    template<typename InputIterator>
    bool operator()(InputIterator first, InputIterator last) const;
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BOOTSTRAPCHECK_CPP
#include "BootstrapCheck.cpp"
#endif

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_BOOTSTRAPCHECK_HPP

//
// A Combiner that iterates in slots and return first 'false' value; otherwise, 'true'
// Created by Michael Lewis on 7/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BOOTSTRAPCHECK_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BOOTSTRAPCHECK_CPP

#include "BootstrapCheck.hpp"

/**
 * A Combiner that iterates in slots and return first 'false' value; otherwise, 'true'
 * @tparam InputIterator
 * @param first An begin iterator for a Signal
 * @param last An end iterator for a Signal
 * @return True if and only if no false values are in the slots
 */
template<typename InputIterator>
bool BootstrapCheck::operator()(InputIterator first, InputIterator last) const
{
    while(first != last)
    {
        if (!*first)
            return false;
        ++first;
    }
    return true;
}

#endif
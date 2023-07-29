//
// A custom Combiner that accumulates slots into a single number
// Note: In general, a combiner is a function object
//
// Created by Michael Lewis on 7/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SUMCOMBINER_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SUMCOMBINER_CPP

#include <numeric>

#include "SumCombiner.hpp"

/**
 * A custom Combiner that accumulates slots into a single number
 * @Note - This Combiner delegates to std::accumulate
 * @tparam T The data type being accumulated
 * @tparam InputIterator A generic type of iterator
 * @param first An begin iterator for this Combiner
 * @param last An end iterator for this Combiner
 * @return A single accumulated value of type T
 */
template<typename T>
template<typename InputIterator>
T SumCombiner<T>::operator()(InputIterator first, InputIterator last) const
{
    return std::accumulate(first, last, 0);
}

#endif
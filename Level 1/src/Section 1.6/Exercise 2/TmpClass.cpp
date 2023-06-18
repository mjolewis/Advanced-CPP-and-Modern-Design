//
// Created by Michael Lewis on 6/11/23.
//

#include <algorithm>
#include <iostream>

#include "TmpClass.hpp"

/**
 * Overloaded ctor
 */
TMPClass::TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction)
: n{n}, startValue{startValue}, iFunction{std::move(iFunction)}, oFunction{std::move(oFunction)}, data(n, startValue)
{
}

/**
 * Template method that derived class must specialize
 */
void TMPClass::computer()
{
    TMPClass::preprocessor();
    TMPClass::compute();
    TMPClass::postprocessor();
}

/**
 * Returns a simple multiplier that will be used to scale the values
 * in the data structure
 */
double TMPClass::preprocessor()
{
    return iFunction();
}

/**
 * Transforms elements in a data structure using STL algorithms and function wrappers.
 *
 * Note, the transformation writes to the same location meaning the source is modified.
 */
void TMPClass::compute()
{
    auto transform = [&] (double& element) -> double {
        return preprocessor() * element;
    };
    std::transform(data.begin(), data.end(), data.begin(), transform);
}

/**
 * Logs data to the console
 */
void TMPClass::postprocessor()
{
    TMPClass::oFunction(data);
}

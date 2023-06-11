//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_TMPCLASS_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_TMPCLASS_HPP

#include <functional>
#include <iostream>
#include <vector>

using InputFunction = std::function<double ()>;
using OutputFunction = std::function<void (const std::vector<double>&)>;

/**
 * Illustrates the Template Method Pattern along with modern C++
 * language features such as universal function wrappers
 */
class TMPClass
{
private:
    std::size_t n;
    double startValue;
    std::vector<double> data;
    InputFunction iFunction;
    OutputFunction oFunction;

public:
    TMPClass() = delete;
    TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction);
    virtual ~TMPClass() = default;

    // Template method
    virtual void computer() final;

    // Hook functions
    virtual double preprocessor();
    virtual void compute();
    virtual void postprocessor();
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_TMPCLASS_HPP

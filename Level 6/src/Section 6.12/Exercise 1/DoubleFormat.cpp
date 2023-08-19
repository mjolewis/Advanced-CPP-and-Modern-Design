//
// Unlike the Observer Pattern, the Propagator Pattern allows for standalone observer classes.
// DoubleFormat is one such standalone observer.
//
// Created by Michael Lewis on 8/16/23.
//

#include <iomanip>
#include <iostream>

#include "DoubleFormat.hpp"
#include "Counter.hpp"
#include "Propagator.hpp"

/**
 * Call operator to transform DoubleFormat into a function object that can be passed around
 * in a universal function wrapper
 * @param observable A Propagator whose state has changed
 */
void DoubleFormat::operator()(const Propagator &observable) const
{
    update(observable);
}

/**
 * Receives updates whenever the subject changes state and prints the counter out in double format
 * @param subject The subject that changed state
 */
void DoubleFormat::update(const Propagator &observable) const
{
    Counter counter = dynamic_cast<const Counter&>(observable);
    double d = counter.getCounter();
    std::string s = std::to_string(d);
    std::cout << "Double Format: " << s << std::endl;
}

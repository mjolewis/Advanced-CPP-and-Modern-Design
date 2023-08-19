//
// Unlike the Observer Pattern, the Propagator Pattern allows for standalone observer classes.
// LongFormat is one such standalone observer.
//
// Created by Michael Lewis on 8/16/23.
//

#include <iomanip>
#include <iostream>

#include "LongFormat.hpp"
#include "Counter.hpp"
#include "Propagator.hpp"

/**
 * Call operator to transform LongFormat into a function object that can be passed around
 * in a universal function wrapper
 * @param observable A Propagator whose state has changed
 */
void LongFormat::operator()(const Propagator &observable) const
{
    update(observable);
}


/**
 * Receives updates whenever the subject changes state and prints the counter out in long format
 * @param subject The subject that changed state
 */
void LongFormat::update(const Propagator &observable) const
{
    Counter counter = dynamic_cast<const Counter&>(observable);
    long l = counter.getCounter();
    std::string s = std::to_string(l);
    std::cout << "Long Format: " << s << std::endl;
}

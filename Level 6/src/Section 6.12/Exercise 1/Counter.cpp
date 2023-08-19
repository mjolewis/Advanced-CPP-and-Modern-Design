//
// Concrete Propagator used to illustrate state changes.
// Maintains observers as a list of universal function wrappers for flexibility
//
// Created by Michael Lewis on 8/18/23.
//

#include "Counter.hpp"

/**
 * Default ctor
 */
Counter::Counter() : Propagator(), counter{0}
{

}

/**
 * Attach or "subscribe" the observer to receive notifications whenever this concrete Propagator changes state
 * @param observer A callable object wrapped in a universal function wrapper
 */
void Counter::addObserver(const std::function<void(const Propagator &)>& observer)
{
    observers.push_back(observer);
}

/**
 * Invoked by Propagators whenever their state changes and their observers need to be notified
 * @param observable The Propagator whose state has changed
 */
void Counter::update(const Propagator &observable)
{
    Counter ob = dynamic_cast<const Counter&>(observable);
    counter = ob.counter + 1;

    for (const auto& observer : ob.observers)
    {
        observer(*this); // observers are function objects
    }
}

/**
 * Returns the value of the counter
 * @return The value of the counter
 */
int Counter::getCounter() const
{
    return counter;
}

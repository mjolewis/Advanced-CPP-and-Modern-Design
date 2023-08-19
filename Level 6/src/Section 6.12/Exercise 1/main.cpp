//
// Propagator Pattern
//
// Created by Michael Lewis on 8/16/23.
//

#include <memory>

#include "Propagator.hpp"
#include "Counter.hpp"
#include "LongFormat.hpp"
#include "DoubleFormat.hpp"

// Alias
using ObserverPtr = std::shared_ptr<Propagator>;

int main()
{
    // Create a concrete Propagator and attach it
    Counter propagator;
    ObserverPtr observable = std::make_shared<Counter>(propagator);
    propagator.addObservable(observable);

    // Pass a call to a function object
    propagator.addObserver(DoubleFormat());
    propagator.addObserver(LongFormat());

    // Observable notifies its observers
    propagator.notify();

    return 0;
}
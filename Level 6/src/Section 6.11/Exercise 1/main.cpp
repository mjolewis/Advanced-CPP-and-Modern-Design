//
// Observer Pattern
//
// Created by Michael Lewis on 8/16/23.
//

#include <iostream>
#include <memory>

#include "Counter.hpp"
#include "LongFormat.hpp"
#include "DoubleFormat.hpp"

// Alias
using ObserverPtr = std::shared_ptr<Observer>;

int main()
{
    // Create Observers
    std::shared_ptr<Observer> longFormat = std::make_shared<LongFormat>();
    std::shared_ptr<Observer> doubleFormat = std::make_shared<DoubleFormat>();

    // Create the Subject and attach Observers
    Counter counter;
    counter.attach(longFormat);
    counter.attach(doubleFormat);

    std::cout << "*** Increase the Counter ***" << std::endl;
    for (int i = 0; i < 5; ++i) counter.increaseCounter();

    std::cout << "*** Decrease the Counter ***" << std::endl;
    for (int i = 0; i < 5; ++i) counter.decreaseCounter();

    return 0;
}
//
// Concrete Subject used to illustrate state changes
//
// Created by Michael Lewis on 8/16/23.
//

#include "Counter.hpp"
#include "Subject.hpp"

/**
 * Default ctor
 */
Counter::Counter() : Subject(), value{0}
{

}

/**
 * Increments the counter by one and notifies all the observers
 */
void Counter::increaseCounter()
{
    ++value;
    Subject::notify();
}

/**
 * Decrements the counter by one and notifies all the observers
 */
void Counter::decreaseCounter()
{
    --value;
    Subject::notify();
}

/**
 * Returns the value of the counter
 * @return The value of the counter
 */
int Counter::getCounter() const
{
    return value;
}

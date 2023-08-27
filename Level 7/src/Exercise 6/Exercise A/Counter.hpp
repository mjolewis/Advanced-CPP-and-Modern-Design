//
// Concrete Subject used to illustrate state changes.
//
// Note - The derived Counter maintains an integer value that the base class Subject needs access
// to. To facilitate this, we can use CRTP (Curiously Recurring Template Pattern). This allows
// the Observers (implemented as universal function wrappers) in the base class to read the counter
// without having to directly pass a counter value to the Subjects Notify.
//
// Created by Michael Lewis on 8/27/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP

#include "Subject.hpp"

class Counter : public Subject<Counter>
{
private:
    double value;

public:
    Counter() : Subject(), value{0} {};
    Counter(const Counter& counter) = default;
    Counter(Counter&& other) = default;
    ~Counter() override = default;

    // Operator Overloads
    Counter& operator=(const Counter& other) = default;
    Counter& operator=(Counter&& other) = default;

    /**
     * Increments the counter by one and notifies all the observers
     */
    void increaseCounter()
    {
        ++value;
        Subject<Counter>::notify();
    }

    /**
     * Decrements the counter by one and notifies all the observers
     */
    void decreaseCounter()
    {
        --value;
        Subject<Counter>::notify();
    }

    /**
     * Returns the value of the counter
     * @return The value of the counter
     */
    int getCounter() const
    {
        return value;
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP

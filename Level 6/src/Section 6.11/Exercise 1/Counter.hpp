//
// Concrete Subject used to illustrate state changes
//
// Created by Michael Lewis on 8/16/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP

#include "Subject.hpp"

class Counter : public Subject
{
private:
    int value;

public:
    Counter();
    Counter(const Counter& counter) = default;
    Counter(Counter&& other) = default;
    ~Counter() override = default;

    // Operator Overloads
    Counter& operator=(const Counter& other) = default;
    Counter& operator=(Counter&& other) = default;

    void increaseCounter();
    void decreaseCounter();
    int getCounter() const;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP

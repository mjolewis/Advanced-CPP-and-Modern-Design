//
// Concrete Propagator used to illustrate state changes.
// Maintains observers as a list of universal function wrappers for flexibility
//
// Created by Michael Lewis on 8/18/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP

#include <functional>
#include <list>

#include "Propagator.hpp"

class Counter : public Propagator
{
private:
    int counter;
    std::list<std::function<void (const Propagator &observable)>> observers;

public:
    Counter();
    Counter(const Counter& counter) = default;
    Counter(Counter&& other) = default;
    ~Counter() override = default;

    // Operator Overloads
    Counter& operator=(const Counter& other) = default;
    Counter& operator=(Counter&& other) = default;

    // Overridden Functions
    void update(const Propagator& observable) override;

    void addObserver(const std::function<void (const Propagator &observable)>& observer);
//    void increaseCounter();
//    void decreaseCounter();
    int getCounter() const;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_COUNTER_HPP

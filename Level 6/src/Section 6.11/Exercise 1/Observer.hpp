//
// Base class for Observer Pattern
//
// Created by Michael Lewis on 8/16/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_OBSERVER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_OBSERVER_HPP

// Forward Declarations
class Subject;

class Observer
{
public:
    Observer() = default;
    Observer(const Observer& other) = default;
    Observer(Observer&& other) = default;
    virtual ~Observer() = default;

    // Operator Overloads
    Observer& operator=(const Observer& other) = default;
    Observer& operator=(Observer&& other) = default;

    virtual void update(const Subject& subject) = 0;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_OBSERVER_HPP

//
// Observer Pattern - Subjects can add, remove, and notify observers
//
// Created by Michael Lewis on 8/16/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SUBJECT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SUBJECT_HPP

#include <list>
#include <memory>

#include "Observer.hpp"

// Alias for code readability
using ObserverPtr = std::shared_ptr<Observer>;

class Subject
{
private:
    std::list<ObserverPtr> observers;

public:
    Subject() = default;
    Subject(const Subject& other) = default;
    Subject(Subject&& other) = default;
    virtual ~Subject() = default;

    // Operator Overloads
    Subject& operator=(const Subject& other) = default;
    Subject& operator=(Subject&& other) = default;

    virtual void attach(ObserverPtr& _observerPtr);
    virtual void detach(ObserverPtr& _observerPtr);
    virtual void notify();
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SUBJECT_HPP

//
// Next Generation Observer Pattern
//
// Note - The derived Counter maintains an integer value that the base class Subject needs access
// to. To facilitate this, we can use CRTP (Curiously Recurring Template Pattern). This allows
// the Observers (implemented as universal function wrappers) in the base class to read the counter
// without having to directly pass a counter value to the Subjects Notify.
//
// Additionally, I've increased the flexibility of the system by designing it with
// Template-Template Parameters, which allows me to store the Observers in any generic container.
//
// Created by Michael Lewis on 8/27/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SUBJECT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SUBJECT_HPP

#include <list>
#include <deque>
#include <functional>
#include <memory>

#include "Counter.hpp"

using ObserverPtr = std::shared_ptr<std::function<void (double)>>;

template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
class Subject
{
private:
    Container<ObserverPtr, TAlloc> observers;  // store observers in a generic container

public:
    Subject() = default;
    Subject(const Subject& other) = default;
    Subject(Subject&& other) = default;
    virtual ~Subject() = default;

    // Operator Overloads
    Subject& operator=(const Subject& other) = default;
    Subject& operator=(Subject&& other) = default;

    /**
     * Attach or "subscribe" the observer to receive notifications whenever this Subject changes state
     * @param observerPtr The Observer that is interested in receiving updates upon state changes
     */
    void attach(const ObserverPtr& observerPtr)
    {
        observers.push_back(observerPtr);
    }

    /**
     * Notifies all the observers when the subject changes state
     */
    void notify()
    {
        for (const auto& observer : observers)
        {
            observer.get()->operator()(static_cast<T*>(this)->getCounter());
        }
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SUBJECT_HPP

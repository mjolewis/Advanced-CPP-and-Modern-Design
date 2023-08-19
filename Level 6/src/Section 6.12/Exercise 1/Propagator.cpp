//
// Propagator Pattern - Subjects can add, remove, update, and notify observers
//
// Created by Michael Lewis on 8/16/23.
//

#include "Propagator.hpp"

/**
 * Default ctor
 */
Propagator::Propagator() : observables{}
{

}

/**
 * Attach or "subscribe" the observer to receive notifications whenever this Propagator changes state
 * @param observable An observable is a derived Propagator that is interested in receiving updates upon state changes
 */
void Propagator::addObservable(std::shared_ptr<Propagator> &observable)
{
    observables.push_back(observable);
}

/**
 * Detach or "unsubscribe" the observable from further notifications whenever this Propagator changes state
 * @param observable An observable is a derived Propagator that is no longer interested in receiving
 * updates upon state changes
 */
void Propagator::deleteObservable(std::shared_ptr<Propagator> &observable)
{
    observables.remove(observable);
}

/**
 * Notifies all the observers when the Propagator changes state
 */
void Propagator::notify()
{
    for (const auto& observable : observables)
    {
        observable->update(*this);
        observable->notify();
    }
}

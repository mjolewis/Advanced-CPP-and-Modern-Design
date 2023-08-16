//
// Created by Michael Lewis on 8/16/23.
//

#include "Subject.hpp"

/**
 * Attach or "subscribe" the observer to receive notifications whenever this Subject changes state
 * @param _observerPtr The Observer that is interested in receiving updates upon state changes
 */
void Subject::attach(ObserverPtr &_observerPtr)
{
    observers.push_back(_observerPtr);
}

/**
 * Detach or "unsubscribe" the observer from further notifications whenever this Subject changes state
 * @param _observerPtr The Observer no longer interested in receiving updates upon state changes
 */
void Subject::detach(ObserverPtr &_observerPtr)
{
    observers.remove(_observerPtr);
}

/**
 * Notifies all the observers when the subject changes state
 */
void Subject::notify()
{
    for (auto& observer : observers)
    {
        observer->update(*this);
    }
}

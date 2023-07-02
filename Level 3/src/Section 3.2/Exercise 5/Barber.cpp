//
// An exemplar class that consumes Customers from a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between multiple producer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Consumer is specialized to consume std::string. It is not CopyConstructible,
// CopyAssignable, or MoveAssignable. It is, however, MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#include <memory>
#include <iostream>
#include <optional>
#include <utility>

#include "ConcurrentQueue.hpp"
#include "Barber.hpp"

/**
 * Overloaded ctor
 * @param queue A ConcurrentQueue to consume data from
 */
Barber::Barber(std::shared_ptr<ConcurrentQueue<std::string>> queue) : queue{std::move(queue)} {}

/**
 * A thread function that consumes data from the ConcurrentQueue.
 * @Note - This is a long running process that will continually consume data.
 */
void Barber::operator()()
{
    while (queue->isOpenForBusiness())
    {
        // Print the data to the console
        auto msg = queue->dequeue();
        if (msg.has_value())
        {
            std::cout << "Barber is cutting hair for " << msg.value() << std::endl;
        }

        // Only one Barber, so no need to yield to other Barber threads
    }
}
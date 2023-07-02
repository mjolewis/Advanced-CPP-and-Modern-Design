//
// An exemplar class that produces Customers to a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between multiple producer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Producer is specialized for std::string. It is not CopyConstructible,
// CopyAssignable, or MoveAssignable. It is, however, MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#include <memory>
#include <utility>
#include <sstream>

#include "ConcurrentQueue.hpp"
#include "Customer.hpp"

/**
 * Overloaded ctor
 * @param queue A ConcurrentQueue to publish data into
 */
Customer::Customer(std::shared_ptr<ConcurrentQueue<std::string>> queue) : queue{std::move(queue)} {}

/**
 * A thread function that publishes Customers into the queue.
 * @Note - This is a long running process that will continually publish data. This can be viewed
 * as an example of an event driven system like exchanges publishing market data throughout the day
 */
void Customer::operator()()
{
    while (queue->isOpenForBusiness())
    {
        std::stringstream customerId;
        customerId << std::this_thread::get_id();
        // Produce and publish data to the queue
        std::string msg = std::string("Customer:").append(customerId.str());
        queue->enqueue(msg);

        // Customers arrive every 10 seconds
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

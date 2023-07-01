//
// An exemplar class that produces data to a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between multiple producer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Producer is not CopyConstructible, CopyAssignable, or MoveAssignable. It is, however,
// MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_CPP

#include <memory>

#include "ConcurrentQueue.hpp"
#include "Producer.hpp"

/**
 * Overloaded ctor
 * @tparam T The type of data that will be produced by this producer
 * @param threadId A unique Producer identifier
 * @param queue A ConcurrentQueue to publish data into
 */
template<typename T>
Producer<T>::Producer(int threadId, std::shared_ptr<ConcurrentQueue<T>> queue) : threadId{threadId}, queue{queue} {}

/**
 * A thread function that publishes data into the queue.
 * @Note - This is a long running process that will continually publish data. This can be viewed
 * as an example of an event driven system like exchanges publishing market data throughout the day
 * @tparam T The type of data to be published
 */
template<typename T>
void Producer<T>::operator()()
{
    int data = 0;
    while (!queue->isInterrupted())
    {
        // Produce and publish data to the queue
        std::string msg = std::string("Publisher_ThreadId:")
                .append(std::to_string(threadId))
                .append(" - MsgId:")
                .append(std::to_string(++data));
        queue->enqueue(msg);

        // Make sure we can be interrupted
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

#endif

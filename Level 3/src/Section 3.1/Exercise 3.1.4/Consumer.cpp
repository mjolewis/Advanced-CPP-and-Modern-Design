//
// An exemplar class that consumes data from a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between multiple producer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Consumer is not CopyConstructible, CopyAssignable, or MoveAssignable. It is, however,
// MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_CPP

#include <memory>
#include <iostream>

#include "ConcurrentQueue.hpp"
#include "Consumer.hpp"

/**
 * Overloaded ctor
 * @tparam T The type of data that will be consumed by this Consumer
 * @param threadId A unique Consumer identifier
 * @param queue A ConcurrentQueue to consume data from
 */
template<typename T>
Consumer<T>::Consumer(int threadId, std::shared_ptr<ConcurrentQueue<T>> queue) : threadId{threadId}, queue{queue} {}

/**
 * A thread function that consumes data from the ConcurrentQueue.
 * @Note - This is a long running process that will continually consume data.
 * @tparam T The type of data to be published
 */
template<typename T>
void Consumer<T>::operator()()
{
    while (!queue->isInterrupted())
    {
        // Print the data to the console
        T msg = queue->dequeue();
        if (msg.size() > 0)
        {
            std::cout << "Consumer_ThreadID:" << std::to_string(threadId) << " - Consuming " << msg << std::endl;
        }

        // Make sure we can be interrupted
        std::this_thread::yield();
    }
}

#endif

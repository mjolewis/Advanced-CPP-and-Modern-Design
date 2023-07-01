//
// An exemplar class that consumes data from a ConcurrentQueue. The ConcurrentQueue is wrapped in a
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
#include <utility>

#include "ConcurrentQueue.hpp"
#include "Consumer.hpp"

/**
 * Overloaded ctor
 * @param threadId A unique Consumer identifier
 * @param queue A ConcurrentQueue to consume data from
 */
Consumer::Consumer(int threadId, std::shared_ptr<ConcurrentQueue<std::string>> queue) : threadId{threadId}, queue{std::move(queue)} {}

/**
 * A thread function that consumes data from the ConcurrentQueue.
 * @Note - This is a long running process that will continually consume data.
 */
void Consumer::operator()()
{
    while (!queue->isInterrupted())
    {
        // Print the data to the console
        std::string msg = queue->dequeue();
        if (msg != "SCHEDULE_ID_DROP")
        {
            std::cout << "Consumer_ThreadID:" << std::to_string(threadId) << " - Consuming " << msg << std::endl;
        }

        // Make sure we can be interrupted
        std::this_thread::yield();
    }
}

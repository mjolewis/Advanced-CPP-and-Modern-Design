//
// An exemplar class that consumes data from a ConcurrentPriorityQueue. The ConcurrentPriorityQueue is
// wrapped in a std::shared_ptr because it is shared between multiple producer and consumer
// threads that write and read from the shared queue.
//
// @Note - This Consumer is specialized for a Command object. It is not CopyConstructible,
// CopyAssignable, or MoveAssignable. It is, however, MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 7/6/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_CPP

#include <memory>

#include "Consumer.hpp"
#include "ConcurrentPriorityQueue.hpp"
#include "Command.hpp"

/**
 * Overload Ctor.
 * @tparam T The data type to be consumed by this Consumer.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param queue A ConcurrentPriorityQueue.
 */
template<typename T, typename Container, typename Compare>
Consumer<T, Container, Compare>::Consumer(const std::shared_ptr<ConcurrentPriorityQueue<T, Container, Compare>>& queue)
        : queue{queue}
{

}

/**
 * A thread function that consumes data from the ConcurrentQueue.
 * @Note - This is a long running process that will continually consume data.
 */
template<typename T, typename Container, typename Compare>
void Consumer<T, Container, Compare>::Consumer::operator()()
{
    while (true)
    {
        std::optional<T> optionalCommand = queue->dequeue();

        if (optionalCommand.has_value())
        {
            Command command = optionalCommand.value();
            long priority = command.priority();
            if (priority == INTMAX_MAX) break;
            command.Execute(priority);
        }
        std::this_thread::yield(); // Make sure we can be interrupted
    }
}

#endif

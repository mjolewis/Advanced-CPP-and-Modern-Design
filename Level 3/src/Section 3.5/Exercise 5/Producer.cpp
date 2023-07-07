//
// An exemplar class that produces data to a ConcurrentPriorityQueue. The ConcurrentPriorityQueue is
// wrapped in a std::shared_ptr because it is shared between multiple producer and consumer
// threads that write and read from the shared queue.
//
// @Note - This Producer is specialized for a Command object. It is not CopyConstructible,
// CopyAssignable, or MoveAssignable. It is, however, MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 7/6/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_CPP

#include <atomic>
#include <memory>
#include <random>

#include "Producer.hpp"
#include "ConcurrentPriorityQueue.hpp"
#include "Command.hpp"

/**
 * Overload Ctor.
 * @tparam T The data type to be constructed and published by this Producer.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param queue A ConcurrentPriorityQueue.
 */
template<typename T, typename Container, typename Compare>
Producer<T, Container, Compare>::Producer(const std::shared_ptr<ConcurrentPriorityQueue<T, Container, Compare>>& queue)
        : queue{queue}
{

}

/**
 * A thread function that publishes data into the queue.
 * @Note - This is a long running process that will continually publish data. This can be viewed
 * as an example of an event driven system like exchanges publishing market data throughout the day
 */
template<typename T, typename Container, typename Compare>
void Producer<T, Container, Compare>::operator()()
{
    static thread_local std::random_device rd; // a seed source for the random number engine
    static thread_local std::mt19937_64 generator(rd()); // mersenne_twister_engine seeded with rd()
    static thread_local std::uniform_int_distribution<> distribution(1, 100);

    while (true)
    {
        generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
        long priority = distribution(generator);

        // Create a command and publish it to the queue
        if (ConcurrentPriorityQueue<T, Container, Compare>::killSwitch)
        {
            Command killCommand(std::move([&](double value) -> double { return value; }), INTMAX_MAX);
            queue->enqueue(killCommand);
            break;
        }

        Command command(std::move([&](double value) -> double { return value; }), priority);
        queue->enqueue(command);

        // Make sure we can be interrupted
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

#endif
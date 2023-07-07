//
// A generalized Concurrent Priority Queue.
// The Concurrent Priority Queue can be viewed as an adapter of
// std::priority_queue with thread safe mechanisms layered on top.
//
// Created by Michael Lewis on 7/6/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTPRIORITYQUEUE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTPRIORITYQUEUE_CPP

#include <atomic>
#include <condition_variable>
#include <optional>
#include <queue>
#include <thread>
#include <utility>

#include "ConcurrentPriorityQueue.hpp"

// 12 user-defined literals that represent hours, minutes, seconds, milliseconds, milliseconds, and nanoseconds
// Will be used to set minimum duration to block for when attempting to acquire a lock
using namespace std::chrono_literals;

/**
 * Default Ctor
 * @tparam T The data type to be stored in this Concurrent Priority Queue
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs
 */
template<typename T, typename Container, typename Compare>
ConcurrentPriorityQueue<T, Container, Compare>::ConcurrentPriorityQueue() : priorityQueue(Compare(), Container())
{

}

/**
 * Copy constructor. The underlying container is copy-constructed with source.priorityQueue.
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param source The other ConcurrentPriorityQueue.
 */
template<typename T, typename Container, typename Compare>
ConcurrentPriorityQueue<T, Container, Compare>::ConcurrentPriorityQueue(const ConcurrentPriorityQueue<T> &source)
{
    // Delegate copying to underlying STL implementation
    priorityQueue = std::priority_queue<T, Container, Compare>(source.priorityQueue);
}

/**
 * Move constructor. Move constructor. The underlying container is constructed with std::move(source.priorityQueue)
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param source The other ConcurrentPriorityQueue.
 */
template<typename T, typename Container, typename Compare>
ConcurrentPriorityQueue<T, Container, Compare>::ConcurrentPriorityQueue(ConcurrentPriorityQueue<T>&& source) noexcept
{
    // Delegate moving to underlying STL implementation
    priorityQueue = std::priority_queue<T, Container, Compare>(source.priorityQueue);
}


/**
 * Copy assignment operator. Replaces the contents with a copy of the contents of other.
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param source The other ConcurrentPriorityQueue.
 * @return A reference to the modified ConcurrentPriorityQueue.
 */
template<typename T, typename Container, typename Compare>
ConcurrentPriorityQueue<T, Container, Compare>&
        ConcurrentPriorityQueue<T, Container, Compare>::operator=(const ConcurrentPriorityQueue<T>& source)
{
    // Avoid self assignment
    if (this != source)
    {
        // Delegate assignment to underlying STL implementation
        priorityQueue = source;
    }

    return *this;
}

/**
 * Move assignment operator. Replaces the contents with those of other using move semantics.
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param source The other ConcurrentPriorityQueue that will be moved from.
 * @return A reference to the moved to ConcurrentPriorityQueue
 */
template<typename T, typename Container, typename Compare>
ConcurrentPriorityQueue<T, Container, Compare>&
ConcurrentPriorityQueue<T, Container, Compare>::operator=(ConcurrentPriorityQueue<T>&& source) noexcept
{
    // Avoid self move
    if (this != source)
    {
        // Delegate moving to underlying STD implementation
        priorityQueue = source;
    }

    return *this;
}

/**
 * Moves the given element value to the priority queue
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param data The generic element pushed onto this priority queue
 */
template<typename T, typename Container, typename Compare>
void ConcurrentPriorityQueue<T, Container, Compare>::enqueue(const T& data)
{
    {
        std::lock_guard<std::mutex> lock(mutex);
        priorityQueue.push(std::move(data));
    }

    cv.notify_all();
}

/**
 * Removes the top element from the priority queue.
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 */
template<typename T, typename Container, typename Compare>
std::optional<T> ConcurrentPriorityQueue<T, Container, Compare>::dequeue()
{
    // Only try to consume data if there is any data. cv.wait atomically unlocks lock, blocks the current
    // executing thread, and adds it to the list of threads waiting on *this. The thread will be
    // unblocked when notify_all() or notify_one() is executed (typically done when data is enqueued)
    while (true)
    {
        try
        {
            std::optional<T> task;
            {
                // Unique lock is used with cv.wait per https://en.cppreference.com/w/cpp/thread/condition_variable/wait
                std::unique_lock<std::mutex> lock(mutex);

                // Unlocks mutex and waits for other threads to acquire lock and populate queue
                cv.wait(lock, [this]() -> bool { return !priorityQueue.empty(); });
                task = std::move(priorityQueue.top());
                priorityQueue.pop();
            }

            // Critical for this to be outside previous scope so multiple threads can execute the algo
            // concurrently. If this were in the above scope, then each thread would incur the 5000ms delay
            // embedded in the algo before the next thread could execute.
            return task;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

#endif

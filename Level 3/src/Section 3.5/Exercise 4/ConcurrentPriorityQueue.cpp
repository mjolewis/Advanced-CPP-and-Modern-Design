//
// A generalized Concurrent Priority Queue.
// The Concurrent Priority Queue can be viewed as an adapter of
// std::priority_queue with thread safe mechanisms layered on top.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTPRIORITYQUEUE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTPRIORITYQUEUE_CPP

#include <atomic>
#include <condition_variable>
#include <iostream>
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
 * Returns reference to the top element in the priority queue. This element will be removed on a call to pop().
 * If default comparison function is used, the returned element is also the greatest among the elements in the queue.
 * @note This operation is thread safe to prevent container modification while another client is potentially
 * reading the top element.
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @return A reference to the top element in the priority queue.
 */
template<typename T, typename Container, typename Compare>
const T& ConcurrentPriorityQueue<T, Container, Compare>::top() const
{
    std::lock_guard<std::mutex> lock(mutex);
    const T& top = priorityQueue.top();

    return top;
}

/**
 * Checks if the underlying container has no elements
 * @note This operation is thread safe to prevent container modification while another client is potentially
 * checking if this priority queue is empty.
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @return True if the underlying container is empty, false otherwise
 */
template<typename T, typename Container, typename Compare>
bool ConcurrentPriorityQueue<T, Container, Compare>::empty() const
{
    std::lock_guard<std::mutex> lock(mutex);
    bool isEmpty = priorityQueue.empty();

    return isEmpty;
}

/**
 * Returns the number of elements in the underlying container, that is, c.size()
 * @note This operation is thread safe to prevent container modification while another client is potentially
 * reading the size of the priority queue.
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @return The number of elements in the container.
 */
template<typename T, typename Container, typename Compare>
size_t ConcurrentPriorityQueue<T, Container, Compare>::size() const
{
    std::lock_guard<std::mutex> lock(mutex);
    size_t size = priorityQueue.size();

    return size;
}

/**
 * Pushes the given element value to the priority queue
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param data The generic element pushed onto this priority queue
 */
template<typename T, typename Container, typename Compare>
void ConcurrentPriorityQueue<T, Container, Compare>::push(const T& data)
{
    std::lock_guard<std::mutex> lock(mutex);
    priorityQueue.push(data);
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
void ConcurrentPriorityQueue<T, Container, Compare>::push(T&& data)
{
    std::lock_guard<std::mutex> lock(mutex);
    priorityQueue.push(std::move(data));
}

/**
 * Pushes a new element to the priority queue. The element is constructed in-place, i.e. no copy
 * or move operations are performed. The constructor of the element is called with exactly the
 * same arguments as supplied to the function
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @tparam Args Type of variadic elements (note - example of function template specialization)
 * @param args Arguments to forward to the constructor of the element
 */
template<typename T, typename Container, typename Compare>
template<typename... Args>
void ConcurrentPriorityQueue<T, Container, Compare>::emplace(Args &&... args)
{
    std::lock_guard<std::mutex> lock(mutex);
    (priorityQueue.emplace(std::forward<T>(args)), ...);
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
void ConcurrentPriorityQueue<T, Container, Compare>::pop()
{
    std::lock_guard<std::mutex> lock(mutex);
    priorityQueue.pop();
}

/**
 * Exchanges the contents of the container adaptor with those of other.
 * @tparam T The data type to be stored in this Concurrent Priority Queue.
 * @tparam Container The type of the underlying container to use to store the elements.
 * The container must satisfy the requirements of SequenceContainer, and its iterators must
 * satisfy the requirements of LegacyRandomAccessIterator. The standard containers std::vector
 * (including std::vector<bool>) and std::deque satisfy these requirements.
 * @tparam Compare Default comparator that evaluates lhs < rhs.
 * @param source A container adaptor to exchange the contents with.
 */
template<typename T, typename Container, typename Compare>
void ConcurrentPriorityQueue<T, Container, Compare>::swap(ConcurrentPriorityQueue& source) noexcept
{
    std::lock_guard<std::mutex> lock(mutex);
    priorityQueue.swap(source.priorityQueue);
}

#endif

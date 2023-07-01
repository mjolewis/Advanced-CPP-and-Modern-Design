//
// A generalized concurrent queue that can be used to implement a pub/sub pattern.
// The ConcurrentQueue can be viewed as an adapter of std::queue with thread safe
// mechanisms layered on top. A publisher client will enqueue data and a consumer
// client with dequeue data.
//
// @Note - This ConcurrentQueue is not CopyConstructible, MoveConstructible, CopyAssignable, or MoveAssignable
// to prevent purposeful or accidental assignments operations that should not occur
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTQUEUE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTQUEUE_CPP

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <thread>

#include "ConcurrentQueue.hpp"

// 12 user-defined literals that represent hours, minutes, seconds, milliseconds, microseconds, and nanoseconds
// Will be used to set minimum duration to block for when attempting to acquire a lock
using namespace std::chrono_literals;

/**
 * Default ctor
 * @tparam T The data type for elements in this std::queue
 */
template<typename T>
ConcurrentQueue<T>::ConcurrentQueue() : queue{}, interrupt(false)
{

}

template<typename T>
ConcurrentQueue<T>::~ConcurrentQueue()
{
    queue = {};
}

/**
 * Inserts an element into this queue in a thread safe manner
 * @tparam T The data type for elements in this std::queue
 * @param data The element to be inserted
 */
template<typename T>
void ConcurrentQueue<T>::enqueue(const T& data)
{
    // Thread safe mechanisms
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(data);
    cv.notify_all(); // Notifies consumer threads that are waiting on the condition variable that data is available
    // The lock_guard is destructed and the mutex is released at the end of the previous scope
}

/**
 * Removes the first element off this queue in a thread safe manner
 * @tparam T The data type for elements in this std::queue
 * @return The element at the front of the queue
 */
template<typename T>
T ConcurrentQueue<T>::dequeue()
{
    // Thread safe mechanisms
    // Unique lock is used with cv.wait per https://en.cppreference.com/w/cpp/thread/condition_variable/wait
    std::unique_lock<std::mutex> lock(mutex);

    // Only try to consume data if there is any data. cv.wait atomically unlocks lock, blocks the current
    // executing thread, and adds it to the list of threads waiting on *this. The thread will be
    // unblocked when notify_all() or notify_one() is executed (typically done when data is enqueued)
    while (queue.empty() && !interrupt)
    {
        try
        {
            // Wait a maximum of 1s for data before releasing the condition
            // variable and allowing other threads to start consuming
            cv.wait_for(lock, 1s);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    // Remove the element from the front of the queue and return it.
    if (!queue.empty())
    {
        T result = queue.front();
        queue.pop();
        return result;
    }

    // Handles case where the queue may be empty at time of interrupt.
    return "SCHEDULE_ID_DROP";

    // The lock_guard is destructed and the mutex is released when the scope ends
}

/**
 * Allows a client to interrupt the producer and consumer threads
 * @tparam T The type of data in this ConcurrentQueue
 * @param value A boolean flag that can be used to terminate the producer and consumer threads
 */
template<typename T>
void ConcurrentQueue<T>::setInterrupt(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    interrupt.store(value);
}

/**
 * Atomically obtains the value of the atomic object.
 * @tparam T The type of data in this ConcurrentQueue.
 * @return True if the Producers and Consumers should be interrupted. Otherwise false and the
 * Producers and Consumers continue working.
 */
template<typename T>
std::atomic<bool> ConcurrentQueue<T>::isInterrupted()
{
    return interrupt.load();
}

#endif

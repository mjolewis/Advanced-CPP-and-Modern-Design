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
#include <optional>
#include <queue>
#include <thread>

#include "ConcurrentQueue.hpp"

// 12 user-defined literals that represent hours, minutes, seconds, milliseconds, milliseconds, and nanoseconds
// Will be used to set minimum duration to block for when attempting to acquire a lock
using namespace std::chrono_literals;

/**
 * Overloaded ctor
 * @tparam T The data type for Customers in this std::queue
 * @param numChairs Max number of chairs in the waiting room
 */
template<typename T>
ConcurrentQueue<T>::ConcurrentQueue(int numChairs) : numChairs{numChairs}, queue{}, openForBusiness{true}
{

}

/**
 * Inserts a Customer into this queue in a thread safe manner
 * @tparam T The data type for Customers in this std::queue
 * @param data The Customer to be inserted
 */
template<typename T>
void ConcurrentQueue<T>::enqueue(const T& data)
{
    // Precondition that ensures the waiting room doesn't overcrowd
    if (queue.size() >= numChairs)
    {
        std::cout << "*** WAITING ROOM IS FULL ***" << std::endl;
        return;
    }

    // Thread safe mechanisms
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(data);
    cv.notify_all(); // Notifies consumer threads that are waiting on the condition variable that data is available
    // The lock_guard is destructed and the mutex is released at the end of the previous scope
}

/**
 * Removes the next customer from the queue in a thread safe manner
 * @tparam T The data type for Customers in this std::queue
 * @return The next Customer in the queue
 */
template<typename T>
std::optional<T> ConcurrentQueue<T>::dequeue()
{
    // Thread safe mechanisms
    // Unique lock is used with cv.wait per https://en.cppreference.com/w/cpp/thread/condition_variable/wait
    std::unique_lock<std::mutex> lock(mutex);

    // Only try to consume data if there is any data. cv.wait atomically unlocks lock, blocks the current
    // executing thread, and adds it to the list of threads waiting on *this. The thread will be
    // unblocked when notify_all() or notify_one() is executed (typically done when data is enqueued)
    while (queue.empty() && openForBusiness)
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

    // Optionally remove and return the Customer at the front of the queue.
    // If no customer is in the queue, return an optional empty. Based on the pre-condition
    // in the while condition above, an empty optional is only possible when the user
    // sends a signal into the system to terminate the otherwise long running process.
    auto result = queue.empty() ? std::optional<T>{} : std::optional<T>{queue.front()};
    if (result.has_value()) queue.pop();
    return result;

    // The lock_guard is destructed and the mutex is released when the scope ends
}

/**
 * Used to determine when the program should start or stop executing
 * @tparam T The data type for Customers in this std::queue
 * @param value True if the program can work, false when it should stop
 */
template<typename T>
void ConcurrentQueue<T>::setOpenForBusiness(bool value)
{
    openForBusiness.store(value);
}

/**
 * Used to determine when the program should start or stop executing
 * @tparam T The data type for Customers in this std::queue
 * @return True if the program can work, false when it should stop
 */
template<typename T>
bool ConcurrentQueue<T>::isOpenForBusiness()
{
    return openForBusiness.load();
}

#endif

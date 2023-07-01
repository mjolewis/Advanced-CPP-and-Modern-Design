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

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTQUEUE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTQUEUE_HPP

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <thread>

template<typename T>
class ConcurrentQueue
{
private:
    std::queue<T> queue;
    std::mutex mutex;
    std::condition_variable cv;
    std::atomic<bool> interrupt;

public:
    ConcurrentQueue();
    ConcurrentQueue(const ConcurrentQueue<T>& source) = default;
    ConcurrentQueue(ConcurrentQueue<T>&& source) noexcept = default;
    ~ConcurrentQueue();

    // Operator overloads
    ConcurrentQueue& operator=(const ConcurrentQueue<T>& source) = default;
    ConcurrentQueue& operator=(ConcurrentQueue<T>&& source) noexcept = default;

    // Core functionality
    void enqueue(const T& data);
    T dequeue();

    // Allow threads to be interrupted
    void setInterrupt(bool value);
    std::atomic<bool> isInterrupted();
};

// *** Template Definitions ***
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTQUEUE_CPP
#include "ConcurrentQueue.cpp"
#endif

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTQUEUE_HPP

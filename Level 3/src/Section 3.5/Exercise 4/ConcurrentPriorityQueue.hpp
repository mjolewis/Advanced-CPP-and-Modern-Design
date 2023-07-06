//
// A generalized concurrent queue that can be used to implement a pub/sub pattern.
// The ConcurrentQueue can be viewed as an adapter of std::queue with thread safe
// mechanisms layered on top. A publisher client will enqueue data and a consumer
// client with dequeue data.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTPRIORITYQUEUE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTPRIORITYQUEUE_HPP

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <optional>
#include <queue>
#include <thread>

template<typename T,
        typename Container = std::vector<T>,
        typename Compare = std::less<typename Container::value_type>>
class ConcurrentPriorityQueue
{
private:
    std::priority_queue<T, Container, Compare> priorityQueue;
    std::condition_variable cv;
    mutable std::mutex mutex;

public:
    ConcurrentPriorityQueue();
    explicit ConcurrentPriorityQueue(const ConcurrentPriorityQueue<T>& source);
    explicit ConcurrentPriorityQueue(ConcurrentPriorityQueue<T>&& source) noexcept;
    ~ConcurrentPriorityQueue() = default;

    // Operator overloads
    ConcurrentPriorityQueue& operator=(const ConcurrentPriorityQueue<T>& source);
    ConcurrentPriorityQueue& operator=(ConcurrentPriorityQueue<T>&& source) noexcept;

    // Element Access
    const T& top() const;

    // Capacity
    bool empty() const;
    size_t size() const;

    // Modifiers
    void push(const T& data);
    void push(T&& data);
    template<typename... Args> void emplace(Args&&... args);
    void pop();
    void swap(ConcurrentPriorityQueue& source) noexcept;
};

// *** Template Definitions ***
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTPRIORITYQUEUE_CPP
#include "ConcurrentPriorityQueue.cpp"
#endif

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CONCURRENTPRIORITYQUEUE_HPP

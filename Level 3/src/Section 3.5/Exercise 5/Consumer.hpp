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

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_HPP

#include <memory>

#include "ConcurrentPriorityQueue.hpp"

template<typename T,
        typename Container = std::vector<T>,
        typename Compare = std::less<typename Container::value_type>>
class Consumer
{
private:
    std::shared_ptr<ConcurrentPriorityQueue<T, Container, Compare>> queue;

public:
    Consumer() = delete;
    explicit Consumer(const std::shared_ptr<ConcurrentPriorityQueue<T, Container, Compare>>& queue);
    Consumer(const Consumer& source) = delete;
    Consumer(Consumer&& source) noexcept = default;
    ~Consumer() = default;

    // Operator overloads
    Consumer& operator=(const Consumer& source) = delete;
    Consumer& operator=(Consumer&& source) noexcept = delete;
    void operator()();
};

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_CPP
#include "Consumer.cpp"
#endif

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_HPP

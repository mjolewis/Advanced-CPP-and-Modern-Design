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

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP

#include <memory>

#include "Command.hpp"
#include "ConcurrentPriorityQueue.hpp"

template<typename T,
        typename Container = std::vector<T>,
        typename Compare = std::less<typename Container::value_type>>
class Producer
{
private:
    std::shared_ptr<ConcurrentPriorityQueue<T, Container, Compare>> queue;

public:
    Producer() = delete;
    explicit Producer(const std::shared_ptr<ConcurrentPriorityQueue<T, Container, Compare>>& queue);
    Producer(const Producer& source) = delete;
    Producer(Producer&& source) noexcept = default;
    ~Producer() = default;

    // Operator overloads
    Producer& operator=(const Producer& source) = delete;
    Producer& operator=(Producer&& source) noexcept = delete;
    void operator()();
};

// *** Template Definitions ***
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_CPP
#include "Producer.cpp"
#endif

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP

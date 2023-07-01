//
// An exemplar class that consumes data from a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between multiple producer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Consumer is specialized to consume std::string. It is not CopyConstructible,
// CopyAssignable, or MoveAssignable. It is, however, MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_HPP

#include <memory>

#include "ConcurrentQueue.hpp"

class Consumer
{
private:
    int threadId;
    std::shared_ptr<ConcurrentQueue<std::string>> queue;

public:
    Consumer() = delete;
    explicit Consumer(int threadId, std::shared_ptr<ConcurrentQueue<std::string>> queue);
    Consumer(const Consumer& source) = default;
    Consumer(Consumer&& source) noexcept = default;
    ~Consumer() = default;

    // Operator overloads
    Consumer& operator=(const Consumer& source) = default;
    Consumer& operator=(Consumer&& source) noexcept = default;
    void operator()();
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CONSUMER_HPP

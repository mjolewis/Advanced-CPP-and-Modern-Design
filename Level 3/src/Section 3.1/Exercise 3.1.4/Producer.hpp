//
// An exemplar class that produces data to a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between multiple producer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Producer is specialized for std::string. It is not CopyConstructible,
// CopyAssignable, or MoveAssignable. It is, however, MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP

#include <memory>

#include "ConcurrentQueue.hpp"

class Producer
{
private:
    int threadId;
    std::shared_ptr<ConcurrentQueue<std::string>> queue;

public:
    Producer() = delete;
    explicit Producer(int threadId, std::shared_ptr<ConcurrentQueue<std::string>> queue);
    Producer(const Producer& source) = default;
    Producer(Producer&& source) noexcept = default;
    ~Producer() = default;

    // Operator overloads
    Producer& operator=(const Producer& source) = default;
    Producer& operator=(Producer&& source) noexcept = default;
    void operator()();
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP

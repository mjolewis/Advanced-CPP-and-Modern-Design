//
// An exemplar class that produces data to a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between multiple producer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Producer is not CopyConstructible, CopyAssignable, or MoveAssignable. It is, however,
// MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP

#include <memory>

#include "ConcurrentQueue.hpp"

/**
 * An exemplar class that creates and publishes into a ConcurrentQueue
 * @Note - This Producer is not CopyConstructible, MoveConstructible, CopyAssignable, or MoveAssignable.
 */
template<typename T>
class Producer
{
private:
    int threadId;
    std::shared_ptr<ConcurrentQueue<T>> queue;

public:
    Producer() = delete;
    explicit Producer(int threadId, std::shared_ptr<ConcurrentQueue<T>> queue);
    Producer(const Producer<T>& source) = default;
    Producer(Producer<T>&& source) noexcept = default;
    ~Producer() = default;

    // Operator overloads
    Producer& operator=(const Producer<T>& source) = default;
    Producer& operator=(Producer<T>&& source) noexcept = default;
    void operator()();
};

//*** Template Definitions ***
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_CPP
#include "Producer.cpp"
#endif

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_PRODUCER_HPP

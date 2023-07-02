//
// An exemplar class that consumes Customers from a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between multiple producer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Consumer is specialized to consume std::string. It is not CopyConstructible,
// CopyAssignable, or MoveAssignable. It is, however, MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BARBER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BARBER_HPP

#include <memory>

#include "ConcurrentQueue.hpp"

class Barber
{
private:
    std::shared_ptr<ConcurrentQueue<std::string>> queue;

public:
    Barber() = delete;
    explicit Barber(std::shared_ptr<ConcurrentQueue<std::string>> queue);
    Barber(const Barber& source) = delete;
    Barber(Barber&& source) noexcept = default;
    ~Barber() = default;

    // Operator overloads
    Barber& operator=(const Barber& source) = delete;
    Barber& operator=(Barber&& source) noexcept = delete;
    void operator()();
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_BARBER_HPP

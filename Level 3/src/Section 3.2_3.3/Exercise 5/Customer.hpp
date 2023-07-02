//
// An exemplar class that produces Customers to a ConcurrentQueue. The ConcurrentQueue is wrapped in a
// std::shared_ptr because it is shared between Customer and consumer threads that write
// and read from the shared queue.
//
// @Note - This Producer (aka Customer) is specialized for std::string. It is not CopyConstructible,
// CopyAssignable, or MoveAssignable. It is, however, MoveConstructible to comply with the std::thread protocol.
//
// Created by Michael Lewis on 6/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CUSTOMER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CUSTOMER_HPP

#include <memory>

#include "ConcurrentQueue.hpp"

class Customer
{
private:
    std::shared_ptr<ConcurrentQueue<std::string>> queue;

public:
    Customer() = delete;
    explicit Customer(std::shared_ptr<ConcurrentQueue<std::string>> queue);
    Customer(const Customer& source) = delete;
    Customer(Customer&& source) noexcept = default;
    ~Customer() = default;

    // Operator overloads
    Customer& operator=(const Customer& source) = delete;
    Customer& operator=(Customer&& source) noexcept = delete;
    void operator()();
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CUSTOMER_HPP

//
// A derived Exception object that is thrown when a customer attempts to withdraw without sufficient funds
//
// Note - This Exception is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/9/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NOFUNDSEXCEPTION_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_NOFUNDSEXCEPTION_HPP

#include "Exception.hpp"

class NoFundsException : public Exception
{
public:
    NoFundsException() = default;
    NoFundsException(const NoFundsException& other) = default;
    NoFundsException(NoFundsException&& other) = default;
    ~NoFundsException() override = default;

    // Operator Overloads
    NoFundsException& operator=(const NoFundsException& other) = default;
    NoFundsException& operator=(NoFundsException&& other) = default;

    std::string getMessage() const override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_NOFUNDSEXCEPTION_HPP

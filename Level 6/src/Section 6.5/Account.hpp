//
// An abstract base class that is implemented by the account proxy and other concrete accounts
//
// Note - This account cannot be copied, moved, or assigned to prevent accidental or purposeful
// operations on an account.
//
// Created by Michael Lewis on 8/9/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_ACCOUNT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_ACCOUNT_HPP

#include "NoFundsException.hpp"

class Account
{
public:
    Account() = default;
    Account(const Account& other) = delete;
    Account(Account&& other) = delete;
    virtual ~Account() = default;

    // Operator overloads
    Account& operator=(const Account& other) = delete;
    Account& operator=(const Account&& other) = delete;

    // Core functionality
    virtual void withdraw(double amount) = 0;
    virtual double getBalance() = 0;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_ACCOUNT_HPP

//
// An interface for the actual account. Provides clients with the ability to withdraw funds or query the
// current balance of the account.
//
// Note - This account is not copy or move constructable. Nor is it copy or move assignable. This is intended to
// unintentional or malicious use of the account.
//
// Created by Michael Lewis on 8/9/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_REALACCOUNT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_REALACCOUNT_HPP

#include <string>

#include "Account.hpp"

class RealAccount : public Account
{
private:
    double balance;

    // Private so clients must access the balance through the ProtectedAccount proxy
    double getBalance() override;

public:
    RealAccount();
    explicit RealAccount(double initialBalance);
    RealAccount(const RealAccount& other) = delete;
    RealAccount(RealAccount&& other) = delete;
    ~RealAccount() override = default;

    // Operator Overloads
    RealAccount& operator=(const RealAccount& other) = delete;
    RealAccount& operator=(RealAccount&& other) = delete;

    // Core functionality
    void withdraw(double amount) override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_REALACCOUNT_HPP

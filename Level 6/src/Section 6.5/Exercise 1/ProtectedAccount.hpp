//
// A proxy for the actual account. Provides restricted access to the real account so that only authorized
// users may query the balance of the real account.
//
// Note - This account is not copy or move constructable. Nor is it copy or move assignable. This is intended to
// unintentional or malicious use of the account.
//
// Created by Michael Lewis on 8/9/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PROTECTEDACCOUNT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PROTECTEDACCOUNT_HPP

#include <memory>

#include "Account.hpp"

class ProtectedAccount : public Account
{
private:
    std::shared_ptr<Account> account;
    std::string password;

public:
    ProtectedAccount() = delete; // Deleted to ensure client provides a password
    ProtectedAccount(double initialBalance, std::string password);
    ProtectedAccount(const ProtectedAccount& other) = delete;
    ProtectedAccount(ProtectedAccount&& other) = delete;
    ~ProtectedAccount() override = default;

    // Operator Overloads
    ProtectedAccount& operator=(const ProtectedAccount& other) = delete;
    ProtectedAccount& operator=(ProtectedAccount& other) = delete;

    // Core functionality
    void withdraw(double amount) override;
    double getBalance() override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_PROTECTEDACCOUNT_HPP

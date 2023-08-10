//
// A proxy for the actual account. Provides restricted access to the real account so that only authorized
// users may query the balance of the real account.
//
// Note - This account is not copy or move constructable. Nor is it copy or move assignable. This is intended to
// unintentional or malicious use of the account.
//
// Created by Michael Lewis on 8/9/23.
//

#include <iostream>
#include <utility>

#include "Account.hpp"
#include "RealAccount.hpp"
#include "ProtectedAccount.hpp"
#include "NoAccessException.hpp"

/**
 * Overloaded ctor. Clients can initialize a RealAccount with a non-zero balance
 * @param initialBalance The initial balance for this account
 * @param password The password used to protect access to viewing the balance of the account
 * @throws invalid_argument If initial balance is negative
 */
ProtectedAccount::ProtectedAccount(double initialBalance, std::string password)
    : Account(), password{std::move(password)}, account(new RealAccount{initialBalance})
{

}

/**
 * Allows a client to withdraw funds from the account if funds are available. If the withdraw request exceeds
 * the current balance, then a NoFundsException is thrown
 * @param amount The amount to withdraw
 * @throws NoFundsException Indicates that the withdraw request exceeds the current account balance
 */
void ProtectedAccount::withdraw(double amount)
{
    account->withdraw(amount);
}

/**
 * Reads the current balance of the account. Requires privileged access to read the balance. This overridden
 * function is private to prevent clients from accessing the balance without providing the correct password first
 * @return The current balance of the account
 * @throws NoAccessException Indicates that the current user does not have permission to read the balance
 */
double ProtectedAccount::getBalance()
{
    // Read in user password to validate if this user can access the balance
    std::string pwd;
    std::cout << "Enter password: ";
    std::cin >> pwd;

    if (pwd.empty() || password != pwd) throw NoAccessException();
    else return account->getBalance();
}
//
// An interface for the actual account. Provides clients with the ability to withdraw funds or query the
// current balance of the account.
//
// Note - This account is not copy or move constructable. Nor is it copy or move assignable. This is intended to
// unintentional or malicious use of the account.
//
// Created by Michael Lewis on 8/9/23.
//

#include <stdexcept>
#include <string>

#include "Account.hpp"
#include "RealAccount.hpp"
#include "NoFundsException.hpp"

/**
 * Default ctor. Initializes the balance to zero
 */
RealAccount::RealAccount() : Account(), balance{0}
{

}

/**
 * Overloaded ctor. Clients can initialize a RealAccount with a non-zero balance
 * @param initialBalance The initial balance for this account
 * @throws invalid_argument If initial balance is negative
 */
RealAccount::RealAccount(double initialBalance) : Account(), balance{initialBalance}
{
    if (initialBalance < 0) throw std::invalid_argument("Initial balance must be greater than or equal to zero");
}

/**
 * Allows a client to withdraw funds from the account if funds are available. If the withdraw request exceeds
 * the current balance, then a NoFundsException is thrown
 * @param amount The amount to withdraw
 * @throws NoFundsException Indicates that the withdraw request exceeds the current account balance
 */
void RealAccount::withdraw(double amount)
{
    if ((balance - amount) < 0) throw NoFundsException();
    else balance -= amount;
}

/**
 * Reads the current balance of the account
 * @return The current balance of the account
 */
double RealAccount::getBalance()
{
    return balance;
}
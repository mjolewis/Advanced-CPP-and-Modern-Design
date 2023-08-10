//
// Simple test case to illustrate the Proxy Pattern.
//
// Created by Michael Lewis on 8/9/23.
//

#include <iostream>

#include "Exception.hpp"
#include "ProtectedAccount.hpp"

// Get the account balance. The user must enter the correct password to see the balance
void test_GetBalance()
{
    std::cout << "\n*** Test GetBalance ***" << std::endl;

    try
    {
        ProtectedAccount protectedAccount(100, "password");
        double balance = protectedAccount.getBalance();
        std::cout << "Current Balance: $" << balance << std::endl;
    }
    catch(const Exception& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Ensure password functionality by entering the incorrect password when reading the balance
void test_GetBalance_NoAccess()
{
    std::cout << "\n*** Test No Access to GetBalance ***" << std::endl;

    try
    {
        ProtectedAccount protectedAccount(100, "password");
        double balance = protectedAccount.getBalance();
        std::cout << "Current Balance: $" << balance << std::endl;
    }
    catch(const Exception& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// View the starting balance by entering the correct password. Create a withdrawal request and enter the
// correct password again to view the new balance
void test_Withdraw()
{
    std::cout << "\n*** Test Withdraw ***" << std::endl;

    try
    {
        ProtectedAccount protectedAccount(100, "password");
        double balance = protectedAccount.getBalance();
        std::cout << "Starting Balance: $" << balance << std::endl;

        double withdrawRequest;
        std::cout << "Amount to Withdraw: ";
        std::cin >> withdrawRequest;
        protectedAccount.withdraw(withdrawRequest);

        balance = protectedAccount.getBalance();
        std::cout << "New Balance: $" << balance << std::endl;
    }
    catch(const Exception& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Attempt to withdraw more funds than are available
void test_Withdraw_InsufficientFunds()
{
    std::cout << "\n*** Test Withdraw - Insufficient Funds ***" << std::endl;

    try
    {
        ProtectedAccount protectedAccount(100, "password");

        double withdrawRequest;
        std::cout << "Amount to Withdraw: ";
        std::cin >> withdrawRequest;
        protectedAccount.withdraw(withdrawRequest);
    }
    catch(const Exception& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Try to create an account with a negative balance to ensure that it can't be created with an initial value of
// less than zero
void test_invalidInitialBalance()
{
    std::cout << "\n*** Test Invalid Initial Balance ***" << std::endl;

    try
    {
        ProtectedAccount protectedAccount(-100, "password");
    }
    catch(const Exception& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    test_GetBalance();
    test_GetBalance_NoAccess();
    test_Withdraw();
    test_Withdraw_InsufficientFunds();
    test_invalidInitialBalance();

    return 0;
}
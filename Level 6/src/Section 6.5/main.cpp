//
// Simple test case to illustrate the Proxy Pattern.
//
// Created by Michael Lewis on 8/9/23.
//

#include <iostream>

#include "NoAccessException.hpp"
#include "NoFundsException.hpp"
#include "ProtectedAccount.hpp"

void test_GetBalance()
{
    std::cout << "*** Test GetBalance ***" << std::endl;

    ProtectedAccount protectedAccount(100, "password");

    try
    {
        std::cout << "Current Balance: $" << protectedAccount.getBalance("password") << std::endl;
    }
    catch(const NoAccessException& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void test_GetBalance_NoAccess()
{
    std::cout << "*** Test No Access to GetBalance ***" << std::endl;

    ProtectedAccount protectedAccount(100, "password");

    try
    {
        std::cout << "Current Balance: $" << protectedAccount.getBalance("fake password") << std::endl;
    }
    catch(const NoAccessException& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void test_Withdraw()
{
    std::cout << "*** Test Withdraw ***" << std::endl;

    try
    {
        ProtectedAccount protectedAccount(100, "password");

        std::cout << "Current Balance: $" << protectedAccount.getBalance("password") << std::endl;
        std::cout << "Withdraw Request: $50" << std::endl;
        protectedAccount.withdraw(50);
        std::cout << "New Balance: $" << protectedAccount.getBalance("password") << std::endl;
    }
    catch(const NoFundsException& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void test_Withdraw_InsufficientFunds()
{
    std::cout << "*** Test Withdraw - Insufficient Funds ***" << std::endl;

    try
    {
        ProtectedAccount protectedAccount(100, "password");

        std::cout << "Current Balance: $" << protectedAccount.getBalance("password") << std::endl;
        std::cout << "Withdraw Request: $150" << std::endl;
        protectedAccount.withdraw(150);
        std::cout << "New Balance: $" << protectedAccount.getBalance("password") << std::endl;
    }
    catch(const NoFundsException& e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void test_invalidInitialBalance()
{
    std::cout << "*** Test Invalid Initial Balance ***" << std::endl;

    try
    {
        ProtectedAccount protectedAccount(-100, "password");

        std::cout << "Current Balance: $" << protectedAccount.getBalance("password") << std::endl;
        std::cout << "Withdraw Request: $50" << std::endl;
        protectedAccount.withdraw(50);
        std::cout << "New Balance: $" << protectedAccount.getBalance("password") << std::endl;
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
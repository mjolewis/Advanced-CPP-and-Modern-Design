//
// Created by Michael Lewis on 6/11/23.
//

#include "Client.hpp"
#include "ClientUsingAlias.hpp"

/**
 * Test client where storage is implemented using C++98 approach with
 * typedef and a data storage ADT to implement the templating
 */
void test_Client_Typedef()
{
    // Client of storage using typedef (C++ 98)
    int n = 10; int val = 2;
    Client<int> myClient(n, val); myClient.print();
}

/**
 * Test client where storage is implemented using an alias template
 */
void test_Client_Alias()
{
    // Client of storage using alias templates (Modern C++)
    int n = 10; int val = 2;
    ClientUsingAlias<int> myClient(n, val); myClient.print();
}

int main()
{
    test_Client_Typedef();
    test_Client_Alias();
    return 0;
}
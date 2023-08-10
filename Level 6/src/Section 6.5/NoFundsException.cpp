//
// A derived Exception object that is thrown when a customer attempts to withdraw without sufficient funds
//
// Note - This Exception is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/9/23.
//

#include "NoFundsException.hpp"
#include "Exception.hpp"

/**
 * Default ctor
 */
//NoFundsException::NoFundsException() : Exception()
//{
//
//}

/**
 * Overridden function used to indicate cause of the exception
 * @return A message indicating why the exception occurred
 */
std::string NoFundsException::getMessage() const
{
    return "Insufficient funds.";
}

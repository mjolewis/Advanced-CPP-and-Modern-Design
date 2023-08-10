//
// A derived Exception object that is thrown when the client has no permission to access the GetBalance() method.
//
// Note - This Exception is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/9/23.
//

#include "NoAccessException.hpp"
#include "Exception.hpp"

/**
 * Default ctor
 */
NoAccessException::NoAccessException() : Exception()
{

}

/**
 * Overridden function used to indicate cause of the exception
 * @return A message indicating why the exception occurred
 */
std::string NoAccessException::getMessage() const
{
    return "Permission denied.";
}
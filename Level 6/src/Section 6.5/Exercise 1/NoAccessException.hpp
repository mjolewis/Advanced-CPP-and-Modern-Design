//
// A derived Exception object that is thrown when the client has no permission to access the GetBalance() method.
//
// Note - This Exception is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/9/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NOACCESSEXCEPTION_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_NOACCESSEXCEPTION_HPP

#include <string>

#include "Exception.hpp"

class NoAccessException : public Exception
{
public:
    NoAccessException();
    NoAccessException(const NoAccessException& other) = delete;
    NoAccessException(NoAccessException&& other) = delete;
    ~NoAccessException() override = default;

    // Operator Overloads
    NoAccessException& operator=(const NoAccessException& other) = delete;
    NoAccessException& operator=(NoAccessException&& other) = delete;

    std::string getMessage() const override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_NOACCESSEXCEPTION_HPP

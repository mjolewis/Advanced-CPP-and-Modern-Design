//
// A base exception class.
//
// Note - This Exception is not copy or move constructable. Nor is it copy or move assignable. Its purpose
// is to act as an interface for derived classes and, as a result, does not need to support these capabilities
//
// Created by Michael Lewis on 8/9/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_EXCEPTION_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_EXCEPTION_HPP

#include <string>

class Exception
{
public:
    Exception() = default;
    Exception(const Exception& other) = delete;
    Exception(Exception&& other) = delete;
    virtual ~Exception() = default;

    // Operator Overloads
    Exception& operator=(const Exception& other) = delete;
    Exception& operator=(Exception&& other) = delete;

    // Pure virtual member function that will be implemented in derived classes.
    virtual std::string getMessage() const = 0;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_EXCEPTION_HPP

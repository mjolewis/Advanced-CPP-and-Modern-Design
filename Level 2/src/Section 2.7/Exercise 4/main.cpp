//
// Illustrate platform dependent error codes using std::error_code.
// This differs from the platform independent errors within std::error_condition
//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>
#include <system_error>
#include <tuple>

// Create and return properties of an error code inside of a tuple
std::tuple<std::string, int, std::string> getErrorProperties()
{
    std::error_code errorCode{3, std::generic_category()};
    return std::make_tuple(errorCode.message(), errorCode.value(), std::string{errorCode.category().name()});
}

int main()
{
    {
        // Part A - Create a default error code along with a platform dependent error code with value and category
        std::error_code defaultErrorCode{};
        std::error_code eCode{2, std::generic_category()};
        std::cout << defaultErrorCode.message() << std::endl;
        std::cout << eCode.message() << " | " << std::string{eCode.category().name()} << std::endl;
    }

    {
        // Part B - Unpack a tuple containing error code properties using std::tie
        std::string message;
        int code;
        std::string category;
        std::tie(message, code, category) = getErrorProperties();
        std::cout << message << std::endl;
        std::cout << code << std::endl;
        std::cout << category << std::endl;
    }

    {
        // Part C - Test equality of error codes and error conditions
        std::error_code eCode{2, std::generic_category()};
        std::error_condition eCondition(2, std::generic_category());
        std::cout << std::boolalpha << (eCode == eCondition) << std::endl;
        std::cout << std::boolalpha << (eCode != eCondition) << std::endl;

        std::error_code eCode1{4, std::iostream_category()};
        std::error_condition eCondition1(2, std::generic_category());
        std::cout << std::boolalpha << (eCode1 == eCondition1) << std::endl;
        std::cout << std::boolalpha << (eCode1 != eCondition1) << std::endl;
    }

    return 0;
}
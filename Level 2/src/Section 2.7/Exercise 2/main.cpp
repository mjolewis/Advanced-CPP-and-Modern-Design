//
// Illustrate how to interface with std::error_condition
//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>
#include <system_error>
#include <tuple>

// Create and return properties of an error condition in a tuple
std::tuple<std::string, int, std::string> getErrorProperties()
{
    std::error_condition errc{std::make_error_condition(std::errc::no_such_file_or_directory)};
    return std::make_tuple(errc.message(), errc.value(), std::string{errc.category().name()});
}

int main()
{
    // Part A - Create a default error condition, a platform independent error category with value and category
    // and an error_condition based on std::errc
    std::error_condition defaultError{};
    std::error_condition value{2, std::generic_category()};
    std::error_condition errc{std::make_error_condition(std::errc::no_such_file_or_directory)};
    std::cout << defaultError.message() << std::endl;
    std::cout << value.message() << std::endl;
    std::cout << errc.message() << std::endl;

    // Part B - Unpack a tuple containing error condition properties
    auto errorProps = getErrorProperties();
    std::cout << "error message=" << std::get<0>(errorProps) << std::endl;
    std::cout << "error code=" << std::get<1>(errorProps) << std::endl;
    std::cout << "error category=" << std::get<2>(errorProps) << std::endl;
    return 0;
}
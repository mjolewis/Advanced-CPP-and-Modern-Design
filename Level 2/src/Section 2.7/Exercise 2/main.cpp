//
// Illustrate how to interface with std::error_condition
//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>
#include <system_error>
#include <string>
#include <tuple>

std::tuple<std::string, int, std::string> getErrorProperties()
{
    std::error_condition errc{std::make_error_condition(std::errc::no_such_file_or_directory)};
    return std::make_tuple(errc.message(), errc.value(), std::string{errc.category().name()});
}

int main()
{
    std::cout << "*** Start Part A ***" << std::endl;
    std::error_condition defaultError{};
    std::error_condition value{2, std::generic_category()};
    std::error_condition errorCategory{std::generic_category().default_error_condition(EDOM)};
    std::error_condition errc{std::make_error_condition(std::errc::no_such_file_or_directory)};
    std::cout << defaultError.message() << std::endl;
    std::cout << value.message() << std::endl;
    std::cout << errorCategory.message() << std::endl;
    std::cout << errc.message() << std::endl;
    std::cout << "*** End Part A ***" << std::endl;

    std::cout << "*** Start Part B ***" << std::endl;
    auto errorProps = getErrorProperties();
    std::cout << "error message=" << std::get<0>(errorProps) << std::endl;
    std::cout << "error code=" << std::get<1>(errorProps) << std::endl;
    std::cout << "error category=" << std::get<2>(errorProps) << std::endl;
    std::cout << "*** End Part B ***" << std::endl;
    return 0;
}
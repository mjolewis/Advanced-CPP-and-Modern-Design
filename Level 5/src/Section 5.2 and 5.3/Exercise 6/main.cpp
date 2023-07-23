//
// Illustrate ECMAScript Grammar
//
// Created by Michael Lewis on 7/23/23.
//

#include <optional>
#include <iostream>
#include <regex>

/* Part A - What kind of numbers does the regex subsume?
 * Regex: {"((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?"};
 * ((\+|-)? -> optional positive or negative sign
 * [[:digit:]]+) -> one or more digits
 * (\.(([[:digit:]]+)?)) -> optionally one or more digit
 * (e|E) e or E
 * [[:digit:]]+)? -> optionally one or more digit
 * EXAMPLE: 123e10 | +123E10 | -123E10
 */

// Part B & C - Test the kinds of numbers subsumed by a given regex and convert them to double
// Use an optional to handle scenarios where the input string doesn't match the regex
std::optional<double> test_subsume_numbers(const std::string& number)
{
    std::regex ecmaReg{"((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?"};

    std::smatch match;
    bool is_match = std::regex_search(number, match, ecmaReg);
    return is_match ? std::optional<double>{std::stod(match[0])} : std::nullopt;
}

int main()
{
    std::optional<double> num1 = test_subsume_numbers("+123e10");
    if (num1.has_value()) std::cout << num1.value() << std::endl;

    std::optional<double> num2 = test_subsume_numbers("-123e10");
    if (num2.has_value()) std::cout << num2.value() << std::endl;

    std::optional<double> num3 = test_subsume_numbers("-123E10");
    if (num3.has_value()) std::cout << num3.value() << std::endl;

    std::optional<double> num4 = test_subsume_numbers("123E10");
    if (num4.has_value()) std::cout << num4.value() << std::endl;

    std::optional<double> num5 = test_subsume_numbers("1E9");
    if (num5.has_value()) std::cout << num5.value() << std::endl;

    std::optional<double> num6 = test_subsume_numbers("1E9");
    if (num6.has_value()) std::cout << num6.value() << std::endl;

    // No value printed to console because input string is not a number
    std::optional<double> num7 = test_subsume_numbers("dummy test");
    if (num7.has_value()) std::cout << num7.value() << std::endl;

    return 0;
}
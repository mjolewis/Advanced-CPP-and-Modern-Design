//
// Illustrate basic ways to classify strings using boost string algorithm and it's related
// predicates.
//
// Created by Michael Lewis on 7/22/23.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

#include <boost/algorithm/string.hpp>

// Part A - Consider the string std::string str1(" abd1 234\*").
// Test the string contains at least some characters that are either digits or letters
void test_recongize_digits_or_letters()
{
    std::string s1{" abd1 234\*"};
    std::cout << std::boolalpha << boost::all(s1, boost::is_alnum() || boost::is_any_of(" \*")) << std::endl;
}

// Part A - Consider the string std::string str1(" abd1 234\*").
// Test the string contains a few characters that may be digits but there are no letters
void test_recognize_digits_not_letters()
{
    std::string s1{" abd1 234\*"};
    std::cout << std::boolalpha << boost::all(s1, boost::is_digit()
                                               && !boost::is_alpha()
                                               || boost::is_any_of(" \*")) << std::endl;
}

// Part A - Consider the string std::string str1(" abd1 234\*").
// Test the string contains at least some characters that are in the range ['a', 'z'] (case sensitive)
void test_recognize_characters()
{
    std::string s1{" abd1 234\*"};
    std::cout << std::boolalpha << boost::all(s1, boost::is_alpha()
                                               && boost::is_lower()
                                               || boost::is_digit()
                                               || boost::is_any_of(" \*")) << std::endl;
}

// Part B - Validates that the incoming string meets the password requirements
// Requirements are:
// It must contain at least 8 characters.
// It must contain a combination of digits and characters.
// At least one character must be upper case.
// No control characters allowed.
// No spaces allowed.
std::pair<bool, std::string> password_validator(const std::string& password)
{
    if (password.length() < 8)
    {
        return std::make_pair<bool, std::string>(false, "Password length must be 8 characters or more");
    }

    if (!std::any_of(password.cbegin(), password.cend(), boost::is_alpha()))
    {
        return std::make_pair<bool, std::string>(false, "Password must contain characters");
    }

    if (!std::any_of(password.cbegin(), password.cend(), boost::is_digit()))
    {
        return std::make_pair<bool, std::string>(false, "Password must contain digits");
    }

    if (!std::any_of(password.cbegin(), password.cend(), boost::is_upper()))
    {
        return std::make_pair<bool, std::string>(false, "Password must contain at least one upper case character");
    }

    if (std::any_of(password.cbegin(), password.cend(), boost::is_cntrl()))
    {
        return std::make_pair<bool, std::string>(false, "Control character not allowed");
    }

    if (std::any_of(password.cbegin(), password.cend(), boost::is_space()))
    {
        return std::make_pair<bool, std::string>(false, "Spaces not allowed");
    }

    return std::make_pair<bool, std::string>(true, "Success");
}

// Part B -  Create a simple password checker function that accepts a target string as input
// and result type of (true or false) and a string stating the cause of possible error or success.
void test_password_validator()
{
    std::string pwd1("DanielDuffy1952"); // true
    std::string pwd2("DanielDuffy");  // false
    std::string pwd3("U19520829"); // true
    std::string pwd4("19520829U"); // true
    std::string pwd5("19520829U   "); // false
    std::string pwd6("    19520829U   "); // false
    std::string pwd7("19520"); // false

    std::cout << "\n*** Password Validator ***" << std::endl;
    std::pair<bool, std::string> result1 = password_validator(pwd1);
    std::pair<bool, std::string> result2 = password_validator(pwd2);
    std::pair<bool, std::string> result3 = password_validator(pwd3);
    std::pair<bool, std::string> result4 = password_validator(pwd4);
    std::pair<bool, std::string> result5 = password_validator(pwd5);
    std::pair<bool, std::string> result6 = password_validator(pwd6);
    std::pair<bool, std::string> result7 = password_validator(pwd7);

    std::cout << result1.first << " : " << result1.second << std::endl;
    std::cout << result2.first << " : " << result2.second << std::endl;
    std::cout << result3.first << " : " << result3.second << std::endl;
    std::cout << result4.first << " : " << result4.second << std::endl;
    std::cout << result5.first << " : " << result5.second << std::endl;
    std::cout << result6.first << " : " << result6.second << std::endl;
    std::cout << result7.first << " : " << result7.second << std::endl;
}

int main()
{
    test_recongize_digits_or_letters();
    test_recognize_digits_not_letters();
    test_recognize_characters();
    test_password_validator();
    return 0;
}
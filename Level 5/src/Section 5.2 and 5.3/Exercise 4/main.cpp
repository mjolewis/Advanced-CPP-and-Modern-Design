//
// Illustrate how to use Token Iterator to process tokens from a given string
//
// Created by Michael Lewis on 7/23/23.
//

#include <iostream>
#include <regex>
#include <list>

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>

using Date = boost::gregorian::date;
using ResultSet = std::list<Date>;

// Part A & C - Extract the data 2016, 3 and 15 from this string
// and cache the results in an appropriate data structure
void test_match_between_regex()
{
    std::cout << "\n*** Match Date String ***" << std::endl;

    std::regex myReg10("/");
    std::string S3 = "2016/3/15";

    // Find all subsequences between matched regular expressions using -1
    auto it = std::sregex_token_iterator(S3.cbegin(), S3.cend(), myReg10, -1);

    std::vector<std::string> results;
    const std::string& year = *it;
    const std::string& month = *(++it);
    const std::string& day = *(++it);
    Date date(boost::lexical_cast<int>(year),
                    boost::lexical_cast<int>(month),
                    boost::lexical_cast<int>(day));

    ResultSet resultSet;
    resultSet.push_back(date);

    // Log the results
    for (const auto& result : resultSet)
    {
        std::cout << result << std::endl;
    }
}

// Part B & C - Extract ‘/’ from this string and cache the results in an appropriate data structure
void test_match_regex()
{
    std::cout << "\n*** Match Regex Exactly ***" << std::endl;

    std::regex myReg10("/");
    std::string S3 = "2016/3/15";

    // Find all subsequences that match the regular expression using 0 as the submatch flag
    auto start = std::sregex_token_iterator(S3.cbegin(), S3.cend(), myReg10, 0);
    auto end = std::sregex_token_iterator();

    std::vector<std::string> resultSet;
    for (auto it = start; it != end; ++it)
    {
        resultSet.push_back(*it);
    }

    // Log the results
    for (const auto& result : resultSet)
    {
        std::cout << result << std::endl;
    }
}

// Additional text Extract the data 2016, 3 and 15 from this string separated by hyphen and slash
// and cache the results in an appropriate data structure
void test_match_between_regex_hyphen_and_slash()
{
    std::cout << "\n*** Match Date String - Hyphen and Slash ***" << std::endl;

    std::regex myReg10("(-)|(/)"); // Hyphen or Slash
    std::string S3 = "2016-3/15";

    // Find all subsequences between matched regular expressions using -1
    auto it = std::sregex_token_iterator(S3.cbegin(), S3.cend(), myReg10, -1);

    std::vector<std::string> results;
    const std::string& year = *it;
    const std::string& month = *(++it);
    const std::string& day = *(++it);
    Date date(boost::lexical_cast<int>(year),
              boost::lexical_cast<int>(month),
              boost::lexical_cast<int>(day));

    ResultSet resultSet;
    resultSet.push_back(date);

    // Log the results
    for (const auto& result : resultSet)
    {
        std::cout << result << std::endl;
    }
}

int main()
{
    test_match_between_regex();
    test_match_regex();
    test_match_between_regex_hyphen_and_slash();
    return 0;
}
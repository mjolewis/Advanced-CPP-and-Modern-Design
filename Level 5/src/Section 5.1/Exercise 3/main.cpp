//
// Illustrate how to split and join strings.
// Illustrate basic date utilities.
//
// Created by Michael Lewis on 7/22/23.
//

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>

// Part A - Consider the string std::string sA("1,2,3,4/5/9*56").
// It has delimiters / and *. Split this string into a vector of
// strings and then join them to form the string std::string sA("1/2/3/4/5/9/56").
void test_string_split_and_join()
{
    std::string sA("1,2,3,4/5/9*56");
    std::vector<std::string> vec;

    boost::split(vec, sA, boost::is_any_of(",/*"), boost::token_compress_on);
    std::cout << "*** Split String ***" << std::endl;
    for (const auto& word : vec)
    {
        std::cout << word << ",";
    }

    std::string joined_string = boost::join(vec, "/");
    std::cout << "\n*** Joined String ***" << std::endl;
    std::cout << joined_string << std::endl;
}

// Utility function that converts a string into a date
boost::gregorian::date create_date(std::string& date)
{
    std::vector<std::string> date_parts;
    boost::split(date_parts, date, boost::is_any_of("-"), boost::token_compress_on);

    // Use Boost lexical_cast to convert strings to integers.
    int year = boost::lexical_cast<int>(date_parts.at(0));
    int month = boost::lexical_cast<int>(date_parts.at(1));
    int day = boost::lexical_cast<int>(date_parts.at(2));

    return {year, month, day};
}

// Part B - Consider a string that models dates, for example “2015-12-31”.
// Write a function that converts strings having this format into a Boost date.
void test_convert_string_to_date()
{
    std::cout << "\n*** Convert String to Date ***" << std::endl;

    std::string date_string{"2015-12-31"};
    auto date = create_date(date_string);
    std::cout << "String version: " << date_string << std::endl;
    std::cout << "Date version: " << date << std::endl;
}

// Part C - Consider a string consisting of string pairs of the form key = value
// (for example, port = 23, pin = 87, value = 34.4).
// Write a function to convert the string to an instance of std::map<std::string, double>.
// In other words, we create name-value maps .
void test_convert_string_to_map()
{
    std::cout << "\n*** Convert String to Map ***" << std::endl;

    std::string s1{"port = 23, pin = 87, value = 34.4"};
    std::remove(s1.begin(), s1.end(), ' ');
    std::vector<std::string> pairs;
    boost::split(pairs, s1, boost::is_any_of(","), boost::token_compress_on);

    std::unordered_map<std::string, double> name_value;
    for (auto pair : pairs)
    {
        std::vector<std::string> temp;
        boost::split(temp, pair, boost::is_any_of("="), boost::token_compress_on);
        name_value.insert( {temp.at(0), stod(temp.at(1))} );
    }

    for (const auto& pair : name_value)
    {
        std::cout << pair.first << "=" << pair.second << std::endl;
    }
}

int main()
{
    test_string_split_and_join();
    test_convert_string_to_date();
    test_convert_string_to_map();
    return 0;
}

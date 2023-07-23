//
// Extract key-value pairs from a string and cache the key and value into a map.
// Uses boost, STL, and regex APIs
//
// Created by Michael Lewis on 7/23/23.
//

#include <iostream>
#include <unordered_map>
#include <regex>
#include <string>

#include <boost/algorithm/string.hpp>

// Preprocess the string to eliminate all spaces
void preProcess(std::string& s)
{
    boost::erase_all(s, " ");
}

// Part A & B - Use a regex to extract a kev/value pair from a string
// and cache the results into a map
void test_extract_name_value_pair()
{
    // Part A - Use std::sregex_token_iterator to extract strings of the form “a = 1”
    std::string sA{"a = 1, b = 2, c = 3"};

    // Pre-process the string
    preProcess(sA);

    std::regex reg{","};
    auto begin = std::sregex_token_iterator(sA.cbegin(), sA.cend(), reg, -1);
    auto end = std::sregex_token_iterator();

    // Part B - Use Boost Algo split() to extract its left and right parts,
    // which will become the map’s key and the value, respectively.
    std::unordered_map<std::string, std::string> pairs;
    for (auto it = begin; it != end; ++it)
    {
        std::vector<std::string> resultSet;
        boost::split(resultSet, it->str(), boost::is_any_of("="), boost::token_compress_on);
        pairs.emplace(resultSet.at(0), resultSet.at(1));
    }

    // Log the results to the console
    for (const auto& pair : pairs)
    {
        std::cout << pair.first << ":" << pair.second << std::endl;
    }
}

int main()
{
    test_extract_name_value_pair();
    return 0;
}
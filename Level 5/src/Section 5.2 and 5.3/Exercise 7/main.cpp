//
// Basic illustration of how to use regex replace
//
// Created by Michael Lewis on 7/23/23.
//

#include <iostream>
#include <regex>

int main()
{
    // Use std::regex_replace to produce the following output:
    // Q**ck br*wn f*x

    std::string text("Quick brown fox");
    std::regex vowels("a|e|i|o|u");

    // Output iterator must meet requirements as specified by:
    // https://en.cppreference.com/w/cpp/named_req/OutputIterator
    std::regex_replace(std::ostreambuf_iterator<char>(std::cout), text.begin(), text.end(), vowels, "*");
}
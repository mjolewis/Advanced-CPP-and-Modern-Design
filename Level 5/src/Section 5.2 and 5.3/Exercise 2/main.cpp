//
// Illustrate how to search a string for subsequences using regular expressions
//
// Created by Michael Lewis on 7/23/23.
//

#include <iostream>
#include <string>
#include <regex>

// Search a string for a specific subsequence using a regular expression
void test_search_subsequence()
{
    std::regex mySearchReg("(rain)|(Spain)");
    std::string myText("The rain in Spain stays mainly on the plain");

    std::smatch match;
    bool is_match = std::regex_search(myText, match, mySearchReg);
    std::cout << std::boolalpha << is_match << " : " << match[0] << std::endl;

    std::string myText1("The Spain in rain stays mainly on the plain");
    bool is_match_1 = std::regex_search(myText1, match, mySearchReg);
    std::cout << std::boolalpha << is_match_1 << " : " << match[0] << std::endl;

    std::string myText2("The water stays mainly on the plain");
    bool is_match_2 = std::regex_search(myText2, match, mySearchReg);
    std::cout << std::boolalpha << is_match_2 << " : " << match[0] << std::endl;
}

int main()
{
    test_search_subsequence();
    return 0;
}

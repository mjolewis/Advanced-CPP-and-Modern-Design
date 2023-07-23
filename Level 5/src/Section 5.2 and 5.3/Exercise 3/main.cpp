//
// Created by Michael Lewis on 7/23/23.
//

#include <iostream>
#include <regex>
#include <set>

// Part A - C Iterator over a string using std::regex to match results and cache them into a set
void test_regex_iterators_to_strings()
{
    std::cout << "\n*** Cache Results in Set<std::string> ***" << std::endl;

    // Setup
    std::string S2 = "1,1,2,3,5,8,13,21";
    std::regex myReg("(\\d+),?");
    std::set<std::string> results;

    // Part A - Create an instance it of sregex_iterator based on S2 and myReg.
    auto start = std::sregex_iterator(S2.begin(), S2.end(), myReg);
    auto end = std::sregex_iterator();

    // Part B - Iterate over , converting its dereferenced value and inserting it into the output result.
    for (auto it = start; it != end; ++it)
    {
        const std::smatch& match = *it;
        results.insert(match.str());
    }

    // Part C - Print it and check your output
    for (const auto& result : results)
    {
        std::cout << result << std::endl;
    }
}

// Part D - Modify the code so that the output is of type std::set<int>.
void test_regex_iterators_to_ints()
{
    std::cout << "\n*** Cache Results in Set<int> ***" << std::endl;
    // Setup
    std::string S2 = "1,1,2,3,5,8,13,21";
    std::regex myReg("(\\d+),?");
    std::set<int> results;

    // Part A - Create an instance it of sregex_iterator based on S2 and myReg.
    auto start = std::sregex_iterator(S2.begin(), S2.end(), myReg);
    auto end = std::sregex_iterator();

    // Part B - Iterate over , converting its dereferenced value and inserting it into the output result.
    for (auto it = start; it != end; ++it)
    {
        const std::smatch& match = *it;
        results.insert(std::stoi(match.str()));
    }

    // Part C - Print it and check your output
    for (const auto& result : results)
    {
        std::cout << result << std::endl;
    }
}

// Additional test with alphanumeric test string while converting matches into a std::set<int>
void test_regex_iterators_with_alphanumeric()
{
    std::cout << "\n*** Cache Results in Set<int> - Alphanumeric ***" << std::endl;
    // Setup
    std::string S2 = "1,1,2,3,5,8,13,21,a,b,c";
    std::regex myReg("(\\d+),?");
    std::set<int> results;

    // Part A - Create an instance it of sregex_iterator based on S2 and myReg.
    auto start = std::sregex_iterator(S2.begin(), S2.end(), myReg);
    auto end = std::sregex_iterator();

    // Part B - Iterate over , converting its dereferenced value and inserting it into the output result.
    for (auto it = start; it != end; ++it)
    {
        const std::smatch& match = *it;
        results.insert(std::stoi(match.str()));
    }

    // Part C - Print it and check your output
    for (const auto& result : results)
    {
        std::cout << result << std::endl;
    }
}

int main()
{
    test_regex_iterators_to_strings();
    test_regex_iterators_to_ints();
    test_regex_iterators_with_alphanumeric();
    return 0;
}
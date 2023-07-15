//
// Write custom non-modifying algorithms to illustrate common problems that can be solved by
// non-modifying algorithms.
//
// Created by Michael Lewis on 7/14/23.
//

#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
#include <numeric>
#include <tuple>
#include <vector>

using Vector = std::vector<int>;
using namespace std::placeholders; // used for std::bind

// Part A - Count the frequency of each value in a container.
// For example, for {1,2,4,5,4,1} we get the output {{1,2}, {2,1}, {4,2}, {5,1}}.
void test_frequency()
{
    Vector vec{1,2,4,5,4,1};
    std::map<int, int> map;

    for (int & key : vec)
    {
        if (map.contains(key)) map.at(key)++;
        else (map.emplace(std::make_pair(key, 1)));
    }

    std::cout << "{";
    for (auto pair : map)
    {
        std::cout << "{" << pair.first << ", " << pair.second << "}, ";
    }
    std::cout << "}" << std::endl;
}

// Calculate stats on a container
std::tuple<double, double, double, double> stats(const Vector& vec)
{
    auto [min, max] = std::minmax_element(vec.cbegin(), vec.cend());
    auto sum = std::accumulate(vec.cbegin(), vec.cend(), 0);
    return std::make_tuple(*min, *max, sum, sum / vec.size());
}

// Part B - Write a function to compute the minimum, maximum, sum and average of the
// values of the elements in a container with numeric values. The output is a tuple with four fields.
void test_container_stats()
{
    Vector vec{1,2,4,5,4,10};
    auto result = stats(vec);
    double min, max, sum, avg;
    std::tie(min, max, sum, avg) = result;
    std::cout << "Min=" << min << ", Max=" << max << ", sum=" << sum << ", avg=" << avg << std::endl;
}

// Part C - Use an STL algorithm to find the first occurrence of the value 5 in S = {1,2,-3,4,5,5,5,6}
void test_first_occurrence()
{
    Vector vec = {1,2,-3,4,5,5,5,6};
    auto pos_of_five = std::distance(vec.cbegin(), std::find(vec.cbegin(), vec.cend(), 5));
    std::cout << "First occurrence of 5: index=" << pos_of_five << std::endl;
}

// Helper function used by std::bind and std::bind2nd function to find an even number
bool is_even(int element)
{
    return element % 2 == 0;
}

// Part C - Use: std::bind2nd() to find the position of the first even number in S = {1,2,-3,4,5,5,5,6}
void test_std_bind2nd()
{
    // https://quantnet.com/threads/3-o-c-17-has-removed-std-random_shuffle.49220/
    // Per the link above we are supposed to be using C++17 and above. std::bind2nd() was
    // removed in C++17. Instead, we should be using std::bind or lambda as show below.
}

// Part C - Use std::bind() to find the position of the first even number in S = {1,2,-3,4,5,5,5,6}
void test_std_bind()
{
    Vector vec{1,2,-3,4,5,5,5,6};
    auto callable = std::bind(is_even, _1);
    auto it = std::find_if(vec.cbegin(), vec.cend(), callable);
    std::cout << "std::bind: Position of first even number is: " << std::distance(vec.cbegin(), it) << std::endl;
}

// Part C - Use Lambda expression to find the position of the first even number in S = {1,2,-3,4,5,5,5,6}
void test_lambda()
{
    Vector vec{1,2,-3,4,5,5,5,6};
    auto it = std::find_if(vec.cbegin(), vec.cend(), [](int element) { return element % 2 == 0; });
    std::cout << "Lambda: Position of first even number is: " << std::distance(vec.cbegin(), it) << std::endl;
}

// Part D - Consider the container S = {1,2,5,5,-3,4,5,5,5,6,3,4,5}. Determine how to do the following:
// Return the position of the first three consecutive elements having the value 5.
void test_consecutive_values()
{
    Vector vec{1,2,5,5,-3,4,5,5,5,6,3,4,5};
    auto it = std::search_n(vec.cbegin(), vec.cend(), 3, 5);
    long firstIdx = std::distance(vec.cbegin(), it);
    long secondIdx = firstIdx + 1;
    long thirdIdx = secondIdx + 1;
    // Package the result
    std::tuple<long, long, long> indices = std::make_tuple(firstIdx, secondIdx, thirdIdx);

    std::cout << "Consecutive indices of 5. First Index=" << firstIdx << ", Second Index=" << secondIdx
    << ", Third Index=" << thirdIdx << std::endl;
}

// Part D - Consider the container S = {1,2,5,5,-3,4,5,5,5,6,3,4,5}. Determine how to do the following:
// Return the position of the first element of the first subrange matching {3,4,5}.
// Note - Uses a std::boyer_moore_searcher to find the needle in the haystack
void test_matching_first_in_subrange()
{
    Vector haystack{1,2,5,5,-3,4,5,5,5,6,3,4,5};
    Vector needle{3,4,5};
    auto it = std::search(haystack.cbegin(), haystack.cend(),
                          std::boyer_moore_searcher(needle.cbegin(), needle.cend()));
    long firstIdx = std::distance(haystack.cbegin(), it);

    std::cout << "Position of first element for the first subrange 345. First Index=" << firstIdx << std::endl;
}

// Part D - Consider the container S = {1,2,5,5,-3,4,5,5,5,6,3,4,5}. Determine how to do the following:
// Return the position of the first element of the last subrange matching {3,4,5}.
// Note - Uses a std::boyer_moore_searcher to find the needle in the haystack while iterating in reverse order
void test_matching_last_in_subrange()
{
    Vector haystack{1,2,5,5,-3,4,5,5,5,6,3,4,5};
    Vector needle{3,4,5};

    // Reverse iterate
    auto it = std::search(haystack.rbegin(), haystack.rend(),
                          std::boyer_moore_searcher(needle.rbegin(), needle.rend()));

    // Move iterator to sit on the first element of the needle
    std::advance(it, needle.size());
    long firstIdx = std::distance(it, haystack.rend());

    std::cout << "Position of first element for last subrange matching 345. First Index=" << firstIdx << std::endl;
}

// Part E - Consider the container S = {1,2,5,5,-3,4,5,5,5,6,3,4,5}.
// Find the first element in S that has a value equal to the value of the following element.
void test_equal_sequential_elements()
{
    Vector vec{1,2,5,5,-3,4,5,5,5,6,3,4,5};
    auto it = std::adjacent_find(vec.cbegin(), vec.cend());
    long firstIdx = std::distance(vec.cbegin(), it);
    std::cout << "Position of first element whose value is equal to following element. First Index=" << firstIdx << std::endl;
}

// Part F - Consider the container S = {1,2,5,5,-3,4,5,5,5,6,3,4,5} and S1 = {1,2,5}.
// Determine whether the elements in S1 are equal to the elements in S.
void test_includes()
{
    Vector S{1,2,5,5,-3,4,5,5,5,6,3,4,5};
    Vector s1{1,2,5};
    std::cout << std::boolalpha << "Is S1 included in S? "
    << std::includes(S.cbegin(), S.cend(), s1.cbegin(), s1.cend()) << std::endl;
}

int main()
{
    test_frequency();
    test_container_stats();
    test_first_occurrence();
    test_std_bind2nd();
    test_std_bind();
    test_lambda();
    test_consecutive_values();
    test_matching_first_in_subrange();
    test_matching_last_in_subrange();
    test_equal_sequential_elements();
    test_includes();
    return 0;
}
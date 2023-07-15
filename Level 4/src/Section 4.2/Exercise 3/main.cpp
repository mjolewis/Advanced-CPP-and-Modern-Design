//
// Deep dive into classifying algorithms as provided by the standard algorithm library.
//
// Created by Michael Lewis on 7/14/23.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using Vector = std::vector<int>;

// Part A - Scale all values by a given factor.
void test_scale_values()
{
    // What is algorithm input?
    // Response: Begin and end iterator and a predicate
    // What is the output?
    // Response: Output iterator to the element that follows the last element transformed.
    // Is the input modified on output?
    // Response: Yes
    // Which category does the algorithm belong to?
    // Response: Modifying

    Vector vec{1, 2, 3};
    Vector destination(3);
    std::transform(vec.cbegin(), vec.cend(),
                   destination.begin(),
                   [](int element) { return element * 2; });

    std::cout << "Scale Values:";
    for (auto element : destination)
    {
        std::cout << element << ", ";
    }
}

// Part B - Count the number of elements whose values are in a given range.
void test_count_elements()
{
    // What is algorithm input?
    // Response: Begin and end iterator and or a unary predicate
    // What is the output?
    // Response: The number of elements satisfying specific criteria
    // Is the input modified on output?
    // Response: No
    // Which category does the algorithm belong to?
    // Response: Non-Modifying

    Vector vec{1, 2, 3};
    auto count = std::count_if(vec.cbegin(), vec.cend(), [](int element) { return element > 1; });

    std::cout << "\nCount Values > 1: " << count << std::endl;
}

// Part C - Find the average, minimum and maximum values in a container.
void test_average()
{
    // What is algorithm input?
    // Response: Begin and end iterator and optionally a custom comparator)
    // What is the output?
    // Response: A std::pair of the smallest and largest element in a range
    // Is the input modified on output?
    // Response: No
    // Which category does the algorithm belong to?
    // Response: Non-Modifying + Numeric

    Vector vec{1, 2, 3};
    auto [min, max] = std::minmax_element(vec.cbegin(), vec.cend());
    auto average = std::accumulate(vec.cbegin(), vec.cend(), 0) / vec.size();
    std::cout << "Min=" << *min << ", Max=" << *max << ", Average=" << average << std::endl;
}

// Part D - Find the first element that is (that is not) in a range.
void test_find_value_in_and_out_of_range()
{
    // What is algorithm input?
    // Response: Begin and end iterator and a target value or unary predicate
    // What is the output?
    // Response: The first iterator in the range satisfying the requirement
    // Is the input modified on output?
    // Response: No
    // Which category does the algorithm belong to?
    // Response: Non-Modifying

    Vector vec{1, 2, 3};
    auto find = std::find(vec.cbegin(), vec.cend(), 2);
    auto find_if_not = std::find_if_not(vec.cbegin(), vec.cend(), [](int element) { return element < 3; });
    std::cout << std::boolalpha << "Was 2 found? " << (find != vec.cend())
    << " Is any element not less than 3? " << (find_if_not != vec.cend()) << std::endl;
}

// Part E - Search for all occurrences of ‘3456’ in the container.
void test_occurrences()
{
    // What is algorithm input?
    // Response: Begin and end iterator for the range to be searched along with a target value
    // What is the output?
    // Response: Returns the number of elements in the range
    // Is the input modified on output?
    // Response: No
    // Which category does the algorithm belong to?
    // Response: Non-Modifying

    Vector vec1{3456, 0, 3456, 0, 3456, 0};

    auto result = std::count(vec1.cbegin(), vec1.cend(), 3456);
    std::cout << std::boolalpha << "There are N occurrences of 3456: N=? " << result << std::endl;
}

// Part F - Determine if the elements in two ranges are equal.
void test_equal_elements()
{
    // What is algorithm input?
    // Response: Begin and end iterator for the two ranges to compare and optionally a custom predicate for comparison
    // What is the output?
    // Response: bool value specifying if the two ranges are equal
    // Is the input modified on output?
    // Response: No
    // Which category does the algorithm belong to?
    // Response: Non-Modifying

    Vector vec1{1, 2, 3};
    Vector vec2{1, 2, 3};
    auto equal = std::equal(vec1.cbegin(), vec1.cend(),
                            vec2.cbegin(), vec2.cend());

    std::cout << std::boolalpha << "Are the elements in two ranges equal? " << equal << std::endl;
}

// Part G - Determine if a set is some permutation of ‘12345’.
void test_is_permutation()
{
    // What is algorithm input?
    // Response: There are multiple overloads, but generally a begin and end iterator for the two ranges
    // to compare and optionally a custom binary predicate
    // What is the output?
    // Response: bool value specifying if there exists a permutation that makes the two ranges equal
    // Is the input modified on output?
    // Response: No
    // Which category does the algorithm belong to?
    // Response: Mutating

    std::set<int> set1{1, 2, 3, 4, 5};
    std::set<int> set2{5, 4, 3, 2, 1};
    auto permutation = std::is_permutation(set1.cbegin(), set1.cend(),
                                           set2.cbegin(), set2.cend());

    std::cout << std::boolalpha << "Does a permutation exist? " << permutation << std::endl;
}

// Part H - Is a container already sorted
void test_is_sorted()
{
    // What is algorithm input?
    // Response: A begin and end iterator for the two ranges and optionally a custom comparator and
    // execution policy
    // What is the output?
    // Response: bool value specifying if the range is already sorted
    // Is the input modified on output?
    // Response: No
    // Which category does the algorithm belong to?
    // Response: Non-Modifying

    Vector vec1{1, 2, 3};
    auto sorted = std::is_sorted(vec1.cbegin(), vec1.cend());

    std::cout << std::boolalpha << "Are the elements sorted? " << sorted << std::endl;
}

// Part I - Copy a container into another container.
void test_copy_container_into_container()
{
    // What is algorithm input?
    // Response: A begin and end iterator for the source range and a begin iterator for the destination range
    // and optionally a custom comparator used to determine which values to copy
    // What is the output?
    // Response: Output iterator to the element in the destination range, one past the last element copied.
    // Is the input modified on output?
    // Response: No
    // Which category does the algorithm belong to?
    // Response: Modifying

    Vector vec1{1, 2, 3};
    Vector vec2(3);
    std::copy(vec1.cbegin(), vec1.cend(), vec2.begin());

    std::cout << "Copied elements: ";
    for (int it : vec2)
    {
        std::cout << it << ", ";
    }
}

// Part J - Move the last 10 elements of a container to the front.
void test_move_elements_to_front()
{
    // What is algorithm input?
    // Response: A begin, middle, and end iterator for the source range and an optional execution policy
    // What is the output?
    // Response: An iterator that represents the new start of the mutated container (could be first, last or
    // any other iterator so long as it represent the first element in the mutated container)
    // Is the input modified on output?
    // Response: Yes
    // Which category does the algorithm belong to?
    // Response: Mutating

    Vector vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    auto middle = std::distance(vec1.cbegin(), vec1.cend()) / 2;
    std::rotate(vec1.begin(), vec1.begin() + middle, vec1.end());

    std::cout << "\nRotated elements: ";
    for (int it : vec1)
    {
        std::cout << it << ", ";
    }
}

// Part K - Swap two ranges at a given position.
void test_swap_ranges()
{
    // What is algorithm input?
    // Response: A begin and end iterator for one range and an iterator to the second range where the swap should occur
    // What is the output?
    // Response: Iterator to the element past the last element exchanged in the second range
    // Is the input modified on output?
    // Response: Yes
    // Which category does the algorithm belong to?
    // Response: Modifying

    Vector vec1{1, 2, 3, 4};
    Vector vec2{5, 6, 7, 8};
    std::swap_ranges(vec1.begin(), vec1.end(), vec2.begin());
    std::cout << "\nSwapped elements in Container 1: ";
    for (int it : vec1)
    {
        std::cout << it << ", ";
    }

    std::cout << "\nSwapped elements in Container 2: ";
    for (int it : vec2)
    {
        std::cout << it << ", ";
    }
}

// Part L - Generate values in a container based on some formula.
void test_generate_values_for_container()
{
    // What is algorithm input?
    // Response: A begin and end iterator for a range in which generated elements will be inserted
    // What is the output?
    // Response: None
    // Is the input modified on output?
    // Response: Yes
    // Which category does the algorithm belong to?
    // Response: Modifying

    Vector vec1(10);
    std::generate(vec1.begin(), vec1.end(), [x = 0]() mutable { return ++x; });
    std::cout << "\nGenerated elements in Container: ";
    for (int it : vec1)
    {
        std::cout << it << ", ";
    }
}

// Part M - Replace all uneven numbers by zero.
void test_replace_uneven_numbers()
{
    // What is algorithm input?
    // Response: A begin and end iterator for a range in which elements will be replaced along
    // with a predicate that determines which values will be replaced by a new value
    // What is the output?
    // Response: None
    // Is the input modified on output?
    // Response: Yes
    // Which category does the algorithm belong to?
    // Response: Modifying

    Vector vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::replace_if(vec1.begin(), vec1.end(), [](int element) { return element % 2 != 0; }, 0);
    std::cout << "\nReplaced elements in Container: ";
    for (int it : vec1)
    {
        std::cout << it << ", ";
    }
}

// Part N - Remove all elements whose value is less than 100.
void test_remove_if()
{
    // What is algorithm input?
    // Response: A begin and end iterator for a range in which elements will be removed along
    // with a predicate that determines which values will be removed. Optionally an execution policy
    // What is the output?
    // Response: Past-the-end iterator for the new range of values
    // Is the input modified on output?
    // Response: Yes
    // Which category does the algorithm belong to?
    // Response: Modifying

    Vector vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 101, 102, 103, 104};
    auto end = std::remove_if(vec1.begin(), vec1.end(), [](int element) { return element < 100; });
    std::cout << "\nRemoved elements in Container: ";
    for (auto it = vec1.cbegin(); it != end; ++it)
    {
        std::cout << *it << ", ";
    }
}

// Part O - Shuffle a container randomly (pre- and post-C++11 versions).
void test_random_shuffle()
{
    // What is algorithm input?
    // Response: A begin and end iterator for a range in which elements will be randomly shuffled
    // along with a random shuffling function (pre C++ 11) or a UniformRandomBitGenerator (post C++ 11)
    // What is the output?
    // Response: None
    // Is the input modified on output?
    // Response: Yes
    // Which category does the algorithm belong to?
    // Response: Mutating

    // Per https://quantnet.com/threads/3-o-c-17-has-removed-std-random_shuffle.49220/
    // the pre C++11 version has been removed and the goal instead is to describe its functionality.
    // Its signature was void random_shuffle( RandomIt first, RandomIt last ); suggesting that
    // the standard provided its own implementation of the shuffle. This differs from the post C++11
    // random shuffle in that we can now provide our own shuffling implementation such as the one below.

    Vector vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(vec1.begin(), vec1.end(), generator);
    std::cout << "\nShuffled elements post- C++ 11: ";
    for (auto it : vec1)
    {
        std::cout << it << ", ";
    }
}

// Part P - Compute one-sided divided differences of the values in a container.
void test_one_sided_divided_differences()
{
    // What is algorithm input?
    // Response: A begin and end iterator for a range in which adjacent difference will be calculated
    // along with an iterator into and output container. You can optionally specify an execution policy and
    // an binary function
    // What is the output?
    // Response: Iterator to the element past the last element written; otherwise empty
    // Is the input modified on output?
    // Response: Yes
    // Which category does the algorithm belong to?
    // Response: Numeric

    Vector vec1{4, 6, 9, 13, 18, 19, 19, 15, 10};
    std::adjacent_difference(vec1.cbegin(), vec1.cend(), vec1.begin());
    std::cout << "\nDivided difference elements: ";
    for (auto it : vec1)
    {
        std::cout << it << ", ";
    }
}

int main()
{
    test_scale_values();
    test_count_elements();
    test_average();
    test_find_value_in_and_out_of_range();
    test_occurrences(); // TODO !!!!!
    test_equal_elements();
    test_is_permutation();
    test_is_sorted();
    test_copy_container_into_container();
    test_move_elements_to_front();
    test_swap_ranges();
    test_generate_values_for_container();
    test_replace_uneven_numbers();
    test_remove_if();
    test_random_shuffle();
    test_one_sided_divided_differences();
    return 0;
}
//
// Analyze mutating algorithms and illustrate basic use cases.
// Mutating algorithms rearrange the elements of a container in some way without modifying the values
// Note - Algorithms that modify the values are classified as Modifying algorithms. Mutating algorithms
// are a special case of Modifying.
//
// Created by Michael Lewis on 7/17/23.
//

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

// Define container aliases
using Set = std::set<int>;
using PowerSet = std::set<Set>;
using Vector = std::vector<int>;

// Part A - Reverse S as a modifier option and copy to a second container. S = {1,-1,7,8,9,10}
void test_reverse_copy()
{
    Vector V{1,-1,7,8,9,10};
    Vector reversed;

    std::reverse_copy(V.cbegin(), V.cend(), std::inserter(reversed, reversed.end()));

    std::cout << "Reversed vector: ";
    for (const auto& element : reversed)
    {
        std::cout << element << ", ";
    }
}

// Part B - Rotate S so that the value 8 is the beginning of the container. S = {1,-1,7,8,9,10}
// Target output {8, 1, -1, 7, 9, 10}
// See https://quantnet.com/threads/ex-4-2-7-rotate-a-vector.28776/post-194866
// See https://quantnet.com/threads/7-move-the-subset-to-the-front.25354/post-180185
void test_rotate()
{
    Vector V{1,-1,7,8,9,10};
    auto middle = std::distance(V.cbegin(), std::find(V.cbegin(), V.cend(), 8));
    std::rotate(V.begin(), V.begin() + middle, V.begin() + middle + 1);

    std::cout << "\nRotated single element: ";
    for (const auto& element : V)
    {
        std::cout << element << ", ";
    }
}

// Part C - Write a function to compute the power set of S = {1,-1,7,8,9,10}
// (that is, the set of all subsets of S containing elements). 2^6=64 subsets
void test_power_set()
{
    Set S{1,-1,7,8,9,10};
    PowerSet powerSet;

    for (auto element : S)
    {
        for (Set subset : powerSet)
        {
            subset.insert(element);
            powerSet.insert(subset);
        }

        // Create a new subset
        powerSet.insert(Set{element});
    }
    powerSet.insert(Set{}); // Add the null set.

    // Log the power set
    std::cout << "\nPower set: \n";
    for (const auto& outer : powerSet)
    {
        std::cout << "{";
        for (const auto& inner : outer)
        {
            std::cout << inner << ", ";
        }
        std::cout << "}\n";
    }
}

// Part D - Move the subset {8,9,10} to the front of the container. S = {1,-1,7,8,9,10}
// Target output {8,9,10,1,-1,7}
void test_move_set_to_front()
{
    Vector V{1,-1,7,8,9,10};
    auto middle = std::distance(V.cbegin(), std::find(V.cbegin(), V.cend(), 8));
    std::rotate(V.begin(), V.begin() + middle, V.end());

    std::cout << "\nSubset moved to front: ";
    for (const auto& element : V)
    {
        std::cout << element << ", ";
    }
}

int main()
{
    test_reverse_copy();
    test_rotate();
    test_power_set();
    test_move_set_to_front();
    return 0;
}
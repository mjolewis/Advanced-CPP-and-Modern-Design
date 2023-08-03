//
// Develop understanding of heaps and illustrate their core fucntionality
//
// Created by Michael Lewis on 7/29/23.
//

#include <algorithm>
#include <iostream>
#include <vector>

// Utility method to print elements in a vector (represented as a heap or otherwise)
void print(const std::vector<int>& v)
{
    for (const auto& e : v) std::cout << e << ' ';
    std::cout << '\n';
}

int main()
{
    // Part A - Create a vector
    std::vector<int> vec2{ 3,4,5,6,7,5,6,7,8,9,1,2,3,4 };

    // Part B - Call std::make_heap() on this vector and print the result. (see below main for drawing)
    std::make_heap(vec2.begin(), vec2.end());
    print(vec2);

    // Part C - Pop the root of the heap by calling pop_heap().
    std::pop_heap(vec2.begin(), vec2.end());
    print(vec2);

    /* What are the effects of calling this function (or not calling it) if the underlying
     * container is not a heap? And why do you need to call pop_back() after calling pop_heap()?
     *
     * Response: Calling pop_heap is actually a non destructive operation. It simply swaps
     * the element from the first position and the value in the last position and then
     * makes a heap from [First, lest - 1). Because it's non-destructive, you then need
     * to call pop_back to actually remove the element from the heap.
    */
    vec2.pop_back();
    print(vec2);

    // Part D - Push a value onto the heap by calling push_heap().
    vec2.push_back(11);
    std::push_heap(vec2.begin(), vec2.end());
    print(vec2);

    /*
     * What are the effects of calling this function (or not calling it) if the
     * underlying container is not a heap? And why do you need to call push_back()
     * before calling push_heap()?
     *
     * Response: push_heap simply inserts the element as last - 1 into the heap.
     * It doesn't actually insert any new element into the underlying container.
     * As a result, you must first call push_back on the underlying container to insert
     * an element. And then call push_heap, to then insert that element into the existing
     * heap
     */

    // Part E - Sort the heap into a sorted collection.
    std::sort_heap(vec2.begin(), vec2.end());
    print(vec2);

    // Part F - Find the largest element in a heap. (Note, I'll first convert the sorted collection into a heap)
    std::make_heap(vec2.begin(), vec2.end());
    auto max = vec2.front();
    std::cout << "Max element:" << max << std::endl;

    return 0;
}

// Draw the corresponding binary tree by hand.
/*
 *                               9
 *                     8                  6
 *                7        7         5        5
 *             3    6   4    1    2    3   4
 */
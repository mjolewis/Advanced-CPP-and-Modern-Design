//
// Illustrate how to basic concepts of a priority queue.
//
// Created by Michael Lewis on 7/29/23.
//

#include <functional>
#include <iostream>
#include <queue>

// Utility method to print elements of a priority queue
template<typename T>
void print(T& container)
{
    while (!container.empty())
    {
        std::cout << container.top() << ", ";
        container.pop();
    }
    std::cout << "\n";
}

int main()
{
    auto data = {10,5,20,30,25,7,40};  // helper container to populate the priority queue
    // Part A - Create a default priority queue of integers with elements {10,5,20,30,25,7,40}. Print the queue.
    std::priority_queue<int> pq1(data.begin(), data.end());
    print(pq1);

    // Part B - Modify the queue in part a) using std::greater<int> as comparator function. Print the queue.
    std::priority_queue<int, std::vector<int>, std::greater<>> pq2(data.begin(), data.end());
    print(pq2);

    // Part C - Create a priority queue using an underlying data container
    // and the following lambda function as comparator:
    auto cmp = [](int left, int right)->bool { return (left > right); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq3(data.begin(), data.end(), cmp);
    print(pq3);

    return 0;
}

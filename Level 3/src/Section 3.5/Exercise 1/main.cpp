//
// The purpose of this test class is to illustrate basic operations on STL containers and their
// associated complexity.
//
// Created by Michael Lewis on 7/4/23.
//

#include <deque>
#include <iostream>
#include <functional>
#include <queue>

// Illustrate basic functionality of a priority queue using the default template arguments. Per the link,
// the objects is to use the STL priority queue versus building a custom one.
// https://quantnet.com/threads/3-5-1-should-i-create-a-priority-queue-by-myself.33934/post-222561
void test_PartA()
{
    std::cout << "\n*** Start Part A ***" << std::endl;

    std::priority_queue<long long> priorityQueue{};

    // Push elements onto the queue
    priorityQueue.push(66);
    priorityQueue.push(22);
    priorityQueue.push(44);

    // Log the top element and then pop it
    std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
    priorityQueue.pop();

    // Push elements onto the queue
    priorityQueue.push(11);
    priorityQueue.push(22);
    priorityQueue.push(33);

    // Log the top element and then pop it
    std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
    priorityQueue.pop();

    // Note - A priority queue purposefully provides a limited interface because
    // it would be too common to have the priority in the queue modified each time a
    // new element is added. This, in part, means iteration is not natively supported
    // via mechanisms such as iterators. However, there are ways around this such as
    // the approach shown below.
    while (!priorityQueue.empty())
    {
        std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
        priorityQueue.pop();
    }
}

// Create a priority queue whose elements are long long whose container is
// std::deque and whose comparator is std::greater<long long>.
// Test this case with the data in part a) of the exercise. Inspect the output.
void test_PartB()
{
    std::cout << "\n*** Start Part B ***" << std::endl;

    std::priority_queue<long long, std::deque<long long>, std::greater<long long>> priorityQueue{};

    // Push elements onto the queue
    priorityQueue.push(66);
    priorityQueue.push(22);
    priorityQueue.push(44);

    // Log the top element and then pop it
    std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
    priorityQueue.pop();

    // Push elements onto the queue
    priorityQueue.push(11);
    priorityQueue.push(22);
    priorityQueue.push(33);

    // Log the top element and then pop it
    std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
    priorityQueue.pop();

    // Note - A priority queue purposefully provides a limited interface because
    // it would be too common to have the priority in the queue modified each time a
    // new element is added. This, in part, means iteration is not natively supported
    // via mechanisms such as iterators. However, there are ways around this such as
    // the approach shown below.
    while (!priorityQueue.empty())
    {
        std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
        priorityQueue.pop();
    }
}

// Modify the code in part b) to use a lambda function instead of std::greater<long long>. Inspect the output.
void test_PartC()
{
    std::cout << "\n*** Start Part C ***" << std::endl;
    auto comparator = [](const long long& lhs, const long long& rhs) -> bool {return lhs > rhs;};

    // Note - must use decltype(comparator) because the declaration expects a type.
    std::priority_queue<long long, std::deque<long long>, decltype(comparator)> priorityQueue{comparator};

    // Push elements onto the queue
    priorityQueue.push(66);
    priorityQueue.push(22);
    priorityQueue.push(44);

    // Log the top element and then pop it
    std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
    priorityQueue.pop();

    // Push elements onto the queue
    priorityQueue.push(11);
    priorityQueue.push(22);
    priorityQueue.push(33);

    // Log the top element and then pop it
    std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
    priorityQueue.pop();

    // Note - A priority queue purposefully provides a limited interface because
    // it would be too common to have the priority in the queue modified each time a
    // new element is added. This, in part, means iteration is not natively supported
    // via mechanisms such as iterators. However, there are ways around this such as
    // the approach shown below.
    while (!priorityQueue.empty())
    {
        std::cout << "Top element in queue: " << priorityQueue.top() << std::endl;
        priorityQueue.pop();
    }
}

int main()
{
    test_PartA();
    test_PartB();
    test_PartC();
}
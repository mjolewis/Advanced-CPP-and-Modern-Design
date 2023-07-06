//
// A simple test program to validate the functionality of a ConcurrentPriorityQueue.
// @Note - The ConccurentPriorityQueues currently don't use a condition variable to notify
// waiting threads. This is a purposeful decision because there are no reasons to wait in this
// implementation (e.g. no pub/sub type of model).
//
// To better understand my logic, please take this hypothetical example If a thread asks to pop data
// from the queue, there is no need to first wait for data to be added just so the thread can pop.
// This approach favors a lower latency approach and, arguably, more accurate approach. As a client shouldn't
// expect to be able to remove data from the queue if no data currently exists, nor should it expect
// to wait until another thread adds it just so it can remove it.
//
// Created by Michael Lewis on 7/5/23.
//

#include <cassert>
#include <deque>
#include <functional>
#include <thread>
#include <future>

#include "ConcurrentPriorityQueue.hpp"

// Construct a ConcurrentPriorityQueue using the default types
void test_DefaultCtor()
{
    ConcurrentPriorityQueue<double> queue{};
    assert(0 == queue.size());
    assert(true == queue.empty());
}

// Construct a ConcurrentPriorityQueue using custom types instead of the default types
void test_NonDefaultParams()
{
    auto comparator = [](double lhs, double rhs) -> bool { return lhs < rhs; };
    ConcurrentPriorityQueue<double, std::deque<double>, decltype(comparator)> queue{};
    assert(0 == queue.size());
    assert(true == queue.empty());
}

// Construct a new ConcurrentPriorityQueue by copying another ConcurrentPriorityQueue
void test_CopyCtor()
{
    ConcurrentPriorityQueue<double> other{};
    for (int i = 0; i < 4; ++i) other.push(i);

    ConcurrentPriorityQueue<double> queue{other};

    assert(3 == queue.top());
    queue.pop();
    assert(2 == queue.top());
    queue.pop();
    assert(1 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();
}

// Construct a new ConcurrentPriorityQueue by moving another ConcurrentPriorityQueue
void test_MoveCtor()
{
    ConcurrentPriorityQueue<double>&& other{};
    for (int i = 0; i < 4; ++i) other.push(i);

    ConcurrentPriorityQueue<double> queue{std::move(other)};

    assert(3 == queue.top());
    queue.pop();
    assert(2 == queue.top());
    queue.pop();
    assert(1 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();
}

// Push RValue elements onto a specified ConcurrentPriorityQueue
void test_PushRValue_Pop()
{
    ConcurrentPriorityQueue<double> queue{};
    for (int i = 0; i < 4; ++i) queue.push(i);

    assert(3 == queue.top());
    queue.pop();
    assert(2 == queue.top());
    queue.pop();
    assert(1 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();
}

// Push RValue elements onto a specified ConcurrentPriorityQueue using threads to test synchronization
void test_PushRValue_Pop_MultiThreaded()
{
    ConcurrentPriorityQueue<double> queue{};

    auto push = [&](double value) -> void {queue.push(value);};
    std::thread t1(push, 0);
    std::thread t2(push, 1);
    std::thread t3(push, 4);
    std::thread t4(push, 3);
    std::thread t5(push, 9);
    std::thread t6(push, 8);
    std::thread t7(push, 7);
    std::thread t8(push, 11);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    assert(11 == queue.top());
    queue.pop();
    assert(9 == queue.top());
    queue.pop();
    assert(8 == queue.top());
    queue.pop();
    assert(7 == queue.top());
    queue.pop();
    assert(4 == queue.top());
    queue.pop();
    assert(3 == queue.top());
    queue.pop();
    assert(1 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();
}

// Push LValue elements onto a specified ConcurrentPriorityQueue
void test_PushLValue_Pop()
{
    ConcurrentPriorityQueue<double> queue{};
    double elem0 = 0;
    double elem1 = 1;
    double elem2 = 2;
    double elem3 = 3;

    queue.push(elem0);
    queue.push(elem1);
    queue.push(elem2);
    queue.push(elem3);

    assert(3 == queue.top());
    queue.pop();
    assert(2 == queue.top());
    queue.pop();
    assert(1 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();
}

// Push LValue elements onto a specified ConcurrentPriorityQueue using mulitple threads to test synchronization
void test_PushLValue_Pop_MultiThreaded()
{
    ConcurrentPriorityQueue<double> queue{};
    double elem0 = 0;
    double elem1 = 1;
    double elem2 = 2;
    double elem3 = 3;
    double elem4 = 4;
    double elem5 = 7;
    double elem6 = 6;
    double elem7 = 2;

    auto push = [&](double element) -> void { queue.push(element); };
    std::thread t1(push, elem0);
    std::thread t2(push, elem1);
    std::thread t3(push, elem2);
    std::thread t4(push, elem3);
    std::thread t5(push, elem4);
    std::thread t6(push, elem5);
    std::thread t7(push, elem6);
    std::thread t8(push, elem7);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    assert(7 == queue.top());
    queue.pop();
    assert(6 == queue.top());
    queue.pop();
    assert(4 == queue.top());
    queue.pop();
    assert(3 == queue.top());
    queue.pop();
    assert(2 == queue.top());
    queue.pop();
    assert(2 == queue.top());
    queue.pop();
    assert(1 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();
}

// Test the size of a given ConcurrentPriorityQueue
void test_Size()
{
    ConcurrentPriorityQueue<double> queue{};
    for (int i = 0; i < 4; ++i) queue.push(i);

    assert(4 == queue.size());
}

// Test the size of a given ConcurrentPriorityQueue using multiple threads to push data into the queue
void test_Size_MultiThreaded()
{
    ConcurrentPriorityQueue<double> queue{};
    auto emplace = [&](auto... args) -> void { (queue.emplace(std::forward<double>(args)), ...); };
    std::thread t1(emplace, 0, 1, 2, 3, 4, 6, 7, 8, 9, 10);
    std::thread t2(emplace, 0, 1, 2, 3, 4, 6, 7, 8, 9, 10);

    t1.join();
    t2.join();

    assert(20 == queue.size());
}

// Test if a given ConcurrentPriorityQueue is empty or not
void test_Empty()
{
    ConcurrentPriorityQueue<double> queue{};
    for (int i = 0; i < 4; ++i) queue.push(i);
    assert(false == queue.empty());

    while (!queue.empty()) queue.pop();
    assert(true == queue.empty());
}

// Emplace elements into a ConcurrentPriorityQueue
void test_Emplace()
{
    ConcurrentPriorityQueue<double> queue{};
    queue.emplace(0, 8, 7, 3);

    assert(4 == queue.size());
    assert(8 == queue.top());
    queue.pop();
    assert(7 == queue.top());
    queue.pop();
    assert(3 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();
}

// Emplace elements into a ConcurrentPriorityQueue with multiple threads
void test_Emplace_MultiThreaded()
{
    ConcurrentPriorityQueue<double> queue{};
    auto emplace = [&](auto... args) -> void { (queue.emplace(std::forward<double>(args)), ...); };
    std::thread t1(emplace, 0, 8, 7, 3);
    std::thread t2(emplace, 10, 13, 8, 6);

    t1.join();
    t2.join();

    assert(8 == queue.size());
    assert(13 == queue.top());
    queue.pop();
    assert(10 == queue.top());
    queue.pop();
    assert(8 == queue.top());
    queue.pop();
    assert(8 == queue.top());
    queue.pop();
    assert(7 == queue.top());
    queue.pop();
    assert(6 == queue.top());
    queue.pop();
    assert(3 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();
}

// Swap elements of two ConcurrentPriorityQueues
void test_Swap()
{
    ConcurrentPriorityQueue<double> other{};
    for (int i = 0; i < 4; ++i) other.push(i);

    ConcurrentPriorityQueue<double> queue{};
    queue.emplace(7, 8, 9, 10);

    queue.swap(other);

    assert(4 == queue.size());
    assert(3 == queue.top());
    queue.pop();
    assert(2 == queue.top());
    queue.pop();
    assert(1 == queue.top());
    queue.pop();
    assert(0 == queue.top());
    queue.pop();

    assert(4 == other.size());
    assert(10 == other.top());
    other.pop();
    assert(9 == other.top());
    other.pop();
    assert(8 == other.top());
    other.pop();
    assert(7 == other.top());
    other.pop();
}

int main()
{
    test_DefaultCtor();
    test_NonDefaultParams();
    test_CopyCtor();
    test_MoveCtor();
    test_PushLValue_Pop();
    test_PushLValue_Pop_MultiThreaded();
    test_PushRValue_Pop();
    test_PushRValue_Pop_MultiThreaded();
    test_Size();
    test_Size_MultiThreaded();
    test_Empty();
    test_Emplace();
    test_Emplace_MultiThreaded();
    test_Swap();

    return 0;
}
//
// A simple test class to illustrate core concepts of std::promise and its relationship with std::future
// @Note - A Promise is the push end of the Promise-Future communication channel
//
// Created by Michael Lewis on 7/2/23.
//

#include <future>
#include <iostream>

// Create a default Promise, a promise with an empty shared state and a promise based on the move constructor
void test_PartA()
{
    // Default Promise
    std::promise<int> p1{};

    // Promise based on a move ctor
    std::promise<int> p2{std::promise<int>{}};
}

// Create a promise with double as stored value. Then create a future that is associated with the promise.
void test_PartB()
{
    std::promise<double> p1{};
    std::shared_future<double> f = p1.get_future();
}

// Start a thread with the new future from part b).
// Create a thread function that uses the value of the shared data.
void test_PartC_And_PartD()
{
    // Create a Promise with double as stored value
    std::promise<double> sharedData{};

    // Associate the Promise with a Future object
    std::shared_future<double> f = sharedData.get_future();

    // Create a thread function that uses the value of the shared data
    auto lambda = [&](const std::shared_future<double>& f1) -> void {std::cout << f1.get() << std::endl;};

    // Start a thread with the same shared future from Part B
    std::thread t1(lambda, f);

    // Part D - Use the promise to set the value of the shared data.
    sharedData.set_value(4.0);

    // Join the thread
    t1.join();
}

int main()
{
    test_PartA();
    test_PartB();
    test_PartC_And_PartD();
}
//
// A simple test class to illustrate core concepts of std::future
//
// Created by Michael Lewis on 7/2/23.
//

#include <cassert>
#include <chrono>
#include <future>
#include <iostream>

using namespace std::chrono_literals;

// Create the following shared future by calling the appropriate constructor:
void test_PartA()
{
    // Default shared future
    std::shared_future<int> sf1{};

    // As a shared future that shares the same state as another shared state.
    std::shared_future<int> sf2{sf1};

    // Transfer shared state from a ‘normal’ future to a shared future.
    std::future<int>&& f1{};
    std::shared_future sf3{std::move(f1)};
    std::shared_future sf4{f1.share()};

    // Transfer shared state from a shared future to a shared future.
    std::shared_future sf5{sf3};
}

// Simple test function to feed a result into the futures shown below.
int multiply(int lhs, int rhs)
{
    return lhs * rhs;
}

// Check the member functions from std::future that they are also applicable to std::shared_future.
void test_PartB()
{
    std::future<int> f = std::async(multiply, 5, 5);
    f.valid();
    f.wait();
    f.wait_for(1000ms);
    f.wait_until(std::chrono::system_clock::now() + 1000ms);
    assert(25 == f.get());
    f.share(); // The two interfaces are the same except the additional share method that enables

    std::shared_future<int> sf = std::async(multiply, 5, 5);
    sf.valid();
    sf.wait();
    sf.wait_for(1000ms);
    sf.wait_until(std::chrono::system_clock::now() + 1000ms);
    assert(25 == sf.get());
}

// Test what happens when you call get() twice on a shared future.
void test_PartC()
{
    std::future<int> f = std::async(multiply, 5, 5);
    std::shared_future<int> sf1 = f.share();
    std::shared_future<int> sf2 = f.share();
    assert(25 == sf1.get());
    assert(25 == sf1.get());
//    assert(25 == sf2.get()); Ends with a SIGSEGV because f was empty when it was shared with sf2.
}

// Create a shared future that waits for an infinite loop to
// finish (which it never does). To this end, use wait_for and wait_until to trigger a time out.
void test_PartD()
{
    auto infiniteLoop = [](int i) -> int { while(true) ++i; return i;};

    std::shared_future<int> sf1 = std::async(infiniteLoop, 1);
    sf1.wait_for(500ms);
    sf1.wait_until(std::chrono::system_clock::now() + 500ms);
    std::cout << "Infinite loop triggered. I'll display the result if I ever get it:" << std::endl;
    std::cout << sf1.get() << std::endl;
}

int main()
{
    test_PartA();
    test_PartB();
    test_PartC();
    test_PartD();
    return 0;
}
//
// Exemplar tests that illustrate how to use several key sorting algorithms as provided by the standard
// template algorithms library. This exercises focuses on working with and sorting numerical containers.
//
// Created by Michael Lewis on 7/14/23.
//

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using Vector = std::vector<double>;

class StopWatch
{
private:
    static std::chrono::steady_clock::time_point start;
    static std::chrono::steady_clock::time_point stop;

public:
    static void start_clock() { start = std::chrono::steady_clock::now(); }
    static void stop_clock() { stop = std::chrono::steady_clock::now(); }
    static auto elapsed_time() { return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count(); };
};

std::chrono::steady_clock::time_point StopWatch::start;
std::chrono::steady_clock::time_point StopWatch::stop;

// Examines the range [first, last) and finds the largest range beginning at first
// in which the elements are sorted in non-descending order.
void test_is_sorted_until()
{
    StopWatch::start_clock();

    Vector vec8{ 1.0, 2.0, 3.0, -4.0, 10.0 }; // Not ordered
    auto pos = std::is_sorted_until(vec8.begin(), vec8.end());
    std::cout << "is sorted bad value: " << *pos << std::endl;

    pos = std::is_sorted_until(vec8.begin(), vec8.end(), [](auto lhs, auto rhs) -> bool {return lhs > rhs; });
    std::cout << "is reverse bad value: " << *pos << std::endl;

    StopWatch::stop_clock();
    std::cout << "Sorted Until elapsed time in nanos: " << StopWatch::elapsed_time() << "\n" << std::endl;
}

// Checks if the elements in range [first, last) are sorted in non-descending order.
void test_is_sorted()
{
    StopWatch::start_clock();

    Vector vec8{ 1.0, 2.0, 3.0, -4.0, 10.0 }; // Not ordered
    auto pos = std::is_sorted(vec8.begin(), vec8.end());
    std::cout << std::boolalpha << "is sorted: " << pos << std::endl;

    pos = std::is_sorted(vec8.begin(), vec8.end(), [](auto lhs, auto rhs) -> bool {return lhs > rhs; });
    std::cout << std::boolalpha << "is reverse sorted: " << pos << std::endl;

    StopWatch::stop_clock();
    std::cout << "Sorted elapsed time in nanos: " << StopWatch::elapsed_time() << "\n" << std::endl;
}

// Checks if the elements in range [first, last) are sorted in non-descending order.
void test_is_sorted_range()
{
    StopWatch::start_clock();

    Vector vec8{ 1.0, 2.0, 3.0, -4.0, 10.0 }; // Not ordered
    auto pos = std::ranges::is_sorted(vec8.begin(), vec8.begin() + 3);
    std::cout << std::boolalpha << "is sorted in range [0, 2]: " << pos << std::endl;

    pos = std::ranges::is_sorted(vec8.begin(), vec8.begin() + 3, [](auto lhs, auto rhs) -> bool {return lhs > rhs; });
    std::cout << std::boolalpha << "is reverse sorted in range [0, 2]:: " << pos << std::endl;

    StopWatch::stop_clock();
    std::cout << "Sorted Range elapsed time in nanos: " << StopWatch::elapsed_time() << "\n" << std::endl;
}

// Examines the range [first, last) and finds the largest range beginning at first
// in which the elements are sorted in non-descending order.
void test_is_sorted_range_until()
{
    StopWatch::start_clock();

    Vector vec8{ 1.0, 2.0, 3.0, -4.0, 10.0 }; // Not ordered
    std::forward_iterator auto pos = std::ranges::is_sorted_until(vec8.begin(), vec8.end());
    std::cout << "bad value: " << *pos << std::endl;

    pos = std::ranges::is_sorted_until(vec8.begin(), vec8.end(), [](auto lhs, auto rhs) -> bool {return lhs > rhs; });
    std::cout << "is reverse bad value: " << *pos << std::endl;

    StopWatch::stop_clock();
    std::cout << "Sorted Range Until elapsed time in nanos: " << StopWatch::elapsed_time() << "\n" << std::endl;
}

int main()
{
    test_is_sorted_until();
    test_is_sorted();
    test_is_sorted_range();
    test_is_sorted_range_until();
    return 0;
}
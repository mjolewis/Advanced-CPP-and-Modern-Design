//
// Simple illustration for how to use the utility StopWatch
//
// Created by Michael Lewis on 7/6/23.
//

#include <cassert>
#include <thread>

#include "StopWatch.hpp"

// 12 user-defined literals that represent hours, minutes, seconds, milliseconds, milliseconds, and nanoseconds
// Will be used to set minimum duration to block for when attempting to acquire a lock
using namespace std::chrono_literals;

// Illustrate how to interact with the Start API
void test_Start()
{
    StopWatch watch{};
    watch.StartStopWatch();
}

// Illustrate how to interact with the Stop API
void test_Stop()
{
    StopWatch watch{};
    watch.StartStopWatch();
}

// Illustrate how to interact with the Start and Stop API.
void test_StartAndStop()
{
    StopWatch watch{};
    watch.StartStopWatch();
    watch.StopStopWatch();
}

// Illustrate how to interact with the GetTime API. Acts as an End-To-End test of the StopWatch class
void test_ElapsedTime()
{
    StopWatch watch{};
    watch.StartStopWatch();

    // Introduce delay
    std::this_thread::sleep_for(1s);

    watch.StopStopWatch();
    double elapsedTime = watch.GetTime();
    assert(1 <= elapsedTime); // Expected elapsed time of more than 1 sec due to delay inserted above
}

int main()
{
    test_Start();
    test_Stop();
    test_StartAndStop();
    test_ElapsedTime();
    return 0;
}

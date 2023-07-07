//
// A simple utility class to measure elapsed time. Typical use cases are for profiling the
// running time of algorithms.
//
// Created by Michael Lewis on 7/6/23.
//

#include "StopWatch.hpp"

/**
 * Starts this StopWatch
 */
void StopWatch::StartStopWatch()
{
    start = std::chrono::steady_clock::now();
}

/**
 * Stops this StopWatch
 */
void StopWatch::StopStopWatch()
{
    stop = std::chrono::steady_clock::now();
}

/**
 * Resets the start and end times to the current time.
 */
void StopWatch::Reset()
{
    stop = start = std::chrono::steady_clock::now();
}

/**
 * Calculates the difference between the stop time and start time
 * @return A double representation of the elapsed time
 */
double StopWatch::GetTime() const
{
    auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    return std::chrono::duration<double>(elapsedTime).count();
}

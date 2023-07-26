//
// A simple utility class to measure elapsed time. Typical use cases are for profiling the
// running time of algorithms.
//
// Created by Michael Lewis on 7/6/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STOPWATCH_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_STOPWATCH_HPP

#include <chrono>

class StopWatch
{
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point stop;

    StopWatch(const StopWatch &);
    StopWatch & operator=(const StopWatch &);

public:
    StopWatch() = default;

    void Start();
    void Stop();
    void Reset();

    double ElapsedTime() const;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_STOPWATCH_HPP

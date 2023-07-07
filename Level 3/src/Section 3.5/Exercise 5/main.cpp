//
// A simple test program to illustrate a multi-threaded Producer/Consumer pattern, where
// Producers push Commands to a ConcurrentPriorityQueue and Consumers pop the Commands from
// the queue for execution.
//
// Created by Michael Lewis on 7/4/23.
//

#include <atomic>
#include <iostream>
#include <functional>
#include <memory>
#include <queue>
#include <vector>

#include "Command.hpp"
#include "Consumer.hpp"
#include "ConcurrentPriorityQueue.hpp"
#include "Producer.hpp"

int main()
{
    constexpr int NUM_THREADS = 100;
    std::array<std::thread, NUM_THREADS> producerThreads;
    std::array<std::thread, NUM_THREADS> consumerThreads;

    // Create a comparator type to construct the ConcurrentPriorityQueue
    auto comparator = [](const Command& lhs, const Command& rhs) -> bool { return lhs.priority() < rhs.priority(); };
    // Create an alias to improve readability
    using CPQ = std::shared_ptr<ConcurrentPriorityQueue<Command, std::vector<Command>, decltype(comparator)>>;
    // Create the ConcurrentPriorityQueue
    CPQ queue(new ConcurrentPriorityQueue<Command, std::vector<Command>, decltype(comparator)>{});

    // Create thread pool for Producers - Producers override the call operator so are Function Objects
    // that will execute when the threads start
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        producerThreads[i] = std::thread(Producer{queue});
    }

    // Create thread pool for Consumers - Consumers override the call operator so are Function Objects
    // that will execute when the threads start
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        consumerThreads[i] = std::thread(Consumer{queue});
    }

    // Wait for signal before joining thread
    std::cout << "***** ENTER ANY CHARACTER TO END *****" << std::endl;
    getchar();
    ConcurrentPriorityQueue<Command, std::vector<Command>, decltype(comparator)>::killSwitch.store(true);

    // Block the main thread in the thread groups finish executing
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        if (producerThreads[i].joinable()) producerThreads[i].join();
        if (consumerThreads[i].joinable()) consumerThreads[i].join();
    }

    std::cout << "***** PROCESS WAS TERMINATED - GRACEFULLY ENDING *****" << std::endl;

    return 0;
}
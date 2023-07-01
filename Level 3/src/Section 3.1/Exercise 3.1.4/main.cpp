//
// A simple test program to illustrate the ConcurrentQueue with multiple threads producing
// and consuming data
//
// Created by Michael Lewis on 6/29/23.
//

#include <array>
#include <memory>
#include <thread>

#include "ConcurrentQueue.hpp"
#include "Consumer.hpp"
#include "Producer.hpp"

int main()
{
    constexpr int NUM_THREADS = 100;
    std::array<std::thread, NUM_THREADS> producerThreads;
    std::array<std::thread, NUM_THREADS> consumerThreads;
    std::shared_ptr<ConcurrentQueue<std::string>> queue(new ConcurrentQueue<std::string>{});

    // Create producers
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        producerThreads[i] = std::thread(Producer<std::string> {Producer {i, queue}});
    }

    // Create consumers
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        consumerThreads[i] = std::thread(Consumer<std::string> {Consumer {i, queue}});
    }

    // Wait for signal before joining thread
    std::cout << "***** ENTER ANY CHARACTER TO END *****" << std::endl;
    getchar();
    queue->setInterrupt(true);

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        if (producerThreads[i].joinable()) producerThreads[i].join();
        if (consumerThreads[i].joinable()) consumerThreads[i].join();
    }

    std::cout << "***** PROCESS WAS TERMINATED - GRACEFULLY ENDING *****" << std::endl;
    return 0;
}

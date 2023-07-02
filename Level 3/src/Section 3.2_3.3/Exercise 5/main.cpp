//
// A simple test program to illustrate the Barbershop Problem where there are N customers
// that potentially enter the Barbershop with only one Barber to provide haircuts.
//
// Created by Michael Lewis on 7/1/23.
//

#include <array>
#include <memory>
#include <thread>

#include "Barber.hpp"
#include "ConcurrentQueue.hpp"
#include "Customer.hpp"

int main()
{
    constexpr int CUSTOMER_THREADS = 100;

    // Create the shared resource - Set the number of available chairs in the barbershop to 10
    std::shared_ptr<ConcurrentQueue<std::string>> queue(new ConcurrentQueue<std::string>{10});

    // Create customer threads
    std::array<std::thread, CUSTOMER_THREADS> customerThreads;
    for (int i = 0; i < CUSTOMER_THREADS; ++i)
    {
        customerThreads[i] = std::thread(Customer{queue});
    }

    // Create the single Barber
    std::thread barberThread(Barber{queue});

    // Open for business
    queue->setOpenForBusiness(true);

    std::cout << "***** ENTER ANY CHARACTER TO END *****" << std::endl;
    getchar();
    queue->setOpenForBusiness(false);

    for (int i = 0; i < CUSTOMER_THREADS; ++i)
    {
        if(customerThreads[i].joinable()) customerThreads[i].join();
    }

    if (barberThread.joinable()) barberThread.join();

    return 0;
}
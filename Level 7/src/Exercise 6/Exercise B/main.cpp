//
// Next Generation Observer Pattern
//
// Created by Michael Lewis on 8/27/23.
//

#include <iostream>

#include "Counter.hpp"

// Alias
using ObserverPtr = std::shared_ptr<std::function<void (double)>>;

void test_ListObservers()
{
    std::cout << "\n*** Using std::list as the container ***" << std::endl;

    // Create Observers
    std::function<void (double)> longFormat = [](double value)
    {
        std::string s = std::to_string((long) value);
        std::cout << "Long Format: " << s << std::endl;
    };

    std::function<void (double)> doubleFormat = [](double value)
    {
        std::string s = std::to_string(value);
        std::cout << "Double Format: " << s << std::endl;
    };

    ObserverPtr longFormatPtr = std::make_shared<decltype(longFormat)>(longFormat);
    ObserverPtr doubleFormatPtr = std::make_shared<decltype(doubleFormat)>(doubleFormat);

    // Choose a list as the container
    Counter<std::list> counter;
    counter.attach(longFormatPtr);
    counter.attach(doubleFormatPtr);

    std::cout << "*** Increase the Counter ***" << std::endl;
    for (int i = 0; i < 5; ++i) counter.increaseCounter();

    std::cout << "*** Decrease the Counter ***" << std::endl;
    for (int i = 0; i < 5; ++i) counter.decreaseCounter();
}

void test_DequeObservers()
{
    std::cout << "\n*** Using std::deque as the container ***" << std::endl;

    // Create Observers
    std::function<void (double)> longFormat = [](double value)
    {
        std::string s = std::to_string((long) value);
        std::cout << "Long Format: " << s << std::endl;
    };

    std::function<void (double)> doubleFormat = [](double value)
    {
        std::string s = std::to_string(value);
        std::cout << "Double Format: " << s << std::endl;
    };

    ObserverPtr longFormatPtr = std::make_shared<decltype(longFormat)>(longFormat);
    ObserverPtr doubleFormatPtr = std::make_shared<decltype(doubleFormat)>(doubleFormat);

    // Choose a list as the container
    Counter<std::deque> counter;
    counter.attach(longFormatPtr);
    counter.attach(doubleFormatPtr);

    std::cout << "*** Increase the Counter ***" << std::endl;
    for (int i = 0; i < 5; ++i) counter.increaseCounter();

    std::cout << "*** Decrease the Counter ***" << std::endl;
    for (int i = 0; i < 5; ++i) counter.decreaseCounter();
}

int main()
{
    test_ListObservers();
    test_DequeObservers();

    return 0;
}
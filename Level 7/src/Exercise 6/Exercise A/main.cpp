//
// Next Generation Observer Pattern
//
// Created by Michael Lewis on 8/27/23.
//

#include <iostream>

#include "Counter.hpp"

// Alias
using ObserverPtr = std::shared_ptr<std::function<void (double)>>;

int main()
{
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

    // Create the Subject and attach Observers
    Counter counter;
    counter.attach(longFormatPtr);
    counter.attach(doubleFormatPtr);

    std::cout << "*** Increase the Counter ***" << std::endl;
    for (int i = 0; i < 5; ++i) counter.increaseCounter();

    std::cout << "*** Decrease the Counter ***" << std::endl;
    for (int i = 0; i < 5; ++i) counter.decreaseCounter();

    std::cout << "*** Detached Long Format - Expect only Double Format Below ***" << std::endl;
    counter.detach(longFormatPtr);
    for (int i = 0; i < 5; ++i) counter.increaseCounter();

    std::cout << "*** Detached Double Format - Expect No Output Below ***" << std::endl;
    counter.detach(doubleFormatPtr);
    for (int i = 0; i < 5; ++i) counter.increaseCounter();

    return 0;
}
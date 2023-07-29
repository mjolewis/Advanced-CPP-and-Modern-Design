//
// Illustrate core functionality of Boost Signal and Slots 2 with a custom combiner
// Note: In general, a combiner is a function object
//
// Created by Michael Lewis on 7/29/23.
//

#include <iostream>

#include <boost/signals2.hpp>

#include "BootstrapCheck.hpp"

int main()
{
    // Part A - Implement the provided signal and combiner
    boost::signals2::signal<bool (), BootstrapCheck> sig;

    // Part B - Create three slots each returning true with the exception of the second slot.
    auto slotA = []() -> bool { return true; };
    auto slotB = []() -> bool { return false; };
    auto slotC = []() -> bool { return true; };

    // Part C - Connect the slots to the signal and then call the signal.
    sig.connect(boost::ref(slotA));
    sig.connect(boost::ref(slotB));
    sig.connect(boost::ref(slotC));

    auto result = sig();
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}
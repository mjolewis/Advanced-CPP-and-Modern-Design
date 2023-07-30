//
// Illustrate the GOF Observer pattern using Signal and Slots to illustrate its ease of use
//
// Created by Michael Lewis on 7/29/23.
//

#include <iostream>
#include <functional>

#include <boost/signals2.hpp>

using namespace std::placeholders;  // for _1, _2, _3...

// Part B - Create a slot
void CPrint(double x)
{
    std::cout << "C function: " << x << std::endl;
}

// Part B - Create another slot
struct Print
{
    void operator() (double x)
    {
        std::cout << "I am a printer " << x << std::endl;
    }
};

int main()
{
    // Part A - Create the signal (The subject)
    boost::signals2::signal<void (double)> signal;

    // Part C - Connect the slots (The observers)
    Print print;
    auto binder = std::bind(&Print::operator(), &print, _1);  // use a delayed variable that gets set by the subject
    signal.connect(boost::ref(binder));
    signal.connect(boost::ref(CPrint));

    // Part D - Emit the signal to test
    signal(7);

    // Disconnect the slots before exiting the program
    signal.disconnect(CPrint);
    signal.disconnect(boost::ref(binder));

    return 0;
}
//
// Created by Michael Lewis on 7/29/23.
//

#include <iostream>
#include <functional>

#include <boost/signals2.hpp>

#include "MyStruct.hpp"

// Function object that can be a slot for a signal
class FunctionObject
{
public:
    void operator()() { std::cout << "function object" << std::endl; }
};

// Free function that can be a slot for a signal
void freeFunction()
{
    std::cout << "free function" << std::endl;
}

// Part A - Create a signal and create slots using lambda functions, free functions
// and function objects. Connect the slots to the signal and emit the signal. Examine the output.
// NOTE - To be able to disconnect non-free functions, you must connect and disconnect using boost::ref
void test_signals_and_slots()
{
    // Create the signal
    boost::signals2::signal<void ()> signal;

    // Connect a slot represented by a lambda
    auto lambda = []{ std::cout << "Lambda" << std::endl; };
    signal.connect(boost::ref(lambda));

    // Connect a slot represented by a free function
    // Note boost::ref not required for free functions
    signal.connect(&freeFunction);

    // Connect a slot represented by a function object
    FunctionObject functionObject;
    signal.connect(boost::ref(functionObject));

    signal();

    // Part B - Create an instance of MyStruct and create a slot based on modify()
    // whose argument is equal to some value. Add this slot to the signal and then emit the signal.
    std::cout << "\n*** Connect another slot via std::bind + emit ***" << std::endl;
    MyStruct myStruct{3};
    auto thirdSlot = std::bind(&MyStruct::modify, &myStruct, 33);
    signal.connect(boost::ref(thirdSlot));

    signal();

    // Part C - Experiment with disconnecting slots in your code.
    std::cout << "\n*** Disconnect Slots + Nothing emitted ***" << std::endl;
    signal.disconnect(boost::ref(lambda));           // boost::ref required
    signal.disconnect(&freeFunction);
    signal.disconnect(boost::ref(functionObject));   // boost::ref required
    signal.disconnect(boost::ref(thirdSlot));        // boost::ref required
    signal();
}

// Part D - The example in parts a) to c) was based on one signal and several
// slots connected to it. An interesting observation is that a signal can also be
// connected to another signal! This allows us to create trees of signals and slots.
// As an exercise, create the signals A,B,C and D as well as the slots S1, S2, S3 and S4:
void test_signals_and_slots_tree()
{
    std::cout << "\n *** Signal Slot Tree ***" << std::endl;

    // Define potential emitters
    boost::signals2::signal<void ()> signalA;
    boost::signals2::signal<void ()> signalB;
    boost::signals2::signal<void ()> signalC;
    boost::signals2::signal<void ()> signalD;

    // Define slots
    auto slotB = []() {std::cout << "Slot B called by B\n " << std::endl; };
    auto slotC = []() {std::cout << "Slot C called by C\n " << std::endl; };
    auto slotD1 = []() {std::cout << "Slot D1 called by D\n " << std::endl; };
    auto slotD2 = []() {std::cout << "Slot D2 called by D\n " << std::endl; };

    // Connect Signal to other Signals
    signalA.connect(boost::ref(signalB));
    signalB.connect(boost::ref(signalC));
    signalC.connect(boost::ref(signalD));

    // Connect Slots to Signals
    signalB.connect(boost::ref(slotB));
    signalC.connect(boost::ref(slotC));
    signalD.connect(boost::ref(slotD1));
    signalD.connect(boost::ref(slotD2));

    // Emit the signal
    signalA();
    // Emitting from signalA is sufficient to emit all signals because all other signals are connected
    // via the signal and slot tree described above. Emitting the signals below will result in duplicate
    // signals being emitted.
    // signalB();
    // signalC();
    // signalD();


    // Examine what happens when you try to disconnect signal C from signal B.
    // Is it possible or do you have to first disconnect the terminal slot?
    std::cout << "*** Disconnecting Signal C from Signal B" << std::endl;
    signalB.disconnect(boost::ref(signalC));
    signalB();  // Calling SignalB or SignalA here works find and emits Slot B
}

int main()
{
    test_signals_and_slots();
    test_signals_and_slots_tree();
    return 0;
}
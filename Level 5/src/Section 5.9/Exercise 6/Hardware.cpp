//
// Hardware layer of the GOF Layered design pattern. The Hardware layer checks if data
// is in the range [2,4]; if not in the range it is set to the value 3.
//
// Note - Signals are non-copyable, so this Hardware layer is non-copy constructable.
//
// Created by Michael Lewis on 7/30/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_HARDWARE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_HARDWARE_CPP

#include <iostream>
#include <functional>

#include <boost/ref.hpp>

#include "Hardware.hpp"

/**
 * Overloaded ctor
 * @tparam T Data type of the change event
 * @param algorithm An algorithm that performs some generic operation on the incoming data
 */
template<typename T>
Hardware<T>::Hardware(std::function<void (T& value)> algorithm)
    : signalHardware(), algorithm{std::move(algorithm)}, data{}
{

}

/**
 * Dtor that disconnects the Slots from the Signal
 */
template<typename T>
Hardware<T>::~Hardware()
{
    std::cout << "Disconnecting Hardware layer" << std::endl;
    connection.disconnect();
}

/**
 * Connects a slot to the embedded signal. The slot should be the next layer higher up in the communication
 * stack
 * @tparam T Data type of the change event
 * @tparam Slot The type of the Slot
 * @param slot A Slot that will be connected to the embedded Signal. This Slot should be the Slot directly
 * above the current layer in the communication stack
 */
template<typename T>
template<typename Slot>
void Hardware<T>::connect(Slot& slot)
{
    connection = signalHardware.connect(boost::ref(slot));
    std::cout << "Hardware Layer Connected? " << std::boolalpha << connection.connected() << std::endl;
}

/**
 * Overloaded all operator that triggers the algorithm to operate on the data and emit the modified data
 * to the next layer higher up in the stack
 * @tparam T Data type of the change event
 * @param value The concrete data being operated on
 */
template<typename T>
void Hardware<T>::operator()(T& value)
{
    algorithm(value);
    data = value;
    signalHardware(data);
}

/**
 * Overloaded call operator that returns the data being operated on
 * @tparam T Data type of the change event
 * @return The data that has been operated on
 */
template<typename T>
T Hardware<T>::operator()() const
{
    return data;
}

/**
 * Disconnects the Slots from the Signal
 */
template<typename T>
void Hardware<T>::disconnect()
{
    connection.disconnect();
    std::cout << "Hardware Layer Connected? " << std::boolalpha << connection.connected() << std::endl;
}

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_HARDWARE_CPP
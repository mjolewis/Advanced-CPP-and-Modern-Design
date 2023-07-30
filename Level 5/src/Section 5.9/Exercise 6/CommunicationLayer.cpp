//
// Communication layer of the GOF Layered design pattern. The Communication layer
// formats and prints the data it receives from the data level. Note,
// signals are emitted from the hardware level, to the data layer, to the communication layer
//
// Note - Signals are non-copyable, so this Communication layer is non-copy constructable.
//
// Created by Michael Lewis on 7/30/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_COMMUNICATIONLAYER_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_COMMUNICATIONLAYER_CPP

#include <iostream>
#include <functional>

#include <boost/signals2.hpp>

#include "CommunicationLayer.hpp"

/**
 * Overloaded ctor
 * @tparam T Data type of the change event
 * @param algorithm An algorithm that performs some generic operation on the incoming data
 */
template<typename T>
CommunicationLayer<T>::CommunicationLayer(std::function<void (T& value)> algorithm)
    : signalCommunication(), algorithm{std::move(algorithm)}, data{}
{
}

/**
 * Dtor that disconnections the Slots from the Signal
 */
template<typename T>
CommunicationLayer<T>::~CommunicationLayer()
{
    std::cout << "Disconnecting Communication layer" << std::endl;
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
void CommunicationLayer<T>::connect(Slot& slot)
{
    connection = signalCommunication.connect(boost::ref(slot));
    std::cout << "Communication Layer Connected? " << std::boolalpha << connection.connected() << std::endl;
}

/**
 * Overloaded all operator that triggers the algorithm to operate on the data and emit the modified data
 * to the next layer higher up in the stack
 * @tparam T Data type of the change event
 * @param value The concrete data being operated on
 */
template<typename T>
void CommunicationLayer<T>::operator()(T& value)
{
    algorithm(value);
    data = value;
}

/**
 * Overloaded call operator that returns the data being operated on
 * @tparam T Data type of the change event
 * @return The data that has been operated on
 */
template<typename T>
T CommunicationLayer<T>::operator()() const
{
    return data;
}

/**
 * Disconnects the Slots from the Signal
 */
template<typename T>
void CommunicationLayer<T>::disconnect()
{
    connection.disconnect();
    std::cout << "Communication Layer Connected? " << std::boolalpha << connection.connected() << std::endl;
}

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_COMMUNICATIONLAYER_CPP
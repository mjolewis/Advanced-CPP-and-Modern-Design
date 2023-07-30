//
// Communication layer of the GOF Layered design pattern. The Communication layer
// formats and prints the data it receives from the data level. Note,
// signals are emitted from the hardware level, to the data layer, to the communication layer
//
// Note - Signals are non-copyable, so this Communication layer is non-copy constructable.
//
// Created by Michael Lewis on 7/30/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_COMMUNICATIONLAYER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_COMMUNICATIONLAYER_HPP

#include <functional>

#include <boost/signals2.hpp>

template<typename T>
class CommunicationLayer
{
private:
    boost::signals2::signal<void(T &d)> signalCommunication;
    boost::signals2::connection connection;
    T data;
    std::function<void (T& value)> algorithm;

public:
    explicit CommunicationLayer(std::function<void (T& value)> algorithm);
    ~CommunicationLayer();

    // Operator overloads
    void operator()(T& value);
    T operator()() const;

    template<typename Slot>
    void connect(Slot& value);
    void disconnect();
};

// ********** Template Definitions *********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_COMMUNICATIONLAYER_CPP
#include "CommunicationLayer.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_COMMUNICATIONLAYER_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_COMMUNICATIONLAYER_HPP

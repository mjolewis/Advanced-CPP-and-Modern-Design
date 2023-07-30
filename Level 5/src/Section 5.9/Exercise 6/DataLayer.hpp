//
// Data layer of the GOF Layered design pattern. The Data layer performs some
// modification of the data the it receives from the hardware level. Note,
// signals are emitted from the hardware level up to the data layer
//
// Note - Signals are non-copyable, so this Data layer is non-copy constructable.
//
// Created by Michael Lewis on 7/30/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DATALAYER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_DATALAYER_HPP

#include <functional>

#include <boost/signals2.hpp>

template<typename T>
class DataLayer
{
private:
    boost::signals2::signal<void(T &d)> signalData;
    boost::signals2::connection connection;
    T data;
    std::function<void (T& value)> algorithm;

public:
    explicit DataLayer(std::function<void (T& value)> algorithm);
    ~DataLayer();

    // Operator overloads
    void operator()(T& value);
    T operator()() const;

    template<typename Slot>
    void connect(Slot& value);
    void disconnect();
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_DATALAYER_CPP
#include "DataLayer.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DATALAYER_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_DATALAYER_HPP

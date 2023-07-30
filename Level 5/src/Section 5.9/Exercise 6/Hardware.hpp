//
// Hardware layer of the GOF Layered design pattern. The Hardware layer checks if data
// is in the range [2,4]; if not in the range it is set to the value 3.
//
// Note - Signals are non-copyable, so this Hardware layer is non-copy constructable.
//
// Created by Michael Lewis on 7/30/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_HARDWARE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_HARDWARE_HPP

#include <functional>

#include <boost/signals2.hpp>

template<typename T>
class Hardware
{
private:
    boost::signals2::signal<void(T &d)> signalHardware;
    boost::signals2::connection connection;
    T data;
    std::function<void (T& value)> algorithm;

public:
    explicit Hardware(std::function<void (T& value)> algorithm);
    Hardware(const Hardware& other) = delete;
    ~Hardware();

    // Operator overloads
    void operator()(T& value);
    T operator()() const;

    template<typename Slot>
    void connect(Slot& value);
    void disconnect();
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_HARDWARE_CPP
#include "Hardware.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_HARDWARE_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_HARDWARE_HPP

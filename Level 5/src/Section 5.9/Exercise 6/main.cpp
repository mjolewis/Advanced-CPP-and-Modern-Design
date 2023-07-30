//
// Illustrate the GOF Layered Pattern using Signals and Slots.
// Note - main represents the Exterior layer where the data is initialised.
// Note - General approach
//          1. Create classes that will hold algorithms, and emit the signal when an event is received
//          2. Instantiate these objects, giving them an algorithm and connecting them to the next layer
//          3. Emit the signal from the lowest level and watch signal flow up to all other levels
//
// Created by Michael Lewis on 7/29/23.
//

#include <iostream>
#include <iomanip>

#include <boost/signals2.hpp>

#include "Hardware.hpp"
#include "DataLayer.hpp"
#include "CommunicationLayer.hpp"

int main()
{
    // Used for code maintainability
    using value_type = double;

    // Hardware Layer - Validates the incoming data
    auto validation = [](value_type& value) { if (value < 2 || value > 5) value = 3; };
    Hardware<value_type> hardwareSignal(validation);

    // Data Layer - Modifies the data received from the Hardware Layer
    auto modifier = [](value_type& value) { value *= value; };
    DataLayer<value_type> dataSignal(modifier);

    // Communication Layer - Logs the data received from the Data Layer
    auto message = [](value_type& value) {
        std::cout << std::fixed << std::setprecision(2) << value << std::endl; };
    CommunicationLayer<value_type> communicationSignal(message);

    // Connect the Hardware Layer with the Exterior Layer
    boost::signals2::signal<void(value_type& d)> signalExterior;
    signalExterior.connect(boost::ref(hardwareSignal));

    // Connect the Data Layer with the Hardware Layer
    hardwareSignal.connect(dataSignal);

    // Connect the Communication Layer with the DataLayer
    dataSignal.connect(communicationSignal);

    // Signal event received
    value_type value = -3.7; // in range [2.0, 4.0]
    signalExterior(value);

    value = 2.0; // in range [2.0, 4.0]
    signalExterior(value);

    value = 2.5; // in range [2.0, 4.0]
    signalExterior(value);

    return 0;
}
//
// A simple singled threaded Command-Processor pattern in which executable commands
// are inserted into a priority queue. When finished, a consumer can execute each command
// at some point in the future.
//
// Created by Michael Lewis on 7/4/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_COMMAND_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_COMMAND_HPP

#include <iostream>
#include <functional>
#include <thread>

using FunctionType = std::function<double (double)>;
using namespace std::chrono_literals;

class Command
{
private:
    long ID; // priority of command
    FunctionType algo;
public:
    Command(const FunctionType& algorithm, long priority)
            : algo(algorithm), ID(priority){}

    void Execute(double x) {
        // Introduce delay to simulate a heavy algorithm
        std::this_thread::sleep_for(5000ms); // Use STL to replace boost
//        std::this_thread::sleep(boost::posix_time::millisec(5000));
        std::cout << algo(x) << '\n';
    }

    long priority() const
    {
        return ID;
    }
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_COMMAND_HPP

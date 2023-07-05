//
// A simple test program to illustrate a  singled threaded Command-Processor
// pattern in which executable commands are cached into a vector and run at
// a future time.

// Created by Michael Lewis on 7/4/23.
//

#include <iostream>
#include <functional>
#include <queue>
#include <vector>

#include "Command.hpp"

int main()
{
    // Part A - Create a comparator for Command to compare two of its instances.
    auto comparator = [](const Command& lhs, const Command& rhs) -> bool {
        return lhs.priority() < rhs.priority(); };

    // Part B - Create several instances of Command.
    Command command1([](double value) -> double {std::cout << "Command=1 : ID=1 : Value="; return value;}, 1);
    Command command2([](double value) -> double {std::cout << "Command=2 : ID=2 : Value="; return value;}, 2);
    Command command3([](double value) -> double {std::cout << "Command=3 : ID=3 : Value="; return value;}, 3);
    Command command4([](double value) -> double {std::cout << "Command=4 : ID=4 : Value="; return value;}, 4);

    // Part C - Create a priority queue of commands and insert the objects from part b) into it.
    std::priority_queue<Command, std::vector<Command>, decltype(comparator)> priorityQueue{comparator};
    priorityQueue.push(command1);
    priorityQueue.push(command2);
    priorityQueue.push(command3);
    priorityQueue.push(command4);

    // Part D - Execute each command in the priority queue until it is empty.
    while (!priorityQueue.empty())
    {
        Command c = priorityQueue.top();
        c.Execute(50);
        priorityQueue.pop();
    }
}
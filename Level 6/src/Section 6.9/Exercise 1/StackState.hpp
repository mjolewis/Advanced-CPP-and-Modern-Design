//
// A base State class that whose derived classes will behave as the concrete States that a
// Stack can transition through
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACKSTATE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_STACKSTATE_HPP

#include <memory>

// Forward Declaration - Required for circular dependency between StackState and Stack
template<typename T>
class Stack;

template<typename T>
class StackState
{
public:
    constexpr StackState() = default;
    StackState(const StackState<T>& other) = default;
    StackState(StackState<T>&& other) = default;
    virtual ~StackState() = default;

    // Operator Overloads
    StackState<T>& operator=(const StackState<T>& other) = default;
    StackState<T>& operator=(StackState<T>&& other) = default;

    // Core Functionality
    virtual void push(Stack<T>* stack, const T& element);
    virtual T pop(Stack<T>* stack);

    void changeState(Stack<T>* stack, StackState<T>* state);
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACKSTATE_CPP
#include "StackState.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_STACKSTATE_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_STACKSTATE_HPP

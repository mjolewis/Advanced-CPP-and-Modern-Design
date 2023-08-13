//
// A derived State object that represents on of three possible States that a Stack can be in
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_EMPTYSTATE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_EMPTYSTATE_HPP

#include "StackState.hpp"
#include "Singleton.hpp"

// Forward Declaration - Required for circular dependency between EmptyState and Stack
template<typename T>
class Stack;

template<typename T>
class EmptyState : public StackState<T>
{
private:
    friend class Singleton<EmptyState<T>>;
public:
    constexpr EmptyState();
    EmptyState(const EmptyState<T>& other) = default;
    EmptyState(EmptyState<T>&& other) = default;
    ~EmptyState() override = default;

    // Operator Overloads
    EmptyState<T>& operator=(const EmptyState<T>& other) = default;
    EmptyState<T>& operator=(EmptyState<T>&& other) = default;

    // Core Functionality
    void push(Stack<T>* stack, const T& element) override;
    T pop(Stack<T>* stack) override;

    static EmptyState<T>* Instance();                // Return a unique instance
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_EMPTYSTATE_CPP
#include "EmptyState.cpp"
#endif

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_EMPTYSTATE_HPP

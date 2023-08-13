//
// A derived State object that represents on of three possible States that a Stack can be in
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_FULLSTATE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_FULLSTATE_HPP

#include "StackState.hpp"

// Forward Declaration - Required for circular dependency between StackState and Stack
template<typename T>
class Stack;

template<typename T>
class FullState : public StackState<T>
{
private:
    friend class Singleton<FullState<T>>;

public:
    constexpr FullState();
    FullState(const FullState<T>& other) = default;
    FullState(FullState<T>&& other) = default;
    ~FullState() override = default;

    // Operator Overloads
    FullState& operator=(const FullState<T>& other) = default;
    FullState& operator=(FullState<T>&& other) = default;

    // Core Functionality
    void push(Stack<T>* stack, const T& element) override;
    T pop(Stack<T>* stack) override;

    static FullState<T>* Instance();                // Return a unique instance
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_FULLSTATE_CPP
#include "FullState.cpp"
#endif

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_FULLSTATE_HPP

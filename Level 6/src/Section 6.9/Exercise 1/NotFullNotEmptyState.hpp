//
// A derived State object that represents on of three possible States that a Stack can be in
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NOTFULLNOTEMPTYSTATE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_NOTFULLNOTEMPTYSTATE_HPP

#include "StackState.hpp"

// Forward Declaration - Required for circular dependency between StackState and Stack
template<typename T>
class Stack;

template<typename T>
class NotFullNotEmptyState : public StackState<T>
{
private:
    friend class Singleton<NotFullNotEmptyState<T>>;

public:
    constexpr NotFullNotEmptyState();
    NotFullNotEmptyState(const NotFullNotEmptyState<T>& other) = default;
    NotFullNotEmptyState(NotFullNotEmptyState<T>&& other) = default;
    ~NotFullNotEmptyState() override = default;

    // Operator Overloads
    NotFullNotEmptyState<T>& operator=(const NotFullNotEmptyState<T>& other) = default;
    NotFullNotEmptyState<T>& operator=(NotFullNotEmptyState<T>&& other) = default;

    // Core Functionality
    void push(Stack<T>* stack, const T& element) override;
    T pop(Stack<T>* stack) override;

    static NotFullNotEmptyState<T>* Instance();                // Return a unique instance
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NOTFULLNOTEMPTYSTATE_CPP
#include "NotFullNotEmptyState.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_NOTFULLNOTEMPTYSTATE_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_NOTFULLNOTEMPTYSTATE_HPP

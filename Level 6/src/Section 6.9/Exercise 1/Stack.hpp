//
// A Stack is a FIFO data structure. However, the main purpose of this Stack is to illustrate the
// State Pattern. The Stake will transition between an EmptyState, a NotFullNotEmptyState and a
// FullState
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACK_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_STACK_HPP

#include <array>
#include <cstddef>
#include <memory>

// Forward Declaration - Required for circular dependency between StackState and Stack
template<typename T>
class StackState;

template<typename T>
class EmptyState;

template<typename T>
class NotFullNotEmptyState;

template<typename T>
class FullState;

template<typename T>
class Stack
{
private:
    std::shared_ptr<T[]> stack;
    size_t size;
    int currentIdx;
    StackState<T>* state;

private:
    friend class StackState<T>;
    friend class EmptyState<T>;
    friend class NotFullNotEmptyState<T>;
    friend class FullState<T>;
    void init(const size_t& size);
    void changeState(StackState<T>* _state);

public:
    constexpr Stack();
    explicit Stack(const size_t& size);
    Stack(const Stack<T>& other) = default;
    Stack(Stack<T>&& other) = default;
    ~Stack() = default;

    // Operator Overloads
    Stack<T>& operator=(const Stack<T>& other) = default;
    Stack<T>& operator=(Stack<T>&& other) = default;

    // Core Functionality
    void push(const T& element);
    T pop();
};
// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACK_CPP
#include "Stack.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_STACK_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_STACK_HPP

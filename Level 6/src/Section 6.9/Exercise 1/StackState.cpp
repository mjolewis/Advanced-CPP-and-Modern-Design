//
// A base State class that whose derived classes will behave as the concrete States that a
// Stack can transition through
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACKSTATE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_STACKSTATE_CPP

#include "Stack.hpp"
#include "StackState.hpp"

template<typename T>
void StackState<T>::push(Stack<T>* stack, const T& element)
{
    stack->stack[stack->currentIdx++] = element;
}

template<typename T>
T StackState<T>::pop(Stack<T>* stack)
{
    return stack->stack[--stack->currentIdx];
}

template<typename T>
void StackState<T>::changeState(Stack<T>* stack, StackState<T>* state)
{
    stack->changeState(state);
}

#endif
//
// A derived State object that represents on of three possible States that a Stack can be in
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_EMPTYSTATE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_EMPTYSTATE_CPP

#include <stdexcept>

#include "Stack.hpp"
#include "StackState.hpp"
#include "EmptyState.hpp"
#include "FullState.hpp"

template<typename T>
constexpr EmptyState<T>::EmptyState() : StackState<T>()
{

}

template<typename T>
void EmptyState<T>::push(Stack<T>* stack, const T& element)
{
    StackState<T>::push(stack, element);
    if (stack->currentIdx == stack->size) this->changeState(stack, FullState<T>::Instance());
    else this->changeState(stack, NotFullNotEmptyState<T>::Instance());
}

/**
 * Throws an out of range exception because you cannot pop from an empty stack
 * @throws std::out_of_range
 */
template<typename T>
T EmptyState<T>::pop(Stack<T>* stack)
{
    throw std::out_of_range("Empty Stack");
}

template<typename T>
EmptyState<T>* EmptyState<T>::Instance()
{
    return Singleton<EmptyState<T>>::instance();
}

#endif

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

/**
 * Default ctor
 * @tparam T The data type contained in the stack
 */
template<typename T>
constexpr EmptyState<T>::EmptyState() : StackState<T>()
{

}

/**
 * Push an element onto a stack
 * @tparam T The data type contained in the stack
 * @param stack The stack to push onto
 * @param element The element to push
 */
template<typename T>
void EmptyState<T>::push(Stack<T>* stack, const T& element)
{
    StackState<T>::push(stack, element);
    if (stack->currentIdx == stack->size) this->changeState(stack, FullState<T>::Instance());
    else this->changeState(stack, NotFullNotEmptyState<T>::Instance());
}

/**
 * Throws an out of range exception because you cannot pop from an empty stack
 * @tparam T The data type contained in the stack
 * @param stack The stack to push onto
 * @return The element at the top of the stack
 * @throws std::out_of_range
 */
template<typename T>
T EmptyState<T>::pop(Stack<T>* stack)
{
    throw std::out_of_range("Empty Stack");
}

/**
 * Leverages the Singleton pattern to create or retrieve the single instance of a FullState
 * @tparam T The data type contained in the stack
 * @return The single instance of FullState
 */
template<typename T>
EmptyState<T>* EmptyState<T>::Instance()
{
    return Singleton<EmptyState<T>>::instance();
}

#endif

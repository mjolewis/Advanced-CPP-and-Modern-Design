//
// A derived State object that represents on of three possible States that a Stack can be in
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NOTFULLNOTEMPTYSTATE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_NOTFULLNOTEMPTYSTATE_CPP

#include "Stack.hpp"
#include "StackState.hpp"
#include "EmptyState.hpp"
#include "FullState.hpp"
#include "NotFullNotEmptyState.hpp"

template<typename T>
constexpr NotFullNotEmptyState<T>::NotFullNotEmptyState() : StackState<T>()
{

}

template<typename T>
void NotFullNotEmptyState<T>::push(Stack<T>* stack, const T& element)
{
    StackState<T>::push(stack, element);
    if (stack->currentIdx == stack->size) this->changeState(stack, FullState<T>::Instance());
}

template<typename T>
T NotFullNotEmptyState<T>::pop(Stack<T>* stack)
{
    if (stack->currentIdx == 1) this->changeState(stack, EmptyState<T>::Instance());
    return StackState<T>::pop(stack);
}

template<typename T>
NotFullNotEmptyState<T>* NotFullNotEmptyState<T>::Instance()
{
    return Singleton<NotFullNotEmptyState<T>>::instance();
}

#endif


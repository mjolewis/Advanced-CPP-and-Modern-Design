//
// A derived State object that represents on of three possible States that a Stack can be in
//
// Note - As the main purpose of this Class is to illustrate the State pattern, ctors and assignment
// operators are defaulted for simplicity.
//
// Created by Michael Lewis on 8/12/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_FULLSTATE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_FULLSTATE_CPP

#include "Stack.hpp"
#include "StackState.hpp"
#include "EmptyState.hpp"
#include "FullState.hpp"
#include "NotFullNotEmptyState.hpp"

template<typename T>
constexpr FullState<T>::FullState() : StackState<T>()
{

}

/**
 * Throws an out of range exception because you cannot push onto a full stack
 * @throws std::out_of_range
 */
template<typename T>
void FullState<T>::push(Stack<T>* stack, const T& element)
{
    throw std::out_of_range("Full Stack");
}

template<typename T>
T FullState<T>::pop(Stack<T>* stack)
{
    if (stack->currentIdx == 1) this->changeState(stack, EmptyState<T>::Instance());
    else this->changeState(stack, NotFullNotEmptyState<T>::Instance());
    return StackState<T>::pop(stack);
}

template<typename T>
FullState<T>* FullState<T>::Instance()
{
    return Singleton<FullState<T>>::instance();
}

#endif



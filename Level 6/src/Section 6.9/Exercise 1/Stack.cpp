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

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACK_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_STACK_CPP

#include <memory>

#include "Stack.hpp"
#include "StackState.hpp"
#include "EmptyState.hpp"

/**
 * Default ctor
 * @tparam T The data type contained in the stack
 */
template<typename T>
constexpr Stack<T>::Stack() : currentIdx{0}, state{}, size{1}
{
    init(1);
}

/**
 * Overloaded ctor
 * @tparam T The data type contained in the stack
 * @param _size The size of the stack
 */
template<typename T>
Stack<T>::Stack(const size_t& _size) : currentIdx{0}, state{}, size{_size}
{
    init(_size);
}

/**
 * Initializes the stack. If size is less than one, then this function overrides the size with a default size
 * of one
 * @tparam T The data type contained in the stack
 * @param _size The size of the stack
 */
template<typename T>
void Stack<T>::init(const size_t& _size)
{
    if (_size < 1)
    {
        stack = std::make_unique<T[]>(1);
        size = 1;
    }
    else
    {
        stack = std::make_unique<T[]>(size);
        size = _size;
    }

    currentIdx = 0;
    state = EmptyState<T>::Instance();
}

/**
 * Transitions the stack into the next state. Follows a state transition diagram based on the number
 * of elements in the stack
 * @tparam T The data type contained in the stack
 * @param state The new state of the stack
 */
template<typename T>
void Stack<T>::changeState(StackState<T>* _state)
{
    state = _state;
}

/**
 * Push an element onto a stack
 * @tparam T The data type contained in the stack
 * @param element The element to push
 */
template<typename T>
void Stack<T>::push(const T &element)
{
    state->push(this, element);
}

/**
 * Removes and returns an element from the top of the stack
 * @tparam T The data type contained in the stack
 * @return The element at the top of the stack
 */
template<typename T>
T Stack<T>::pop()
{
    return state->pop(this);
}

#endif
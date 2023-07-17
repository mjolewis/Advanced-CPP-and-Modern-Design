//
// A simple Stack ADT that will be used to demonstrate basic non-modifying, modifying, and removing
// algorithms. This class acts as an adapter to a std::stack using std::deque as the underlying container
//
// Created by Michael Lewis on 7/17/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACK_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_STACK_CPP

#include <algorithm>
#include <deque>

#include "Stack.hpp"

/**
 * Copy Ctor
 * @tparam T Data type of elements stored in this stack
 * @param other Another Stack whose members will be copied into this Stack
 */
template<typename T>
Stack<T>::Stack(const Stack<T> &other)
{
    // Create a deep copy
    stack = std::deque<T>{};
    for (int i = 0; i < other.stack.size(); ++i)
    {
        stack[i] = other.stack[i];
    }
}

/**
 * Move ctor
 * @tparam T Data type of elements stored in this stack
 * @param other Another Stack whose members will be moved into this Stack
 */
template<typename T>
Stack<T>::Stack(Stack<T>&& other) noexcept
{
    stack = std::deque<T>{};
    std::move(other.stack.begin(), other.stack.end(), stack.begin());
}

/**
 * Copy assignment
 * @tparam T Data type of elements stored in this stack
 * @param other Another Stack whose members will be assigned into this Stack
 * @return This Stack whose members have been assigned to the Other stack
 */
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    // Avoid self assign
    if (this == other) return *this;

    stack = std::deque<T>{};
    stack = std::move(other.stack);

    return *this;
}

/**
 * Move assignment
 * @tparam T Data type of elements stored in this stack
 * @param other Another Stack whose members will be assigned into this Stack
 * @return This Stack whose members have been moved from the Other stack
 */
template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& other)  noexcept
{
    // Avoid self assign
    if (this == other) return *this;

    stack = std::move(other.stack);

    return *this;
}

/**
 * Pushes the given element value to the top of the stack.
 * @tparam T Data type of elements stored in this stack
 * @param value The value of the element to push
 */
template<typename T>
void Stack<T>::push(const T &value)
{
    stack.push_front(value);
}

/**
 * Returns a reference to the element at specified location pos. No bounds checking is performed.
 * @tparam T Data type of elements stored in this stack
 * @param pos The zero based position of the element to return
 * @return The value of the element stored at pos
 */
template<typename T>
const T& Stack<T>::operator[](size_t pos) const
{
    return stack[pos];
}

/**
 * Returns a reference to the element at specified location pos. No bounds checking is performed.
 * @tparam T Data type of elements stored in this stack
 * @return The value at the top of the stack
 */
template<typename T>
const T& Stack<T>::top() const
{
    return stack.front();
}

/**
 * Pops the larger of the top two values on the stack
 * @tparam T Data type of elements stored in this stack
 */
template<typename T>
void Stack<T>::max()
{
    auto it = std::max_element(stack.cbegin(), stack.cend());
    T max = *it;
    stack.erase(it);
    stack.push_front(max);
}

/**
 * Pops the lesser of the top two values on the stack
 * @tparam T Data type of elements stored in this stack
 */
template<typename T>
void Stack<T>::min()
{
    auto it = std::min_element(stack.cbegin(), stack.cend());
    T min = *it;
    stack.erase(it);
    stack.push_front(min);
}

/**
 * Duplicates the second stack value on top of the stack.
 * Note - Per https://quantnet.com/threads/8-clarification-of-requirement.33814/post-322015
 * The stack size should increase
 * @tparam T Data type of elements stored in this stack
 */
template<typename T>
void Stack<T>::over()
{
    // Put the second element onto the top of the stack
    stack.push_front(stack[1]);
}

/**
 * Rotate the stack's third data value to the top of the stack.
 * Note - Per https://quantnet.com/threads/8-clarification-of-requirement.33814/post-249174
 * The stack size should remain unchanged by this operation
 * @tparam T Data type of elements stored in this stack
 */
template<typename T>
void Stack<T>::rot()
{
    // Put the third element onto the top of the stack
    stack.push_front(stack[2]);
}

/**
 * Interchange the top two values on the stack.
 * Note - Per https://quantnet.com/threads/8-clarification-of-requirement.33814/post-249174
 * The stack size should remain unchanged by this operation
 * @tparam T Data type of elements stored in this stack
 */
template<typename T>
void Stack<T>::swap()
{
    T top = stack[0];
    stack.pop_front();

    T next = stack[0];
    stack.pop_front();

    // Swap the top two elements
    stack.push_front(top);
    stack.push_front(next);
}

/**
 * Discard the value on the top of the stack.
 * @tparam T Data type of elements stored in this stack
 */
template<typename T>
void Stack<T>::discard()
{
    stack.pop_front();
}

// ********** Iterators **********

/**
 * Returns an iterator to the first element of the array.
 * If the array is empty, the returned iterator will be equal to end().
 * @tparam T Data type of the elements stored in this std::vector
 * @tparam N The size of this Vector
 * @return Iterator to the first element.
 */
template<typename T>
constexpr typename std::deque<T>::iterator Stack<T>::begin() noexcept
{
    return stack.begin();
}

/**
 * Returns an iterator to the element following the last element of the stack.
 * This element acts as a placeholder; attempting to access it results in undefined behavior.
 * @tparam T Data type of the elements stored in this std::vector
 * @return Iterator to the element following the last element.
 */
template<typename T>
constexpr typename std::deque<T>::iterator Stack<T>::end() noexcept
{
    return stack.end();
}

/**
 * Returns an iterator to the first element of the stack.
 * If the array is empty, the returned iterator will be equal to end().
 * @tparam T Data type of the elements stored in this std::vector
 * @return Iterator to the first element.
 */
template<typename T>
constexpr typename std::deque<T>::const_iterator Stack<T>::begin() const noexcept
{
    return stack.begin();
}

/**
 * Returns an iterator to the element following the last element of the stack.
 * This element acts as a placeholder; attempting to access it results in undefined behavior.
 * @tparam T Data type of the elements stored in this std::vector
 * @return Iterator to the element following the last element.
 */
template<typename T>
constexpr typename std::deque<T>::const_iterator Stack<T>::end() const noexcept
{
    return stack.end();
}

/**
 * Returns an iterator to the first element of the stack.
 * If the array is empty, the returned iterator will be equal to end().
 * @tparam T Data type of the elements stored in this std::vector
 * @return Constant iterator to the first element.
 */
template<typename T>
constexpr typename std::deque<T>::const_iterator Stack<T>::cbegin() const noexcept
{
    return stack.cbegin();
}

/**
 * Returns an iterator to the element following the last element of the stack.
 * This element acts as a placeholder; attempting to access it results in undefined behavior.
 * @tparam T Data type of the elements stored in this std::vector
 * @return Constant iterator to the element following the last element.
 */
template<typename T>
constexpr typename std::deque<T>::const_iterator Stack<T>::cend() const noexcept
{
    return stack.cend();
}

#endif

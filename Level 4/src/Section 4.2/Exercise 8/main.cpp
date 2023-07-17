//
// Categorize and implement simply mutating algorithms by creating an adapter for a std::stack
// Note - The Stack is a LIFO data structure
//
// Created by Michael Lewis on 7/17/23.
//

/*
 * Part A - In which categories do these stack operations belong?
 *
 * max(), min() : leaves on the stack the larger and lesser of the two top values, respectively.
 * over() : duplicates the second stack value on top of the stack.
 * rot() : rotate the stack's third data value to the top of the stack.
 * swap() : interchange the top two values on the stack.
 * drop() : discard the value on the top of the stack.
 *
 * Response:
 * max(), min() : mutating
 * over() : mutating
 * rot() : mutating
 * swap() : mutating
 * drop() : Removing
*/

#include <cassert>
#include <iostream>
#include <random>

#include "Stack.hpp"

// Simple helper that creates a stack. Stack values are literals (versus random) so as to create
// deterministic unit tests
template<typename T>
Stack<T> createStack()
{
    Stack<T> stack;
    stack.push(84);  // bottom of the stack
    stack.push(91);
    stack.push(75);
    stack.push(100);
    stack.push(0);
    stack.push(35);
    stack.push(78);
    stack.push(39);
    stack.push(56);
    stack.push(49); // top of the stack

    return stack;
}

// Test moving the max element to the top of the stack
void test_max()
{
    Stack<int> stack = createStack<int>();
    stack.max();

    std::cout << "\nMax: ";
    for (auto value : stack) std::cout << value << ", ";
    assert(100 == stack.top());
}

// Test moving the min value to the top of the stack
void test_min()
{
    Stack<int> stack = createStack<int>();
    stack.min();

    std::cout << "\nMin: ";
    for (auto value : stack) std::cout << value << ", ";
    assert(0 == stack.top());
}

// Test duplicating the second stack value on top of the stack.
void test_over()
{
    Stack<int> stack = createStack<int>();
    stack.over();

    std::cout << "\nOver: ";
    for (auto value : stack) std::cout << value << ", ";
    assert(56 == stack[0]);
    assert(49 == stack[1]);
    assert(56 == stack[2]);
}

// Test rotating the stack's third data value to the top of the stack
void test_rotate()
{
    Stack<int> stack = createStack<int>();
    stack.rot();

    std::cout << "\nRotate: ";
    for (auto value : stack) std::cout << value << ", ";
    assert(39 == stack[0]);
    assert(49 == stack[1]);
    assert(56 == stack[2]);
    assert(39 == stack[3]);
}

// Test interchanging the top two values on the stack
void test_swap()
{
    Stack<int> stack = createStack<int>();
    stack.swap();

    std::cout << "\nSwap: ";
    for (auto value : stack) std::cout << value << ", ";
    assert(56 == stack[0]);
    assert(49 == stack[1]);
}

// Test discarding the value on the top of the stack
void test_discard()
{
    Stack<int> stack = createStack<int>();
    stack.discard();

    std::cout << "\nDiscard: ";
    for (auto value : stack) std::cout << value << ", ";
    assert(56 == stack.top());
}

int main()
{
    // Log initial stack to console for ease of comparison
    Stack<int> stack = createStack<int>();
    std::cout << "\nInitial Values: ";
    for (auto value : stack) std::cout << value << ", ";

    test_max();
    test_min();
    test_over();
    test_rotate();
    test_swap();
    test_discard();
    return 0;
}

//
// Tests the Stack along with its State transitions from an EmptyState, NotFullNotEmptyState, to a FullState
//
// Created by Michael Lewis on 8/13/23.
//

#include <cassert>
#include <iostream>
#include <stdexcept>

#include "Stack.hpp"

// Test stack full exception using default stack size of 1
void test_StackFullState()
{
    Stack<double> stack;  // Default size of 1

    try
    {
        stack.push(2);
        stack.push(3);  // Throws exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_StackTransitions()
{
    Stack<double> stack{3};

    try
    {
        stack.push(1);
        stack.push(2);
        stack.push(3); // stack is full

        double actual = stack.pop();
        assert(3 == actual);

        actual = stack.pop();
        assert(2 == actual);

        actual = stack.pop();
        assert(1 == actual);  // Stack is empty
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_EmptyStack()
{
    Stack<double> stack{3};

    try
    {
        stack.push(1);
        stack.push(2);
        stack.push(3); // stack is full

        double actual = stack.pop();
        assert(3 == actual);

        actual = stack.pop();
        assert(2 == actual);

        actual = stack.pop();
        assert(1 == actual);  // Stack is empty

        // Stack is empty - Popping throws an exception
        stack.pop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    test_StackFullState();
    test_StackTransitions();
    test_EmptyStack();

    return 0;
}

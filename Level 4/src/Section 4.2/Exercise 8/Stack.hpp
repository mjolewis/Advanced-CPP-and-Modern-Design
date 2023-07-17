//
// A simple Stack ADT that will be used to demonstrate basic non-modifying, modifying, and removing
// algorithms. This class acts as an adapter to a std::stack using std::deque as the underlying container
//
// Created by Michael Lewis on 7/17/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACK_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_STACK_HPP

#include <deque>

template<typename T>
class Stack
{
private:
    std::deque<T> stack;

public:
    Stack() = default;
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    ~Stack() = default;

    // Operator overloads
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;
    const T& operator[](size_t index) const;

    // Core functionality
    void push(const T& value);
    const T& top() const;

    // Mutating
    void min();
    void max();
    void over();
    void rot();
    void swap();
    void discard();

    // Iterators
    constexpr typename std::deque<T>::iterator begin() noexcept;
    constexpr typename std::deque<T>::iterator end() noexcept;
    constexpr typename std::deque<T>::const_iterator begin() const noexcept;
    constexpr typename std::deque<T>::const_iterator end() const noexcept;
    constexpr typename std::deque<T>::const_iterator cbegin() const noexcept;
    constexpr typename std::deque<T>::const_iterator cend() const noexcept;
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STACK_CPP
#include "Stack.cpp"
#endif // ADVANCED_CPP_AND_MODERN_DESIGN_STACK_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_STACK_HPP

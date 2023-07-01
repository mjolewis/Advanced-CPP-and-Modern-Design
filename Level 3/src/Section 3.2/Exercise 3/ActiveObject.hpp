//
// Illustrate an active object, which is a concurrency design pattern used to separate the function
// invocation from its execution. It is an object that executes in its own thread of control.
// One advantage of creating/using active objects is that it results in a one-to-one correspondence
// between an object and a thread.
//
// @Note - This ActiveObject is not CopyConstructible, MoveConstructible, CopyAssignable,
// or MoveAssignable to ensure a one-to-one ownership between master and workers.
//
// Created by Michael Lewis on 7/1/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_ACTIVEOBJECT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_ACTIVEOBJECT_HPP

#include <thread>

class ActiveObject
{
private:
    std::thread& worker;  // Note, per std::thread specs, thread functions are non const, so the worker is non-const

public:
    ActiveObject() = delete;
    explicit ActiveObject(std::thread& worker);
    ActiveObject(const ActiveObject& source) = delete;
    ActiveObject(ActiveObject&& source) = delete;
    ~ActiveObject();

    // Operator overloads
    ActiveObject& operator=(const ActiveObject& source) = delete;
    ActiveObject& operator=(ActiveObject&& source) = delete;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_ACTIVEOBJECT_HPP

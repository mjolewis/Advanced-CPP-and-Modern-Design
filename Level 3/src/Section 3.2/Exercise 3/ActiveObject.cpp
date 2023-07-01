//
// Illustrate an active object, which is a concurrency design pattern used to separate the function
// invocation from its execution. It is an object that executes in its own thread of control.
// One advantage of creating/using active objects is that it results in a one-to-one correspondence
// between an object and a thread.
//
// Created by Michael Lewis on 7/1/23.
//

#include <sstream>
#include <stdexcept>
#include <thread>

#include "ActiveObject.hpp"

/**
 * Overloaded ctor that encapsulates the work to be performed by this worker.
 * @param worker A std::thread with (or without) a thread function.
 * @throws std::logic_error A precondition of this ActiveObject is that the incoming thread must
 * be associated with a thread function. Otherwise, a std::logic error is thrown.
 */
ActiveObject::ActiveObject(std::thread& worker) : worker{worker}
{
    // Perform validation as soon as this object is constructed. Acts as a minor optimization
    // to inform clients as soon as possible that this ActiveObject is invalid
    if (worker.get_id() == std::thread::id())
    {
        std::stringstream ss;
        ss << worker.get_id();
        throw std::logic_error("Thread is not joinable. ThreadId=" + ss.str());
    }
}

/**
 * This dtor will ensure that the thread is joined if it is joinable
 */
ActiveObject::~ActiveObject()
{
    if (worker.joinable()) worker.join();
}



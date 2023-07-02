//
// Created by Michael Lewis on 7/1/23.
//

#include <iostream>
#include <memory>
#include <thread>

// Part A - Set up data needed to implement a simple Master Worker pattern
// Types and data needed
std::string data;// Shared data between master and worker
std::mutex m; // Ensures no race condition

// Synchronization between master and worker
std::condition_variable cv;

// Initial state of worker and master
std::atomic<bool> workerReady = false;
std::atomic<bool> masterReady = false;

// Initial state of worker and master
std::atomic_flag workerFlag = ATOMIC_FLAG_INIT;;
std::atomic_flag masterFlag = ATOMIC_FLAG_INIT;;

// Create the thread function: it updates the resource by acquiring the
// lock, waiting on the atomic<bool> worker flag to be set, updating the resource
// and then finally notifying the master.
void WorkerThread_AtomicBool()
{
    std::unique_lock<std::mutex> workerLock{m}; // cv.wait requires a std::unique_lock
    cv.wait(workerLock, []() {return workerReady.load();}); // Wait until the master gives us data to process
    data += " - Worker Processing (Atomic Bool)"; // Process the data

    // Notify master that worker is done
    masterReady = true;
    workerLock.unlock();
    cv.notify_one();
}

// Create the code that implements the master’s duties. Test the code.
void MasterThread_AtomicBool()
{
    // Create the worker
    std::thread workerThread(WorkerThread_AtomicBool);

    // Set up the data to be processed
    data = "Master Directing (Atomic Bool)";

    // Tell the worker to start work
    {
        std::lock_guard<std::mutex> masterLock{m};
        workerReady = true;
        // lock is released after scope ends
    }

    // Notify the worker
    cv.notify_one();

    // Master waits for its workers to complete their jobs
    {
        std::unique_lock<std::mutex> masterLock{m};
        cv.wait(masterLock, []() {return masterReady.load();});
        masterLock.unlock();
    }

    if (workerThread.joinable()) workerThread.join();
}

// Create the thread function that updates the resource by acquiring the
// lock, waiting on the workers atomic_flag to be set, updating the resource
// and then finally notifying the master.
void WorkerThread_AtomicFlag()
{
    std::unique_lock<std::mutex> workerLock{m};
    // See https://stackoverflow.com/questions/65336409/what-does-memory-order-consume-really-do
    // for additional detail on std::memory_order_consume
    cv.wait(workerLock, []() {return workerFlag.test(std::memory_order_consume);});
    data += " - Worker Processing (Atomic Flag)"; // Process the data

    // Notify Master than Worker is done processing and release resources
    masterFlag.test_and_set(std::memory_order_acquire);
    workerLock.unlock();
    cv.notify_one();
}

void MasterThread_AtomicFlag()
{
    // Create the worker
    std::thread workerThread(WorkerThread_AtomicFlag);

    // Set up the data to be processed
    data = "Master Directing (Atomic Flag)";

    // Tell the worker to start work
    {
        std::lock_guard<std::mutex> masterLock{m};
        workerFlag.test_and_set(std::memory_order_consume);
        // lock is released after scope ends
    }

    // Notify the worker
    cv.notify_one();

    // Master waits for its workers to complete their jobs
    {
        std::unique_lock<std::mutex> masterLock{m};
        cv.wait(masterLock, []() {return masterFlag.test(std::memory_order_acquire);});
        masterLock.unlock();
    }

    if (workerThread.joinable()) workerThread.join();
}

int main()
{
    // Test Parts A - C
    MasterThread_AtomicBool();
    std::cout << data << std::endl;

    // Test Parts A, B, and D
    MasterThread_AtomicFlag();
    std::cout << data << std::endl;

    return 0;
}
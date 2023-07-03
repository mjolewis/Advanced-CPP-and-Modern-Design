//
// Illustrate the core concepts of a Packaged_Task, which is that we can create a
// background task without starting it immediately. This model is particularly useful
// when wanting to start a task in a separate thread. You can simply package the task
// and ship it off to another thread for exeuction.
//
// Created by Michael Lewis on 7/2/23.
//

#include <future>
#include <chrono>
#include <iostream>
#include <queue>
#include <random>
#include <thread>

// Thread function
double compute(double x, double y)
{
    // Wait a while
    std::default_random_engine dre(42);
    std::uniform_int_distribution<int> delay(0, 1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay(dre)));

    return std::cos(x) * std::exp(y);
}

// Rewrite the provided code using packaged tasks and deferred execution
void test_PartB()
{
    // Wrap the task
    std::packaged_task<double (double, double)> packagedTask(compute);

    // Associate the future with the task
    std::future<double> future = packagedTask.get_future();

    // Illustrate deferred execution by only starting the task right now
    packagedTask(0.0, 2.71);

    // Get the result
    std::cout << "PackagedTask Result= " << future.get() << std::endl;
}

// Create a queue of packaged tasks, dequeue each task and execute it.
void test_PartC()
{
    std::queue<std::packaged_task<double (double, double)>> packagedTasks;
    std::queue<std::future<double>> futures;
    for (int i = 0; i < 10; ++i)
    {
        // The element is constructed in-place and pushed to the end of the queue
        std::packaged_task<double (double, double)> task(compute);
        futures.push(task.get_future());
        packagedTasks.push(std::move(task));
    }

    // Dequeue each task and execute it
    for (int i = 0; i < 10; ++i)
    {
        // Execute the task and remove it from the queue
        packagedTasks.front()(i, i + 1);
        packagedTasks.pop();

        // Get the result
        std::cout << "Results of queued packaged task number " << i << " = " << futures.front().get() << std::endl;
        futures.pop();
    }
}

int main()
{
    // Code provided by lecture material
    double x = 0.0; double y = 2.71;
    // A. 'Direct' tasks
    std::future<double> fut = std::async(compute, x, y);

    // Get the shared data
    double result = fut.get();
    std::cout << "Result: " << result << '\n';

    std::cout << "*** Start Part B ***" << std::endl;
    test_PartB();

    std::cout << "*** Start Part C *** " << std::endl;
    test_PartC();

    return 0;
}
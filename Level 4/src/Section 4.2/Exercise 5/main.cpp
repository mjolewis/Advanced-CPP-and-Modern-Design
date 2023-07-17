//
// Analyze usages of custom function objects, STL function objects, and
// lambdas. Discuss the readability, maintainability, and efficiency of each approach.
//
// Created by Michael Lewis on 7/15/23.
//

#include <chrono>
#include <functional>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

// Define aliases
using Vector = std::vector<int>;
using Set = std::set<int>;

// Simple stop watch clock that can be used to track performance of algorithms
class StopWatch
{
private:
    static std::chrono::steady_clock::time_point start;
    static std::chrono::steady_clock::time_point stop;

public:
    static void start_clock()
    { start = std::chrono::steady_clock::now(); }

    static void stop_clock()
    { stop = std::chrono::steady_clock::now(); }

    static auto elapsed_time()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    }
};

std::chrono::steady_clock::time_point StopWatch::start;
std::chrono::steady_clock::time_point StopWatch::stop;

/* Part A -
 * Some STL algorithms need unary and binary predicates. Both types return a Boolean.
 * A unary predicate has one input argument while a binary predicate has two input argument.
 * We can model these predicates and other kinds of functions in a number of ways:
 *
 * User-defined function objects.
 * Predefined STL function objects (for example, std::multiplies<T>()).
 * Using lambda functions (possibly with captured variables).
 *
 * Compare these three solutions against each other with regard to quality issues such as readability,
 * understandability and maintainability.
 *
 * Function objects are well encapsulated and easy to read; however, they are less "accessible" meaning that
 * a code reader doesn't immediately know what the function object is doing. To learn this, they must break
 * away from the current scope to go find the function objects implementation and this can become an issue
 * because it can break you out of your flow. They would be easy to maintain because they are well encapsulated
 * and also easy to reuse.
 *
 * Predefined STL function objects are very easy to read, understand, and maintain (generally not something
 * an application developer has to worry about considering these are part of the standard library). The
 * library builders have provided very convenient names for these function objects that precisely state what
 * operation they perform, so their use is very natural.
 *
 * Lambda functions are also very convenient and allow developers to reduce code bloat relative to something
 * like a function object. Furthermore, they are more natural to read than a function object because their
 * purpose can be defined at its time of use which means there is no context switching for the code reader.
 * However, lambdas are built and maintained by the developer, so that adds additional work relative to simply
 * using the predefined STL function objects. Although that also comes with greater control as the developer
 * can customize to whatever algorithm they need to perform.
 */

class FunctionObject
{
private:
    int threshold = 2;
public:
    explicit FunctionObject(int threshold) : threshold{threshold} {};
    bool operator()(int element) const { return element > threshold; }
};

// Part B - Transform a vector of integers into a set of integers. Only those elements whose absolute
// value is strictly greater than a given threshold value (e.g. 2). An example is the vector {1,2,1,4,5,5,-1}
// and the set will be {4,5}.
void test_function_objects()
{
    Vector vec{1,2,1,4,5,5,-1};
    Set set;
    FunctionObject f{2};

    StopWatch::start_clock();
    std::copy_if(vec.begin(), vec.end(), std::inserter(set, set.end()), f);
    StopWatch::stop_clock();

    std::cout << "Custom Function Object: Set{";
    for (auto i : set)
    {
        std::cout << i << ", ";
    }
    std::cout << "} : Elapsed Time=" << StopWatch::elapsed_time() << std::endl;
}

// Part B - Transform a vector of integers into a set of integers. Only those elements whose absolute
// value is strictly greater than a given threshold value (e.g. 2). An example is the vector {1,2,1,4,5,5,-1}
// and the set will be {4,5}.
void test_stl_function_objects()
{
    Vector vec{1,2,1,4,5,5,-1};
    Set set;
    int threshold = 2;
    auto bind = std::bind(std::greater<>(), std::placeholders::_1, threshold);

    StopWatch::start_clock();
    std::copy_if(vec.begin(), vec.end(), std::inserter(set, set.end()), bind);
    StopWatch::stop_clock();

    std::cout << "STL Function Object: Set{";
    for (auto i : set)
    {
        std::cout << i << ", ";
    }
    std::cout << "} : Elapsed Time=" << StopWatch::elapsed_time() << std::endl;
}

// Part B - Transform a vector of integers into a set of integers. Only those elements whose absolute
// value is strictly greater than a given threshold value (e.g. 2). An example is the vector {1,2,1,4,5,5,-1}
// and the set will be {4,5}.
void test_lambdas()
{
    Vector vec{1,2,1,4,5,5,-1};
    Set set;
    int threshold = 2;
    auto lambda = [&](int element) { return std::abs(element) > threshold; };

    StopWatch::start_clock();
    // inserter is a convenience function template that constructs a std::insert_iterator
    // for the container c and its iterator i with the type deduced from the type of the argument.
    std::copy_if(vec.begin(), vec.end(), std::inserter(set, set.end()), lambda);
    StopWatch::stop_clock();

    std::cout << "Lambda: Set{";
    for (auto i : set)
    {
        std::cout << i << ", ";
    }
    std::cout << "} : Elapsed Time=" << StopWatch::elapsed_time() << std::endl;
}

/*
 * Part C - Having developed and debugged the code in part b) review the three solutions
 * from the perspective of understandability, maintainability and efficiency.
 *
 * From my perspective, custom function objects and lambdas are much easier to understand than a
 * having to bind values to an STL function object. In general, std::bind is not the most
 * intuitive to me. But lambda's and custom function objects are very easy and natural to
 * understand, develop, read, and maintain.
 *
 * From an efficiency perspective, the lambda was several orders of magnitude faster on this
 * test data. As an example, during one run, the lambda took 2000 nanos, the STL function object
 * took 5000 nanos, and the custom function object took 8000 nanos.
 */

int main()
{
    test_function_objects();
    test_stl_function_objects();
    test_lambdas();
    return 0;
}

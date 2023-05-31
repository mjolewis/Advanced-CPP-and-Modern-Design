//
// A simple set test programs to demonstrate syntax and use cases of lambdas
//
// Created by Michael Lewis on 5/27/23.
//

#include <algorithm>
#include <array>
#include <iostream>

/**
 * Demonstrate simply use cases and syntax of lambdas and capture variable by reference
 */
void test_lambda_captureByReference()
{
    // Ask the user for a multiplier that will be used to scale numbers in an array
    int multiplier = 1;
    std::cout << "Enter a multiplier: ";
    std::cin >> multiplier;

    // Cache a lambda that captures the multiplier variable by reference
    const auto& multiplyValuesByReference = [&] (double value) -> double {
        return value * multiplier;
    };

    // Create the underlying data using uniform initialization
    auto values = std::array<double, 5>{1.0, 2.0, 3.0, 4.0, 5.0};

    // Use the cached lambda to process the container, element-by-element
    for (auto it = values.begin(); it < values.end(); ++it)
    {
        *it = multiplyValuesByReference(*it);
    }

    // Print the values in the scaled array to prove that they have been modified
    std::cout << "test lambda using capture by reference:" << std::endl;
    for (auto it = values.cbegin(); it < values.cend(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

/**
 * Demonstrate simply use cases and syntax of lambdas and capture variables that are copy by value
 */
void test_lambda_captureByValue()
{
    // Ask the user for a multiplier that will be used to scale numbers in an array
    int multiplier = 1;
    std::cout << "Enter a multiplier: ";
    std::cin >> multiplier;

    // Cache a lambda that captures the multiplier variable by reference
    const auto& multiplyValuesByValue = [=] (double value) -> double {
        return value * multiplier;
    };

    // Create the underlying data using uniform initialization
    auto values = std::array<double, 5>{1.0, 2.0, 3.0, 4.0, 5.0};

    // Use the cached lambda to process the container, element-by-element
    for (auto it = values.begin(); it < values.end(); ++it)
    {
        *it = multiplyValuesByValue(*it);
    }

    // Print the values in the scaled array to prove that they have been modified
    std::cout << "test lambda using capture by value:" << std::endl;
    for (auto it = values.cbegin(); it < values.cend(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

/**
 * Demonstrates a use case for using lambda's as predicates to determine the min and max element in a container.
 * Additionally demonstrates a use case for std::pair.
 */
void test_minMax()
{
    // Cache a lambda that finds the min and max values of a given container
    const auto& minMax = [&] (auto& values) -> std::pair<int, int> {
        int min = values[0];
        int max = values[0];

        // Starting at index one is a minor optimization
        // because the min and max are initialized to the value at index 0
        for (auto it = values.cbegin() + 1; it < values.cend(); ++ it)
        {
            if (*it < min) min = *it;
            else if (*it  > max) max = *it;
        }

        return std::make_pair(min, max);
    };

    // Create the underlying data using uniform initialization
    std::array<int, 5> values = {11, 2, 33, 4, 5};

    // Use the cached lambda to process data in the container
    std::pair<int, int> minMaxPair = minMax(values);

    // Assert the min and max pair
    assert(2 == minMaxPair.first);
    assert(33 == minMaxPair.second);
}

/**
 * Demonstrate simply use cases of std::minmax_element. Compared to the custom lambda from exercise 1.C,
 * the built-in function is easy to use and also provides additional flexibility by allowing a developer
 * to pass in a custom comparable.
 */
void test_stdMinMaxElement()
{
    // Create the underlying data using uniform initialization
    std::array<int, 5> values = {11, 2, 33, 4, 5};

    // Using the built-in minmax_element is easy to use and repeatable. Of particular interest is that
    // you can provide your own custom iterator, which makes it more flexible for custom apps
    auto minMaxElement = std::minmax_element(values.begin(), values.end());

    // Assert the min and max pair
    assert(2 == *minMaxElement.first);
    assert(33 == *minMaxElement.second);
}

int main()
{
    test_lambda_captureByReference();
    test_lambda_captureByValue();
    test_minMax();
    test_stdMinMaxElement();
    return 0;
}

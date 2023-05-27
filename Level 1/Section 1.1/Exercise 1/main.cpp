//
// Created by Michael Lewis on 5/27/23.
//

#include <algorithm>
#include <array>
#include <iostream>

/*
 * A simple test program to demonstrate syntax and use cases of lambdas
 */
int main()
{
    // *** Begin exercises 1.A and 1.B ***

    // Ask the user for a multiplier that will be used to scale numbers in an array
    int multiplier = 1;
    std::cout << "Enter a multiplier: ";
    std::cin >> multiplier;

    // Store a lambda into a variable for repeated use and capture the multiplier variable by reference
    const auto& multiplyValuesByReference = [&] (double value) -> double {
        return value * multiplier;
    };

    // Create an array using uniform initialization and pass each element to the lambda
    auto values = std::array<double, 5>{1.0, 2.0, 3.0, 4.0, 5.0};
    for (auto it = values.begin(); it < values.end(); ++it)
    {
        *it = multiplyValuesByReference(*it);
    }

    // Print the values in the scaled array to prove that they have been modified
    std::cout << "Values were scaled using a lambda whose multiplier was captured by refernce:" << std::endl;
    for (auto it = values.cbegin(); it < values.cend(); ++it)
    {
       std::cout << *it << std::endl;
    }

    // Store a lambda into a variable for repeated use and capture the multiplier variable by value
    const auto& multiplyValuesByValue = [=] (double value) -> double {
        return value * multiplier;
    };

    // Pass each element in the existing array to the lambda expression that captures by value
    for (auto it = values.begin(); it < values.end(); ++it)
    {
        *it = multiplyValuesByValue(*it);
    }

    // Print the values in the scaled array to prove that they have been modified
    std::cout << "Values were scaled using a lambda whose multiplier was captured by copy-by-value:" << std::endl;
    for (auto it = values.cbegin(); it < values.cend(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // *** End exercises 1.A and 1.B ***

    // *** Begin exercise 1.C ***

    // Use a lambda to find the min of all values in an array
    const auto& minMax = [&] (auto& values) -> std::pair<int, int> {
        int min = values[0];
        int max = values[0];

        // Starting at index one is a minor optimization since the min and max start out as the value at index 0
        for (auto it = values.cbegin() + 1; it < values.cend(); ++ it)
        {
            if (*it < min) min = *it;
            else if (*it  > max) max = *it;
        }

        return std::make_pair(min, max);
    };

    // Re-assign the existing values array using uniform initialization and pass each element to the lambda
    values = {11, 2, 33, 4, 5};
    std::pair<int, int> minMaxPair = minMax(values);
    std::cout << "Min=" << minMaxPair.first << ", Max=" << minMaxPair.second << std::endl;

    // *** End exercise 1.C ***

    // *** Begin exercise 1.D ***

    // Using the built-in minmax_element is easy to use and repeatable. Of particular interest is that
    // you can provide your own custom iterator, which makes it more flexible for custom apps
    auto minMaxElement = std::minmax_element(values.begin(), values.end());
    std::cout << "Min=" << *minMaxElement.first << ", Max=" << *minMaxElement.second << std::endl;

    // *** End exercise 1.D ***

    return 0;
}

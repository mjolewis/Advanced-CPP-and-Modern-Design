//
// A simple test program to demonstrate move semantics
//
// Created by Michael Lewis on 5/30/23.
//

#include <chrono>
#include <iostream>
#include <string>

#include "C.hpp"

/**
 * Test moving a string and confirm the source and target content.
 */
void test_moveString()
{
    // Create the underlying data
    std::string&& source = "String to be moved";
    std::cout << "source before move=" << source << std::endl;

    // Move the source string
    auto target = std::move(source);
    std::cout << "source after move=" << source << std::endl;
    std::cout << "target after move=" << target << std::endl;
}

/**
 * Test moving a vector and confirm the source and target content.
 */
void test_moveVector()
{
    // Create the underlying data using uniform initialization
    std::vector<double>&& source = std::vector<double>{1.0, 2.0, 3.0, 4.0, 5.0};
    std::cout << "source before move=";
    std::for_each(source.begin(), source.end(), [&] (double element) {std::cout << element << " ";});

    // Move the source vector
    auto target = std::move(source);
    std::cout << "\nsource after move=";
    std::for_each(source.begin(), source.end(), [&] (double element) {std::cout << element << " ";});

    std::cout << "\ntarget after move=";
    std::for_each(target.begin(), target.end(), [&] (double element) {std::cout << element << " ";});
}

/**
 * Performance test of move and copy ctors
 */
void test_moveVsCopyPerformance()
{
    std::cout << "\nStart move vs copy performance test" << std::endl;
    // Create source data
    auto source = std::vector<double>(1000000);
    for (int i = 0; i < 1000000; ++i)
    {
        source.push_back(i);
    }

    // Use steady clock for duration measurements
    std::chrono::steady_clock::time_point start, end;

    // Test performance of move constructor
    std::cout << "start the move" << std::endl;
    auto&& rValueRef = C<double>();
    std::for_each(source.begin(), source.end(), [&] (double element) {rValueRef.insert(element);});
    start = std::chrono::steady_clock::now();
    auto moveClass = C<double>(std::move(rValueRef));
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> moveTime = end - start;

    // Test performance of copy constructor
    std::cout << "start the copy" << std::endl;
    auto copyClass = C<double>();
    std::for_each(source.begin(), source.end(), [&] (double element) {copyClass.insert(element);});
    start = std::chrono::steady_clock::now();
    C<double> myTargetClass = C<double>(copyClass);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> copyTime = end - start;

    double diff = (copyTime - moveTime) / moveTime;
    std::cout << "Move is " << diff << " % faster than a copy" << std::endl;
}

/**
 * Test performance of swapping objects by copy and move
 * Copy swapping creates one temporary object and uses one assignment operator
 */
void test_swap_copy_move()
{
    std::cout << "Start swap by copy and move" << std::endl;
    C<double> myClass = C<double>();

    // Create source data
    auto copyVector1 = std::vector<double>(1000000);
    for (int i = 0; i < 1000000; ++i)
    {
        copyVector1.push_back(i);
    }

    auto copyVector2 = std::vector<double>(1000000);
    for (int i = 0; i < 1000000; ++i)
    {
        copyVector2.push_back(i);
    }

    auto&& moveVector1 = std::vector<double>();
    for (int i = 0; i < 1000000; ++i)
    {
        moveVector1.push_back(i);
    }

    auto&& moveVector2 = std::vector<double>();
    for (int i = 0; i < 1000000; ++i)
    {
        moveVector2.push_back(i);
    }

    std::chrono::steady_clock::time_point start, end;

    // Start swap by copy and measure the duration
    start = std::chrono::steady_clock::now();
    myClass.swapCopyStyle(copyVector1, copyVector2);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> copySwapDuration = end - start;

    // Start swap by move and measure the duration
    start = std::chrono::steady_clock::now();
    myClass.swapMoveStyle(std::move(moveVector1), std::move(moveVector2));
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> moveSwapDuration = end - start;

    double diff = (copySwapDuration - moveSwapDuration) / moveSwapDuration;
    std::cout << "Move is " << diff << " % faster than a copy" << std::endl;
}

int main()
{
    test_moveString();
    test_moveVector();
    test_moveVsCopyPerformance();
    test_swap_copy_move();
    return 0;
}
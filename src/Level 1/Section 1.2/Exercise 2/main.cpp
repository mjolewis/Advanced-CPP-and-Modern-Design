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
        source.at(i) = i;
    }

    // Use steady clock for duration measurements
    std::chrono::steady_clock::time_point start, end;

    // Test performance of copy constructor
    auto copySource = C<double>(1000000);
    for (int i = 0; i < source.size(); ++i) copySource.setVec(i, i);
    std::cout << "start the copy" << std::endl;
    start = std::chrono::steady_clock::now();
    auto copyTarget = C<double>(copySource);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> copyTime = end - start;

    // Test performance of move constructor
    auto&& moveSource = C<double>(1000000);
    for (int i = 0; i < source.size(); ++i) moveSource.setVec(i, i);
    std::cout << "start the move" << std::endl;
    start = std::chrono::steady_clock::now();
    auto moveTarget = C<double>(std::move(moveSource));
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> moveTime = end - start;

    double diff = (copyTime - moveTime) / moveTime;
    std::cout << "Move ctor is " << diff << "% faster than a copy ctor" << std::endl;
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
    auto copyVector1 = std::vector<double>();
    for (int i = 0; i < 1000000; ++i) copyVector1.push_back(i);

    auto copyVector2 = std::vector<double>();
    for (int i = 0; i < 1000000; ++i) copyVector2.push_back(i);

    auto&& moveVector1 = std::vector<double>();
    for (int i = 0; i < 1000000; ++i) moveVector1.push_back(i);

    auto&& moveVector2 = std::vector<double>();
    for (int i = 0; i < 1000000; ++i) moveVector2.push_back(i);

    // Used to track duration to measure performance
    std::chrono::steady_clock::time_point start, end;

    // Start swap by copy and measure the duration
    start = std::chrono::steady_clock::now();
    myClass.swapCopyStyle(copyVector1, copyVector2);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> copyTime = end - start;

    // Start swap by move and measure the duration
    start = std::chrono::steady_clock::now();
    myClass.swapMoveStyle(std::move(moveVector1), std::move(moveVector2));
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> moveTime = end - start;

    double diff = (copyTime - moveTime) / moveTime;
    std::cout << "Swap move is " << diff << "% faster than a swap copy" << std::endl;
}

/**
 * Utility test to ensure all functions from previous lectures continue to compile
 */
void test_backwardCompatibility()
{
    // Test constructors
    auto source = C<double>();
    auto copy = C<double>(source);
    auto&& move = C<double>(std::move(copy));

    // Test assignment operators
    auto copyAssignment = move.operator=(source);
    auto&& moveAssignment = move.operator=(std::move(source));
    for (int i = 0; i < 5; ++i) move.setVec(i, i);

    // Test accessor and mutators
    move.insert(5);
    move.insert(6);
    assert(21 == move.sumVector());
    move.print();
    auto& vec = move.getVec();

    // Test swaps
    std::vector<double> vec1 = {1, 2};
    std::vector<double> vec2 = {3, 4};
    move.swapCopyStyle(vec1, vec2);
    assert(1 == vec2.at(0));
    assert(2 == vec2.at(1));
    assert(3 == vec1.at(0));
    assert(4 == vec1.at(1));

    move.swapMoveStyle(std::move(vec1), std::move(vec2));
    assert(3 == vec2.at(0));
    assert(4 == vec2.at(1));
    assert(1 == vec1.at(0));
    assert(2 == vec1.at(1));
}

int main()
{
    test_moveString();
    test_moveVector();
    test_moveVsCopyPerformance();
    test_swap_copy_move();
    test_backwardCompatibility();
    return 0;
}
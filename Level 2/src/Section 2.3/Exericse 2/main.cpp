//
// Illustrate use cases and drawbacks of using init captures.
// Drawbacks include performance hit caused by copying objects in
// the closure or dangling pointers caused by capture-by-reference
//
// Created by Michael Lewis on 6/21/23.
//

#include <iostream>
#include <array>
#include <vector>

/**
 * Modified the provided code to use move semantics instead of default capture.
 *
 * When using default capture, the data is printing out twice. However, when using
 * move semantics, it is only printed once. The reason is because after data is moved
 * the size of the vector is 0. Recall that move semantics leaves the moved from object
 * in a valid state but the ownership has been assigned to the data within the closure.
 */
void test_MoveSemantics_InitCapture()
{
    int size = 4; double val = 2.71;
    std::vector<double> data(size, val);

    // Default capture mode (not preferred)
//    auto fun = (data&)() mutable

    // Applying move semantics
    auto fun = [data = std::move(data)]() mutable
    {
        for (std::size_t i = 0; i < data.size(); ++i)
        {
            data[i] = 3.14; std::cout << data[i]<<",";
        }
        std::cout <<'\n';
    };

    fun();

    // 'data' exists only when using default capture. After applying move semantics,
    // it is considered a moved from object and has a size of 0
    for (std::size_t i = 0; i < data.size(); ++i)
    {
        data[i] = 3.14; std::cout << data[i]<<":";
    }
}

// C++14 init capture with local variables
int x = 1'000'000; // This is a digit separator
auto fun4 = [&r = x]()
{
    r *= 2;
    std::cout <<"\nr: "<< r;
};

/**
 * Migrated C++11 code that used std::bind when moving objects into the closure.
 *
 * The migrated code below uses C++14 init capture syntax, which is easier to
 * understand from a developer and reviewer standpoint.
 */
void test_migrateStdBind_To_InitCapture()
{
    // Emulating generalized lambda capture with C++11
    int size2 = 3; double val2 = 1.41;
    std::vector<double> data2(size2, val2);
    std::array<double, 3> data3 = { 1.2, 2.4, 4.7 };
    auto fun3 = [array = std::move(data2), array2 = std::move(data3)] () -> auto {
        std::cout <<'\n';
        for (double i : array)
        {
            i = 3.14; std::cout <<i<<"/";
        }
        std::cout <<'\n';
        for (double i : array2)
        {
            i = 2.71; std::cout <<i<<"/";
        }
    };

    fun3();

    if (0 == data2.size() || 0 == data3.size())
    {
        std::cout <<"\nDouble arrays have no elements, OK\n";
    }
    else
    {
        std::cout <<"\n Ouch!\n";
        for (std::size_t i=0;i<data2.size(); ++i)
        {
            std::cout<<data2[i]<<"^";
        }
        for (std::size_t i = 0; i < data3.size(); ++i)
        {
            std::cout<<data3[i]<<"^"; }
    }
}

int main()
{
    test_MoveSemantics_InitCapture();
    fun4();
    test_migrateStdBind_To_InitCapture();
    return 0;
}
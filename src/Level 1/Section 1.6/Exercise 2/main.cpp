//
// Created by Michael Lewis on 6/11/23.
//

#include "TmpClass.hpp"

void test_TmpClass()
{
    // Initialize input data
    std::size_t n = 10;
    double startValue = 2;

    // Function wrappers
    InputFunction iFunction = [] () -> double { return 10; };
    OutputFunction oFunction = [] (const std::vector<double>& source) -> void {
        for (double element : source)
        {
            std::cout << element << std::endl;
        }};

    TMPClass instance{n, startValue, iFunction, oFunction};

    instance.compute();
    instance.postprocessor();
}

int main()
{
    test_TmpClass();
    return 0;
}
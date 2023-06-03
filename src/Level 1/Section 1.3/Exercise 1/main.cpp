//
// Created by Michael Lewis on 6/2/23.
//

#include "Utils.hpp"

/**
 * Test variadic and tail print functions
 */
void test_print()
{
    int j = 1; double d = 2.0;
    Utils::print(j);
    Utils::print(d);
    Utils::print(j, d);
    Utils::print(d, j);
    std::cout << "\n3 params \n";
    Utils::print(d, j, std::bitset<8>(233));
}

int main()
{
    test_print();
    return 0;
}
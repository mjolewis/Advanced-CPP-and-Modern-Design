//
// Illustrate basic usage of std::ratio, which is a class template that supports rational arithmetic.
// Rational arithmetic reduces the risk of run-time overflow because a ratio and any ratios resulting
// from ratio arithmetic are always reduced to the lowest terms.
//
// Created by Michael Lewis on 7/6/23.
//

#include <iostream>
#include <ratio>

// Print ratios
void test_PrintStdRatio()
{
    using oneThird = std::ratio<1, 3>;
    using oneHalf = std::ratio<3, 6>;

    std::cout << "1/3=" << oneThird::num << "/" << oneThird::den << std::endl;
    std::cout << "3/6=" << oneHalf::num << "/" << oneHalf::den << std::endl;
}

// Multiply two ratios
void test_Multiply()
{
    using oneThird = std::ratio<1, 3>;
    using oneHalf = std::ratio<3, 6>;
    using product = std::ratio_multiply<oneThird, oneHalf>;
    static_assert(std::ratio_equal_v<product, std::ratio<3, 18>>);
    std::cout << "1/3 (*) 3/6 = " << product::num << '/' << product::den << '\n';
}

// Divide two ratios
void test_Divide()
{
    using oneThird = std::ratio<1, 3>;
    using oneHalf = std::ratio<3, 6>;
    using divide = std::ratio_divide<oneHalf, oneThird>;
    static_assert(std::ratio_equal_v<divide, std::ratio<3, 2>>);
    std::cout << "3/6 (/) 1/3 = " << divide::num << '/' << divide::den << '\n';
}

// Add two ratios
void test_Add()
{
    using oneFourth = std::ratio<25, 100>;
    using oneHalf = std::ratio<5, 10>;
    using add = std::ratio_add<oneFourth, oneHalf>;
    static_assert(std::ratio_equal_v<add, std::ratio<75, 100>>);
    std::cout << "25/100 (+) 5/10 = " << add::num << '/' << add::den << '\n';
}

// Subtract two ratios
void test_Subtract()
{
    using oneFourth = std::ratio<25, 100>;
    using oneHalf = std::ratio<5, 10>;
    using subtract = std::ratio_subtract<oneHalf, oneFourth>;
    static_assert(std::ratio_equal_v<subtract, std::ratio<25, 100>>);
    std::cout << "5/10 (-) 25/100 = " << subtract::num << '/' << subtract::den << '\n';
}

int main()
{
    test_PrintStdRatio();
    test_Multiply();
    test_Divide();
    test_Add();
    test_Subtract();

    return 0;
}

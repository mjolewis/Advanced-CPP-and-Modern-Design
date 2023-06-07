//
// Created by Michael Lewis on 6/5/23.
//

#include <complex>
#include <iostream>
#include <cfloat>
#include <tuple>
#include <utility>

/**
 * A generic calculator that recursively operates on the data in a tuple
 */
template<typename T, typename Tuple, std::size_t N>
struct Calculator
{
    static T sum(const Tuple& pack)
    {
        T sum = 0;
        sum += Calculator<T, Tuple, N - 1>::sum(pack);
        sum += std::get<N - 1>(pack);
        return sum;
    };
    static T average(const Tuple& pack)
    {
        return sum(pack) / (T) N;
    };
    static T maximum(const Tuple& pack)
    {
        T max = -DBL_MAX;
        max = Calculator<T, Tuple, N - 1>::maximum(pack);
        T current = std::get<N - 1>(pack);
        if (current > max) max = current;
        return max;
    };
};

/**
 * Partially specialized Calculator to handle the tail conditions
 */
template<typename T, typename Tuple>
struct Calculator<T, Tuple, 1>
{
    static T sum(const Tuple& pack)
    {
        return std::get<0>(pack);
    }

    static T maximum(const Tuple& pack)
    {
        return std::get<0>(pack);
    }
};

// setup aliases of real numbers to use in tests below
using TD2 = std::tuple<double, double>;
using TD3 = std::tuple<double, double, double>;
TD2 td2 = std::make_tuple(4.0, 2.0);
TD3 td3 = std::make_tuple(2.0, 3.0, 4.0);
using CD2 = Calculator<double, TD2, 2>;
using CD3 = Calculator<double, TD3, 3>;

// setup aliases of complex numbers to use in tests below
using TD2Complex = std::tuple<std::complex<int>, std::complex<int>>;
using TD3Complex = std::tuple<std::complex<int>, std::complex<int>, std::complex<int>>;
auto td2Complex = std::make_tuple(std::complex<int>(2, 3), std::complex<int>(4, 3));
auto td3Complex = std::make_tuple(std::complex<int>(2, 3), std::complex<int>(4, 3), std::complex<int>(6, 6));
using CDComplex2 = Calculator<std::complex<int>, TD2Complex, 2>;
using CDComplex3 = Calculator<std::complex<int>, TD3Complex, 3>;

/**
 * Test sum of real and complex numbers
 */
void test_sum()
{
    double sum = CD2::sum(td2);
    assert(6.0 == sum);

    sum = CD3::sum(td3);
    assert(9.0 == sum);

    // Complex
    auto sumComplex = CDComplex2::sum(td2Complex);
    assert(std::complex(6, 6) == sumComplex);

    sumComplex = CDComplex3::sum(td3Complex);
    assert(std::complex(12, 12) == sumComplex);
}

/**
 * Test average of real and complex numbers
 */
void test_average()
{
    double average = CD2::average(td2);
    assert(3.0 == average);

    average = CD3::average(td3);
    assert(3.0 == average);

    // Complex
    auto averageComplex = CDComplex2 ::average(td2Complex);
    assert(std::complex(3, 3) == averageComplex);

    averageComplex = CDComplex3::average(td3Complex);
    assert(std::complex(6, 6) == averageComplex);
}

/**
 * Test maximum of real and complex numbers
 */
void test_maximum()
{
    double maximum = CD2::maximum(td2);
    assert(4.0 == maximum);

    maximum = CD3::maximum(td3);
    assert(4.0 == maximum);
}

int main()
{
    test_sum();
    test_average();
    test_maximum();

    return 0;
}
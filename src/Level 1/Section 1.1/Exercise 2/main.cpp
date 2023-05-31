//
// A simple test program to show how lambda's work with std::accumulate
//
// Created by Michael Lewis on 5/28/23.
//

#include <complex>
#include <iostream>
#include <numeric>
#include <vector>

// Setup binary operation as a lambda expression
template<typename T>
T myMultiply(const T& x, const T& y) { return x*y; }

// Setup binary operation as a function object
struct FOMultiply
{
    template <typename T>
    T operator () (const T& x, const T& y)
    { return x * y; }
};

/**
 * Exercise A
 *
 * Use lambda as the binary operation arg for std::accumulate
 */
void test_accumulate_using_lambda()
{
    // Create the underlying data using uniform initialization
    std::vector<int> vec{1, 2, 3, 4, 5};

    // Use lambda as the binary operation for std::accumulate
    int result = std::accumulate(vec.begin(), vec.end(), 1, myMultiply<int>);

    // Assert the product
    assert(120 == result);
}

/**
 * Exercise A
 *
 * Use lambda as the binary operation arg for std::accumulate with complex numbers
 *
 * Question: Does accumulate work with complex numbers?
 * Answer: Yes, std::accumulate works with complex numbers with both lambda's and function objects.
 */
void test_accumulate_using_complexNumbers()
{
    // Using complex numbers
    using Complex = std::complex<double>;
    std::vector<Complex> complexArray{Complex(1.0, 1.0), Complex(2.0, 2.0)};
    Complex initCVal(1.0, 1.0);

    auto acc6CFunctionObject = accumulate(complexArray.begin(), complexArray.end(), initCVal, FOMultiply());
    std::cout << "Sum 6, complex numbers: " << acc6CFunctionObject << std::endl;

    Complex acc6CLambda = accumulate(complexArray.begin(), complexArray.end(), initCVal, myMultiply<Complex>);
    std::cout << "Sum 6, complex numbers: " << acc6CLambda << std::endl;
}

/**
 * Exercise B
 *
 * Use an embedded lambda as the binary operation arg for std::accumulate and implement the iteration using
 * for_each
 */
void test_accumulate_using_forEach()
{
    // Create the underlying data using uniform initialization
    std::vector<int> vec{1, 2, 3, 4, 5};

    // Create the initial values
    int sum = 1;

    // Setup binary operation as a lambda expression
    auto myMultiply = [&] (int rhs) {
        return sum *= rhs;
    };

    // Process data
    std::for_each(vec.begin(), vec.end(), myMultiply);

    // Assert the product
    assert(120 == sum);
}

/**
 * Exercise C
 * Example of a stored lambda function that uses the count_if STL algorithm.
 */
void test_counting_withLambdas()
{
    // Create the underlying data using uniform initialization
    std::vector<int> vec{1, 2, 3, 4, 5};

    // Create the initial value
    int threshold = 3;

    // Stored lambda
    auto counter = [&] (int value) {
        return value < threshold;
    };

    auto result = std::count_if(vec.begin(), vec.end(), counter);

    // Assert the numbers less than threshold
    assert(2 == result);
}

int main()
{
    test_accumulate_using_lambda();
    test_accumulate_using_complexNumbers();
    test_accumulate_using_forEach();
    test_counting_withLambdas();
    return 0;
}
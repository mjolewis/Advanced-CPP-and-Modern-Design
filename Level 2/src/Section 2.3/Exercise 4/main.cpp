//
// Emulating deprecated C++ 98 STL Bind Code.
//
// An illustration of currying which is a technique to translate the
// evaluation of a function that takes multiple arguments into a sequence
// of functions, each with a single argument (partial evaluation)
// Created by Michael Lewis on 6/22/23.
//

#include <iostream>
#include <functional>
#include <vector>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R (const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;

// Bind first argument
template <typename T>
std::function<T (const T&)> bind1st(const std::function<T (const T& x, const T& y)>& f, const T& x_)
{
    return [=](const T& y)
    {
        return f(x_, y);
    };
}

// Bind second argument
template <typename T>
std::function<T(const T&)> bind2nd(const std::function<T(const T& x, const T& y)>& f, const T& y_)
{
    return [=](const T& x)
    {
        return f(x, y_);
    };
}

int main()
{
    std::cout << "*** Start Provided Example" << std::endl;
    double xval = 5.0;
    double yval = 10.0;
    auto fxy = [](const double& x, const double& y) -> double { return x * y; };
    ScalarFunction fy = bind1st<double>(fxy, xval);
    ScalarFunction fx = bind2nd<double>(fxy, yval);
    std::cout << fx(3.0)<< std::endl;
    // Test new bind code on STL algorithms
    std::vector<double> vec(10, 2.0);
    std::transform(vec.begin(), vec.end(), vec.begin(), fx);
    for (auto i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i]<<",";
    }
    std::cout << "*** End Provided Example" << std::endl;

    std::cout << "*** Start Custom Example" << std::endl;
    int x1 = 2;
    int y1 = 4;
    auto fxy1 = [](const int& x, const int& y) -> int { return y - x; };
    ScalarFunction fy1 = bind1st<int>(fxy1, x1);
    ScalarFunction fx1 = bind2nd<int>(fxy1, y1);
    std::cout << fy1(4) << std::endl;
    std::cout << fx1(4) << std::endl;
    std::cout << "*** End Custom Example" << std::endl;

    return 0;
}
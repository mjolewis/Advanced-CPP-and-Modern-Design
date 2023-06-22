//
// Build a simple vector space of functions to show how to create higher-order
// functions in C++ to illustrate the possibilities of lambda functions and their
// applications to mathematics, engineering and numeric computation in general.
//
// Created by Michael Lewis on 6/21/23.
//

#include <iostream>
#include <cmath>
#include <functional>
#include <sstream>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R (const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;

// Add two functions
template<typename R, typename D>
FunctionType<R,D> operator + (const FunctionType<R,D>& f, const FunctionType<R,D>& g)
{
    return [=] (const D& x)
    {
        return f(x) + g(x);
    };
}

// Subtract two functions
template<typename R, typename D>
FunctionType<R,D> operator - (const FunctionType<R,D>& f, const FunctionType<R,D>& g)
{
    return [=] (const D& x)
    {
        return f(x) - g(x);
    };
}

// Multiply two functions
template<typename R, typename D>
FunctionType<R,D> operator * (const FunctionType<R,D> f, const FunctionType<R,D> g)
{
    return [=] (const D& x)
    {
        return f(x) * g(x);
    };
}

// Divide two functions
template<typename R, typename D>
FunctionType<R,D> operator / (const FunctionType<R,D> f, const FunctionType<R,D> g)
{
    return [=] (const D& x)
    {
        return f(x) / g(x);
    };
}

// Scalar multiplication
template<typename R, typename D>
FunctionType<R,D> operator * (const FunctionType<R,D>& f,  const D& d)
{
    return [=] (const D& x)
    {
        return f(x) * d;
    };
}

// Multiply a scalar and a functions - Generalized for any scalar type D
template<typename R, typename D>
FunctionType<R,D> operator * (const D& d, const FunctionType<R,D>& f)
{
    return [=] (const D& x)
    {
        return d * f(x);
    };
}

// Multiply a scalar and a functions - Specialized for integers
template<typename R, typename D>
FunctionType<R,D> operator * (const int& d, const FunctionType<R,D>& f)
{
    return [=] (const D& x)
    {
        return d * f(x);
    };
}

// Unary additive inverse
template<typename R, typename D>
FunctionType<R,D> operator - (const FunctionType<R,D>& f)
{
    return [=] (const D& x)
    {
        return -(f(x));
    };
}

//Composition of functions
template <typename R, typename D>
FunctionType<R,D> operator << (const FunctionType<R,D>& f, const FunctionType<R,D>& g)
{
    return [=] (const D& x)
    {
        return  f(g(x));
    };
}

// exp
template <typename R, typename D>
FunctionType<R,D> exp(const FunctionType<R,D>& f)
{
    return [=](const D& x)
    {
        return std::exp(f(x));
    };
}

// cos
template<typename R, typename D>
FunctionType<R,D> cos(const FunctionType<R,D>& f)
{
    return [=](const D& x)
    {
        return std::cos(f(x));
    };
}

// sin
template<typename R, typename D>
FunctionType<R,D> sin(const FunctionType<R,D>& f)
{
    return [=](const D& x)
    {
        return std::sin(f(x));
    };
}

// tan
template<typename R, typename D>
FunctionType<R,D> tan(const FunctionType<R,D>& f)
{
    return [=](const D& x)
    {
        return std::tan(f(x));
    };
}

// log
template<typename R, typename D>
FunctionType<R,D> log(const FunctionType<R,D>& f)
{
    return [=](const D& x)
    {
        return std::log(f(x));
    };
}

// abs
template<typename R, typename D>
FunctionType<R,D> abs(const FunctionType<R,D>& f)
{
    return [=](const D& x)
    {
        return std::abs(f(x));
    };
}

// sqrt
template<typename R, typename D>
FunctionType<R,D> sqrt(const FunctionType<R,D>& f)
{
    return [=](const D& x)
    {
        return std::sqrt(f(x));
    };
}

// min
template<typename R, typename D>
FunctionType<R,D> min(const FunctionType<R,D>& f, const FunctionType<R,D>& g)
{
    return [=](const D& x)
    {
        return std::min(f(x), g(x));
    };
}

// max
template<typename R, typename D>
FunctionType<R,D> max(const FunctionType<R,D>& f, const FunctionType<R,D>& g)
{
    return [=](const D& x)
    {
        return std::max(f(x), g(x));
    };
}

// max
template<typename R, typename D>
FunctionType<R,D> max(const D& d, const FunctionType<R,D>& f, const D& e, const FunctionType<R,D>& g)
{
    return [=](const D& x)
    {
        return std::max(d * f(x), e * g(x));
    };
}

int main()
{
    std::cout << "*** Start Part A ***" << std::endl;
    // Scalar functions: double to double
    ScalarFunction f = [](double x) {return x*x; };
    ScalarFunction g = [=](double x) { return x; };

    std::cout << g(2) << ", " << g(8) << "*";

    // Set I: Arithmetic functions
    double scale = 2.0;
    auto fA = 2.0 * (f + g);
    auto fM = f - g;
    auto fD = f / g;
    auto fMul = f * g;
    auto fC = g << g << 4.0 * g; // Compose
    auto fMinus = -(f + g);

    double x = 5.0;

    std::cout<< fA(x)<<", "<< fM(x)<<", "<< fD(x)<<", "<< fMul(x)<<", compose: "<< fC(x)<<", "<< fMinus(x);
    std::cout << "\n*** End Part A ***" << std::endl;

    std::cout << "\n*** Start Part B ***" << std::endl;
    auto ftmp = log(g);
    auto ftmp2 = cos(f);
    auto ftmp3 = sin(f);
    auto ftmp4 = tan(f);
    auto f2 = (abs(exp(g))*log(g) + sqrt(ftmp)) / ftmp2;
    std::cout<< ftmp(x) <<", "<< ftmp2(x) << ", " << f2(x) << ", "<< ftmp3(x) << ", " << ftmp4(x);
    std::cout << "\n*** End Part B ***" << std::endl;

    std::cout << "\n*** Start Part C ***" << std::endl;
    auto h1 = min(f, g);
    auto h2 = max(f, g);
    std::cout <<"min(f,g): "<< h1(2.0)<<'\n';
    std::cout <<"max(f,g): "<< h2(2.0)<<'\n';
    auto h3 = min(h1, max(2 * f, 3 * g));
    auto h4 = max(h2, max(-2 * f, 3 * g));
    std::cout <<"min(h1, max(2 * f, 3 * g)): "<< h3(2.0)<<'\n';
    std::cout <<"max(h2, max(-2 * f, 3 * g)): "<< h4(2.0)<<'\n';
    std::cout << "*** End Part C ***" << std::endl;

    return 0;
}
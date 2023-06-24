//
// Examine floating-point arithmetic, round-off error and machine precision issues.
// Note: Floating-point arithmetic is based on IEEE 754.
//
// Created by Michael Lewis on 6/24/23.
//

#include <cmath>
#include <iostream>
#include <limits>
#include <cfloat>

// Lecture provided template function to classify different types of numbers.
template <typename T>
const char* Classify(T t)
{
    switch (std::fpclassify(t))
    {
        case FP_INFINITE:  return "Inf";
        case FP_NAN: return "NaN";
        case FP_NORMAL:    return "normal";
        case FP_SUBNORMAL: return "subnormal";
        case FP_ZERO: return "zero";
        default:  return "unknown";
    }
}

int main()
{
    {
        // Part A - Test the classifier against the following types of numbers.
        double val = std::numeric_limits<double>::max();
        auto result1 = 2.0 * val;
        auto result2 = 3.1415 + val;
        double val2 = std::numeric_limits<double>::min();
        val2 -= 3.1415;
        auto result3 = val2/2.0;
        auto result4 = DBL_MIN / 2.0;

        std::cout << "(2.0 * val)=" << Classify(result1) << std::endl;
        std::cout <<  "(3.1415 + val)=" << Classify(result2) << std::endl;
        std::cout << "(val2/2.0)=" << Classify(result3) << std::endl;
        std::cout << "(DBL_MIN/2.0)=" << Classify(result4) << std::endl;
    }

    {
        // Part B - Apply the functions std::isfinite, std::isinf, std::isnan, std::isnormal to the following values:
        double factor = 2.0;
        double val = factor*std::numeric_limits<double>::max();
        auto val2 = val - val;
        auto sqrt = std::sqrt(-1.0);
        auto log = std::log(0.0);
        auto exp = std::exp(val);

        std::cout << std::boolalpha;
        std::cout << "is a double finite? " << std::isfinite(factor) << std::endl;
        std::cout << "is numeric_limits<double>::max() finite? " << std::isfinite(val) << std::endl;
        std::cout << "is numeric_limits<double>::max() - numeric_limits<double>::max() finite? " << std::isfinite(val2) << std::endl;
        std::cout << "is sqrt finite? " << std::isfinite(sqrt) << std::endl;
        std::cout << "is log finite? " << std::isfinite(log) << std::endl;
        std::cout << "is exp finite? " << std::isfinite(exp) << std::endl;

        std::cout << "is a double infinite? " << std::isinf(factor) << std::endl;
        std::cout << "is numeric_limits<double>::max() infinite? " << std::isinf(val) << std::endl;
        std::cout << "is numeric_limits<double>::max() - numeric_limits<double>::max() infinite? " << std::isinf(val2) << std::endl;
        std::cout << "is sqrt infinite? " << std::isinf(sqrt) << std::endl;
        std::cout << "is log infinite? " << std::isinf(log) << std::endl;
        std::cout << "is exp infinite? " << std::isinf(exp) << std::endl;

        std::cout << "is a double NAN? " << std::isnan(factor) << std::endl;
        std::cout << "is numeric_limits<double>::max() NAN? " << std::isnan(val) << std::endl;
        std::cout << "is numeric_limits<double>::max() - numeric_limits<double>::max() NAN? " << std::isnan(val2) << std::endl;
        std::cout << "is sqrt NAN? " << std::isnan(sqrt) << std::endl;
        std::cout << "is log NAN? " << std::isnan(log) << std::endl;
        std::cout << "is exp NAN? " << std::isnan(exp) << std::endl;

        std::cout << "is a double normal? " << std::isnormal(factor) << std::endl;
        std::cout << "is numeric_limits<double>::max() normal? " << std::isnormal(val) << std::endl;
        std::cout << "is numeric_limits<double>::max() - numeric_limits<double>::max() normal? " << std::isnormal(val2) << std::endl;
        std::cout << "is sqrt normal? " << std::isnormal(sqrt) << std::endl;
        std::cout << "is log normal? " << std::isnormal(log) << std::endl;
        std::cout << "is exp normal? " << std::isnormal(exp) << std::endl;
    }

    return 0;
}

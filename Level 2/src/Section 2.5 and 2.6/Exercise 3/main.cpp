//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>

#include <boost/math/special_functions/next.hpp>

int main()
{
    // Number gaps/bits/ULP between 2 floating-point values a and b.
    // Returns a signed value indicating whether a < b
    double a = 0.1;
    double b = a + std::numeric_limits<double>::min();
    std::cout << boost::math::float_distance(a, b) << std::endl;
    a = 1.0;
    b = 0.0;
    std::cout << boost::math::float_distance(a, b) << std::endl;

    // Float Distance
    a = 0.1;
    std::cout << std::setprecision(20) << boost::math::float_distance(a, a) << std::endl;  // Expect 0
    std::cout << std::setprecision(20) << boost::math::float_distance(a, boost::math::float_next(a)) << std::endl; // Expect 1
    std::cout << std::setprecision(20) << boost::math::float_distance(boost::math::float_next(a), a) << std::endl; // Expect  -1

    // Float Next
    std::cout << std::setprecision(20) << boost::math::float_next(std::numeric_limits<double>::min()) << std::endl;
    std::cout << std::setprecision(20) << boost::math::float_next(a) << std::endl;

    // Float Prior
    std::cout << std::setprecision(20) << boost::math::float_prior(std::numeric_limits<double>::min()) << std::endl;

    try
    {
        // Expect an overflow error when finding the next flow for a max double
        std::cout << std::setprecision(20) << boost::math::float_next(std::numeric_limits<double>::max()) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Float advance
    std::cout << std::setprecision(20) << boost::math::float_advance(0.1,  1) << std::endl;
    std::cout << std::setprecision(20) << boost::math::float_advance(0.1,  -1) << std::endl;

    // Next After
    std::cout << std::setprecision(20) << boost::math::nextafter(a, 1.0) << std::endl;
    std::cout << std::setprecision(20) << boost::math::nextafter(0.0f, 1.0f) << std::endl;
    std::cout << std::setprecision(20) << boost::math::nextafter(-1.0f, -2.0f) << std::endl;
    std::cout << std::setprecision(20) << std::nextafter(-1.0f, -2.0f) << std::endl;

    return 0;
}
//
// Basic illustration of how to use Boost UBLAS for vectors
//
// Created by Michael Lewis on 7/30/23.
//

#include <algorithm>
#include <functional>
#include <iomanip>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

int main()
{
    // Part A - Create a vector v1 of a given size. Use the indexing
    // operators () and [] to access the elements of the vector.
    using namespace boost::numeric::ublas;
    vector<double> v1{2};
    v1(0) = 1;
    v1[1] = 2;

    // Part B - Create a vector v2 having the same size as v1. Compute v1 += v2, v1 *= 2.5, v1 -= v2.
    vector<double> v2{2};
    v2(0) = 3;
    v2[1] = 4;

    std::cout << "*** Perform mathematical operations on vectors ***" << std::endl;
    std::cout << "v1 += v2 =" << (v1 += v2) << std::endl;
    std::cout << "v1 *= 2.5 =" << (v1 *= 2.5) << std::endl;
    std::cout << "v1 -= v2 =" << (v1 -= v2) << std::endl;

    // Part C - Use std::transform and std::multiply<> to multiply v1 and v2 to produce a vector v3.
    std::cout << "*** V1 and V2 Before Transforming into V3 ***" << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    vector<double> v3{2};
    std::transform(v1.cbegin(), v1.cend(),  // Read from vector 1
                   v2.cbegin(), // Read from vector 2
                   v3.begin(),  // Write the a new location
                   std::multiplies<>());

    std::cout << "v3 = " << v3 << std::endl;

    // Part D - Produce a scalar vector of size 100 all of whose values are equal to 5.0.
    scalar_vector<double> v4(100, 5.0);
    std::cout << "v4 = " << std::fixed << std::setprecision(1) << v4 << std::endl;

    return 0;
}

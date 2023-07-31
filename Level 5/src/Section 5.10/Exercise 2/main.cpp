//
// Illustrate basic features of ublas matrices. Note how easy these are to work with relative
// to building and maintaining your own matrix libraries.
//
// Created by Michael Lewis on 7/31/23.
//

#include <iomanip>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

int main()
{
    using namespace boost::numeric::ublas;

    // Part A -  Create matrices with given row and column using variations of the above template parameters.

    // Default parameters (row_major and unbounded_array<T>)
    matrix<double> m1 (3, 3);
    for (unsigned i = 0; i < m1.size1 (); ++i)
    {
        for (unsigned j = 0; j < m1.size2 (); ++j)
        {
            // Part B - Use the operator () to access and modify the elements of matrices.
            m1(i, j) = 4 * (i + j + 1);
        }
    }

    // Custom parameters (column_major and bounded_array<T, size>)
    matrix<double, column_major, bounded_array<double, 9>> m2 (3, 3);
    for (unsigned i = 0; i < m2.size1 (); ++ i)
    {
        for (unsigned j = 0; j < m2.size2 (); ++j)
        {
            // Part B - Use the operator () to access and modify the elements of matrices.
            m2(i, j) = 2 * (i + j + 1);
        }
    }

    // Part C - Add and subtract matrices.
    std::cout << "\n*** Matrix addition and subtraction ***" << std::endl;
    std::cout << "m1 + m2 = " << (m1 + m2) << std::endl;
    std::cout << "m1 - m2 = " << (m1 - m2) << std::endl;

    // Part D - Resize a matrix (modify the number of rows or columns).
    m1.resize(4, 4);
    m2.resize(2, 2);
    std::cout << "\n*** Resized Matrices ***" << std::endl;
    std::cout << "m1 = " << m1 << std::endl;
    std::cout << "m2 = " << m2 << std::endl;

    // Part E - Create the zero (all zeroes)
    zero_matrix<double> m3 (3, 5);
    std::cout << "\n*** Zero Matrix ***" << std::endl;
    std::cout << m3 << std::endl;

    // Part E - Create the identity matrix.
    identity_matrix<double> m4 (3);
    std::cout << "\n*** Identity Matrix ***" << std::endl;
    std::cout << m4 << std::endl;

    return 0;
}

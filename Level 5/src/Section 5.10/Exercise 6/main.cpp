//
// Illustrate how to create and use matrix proxies
//
// Created by Michael Lewis on 8/2/23.
//

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

#include "MatrixProxy.hpp"

using namespace boost::numeric::ublas;
using value_type = double;
using Matrix = matrix<value_type>;

int main()
{
    // Part A - Create proxies for matrix_row, matrix_column, matrix_range, and matrix_slice and print them
    Matrix m(10, 10);
    for (unsigned i = 0; i < m.size1 (); ++ i)
    {
        for (unsigned j = 0; j < m.size2 (); ++ j)
        {
            m(i, j) = (3 * i + j, i);
        }
    }

    MatrixProxy<Matrix>::matrix_row(m);
    MatrixProxy<Matrix>::matrix_column(m);
    MatrixProxy<Matrix>::matrix_range(m, 1, 3);
    MatrixProxy<Matrix>::matrix_slice(m, 2, 3, 3);

    // Part B - Create the following matrix slice and print its elements
    // Note, I've filled the matrix so it doesn't just print zeros.
    matrix<double> m1(3, 3);
    for (unsigned i = 0; i < m1.size1 (); ++ i)
    {
        for (unsigned j = 0; j < m1.size2 (); ++ j)
        {
            m1(i, j) = (3 * i + j, i);
        }
    }
    MatrixProxy<matrix<double>>::matrix_slice(m1, 0, 1, 3);

    return 0;
}

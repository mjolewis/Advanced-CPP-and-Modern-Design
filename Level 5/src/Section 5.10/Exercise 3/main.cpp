//
// Illustrate how to create, modify, and read from sparse Matrices and Triangular Matrices with Boost ublas
//
// Created by Michael Lewis on 7/31/23.
//

#include <complex>

#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

int main()
{
    using namespace boost::numeric::ublas;

    // Part A - Create a sparse matrix whose elements are complex numbers.
    // The interface is similar to that of a dense matrix.
    // Note - mapped_matrix<T, F, A> is the base container adaptor for sparse matricies
    mapped_matrix<std::complex<double>> m1 (3, 3, 3 * 3);
    for (unsigned i = 0; i < m1.size1 (); ++ i)
    {
        for (unsigned j = 0; j < m1.size2 (); ++ j)
        {
            m1(i, j) = std::complex<double>(3 * i + j, i);
        }
    }

    std::cout << "\n*** Complex sparse matrix ***" << std::endl;
    std::cout << m1 << std::endl;

    // Part A -  Experiment with insertion
    std::cout << "\n*** Inserted into sparse matrix ***" << std::endl;
    m1(0, 0) = std::complex<double>(12, 1);
    m1(2, 2) = std::complex<double>(99, 1);
    std::cout << m1 << std::endl;

    // Part A - Erasure elements
    std::cout << "\n***Erase a sparse Matrix" << std::endl;
    m1.erase_element(0, 0);
    m1.erase_element(2, 2);
    std::cout << m1 << std::endl;

    // Part A - Clear a sparse matrix.
    std::cout << "\n***Clear a sparse Matrix" << std::endl;
    m1.clear();
    std::cout << m1 << std::endl;

    // Part B - Create a number of upper and lower triangular
    // matrices with row and column-major storage organization.

    // Lower Triangular matrices - Column Major + Unbounded
    matrix<double, column_major> m2 (3, 3);
    triangular_adaptor<matrix<double, column_major, unbounded_array<double>>, lower> triangularLower1(m2);
    for (unsigned i = 0; i < triangularLower1.size1 (); ++ i)
    {
        for (unsigned j = 0; j <= i; ++ j)
        {
            triangularLower1(i, j) = 3 * i + j;
        }
    }
    std::cout << "\n*** Lower Triangle Column Major Matrix with Unbounded Storage ***" << std::endl;
    std::cout << triangularLower1 << std::endl;

    // Lower Triangular matrices - Row Major + Bounded
    matrix<double, row_major, bounded_array<double, 9>> m3(3, 3);
    triangular_adaptor<matrix<double, row_major, bounded_array<double, 9>>, lower> triangularLower2(m3);
    for (unsigned i = 0; i < triangularLower2.size1(); ++ i)
    {
        for (unsigned j = 0; j <= i; ++ j)
        {
            triangularLower2(i, j) = 3 * i + j;
        }
    }
    std::cout << "\n*** Lower Triangle Row Major Matrix with Bounded Storage ***" << std::endl;
    std::cout << triangularLower2 << std::endl;

    // Lower Triangular matrices - Column Major + Unbounded
    matrix<double, column_major, unbounded_array<double>> m4(3, 3);
    triangular_adaptor<matrix<double, column_major, unbounded_array<double>>, upper> triangularUpper1(m4);
    for (unsigned i = 0; i < triangularUpper1.size1 (); ++ i)
    {
        for (unsigned j = 0; j <= i; ++ j)
        {
            triangularUpper1(j, i) = 3 * i + j;
        }
    }
    std::cout << "\n*** Upper Triangle Column Major Matrix with Unbounded Storage ***" << std::endl;
    std::cout << triangularUpper1 << std::endl;

    // Lower Triangular matrices - Row Major + Bounded
    matrix<double, row_major, bounded_array<double, 9>> m5(3, 3);
    triangular_adaptor<matrix<double, row_major, bounded_array<double, 9>>, upper> triangularUpper2(m5);
    for (unsigned i = 0; i < triangularUpper2.size1 (); ++ i)
    {
        for (unsigned j = 0; j <= i; ++ j)
        {
            triangularUpper2(j, i) = 3 * i + j;
        }
    }
    std::cout << "\n*** Upper Triangle Row Major Matrix with Bounded Storage ***" << std::endl;
    std::cout << triangularUpper2 << std::endl;

    // Part C -  Boost uBLAS supports matrix adapters for dense matrices. For example,
    // it is possible to define upper and lower triangular views of a dense matrix.
    // Create these views by taking some examples.
    // NOTE: Per https://quantnet.com/threads/3-matrix-views.55078/#post-323086 and lecture material
    // matrix views are also known as Matrix Proxies (aka slices, ranges, etc).
    std::cout << "\n Matrix Slice to create a view of the matrix ***" << std::endl;
    matrix<double> m6(3, 3);
    matrix_slice<matrix<double> > mSlice (m6, slice (0, 1, 3), slice (0, 1, 3));
    for (unsigned i = 0; i < mSlice.size1 (); ++ i)
    {
        for (unsigned j = 0; j < mSlice.size2 (); ++ j)
        {
            mSlice(i, j) = 3 * i + j;
        }
    }
    std::cout << mSlice << std::endl;

    std::cout << "\n Matrix Range to create a view of the matrix ***" << std::endl;
    matrix<double> m7(3, 3);
    matrix_range<matrix<double>> mRange(m7, range (0, 3), range (0, 3));
    for (unsigned i = 0; i < mRange.size1 (); ++ i)
    {
        for (unsigned j = 0; j < mRange.size2 (); ++ j)
        {
            mRange(i, j) = 3 * i + j;
        }
    }
    std::cout << mRange << std::endl;

    std::cout << "\n Matrix Row to create a view of the matrix ***" << std::endl;
    matrix<double> m8(3, 3);
    for (unsigned i = 0; i < m8.size1 (); ++ i)
    {
        matrix_row<matrix<double> > mRow(m8, i);
        for (unsigned j = 0; j < mRow.size (); ++ j)
        {
            mRow(j) = 3 * i + j;
        }
        std::cout << mRow << std::endl;
    }

    std::cout << "\n Matrix Row to create a view of the matrix ***" << std::endl;
    matrix<double> m9(3, 3);
    for (unsigned j = 0; j < m9.size2 (); ++ j)
    {
        matrix_column<matrix<double> > mColumn(m9, j);
        for (unsigned i = 0; i < mColumn.size (); ++ i)
        {
            mColumn(i) = 3 * i + j;
        }
        std::cout << mColumn << std::endl;
    }

    return 0;
}

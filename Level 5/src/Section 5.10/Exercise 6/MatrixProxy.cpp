//
// A MatrixProxy that provides an interface for ublas matrix row, column, range, and slice operations.
// Note - These operations are currently provided as static functions because MatrixProxy has no need
// to maintain state.
//
// Created by Michael Lewis on 8/2/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_MATRIXPROXY_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_MATRIXPROXY_CPP

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

#include "MatrixProxy.hpp"

/**
 * The templated class matrix_row<M> allows addressing a row of a matrix.
 * @param matrix The referenced Matrix
 */
template<typename T>
void MatrixProxy<T>::matrix_row(T& matrix)
{
    std::cout << "\n Matrix Row ***" << std::endl;
    for (unsigned i = 0; i < matrix.size1(); ++ i)
    {
        boost::numeric::ublas::matrix_row<T> mRow(matrix, i);
        std::cout << mRow << std::endl;
    }
}

/**
 * The templated class matrix_column<M> allows addressing a column of a matrix.
 * @param matrix The referenced Matrix
 */
template<typename T>
void MatrixProxy<T>::matrix_column(T& matrix)
{
    std::cout << "\n Matrix Column ***" << std::endl;
    for (unsigned j = 0; j < matrix.size2 (); ++ j)
    {
        boost::numeric::ublas::matrix_column<T> mColumn(matrix, j);
        std::cout << mColumn << std::endl;
    }
}

/**
 * The class range specifies a range of indicies. The range is a sequence of indices from a
 * start value to stop value. The indices increase by one and exclude the stop value.
 * range can therefore be used to specify ranges of elements from vectors and matrices.
 * @param matrix The Matrix from which to construct a Range
 * @param start A start index
 * @param stop An exclusive index
 */
template<typename T>
void MatrixProxy<T>::matrix_range(T& matrix, size_t start, size_t stop)
{
    std::cout << "\n Matrix Range ***" << std::endl;
    boost::numeric::ublas::matrix_range<T> mRange(matrix,
                                                  boost::numeric::ublas::range(start, stop),
                                                  boost::numeric::ublas::range(start, stop));
    std::cout << mRange << std::endl;
}

/**
 * The class slice specifies a 'slice' of indicies. Slices are more general then ranges, the
 * stride allows the sequence of indicies to increase and decrease by the specified amount
 * between element. slice can therefore be used to specify slices of element from vectors and matrices.
 * @param matrix The Matrix from which to construct a Slice
 * @param start A start index
 * @param stride An amount by which to increase or decrease the distance between each element in the Slice
 * @param size The number of elements to include in the slice
 */
template<typename T>
void MatrixProxy<T>::matrix_slice(T& matrix, size_t start, long stride, size_t size)
{
    std::cout << "\n Matrix Slice ***" << std::endl;
    boost::numeric::ublas::matrix_slice<T> mSlice (matrix,
                                                   boost::numeric::ublas::slice(start, stride, size),
                                                   boost::numeric::ublas::slice(start, stride, size));
    std::cout << mSlice << std::endl;
}

#endif

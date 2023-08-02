//
// A MatrixProxy that provides an interface for ublas matrix row, column, range, and slice operations.
// Note - These operations are currently provided as static functions because MatrixProxy has no need
// to maintain state.
//
// Created by Michael Lewis on 8/2/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_MATRIXPROXY_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_MATRIXPROXY_HPP

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

template<typename T>
class MatrixProxy
{
public:
    static void matrix_row(T& matrix);
    static void matrix_column(T& matrix);
    static void matrix_range(T& matrix, size_t start, size_t stop);
    static void matrix_slice(T& matrix, size_t start, long stride, size_t size);
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_MATRIXPROXY_CPP
#include "MatrixProxy.cpp"
#endif // ADVANCED_CPP_AND_MODERN_DESIGN_MATRIXPROXY_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_MATRIXPROXY_HPP

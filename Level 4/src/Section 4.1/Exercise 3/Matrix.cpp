//
// A compile-time Matrix adapter that wraps a std::array.
//
// Created by Michael Lewis on 7/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_MATRIX_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_MATRIX_CPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>

#include "Matrix.hpp"

/**
 * Default ctor, which constructs this Matrix with a specified number of rows and columns
 * @tparam T The type of element that will be stored in this Matrix
 * @tparam NR The number of rows in this Matrix
 * @tparam NC The number of columns in this Matrix
 */
template<typename T, size_t NR, size_t NC>
Matrix<T, NR, NC>::Matrix() : rows{NR}, columns{NC}
{
    matrix = std::array<std::array<T, NC>, NR>();
}

/**
 * Copy ctor
 * @tparam T The type of element that will be stored in this Matrix
 * @tparam N The size of this Matrix
 * @param other A Matrix whose elements will be deeply copied into this Matrix
 */
template<typename T, size_t NR, size_t NC>
Matrix<T, NR, NC>::Matrix(const Matrix<T, NR, NC>&other) : rows{NR}, columns{NC}
{
    if (rows != other.rows) throw std::invalid_argument("Matrices must have the same number of rows");
    if (columns != other.columns) throw std::invalid_argument("Matrices must have the same number of columns");

    // Reallocate this Matrix
    matrix = std::array<std::array<T, NC>, NR>();
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < matrix[j].size(); ++j)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

/**
 * Overloaded ctor that populates each index in this Matrix with a default value
 * @tparam T The type of element that will be stored in this Matrix
 * @tparam N The size of this Matrix
 * @param args A list of values to fill this Matrix
 */
template<typename T, size_t NR, size_t NC>
Matrix<T, NR, NC>::Matrix(const T& defaultValue) : rows{NR}, columns{NC}
{
    matrix = std::array<std::array<T, NC>, NR>();
    for (int i = 0; i < rows; ++i)
    {
        matrix[i].fill(defaultValue);  // Fill in each row with a default value
    }
}

/**
 * Overloaded ctor
 * @tparam T The type of element that will be stored in this Matrix
 * @tparam N The size of this Matrix
 * @param args A list of values to fill this Matrix
 */
template<typename T, size_t NR, size_t NC>
Matrix<T, NR, NC>::Matrix(const std::initializer_list<T>& args) : rows{NR}, columns{NC}
{
    matrix = std::array<std::array<T, NC>, NR>();
    size_t row = 0;
    size_t col = 0;
    for (const T& element : args)
    {
        if (col == columns)
        {
            ++row; // Shift to next row only when all columns in this row are filled in
            col = 0; // Reset col to begining of row
        }
        matrix[row][col++] = element;
    }
}

/**
 * Returns a reference to the element at specified location index. No bounds checking is performed
 * @tparam T Data type of the elements stored in this std::Matrix
 * @tparam N The size of this Matrix
 * @param row Row position of the element to return
 * @param column Column position of the element to return
 * @return Reference to the requested element.
 */
template<typename T, size_t NR, size_t NC>
const T& Matrix<T, NR, NC>::operator()(size_t row, size_t column) const
{
    return matrix[row][column];
}

/**
 * Returns a reference to the element at specified location index. No bounds checking is performed
 * @tparam T Data type of the elements stored in this std::Matrix
 * @tparam N The size of this Matrix
 * @param row Row position of the element to return
 * @param column Column position of the element to return
 * @return Reference to the requested element.
 */
template<typename T, size_t NR, size_t NC>
T& Matrix<T, NR, NC>::operator()(size_t row, size_t column)
{
    return matrix[row][column];
}

/**
 * Performs Matrix addition. Uses STL transform to perform Matrix addition
 * @tparam T Data type of the elements stored in this std::Matrix
 * @tparam N The size of this Matrix
 * @param other Another Matrix that will be added with the elements from this Matrix
 * @return A new stack based memory object.
 */
template<typename T, size_t NR, size_t NC>
Matrix<T, NR, NC> Matrix<T, NR, NC>::operator+(const Matrix<T, NR, NC> &other) const
{
    if (rows != other.rows) throw std::invalid_argument("Matrices must have the same number of rows");
    if (columns != other.columns) throw std::invalid_argument("Matrices must have the same number of columns");

    Matrix<T, NR, NC> result{};
    for (int i = 0; i < rows; ++i)
    {
        std::transform(matrix[i].cbegin(), matrix[i].cend(), // iterate from beginning to end column for the ith row
                       other.matrix[i].cbegin(),
                       result.matrix[i].begin(), // Write to a new Matrix
                       std::plus<T>());
    }

    return result;
}

/**
 * Performs Matrix subtraction. Uses STL transform to perform Matrix subtraction
 * @tparam T Data type of the elements stored in this std::Matrix
 * @tparam N The size of this Matrix
 * @param other Another Matrix that will be subtracted from the elements from this Matrix
 * @return A new stack based memory object.
 */
template<typename T, size_t NR, size_t NC>
Matrix<T, NR, NC> Matrix<T, NR, NC>::operator-(const Matrix<T, NR, NC> &other) const
{
    if (rows != other.rows) throw std::invalid_argument("Matrices must have the same number of rows");
    if (columns != other.columns) throw std::invalid_argument("Matrices must have the same number of columns");

    Matrix<T, NR, NC> result{};
    for (int i = 0; i < rows; ++i)
    {
        std::transform(matrix[i].cbegin(), matrix[i].cend(), // iterate from beginning to end column for the ith row
                       other.matrix[i].cbegin(),
                       result.matrix[i].begin(), // Write to a new Matrix
                       std::minus<T>());
    }

    return result;
}

/**
 * Performs unary negation of this Matrix. Uses STL transform to perform negation
 * @tparam T Data type of the elements stored in this std::Matrix
 * @tparam N The size of this Matrix
 * @return A new stack based memory object.
 */
template<typename T, size_t NR, size_t NC>
Matrix<T, NR, NC> Matrix<T, NR, NC>::operator-()
{
    for(int i = 0; i < rows; ++i)
    {
        std::transform(matrix[i].cbegin(), matrix[i].cend(), // iterate from beginning to end column for the ith row
                       matrix[i].begin(), // Write to the current Matrix
                       [](double element) -> double {return -element;});
    }

    return *this;;
}

/**
 * Injects a std::function that can be used to modify this Matrix.
 * @tparam T Data type of the elements stored in this std::Matrix
 * @tparam N The size of this Matrix
 * @tparam Type Data type of the incoming function that is used to transform this Matrix
 * @param function
 */
template<typename T, size_t NR, size_t NC>
template<typename Type>
void Matrix<T, NR, NC>::modify(const std::function<Type(Type &)> &function)
{
    for(int i = 0; i < rows; ++i)
    {
        std::transform(matrix[i].begin(), matrix[i].end(), // iterate from beginning to end column for the ith row
                       matrix[i].begin(), // Write to this Matrix
                       function);
    }
}

/**
 * Utility method to print each element in this Matrix
 * @tparam T Data type of the elements stored in this std::Matrix
 * @tparam N The size of this Matrix
 */
template<typename T, size_t NR, size_t NC>
void Matrix<T, NR, NC>::print() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cout << matrix[i][j] << ", ";
        }
        std::cout << "\n";
    }
}

// ********** Friend Functions *********

/**
 * Pre-multiplication by a scalar quantity. Implemented as a friend function because
 * scalar multiplication is left associative
 * @tparam Type Data type of the elements stored in the incoming Matrix
 * @tparam N_ The size of this Matrix
 * @tparam F Scalar type used to multiply with this Matrix
 * @param a The scalar multiplier
 * @param pt The source matrix that will be scaled
 * @return The scaled Matrix
 */
template<typename Type, size_t NR_, size_t NC_, typename F>
Matrix<Type, NR_, NC_> operator*(const F& a, const Matrix<Type, NR_, NC_>& pt)
{
    Matrix<Type, NR_, NC_> scaled;
    for (int i = 0; i < NR_; ++i)
    {
        for (int j = 0; j < NC_; ++j)
        {
            scaled(i, j) = a * pt(i, j);
        }
    }
}

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_Matrix_CPP
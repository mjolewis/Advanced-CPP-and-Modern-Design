//
// A compile-time Matrix adapter that wraps a std::array.
//
// Created by Michael Lewis on 7/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_MATRIX_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_MATRIX_HPP

#include <array>
#include <functional>

template<typename T, size_t NR, size_t NC>
class Matrix
{
private:
    const size_t rows;
    const size_t columns;
    std::array<std::array<T, NC>, NR> matrix;

public:
    Matrix();
    Matrix(const Matrix<T, NR, NC>& other);
    explicit Matrix(const T& defaultValue);
    explicit Matrix(T&& defaultValue);
    Matrix(const std::initializer_list<T>& args);
    ~Matrix() = default;

    // Operator overloads
    const T& operator()(size_t row, size_t column) const;
    T& operator()(size_t row, size_t column);
    Matrix<T, NR, NC> operator+(const Matrix<T, NR, NC>& other) const;
    Matrix<T, NR, NC> operator-(const Matrix<T, NR, NC>& other) const;
    Matrix<T, NR, NC> operator-();
    void operator<<(const Matrix<T, NR, NC>& other) const;
    void operator<<(Matrix<T, NR, NC>& other);

    template<typename Type>
    void modify(const std::function <Type (Type&)>& function);
    void print() const;

    // Friends
    template<typename Type, size_t NR_, size_t NC_, typename F> Matrix<T, NR, NC>
    friend operator*(const F& a, const Matrix<Type, NR, NC>& pt);
};

// *** Template Definitions ***
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_MATRIX_CPP
#include "Matrix.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_MATRIX_CPP


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_MATRIX_HPP

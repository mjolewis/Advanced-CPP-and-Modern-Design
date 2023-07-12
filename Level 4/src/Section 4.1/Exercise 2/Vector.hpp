//
// A compile-time Vector adapter that wraps a std::array.
//
// Created by Michael Lewis on 7/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_VECTOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_VECTOR_HPP

#include <array>
#include <functional>

template<typename T, size_t N>
class Vector
{
private:
    const size_t size;
    std::array<T, N> array;

public:
    Vector();
    Vector(const Vector<T, N>& other);
    explicit Vector(const T& defaultValue);
    Vector(const std::initializer_list<T>& args);
    ~Vector() = default;

    // Operator overloads
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    Vector<T, N> operator+(const Vector<T, N>& other) const;
    Vector<T, N> operator-(const Vector<T, N>& other) const;
    Vector<T, N> operator-();

    template<typename Type>
    void modify(const std::function <Type (Type&)>& function);
    void print() const;

    // Friends
    template<typename Type, size_t N_, typename F> Vector<T, N>
    friend operator*(const F& a, const Vector<Type, N>& pt);
};

// *** Template Definitions ***
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_VECTOR_CPP
#include "Vector.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_VECTOR_CPP


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_VECTOR_HPP

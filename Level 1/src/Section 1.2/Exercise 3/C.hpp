//
// Created by Michael Lewis on 5/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP

#include <array>
#include <vector>
#include <string>

/**
 * Example class that illustrates modern C++ concepts and features
 */
template<typename T>
class C
{
private:
    // Compile time constant to illustrate use case of constexpr specifier
    constexpr static int DEFAULT_SIZE = 5;

    int size;
    std::unique_ptr<std::vector<T>> vec;

public:
    constexpr explicit C(); // no arg ctor
    explicit C(int size); // overloaded ctor
    C(const C<T>& source); // copy ctor
    C(C<T>&& source) noexcept; // move ctor
    virtual ~C(); // default dtor

    // Operator overload
    C<T>& operator=(const C<T>& source);
    C<T>& operator=(C<T>&& source) noexcept;

    // Member functions
    void print() const;  // not eligible for noexcept because stream operations can throw an exception
    void insert(const T& value); // not eligible for noexcept because insertion operations can fail
    T sumVector() noexcept;

    template<typename U>
    void swapCopyStyle(U& a, U& b) noexcept;

    template<typename U>
    void swapMoveStyle(U&& a, U&& b) noexcept;

    // Accessors and mutators
    const std::unique_ptr<std::vector<T>>& getVec() const noexcept;
    void setVec(int index, T element) noexcept;
};

#ifndef C_PP
#include "C.cpp"

#endif // C_PP
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP

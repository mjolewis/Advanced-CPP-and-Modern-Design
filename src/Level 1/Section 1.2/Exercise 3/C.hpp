//
// Created by Michael Lewis on 5/29/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP

#include <array>
#include <vector>
#include <string>

template<typename T>
class C
{
private:
    std::vector<T> vec;

public:
    constexpr explicit C();
    C(const C<T>& source);
    C(const C<T>&& source) noexcept;
    virtual ~C();

    // Operator overload
    C<T>& operator=(const C<T>& source);

    // Member functions
    void print() const;  // not eligible for noexcept because stream operations can throw an exception
    void insert(T value); // not eligible for noexcept because insertion operations can fail
    int sumArray() noexcept;
    T sumVector() noexcept;

    template<typename U>
    void swapCopyStyle(U& a, U& b) noexcept;

    template<typename U>
    void swapMoveStyle(U&& a, U&& b) noexcept;

    // Accessors and mutators
    std::vector<T>& getVec() const noexcept;
    void setVec(const std::vector<T>& source) noexcept;
};

#ifndef C_PP
#include "C.cpp"

#endif // C_PP
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP

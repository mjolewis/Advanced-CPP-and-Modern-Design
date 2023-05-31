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
    // Compile time constant to illustrate use case of constexpr specifier
    int PUBLISH_FREQ_MILLIS = 1000;

    std::vector<T> vec;
    std::array<int, 5> array{1, 2, 3, 4, 5}; // illustrate compile time constexpr with std::array

public:
    constexpr explicit C() = default;
    C(const C<T>& source) = delete; // Note - Deleted members must be public to perform required test per HW notes
    virtual ~C();

    C& operator=(const C<T>& source) = delete; // Note - Deleted members must be public to perform required test per HW notes

    // Member functions
    void print() const;  // not eligible for noexcept because stream operations can throw an exception
    void insert(T value); // not eligible for noexcept because insertion operations can fail
    int sumArray() noexcept;
    T sumVector() noexcept;

    // Accessors and mutators
    std::vector<T>& getVec() const noexcept;
    void setVec(const std::vector<T>& source) noexcept;
    std::array<int, 5>& getArray() noexcept;
    void setArray(const std::array<int, 5>& source) noexcept;
    constexpr int getPublishFrequency() noexcept;
};

#ifndef C_PP
#include "C.cpp"

#endif // C_PP
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP

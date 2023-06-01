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

    // Compile time constant to illustrate use case of constexpr specifier
    constexpr static int DEFAULT_SIZE = 5;

    int size;
    std::unique_ptr<std::vector<T>> vec;
    std::array<int, 5> array{1, 2, 3, 4, 5}; // illustrate compile time constexpr with std::array

public:
    constexpr explicit C() = default;
    explicit C(int size); // overloaded ctor
    C(const C<T>& source) = delete; // Note - Deleted members must be public to perform required test per HW notes
    virtual ~C(); // default dtor

    // Operator overload
    C& operator=(const C<T>& source) = delete; // Note - Deleted members must be public to perform required test per HW notes

    // Member functions
    void print() const;  // not eligible for noexcept because stream operations can throw an exception
    void insert(const T& value); // not eligible for noexcept because insertion operations can fail
    T sumVector() noexcept;
    int sumArray() noexcept;

    // Accessors and mutators
    const std::unique_ptr<std::vector<T>>& getVec() const noexcept;
    void setVec(int index, T element) noexcept;
    const std::array<int, 5>& getArray() noexcept;
    void setArray(int index, int element) noexcept;
    constexpr int getPublishFrequency() noexcept;
    int getSize() const noexcept;
};

#ifndef C_PP
#include "C.cpp"

#endif // C_PP
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP

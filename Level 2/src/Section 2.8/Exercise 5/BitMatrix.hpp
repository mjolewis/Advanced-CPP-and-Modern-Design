//
// A BitMatrix is an std::array of std::bitsets
// The class template bitset represents a fixed-size sequence of N bits.
// Bitsets can be manipulated by standard logic operators and converted to and
// The sequence is thought of as having its lowest indexed elements at the right (or little endian),
// as in the binary representation of integers.
//
// Created by Michael Lewis on 6/25/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BITMATRIX_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BITMATRIX_HPP


#include <array>
#include <bitset>
#include <list>

template<size_t M, size_t N>
class BitMatrix
{
private:
    std::array<std::bitset<M>, N> bitMatrix;

public:
    constexpr BitMatrix();
    explicit BitMatrix(unsigned long value);
    BitMatrix(const BitMatrix& source);
    BitMatrix(BitMatrix&& source) noexcept;
    ~BitMatrix() = default;

    // Accessors
    const std::array<std::bitset<M>, N>& getBitMatrix() const { return bitMatrix; }

    // Mutators
    BitMatrix& set() noexcept;
    BitMatrix& set(size_t M_, size_t N_, bool value = true);
    BitMatrix& reset() noexcept;
    BitMatrix& reset(size_t M_, size_t N_);
    BitMatrix& flip() noexcept;
    BitMatrix& flip(size_t M_, size_t N_);
    BitMatrix& operator&=(const BitMatrix& other) noexcept;
    BitMatrix& operator|=(const BitMatrix& other) noexcept;
    BitMatrix& operator^=(const BitMatrix& other) noexcept;

    // Element Access
    bool all() const noexcept;
    bool any() const noexcept;
    bool none() const noexcept;
    constexpr std::bitset<M> operator[](std::size_t row) const;
    std::list<std::size_t>&& count() const noexcept;

};

//*** Start Template Definitions ***
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BITMATRIX_CPP
#include "BitMatrix.cpp"
#endif
//*** End Template Definitions ***

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_BITMATRIX_HPP

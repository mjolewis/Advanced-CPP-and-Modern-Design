//
// A BitMatrix is an std::array of std::bitsets
// The class template bitset represents a fixed-size sequence of N bits.
// Bitsets can be manipulated by standard logic operators and converted to and
// The sequence is thought of as having its lowest indexed elements at the right (or little endian),
// as in the binary representation of integers.
//
// Created by Michael Lewis on 6/25/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BITMATRIX_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BITMATRIX_CPP

#include <iostream>
#include <stdexcept>

#include "BitMatrix.hpp"

/**
 * Default ctor
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 */
template<size_t M, size_t N>
constexpr BitMatrix<M, N>::BitMatrix()
{
    for (int i = 0; i < N; ++i)
    {
        bitMatrix[i] = std::bitset<M>{};
    }
}

/**
 * Overloaded ctor that sets each std::bitset to the specified value
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param value An unsigned long that is used as the value of each std::bitset within the BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>::BitMatrix(unsigned long value)
{
    for (int i = 0; i < N; ++i)
    {
        bitMatrix[i] = std::bitset<M>{value};
    }
}

/**
 * Copy ctor
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param source A BitMatrix whose member values will be copied into this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>::BitMatrix(const BitMatrix& source)
{
    // Deep copy of the source array
    int rows = source.bitMatrix.size();
    for (int i = 0; i < rows; ++i)
    {
        bitMatrix[i] = source.bitMatrix[i];
    }
}

/**
 * Move ctor
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param source A BitMatrix whose member values will be copied into this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>::BitMatrix(BitMatrix&& source) noexcept
{
    for (int i = 0; i < N; ++i)
    {
        bitMatrix[i] = std::move(source.bitMatrix[i]);
        std::cout << bitMatrix[i] << std::endl;
    }
}

/**
 * Sets all bits to true for each st::bitset in the BitMatrix.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::set() noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i) bitMatrix[i].set();
    return *this;
}

/**
 * Sets one bit to specified value.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param M_ The column index to be set
 * @param N_ The row index to be set
 * @param value The new value of the specified bit
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::set(size_t M_, size_t N_, bool value)
{
    if (N_ > bitMatrix.size())
    {
        throw std::out_of_range("N_ is out of range. N_ must be between [0," + std::to_string(bitMatrix.size() - 1) + ")");
    }
    else if (M_ > bitMatrix.at(N_).size())
    {
        throw std::out_of_range("M_ is out of range. M_ must be between [0," + std::to_string(bitMatrix.size() - 1) + ")");
    }
    else
    {
        bitMatrix[N_][M_] = value;
    }

    return *this;
}

/**
 * Sets all bits to false
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::reset() noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i) bitMatrix[i].reset();
    return *this;
}

/**
 * Sets the bit at position pos to false.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param M_ The column index to be reset
 * @param N_ The row index to be reset
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::reset(size_t M_, size_t N_)
{
    return set(M_, N_, false);
}

/**
 * Flips all bits (like operator~, but in-place).
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::flip() noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i) bitMatrix[i].flip();
    return *this;
}

/**
 * Flips the bit at the position pos.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param M_ The column index to be reset
 * @param N_ The row index to be reset
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::flip(size_t M_, size_t N_)
{
    if (N_ > bitMatrix.size())
    {
        throw std::out_of_range("N_ is out of range. N_ must be between [0," + std::to_string(bitMatrix.size() - 1) + ")");
    }
    else if (M_ > bitMatrix.at(N_).size())
    {
        throw std::out_of_range("M_ is out of range. M_ must be between [0," + std::to_string(bitMatrix.size() - 1) + ")");
    }
    else
    {
        bitMatrix[N_].flip(N_);
    }

    return *this;
}

/**
 * Sets the bits to the result of binary AND on corresponding pairs of bits of *this and other.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param other The BitMatrix used to compare this BitMatrix against
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::operator&=(const BitMatrix<M, N> &other) noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i) bitMatrix[i] &= other[i];
    return *this;
}

/**
 * Sets the bits to the result of binary OR on corresponding pairs of bits of *this and other.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param other The BitMatrix used to compare this BitMatrix against
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::operator|=(const BitMatrix<M, N> &other) noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i) bitMatrix[i] |= other[i];
    return *this;
}

/**
 * Sets the bits to the result of binary XOR on corresponding pairs of bits of *this and other.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param other The BitMatrix used to compare this BitMatrix against
 * @return A reference to this BitMatrix
 */
template<size_t M, size_t N>
BitMatrix<M, N>& BitMatrix<M, N>::operator^=(const BitMatrix<M, N> &other) noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i) bitMatrix[i] ^= other[i];
    return *this;
}

/**
 * Checks if all bits are set to true.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @return true if all bits are set to true, otherwise false.
 */
template<size_t M, size_t N>
bool BitMatrix<M, N>::all() const noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i)
    {
        if (!bitMatrix[i].all()) return false;
    }

    return true;
}

/**
 * Checks if any bits are set to true.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @return true if any of the bits are set to true, otherwise false.
 */
template<size_t M, size_t N>
bool BitMatrix<M, N>::any() const noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i)
    {
        if (bitMatrix[i].any()) return true;
    }

    return false;
}

/**
 * Checks if none of the bits are set to true.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @return true if none of the bits are set to true, otherwise false.
 */
template<size_t M, size_t N>
bool BitMatrix<M, N>::none() const noexcept
{
    for (int i = 0; i < bitMatrix.size(); ++i)
    {
        if (!bitMatrix[i].none()) return false;
    }

    return true;
}

/**
 * The std::bitset contained in the specified row
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @param row The target row for this BitMatrix
 * @return std::bitset
 */
template<size_t M, size_t N>
constexpr std::bitset<M> BitMatrix<M, N>::operator[](std::size_t row) const
{
    return bitMatrix[row];
}

/**
 * Returns the number of bits that are set to true.
 * @tparam M The number of columns in this BitMatrix
 * @tparam N The number of rows in this BitMatrix
 * @return A list where each element represents the number of bits that are set to true in the corresponding bitset
 */
template<size_t M, size_t N>
std::list<size_t>&& BitMatrix<M, N>::count() const noexcept
{
    std::list<size_t> count;
    for (int i = 0; i < bitMatrix.size(); ++i)
    {
        count.push_back(bitMatrix[i].count());
    }

    return std::move(count);
}

#endif
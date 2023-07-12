//
// An illustration of how to create and interact with useful bitmap classes that are partially
// specialized with a Proposition. These can be used to implement bitmasking.
//
// Created by Michael Lewis on 7/10/23.
//

#include <functional>
#include <string>

#include "Matrix.hpp"
#include "Proposition.hpp"

// Partial specialization of Matrix to create a BitMap
using value_type = Proposition;
template <size_t NR, size_t NC>
using BitMap = Matrix<value_type, NR, NC>;
template <size_t NR, size_t NC>
using BitMap2 = std::array<std::bitset<NC>, NR>;

// Generic function that can be used to superimpose to bitmaps
using BitFunction = std::function<Proposition (const Proposition&, const Proposition&)>;

// Print each element in this BitMap
template<size_t NR, size_t NC>
void print(const BitMap<NR, NC>& bitMap)
{
    for (int i = 0; i < NR; ++i)
    {
        for (int j = 0; j < NC; ++j)
        {
            std::cout << bitMap(i, j) << ", ";
        }
        std::cout << "\n";
    }
}

// Print each element in this BitMap2
template<size_t NR, size_t NC>
void print(const BitMap2<NR, NC>& bitMap)
{
    for (int i = 0; i < NR; ++i)
    {
        for (int j = 0; j < NC; ++j)
        {
            std::cout << bitMap(i, j) << ", ";
        }
        std::cout << "\n";
    }
}

// Merges two bitmaps using the specified BitFunction. Can be used to implement a bitmask
template<size_t NR, size_t NC>
BitMap<NR, NC> mask(const BitMap<NR, NC>& bitMap1, const BitMap<NR, NC>& bitmap2, const BitFunction& masker)
{
    BitMap<NR, NC> masked;
    for (int i = 0; i < NR; ++i)
    {
        for (int j = 0; j < NC; ++j)
        {
            masked(i, j) = masker(bitMap1(i, j), bitmap2(i, j));
        }
    }

    return masked;
}

// Create a bitmask between two bitmaps that using bitwise equality between two Propositions
void test_BitMask_Equality()
{
    std::cout << "\n*** BITMASK EQUAL ***" << std::endl;

    BitMap<4, 3> bm(true);
    bm(0, 1) = false;
    bm(1, 1) = false;
    bm(2, 1) = false;
    bm(3, 1) = false;

    BitMap<4, 3> bm2(true);

    auto EQUAL = [](const Proposition& lhs, const Proposition& rhs) { return lhs == rhs; };
    auto bmA = mask(bm, bm2, EQUAL);
    print(bmA);
}

// Create a bitmask between two bitmaps that using bitwise inequality between two Propositions
void test_BitMask_Inequality()
{
    std::cout << "\n*** BITMASK INEQUALITY ***" << std::endl;

    BitMap<4, 3> bm(true);
    bm(0, 2) = false;
    bm(1, 2) = false;
    bm(2, 2) = false;
    bm(3, 2) = false;

    BitMap<4, 3> bm2(true);

    auto INEQAULITY = [](const Proposition& lhs, const Proposition& rhs) { return lhs != rhs; };
    auto bmA = mask(bm, bm2, INEQAULITY);
    print(bmA);
}

// Create a bitmask between two bitmaps that using bitwise AND between two Propositions
void test_BitMask_AND()
{
    std::cout << "\n*** BITMASK AND ***" << std::endl;

    BitMap<4, 3> bm(true);
    bm(3, 2) = false;

    BitMap<4, 3> bm2(true);
    bm2(3, 2) = true;

    auto AND = [](const Proposition& lhs, const Proposition& rhs) { return lhs & rhs; };
    auto bmA = mask(bm, bm2, AND);
    print(bmA);
}

// Create a bitmask between two bitmaps that using bitwise OR between two Propositions
void test_BitMask_OR()
{
    std::cout << "\n*** BITMASK OR ***" << std::endl;

    BitMap<4, 3> bm(true);
    bm(1, 1) = false;

    BitMap<4, 3> bm2(false);

    auto OR = [](const Proposition& lhs, const Proposition& rhs) { return lhs | rhs; };
    auto bmA = mask(bm, bm2, OR);
    print(bmA);
}

// Create a bitmask between two bitmaps that using bitwise XOR between two Propositions
void test_BitMask_XOR()
{
    std::cout << "\n*** BITMASK XOR ***" << std::endl;

    BitMap<4, 3> bm(true);
    bm(3, 2) = false;

    BitMap<4, 3> bm2(true);
    bm2(3, 2) = true;

    const BitFunction& XOR = [](const Proposition& lhs, const Proposition& rhs) { return lhs ^ rhs; };
    auto bmA = mask(bm, bm2, XOR);
    print(bmA);
}

// Create a bitmask between two bitmaps that using bitwise conditional between two Propositions
void test_BitMask_Conditional()
{
    std::cout << "\n*** BITMASK CONDITIONAL ***" << std::endl;

    BitMap<4, 3> bm(true);
    bm(0, 0) = false;
    bm(2, 2) = false;

    BitMap<4, 3> bm2(true);
    bm2(1, 1) = false;
    bm2(2, 2) = false;
    bm2(0, 2) = false;

    auto CONDITIONAL = [](const Proposition& lhs, const Proposition& rhs) { return lhs % rhs; };
    auto bmA = mask(bm, bm2, CONDITIONAL);
    print(bmA);
}

// Create a bitmask between two bitmaps that using bitwise bi-conditional between two Propositions
void test_BitMask_BiConditional()
{
    std::cout << "\n*** BITMASK BI-CONDITIONAL ***" << std::endl;

    BitMap<4, 3> bm(true);

    BitMap<4, 3> bm2(true);
    bm2(0, 0) = false;
    bm2(1, 1) = false;
    bm2(2, 2) = false;
    bm2(0, 2) = false;
    bm2(2, 0) = false;

    auto BI_CONDITIONAL = [](const Proposition& lhs, const Proposition& rhs) { return lhs <=> rhs; };
    auto bmA = mask(bm, bm2, BI_CONDITIONAL);
    print(bmA);
}

template<size_t NR, size_t NC>
void initialise(BitMap2<NR, NC>& bitMap, int row, const std::string& initialValue)
{
    std::bitset<NC> bitset{initialValue};
    bitMap[row] = bitset;
}

// Compare and contrast the initialization of two different bitmaps with a different underlying structure
// using BitMap = Matrix<value_type, NR, NC>;
// using BitMap2 = std::array<std::bitset<NC>, NR>;
// The benefit of using BitMap2 is significant. You can simply pass in a string to represent the
// full bitset that you wish to construct. Subsequently, the std::bitset constructor will convert that
// string into the desired bitset. This allows you to create a bitset of N size in one line of code.
// This is a significant improvement to the initialization of BitMap, which requires a new line of code
// for initializing each bit in the bitset. Not only is this less efficient, but it is also more
// error prone.
void test_BitMap_VS_BitMap2()
{
    BitMap<4, 7> bitblt(false);
    bitblt(1, 2) =
    bitblt(1, 3) =
    bitblt(1, 4) =
    bitblt(1, 6) = true;

    const int P = 8;
    const int Q = 8;
    BitMap2<P, Q> bitblt2;
    initialise(bitblt2, 0, std::string("01111100"));
}

int main()
{
    test_BitMask_Equality();
    test_BitMask_Inequality();
    test_BitMask_AND();
    test_BitMask_OR();
    test_BitMask_XOR();
    test_BitMask_Conditional();
    test_BitMask_BiConditional();
    test_BitMap_VS_BitMap2();

    return 0;
}
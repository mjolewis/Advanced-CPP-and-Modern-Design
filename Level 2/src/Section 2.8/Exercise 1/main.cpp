//
// Illustrate simple use cases of the bitset interface
//
// Created by Michael Lewis on 6/25/23.
//

#include <iostream>
#include <bitset>
#include <type_traits>

#include "boost/dynamic_bitset.hpp"

// create a bitset from an unsigned long
void test_UnsignedLongBitSet()
{
    std::bitset<4> b1{0b0100UL};
    assert(4 == b1);
}

// Create a bitset from an unsigned long long
void test_UnsignedLongLongBitSet()
{
    std::bitset<4> b1{0b0100ULL};
    assert(4 == b1);
}

// Create a bitset from a string
void test_StringBitSet()
{
    std::bitset<4> b1{"0100"};
    assert(4 == b1);
}

// Create a bitset from a string using only part of the string as specified by the index and number of bits
void test_PartOfStringBitSet()
{
    int index = 7;
    int numBits = 3;
    std::bitset<10> b1(std::string{"1111111100"}, index, numBits);
    assert(4 == b1);
}

// Use exception handling to check for out-of-range values and invalid arguments (bits that are neither 0 nor 1).
void test_InvalidBitset()
{
    try
    {
        // Generate an out of range exception by setting the start index greater than string size
        std::bitset<4> b1(std::string{"1111"}, 6, 8);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Generate an invalid argument exception by creating a bitset with values other than 0 or 1
        std::bitset<4> b1{"7456"};
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

// Set all bits to true
void test_SetBits()
{
    std::bitset<4> b1;
    b1.set();
    assert(15 == b1);
}

// Reset all bits to false
void test_ResetBits()
{
    std::bitset<4> b1{0b1111};
    b1.reset();
    assert(0 == b1);
}

// Inverts true bits to false bits and false bits to true bits
void test_FlipBits()
{
    std::bitset<4> b1{0b1010};
    b1.flip();
    assert(5 == b1);
}

// Check if no bits are set
void test_NoBitsSet()
{
    std::bitset<4> b1{0b0000};
    assert(true == b1.none());

    std::bitset<4> b2{0b1000};
    assert(false == b2.none());
}

// Check if all bits are set
void test_AllBitsSet()
{
    std::bitset<4> b1{0b1111};
    assert(true == b1.all());

    std::bitset<4> b2{0b1000};
    assert(false == b2.all());
}

// Check if any of the bits are set
void test_AnyBitsSet()
{
    std::bitset<4> b1{0b1111};
    assert(true == b1.any());

    std::bitset<4> b2{0b1000};
    assert(true == b2.any());

    std::bitset<4> b3{0b0000};
    assert(false == b3.any());
}

// Access bits by their index within the bitset
void test_AccessBits()
{
    std::bitset<4> b1{0b1010};
    assert(0 == b1[0]);
    assert(1 == b1[1]);
    assert(0 == b1[2]);
    assert(1 == b1[3]);
}

// Count the number of bits that are set
void test_CountSetBits()
{
    std::bitset<4> b1{0b1010};
    assert(2 == b1.count());
}

// Convert a bitset to a string
void test_ConvertBitsetToString()
{
    std::bitset<4> b1{0b1000};
    static_assert(std::is_same<std::string, decltype(b1.to_string())>::value == true);
}

// Convert a bitset to an unsigned long
void test_ConvertBitsetToUnsignedLong()
{
    std::bitset<4> b1{"1000"};
    static_assert(std::is_same<unsigned long, decltype(b1.to_ulong())>::value == true);
}

// Convert a bitset to an unsigned long long
void test_ConvertBitsetToUnsignedLongLong()
{
    std::bitset<4> b1{"1000"};
    static_assert(std::is_same<unsigned long long, decltype(b1.to_ullong())>::value == true);
}

// Compare equal bitsets
void test_BitsetsEqual()
{
    std::bitset<4> b1{0b1000};
    std::bitset<4> b2{0b1000};
    assert(true == (b1 == b2));
}

// Compare unequal bitsets
void test_BitsetsUnEqual()
{
    std::bitset<4> b1{0b1000};
    std::bitset<4> b2{0b1001};
    assert(true == (b1 != b2));
}

int main()
{
    test_UnsignedLongBitSet();
    test_UnsignedLongLongBitSet();
    test_StringBitSet();
    test_PartOfStringBitSet();
    test_InvalidBitset();
    test_SetBits();
    test_ResetBits();
    test_FlipBits();
    test_NoBitsSet();
    test_AllBitsSet();
    test_AnyBitsSet();
    test_AccessBits();
    test_CountSetBits();
    test_ConvertBitsetToString();
    test_ConvertBitsetToUnsignedLong();
    test_ConvertBitsetToUnsignedLongLong();
    test_BitsetsEqual();
    test_BitsetsUnEqual();
    return 0;
}
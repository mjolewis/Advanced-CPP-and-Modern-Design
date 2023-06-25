//
// Illustrate simple use cases of a boost dynamic bitset.
// Note: The dynamic nature of the boost bitsets means that they can be modified at runtime.
// This behavior is different from that of the STL bitset, which is a compile-time mechanism
//
// Created by Michael Lewis on 6/25/23.
//

#include <iostream>

#include <boost/dynamic_bitset.hpp>

// create a bitset from an unsigned long
void test_UnsignedLongBitSet()
{
    boost::dynamic_bitset<> b1{3, 4ul};
    assert(4 == b1.to_ulong());
}

// Create a bitset from an unsigned long long
void test_UnsignedLongLongBitSet()
{
    boost::dynamic_bitset<> b1{3, 4ul};
    assert(4 == b1.to_ulong());
}

// Create a bitset from a string
void test_StringBitSet()
{
    boost::dynamic_bitset<> b1{std::string{"0100"}};
    assert(4 == b1.to_ulong());
}

// Create a bitset from a string using only part of the string as specified by the index and number of bits
void test_PartOfStringBitSet()
{
    int index = 7;
    int numBits = 3;
    boost::dynamic_bitset<> b1(std::string{"1111111100"}, index, numBits);
    assert(4 == b1.to_ulong());
}

// Use exception handling to check for out-of-range values and invalid arguments (bits that are neither 0 nor 1).
void test_InvalidBitset()
{
    try
    {
        // Unlike std::bitset, boost::dynamic_bitset does not throw an exception for an out of range.
        // This is because boost uses a static assert to check that pos <= s.size(). And, if this
        // assertion fails, the program terminates.
        // Assertion failed: (pos <= s.size()), function init_from_string, file /usr/local/include/boost/dynamic_bitset/dynamic_bitset.hpp, line 439.

        // boost::dynamic_bitset<> b1(std::string{"1111"}, 6, 8);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Unlike std::bitset, boost::dynamic_bitset does not throw an exception for invalid arguments
        // This is because boost uses a static assert to check the arguments. And, if this
        // assertion fails, the program terminates.
        // Assertion failed: (Tr::eq(c, one) || Tr::eq(c, BOOST_DYNAMIC_BITSET_WIDEN_CHAR(fac, '0'))), function init_from_string, file /usr/local/include/boost/dynamic_bitset/dynamic_bitset.hpp,

        // boost::dynamic_bitset<> b1{std::string{"7456"}};
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

// Set all bits to true
void test_SetBits()
{
    boost::dynamic_bitset<> b1{4};
    b1.set();
    assert(15 == b1.to_ulong());
}

// Reset all bits to false
void test_ResetBits()
{
    boost::dynamic_bitset<>b1{4, 15ul};
    b1.reset();
    assert(0 == b1.to_ulong());
}

// Inverts true bits to false bits and false bits to true bits
void test_FlipBits()
{
    boost::dynamic_bitset<> b1{4, 10ul};
    b1.flip();
    assert(5 == b1.to_ulong());
}

// Check if no bits are set
void test_NoBitsSet()
{
    boost::dynamic_bitset<> b1{4};
    assert(true == b1.none());

    boost::dynamic_bitset<> b2{4, 8ul};
    assert(false == b2.none());
}

// Check if all bits are set
void test_AllBitsSet()
{
    boost::dynamic_bitset<> b1{4, 15ul};
    assert(true == b1.all());

    boost::dynamic_bitset<> b2{4, 8ul};
    assert(false == b2.all());
}

// Check if any of the bits are set
void test_AnyBitsSet()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    assert(true == b1.any());

    boost::dynamic_bitset<> b2{4, 15ul};
    assert(true == b2.any());

    boost::dynamic_bitset<> b3{1, 0ul};
    assert(false == b3.any());
}

// Access bits by their index within the bitset
void test_AccessBits()
{
    boost::dynamic_bitset<> b1{4, 10ul};
    assert(0 == b1[0]);
    assert(1 == b1[1]);
    assert(0 == b1[2]);
    assert(1 == b1[3]);
}

// Count the number of bits that are set
void test_CountSetBits()
{
    boost::dynamic_bitset<> b1{4, 10ul};
    assert(2 == b1.count());
}

// Convert a bitset to a string
void test_ConvertBitsetToString()
{
    boost::dynamic_bitset<> b1{0b1000};
    std::string s;
    to_string(b1, s);
    static_assert(std::is_same<std::string, decltype(s)>::value == true);
}

// Convert a bitset to an unsigned long
void test_ConvertBitsetToUnsignedLong()
{
    boost::dynamic_bitset<> b1{std::string{"1000"}};
    static_assert(std::is_same<unsigned long, decltype(b1.to_ulong())>::value == true);
}

// Convert a bitset to an unsigned long long
// Unlike std::bitset, boost::dynamic_bitset does not support converting a bitset to an unsigned long long
void test_ConvertBitsetToUnsignedLongLong()
{
//    boost::dynamic_bitset<> b1{std::string{"1000"}};
//    static_assert(std::is_same<unsigned long long, decltype(b1.to_ulong())>::value == true);
}

// Compare equal bitsets
void test_BitsetsEqual()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    boost::dynamic_bitset<> b2{4, 8ul};
    assert(true == (b1 == b2));
}

// Compare unequal bitsets
void test_BitsetsUnEqual()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    boost::dynamic_bitset<> b2{4, 9ul};
    assert(true == (b1 != b2));
}

// Change the size of a bitset at run-time
void test_Resize()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    assert(4 == b1.size());
    b1.resize(5);
    assert(5 == b1.size());
}

// Clears the bitset so that the size becomes zero
void test_Clear()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    b1.clear();
    assert(true == b1.empty());
}

// Increases the size of the bitset by one, and sets the value of the new most-significant bit to value.
void test_PushBack()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    b1.push_back(true);
    assert(24 == b1.to_ulong());

    boost::dynamic_bitset<> b2{4, 8ul};
    b1.push_back(false);
    assert(8 == b2.to_ulong());
}

// Decreases the size of the bitset by one by removing the most significant bit
void test_PopBack()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    b1.pop_back();
    assert(0 == b1.to_ulong());

    boost::dynamic_bitset<> b2{4, 9ul};
    b2.pop_back();
    assert(1 == b2.to_ulong());
}

// Appends new bits to the bitset from the most significant end
void test_Append()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    b1.append(11); // decimal 11 is equivalent to 1011 in binary, so expected bitset = 10111000 or 184
    assert(184 == b1.to_ulong());
}

// Test is bitset B is a subset of bitset A. Note that the size of the bitsets must be equal
void test_Subset()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    boost::dynamic_bitset<> b2{4, 8ul};
    assert(true == b2.is_subset_of(b1));
}

// Test is bitset B is a proper subset of bitset A. Note that the size of the bitsets must be equal.
// A proper subset occurs when bitset B is a subset of bitset A but not equal to bitset A.
void test_ProperSubset()
{
    boost::dynamic_bitset<> b1{4, 15ul};
    boost::dynamic_bitset<> b2{4, 8ul};
    assert(true == b2.is_proper_subset_of(b1));

    boost::dynamic_bitset<> b3{4, 8ul};
    boost::dynamic_bitset<> b4{4, 8ul};
    assert(false == b3.is_proper_subset_of(b4));
}

// Find the index of the first bit that is set in this bitset
void test_FindFirst()
{
    boost::dynamic_bitset<> b1{4, 8ul};
    assert(3 == b1.find_first());

    boost::dynamic_bitset<> b2{4, 9ul};
    assert(0 == b2.find_first());
}

// Find the lowest index that is set after the specified position in the bitset.
// Returns the number of positions if there is no next bit set
void test_FindNext()
{
    boost::dynamic_bitset<> b1{4, 10ul};
    assert(3 == b1.find_next(1));

    boost::dynamic_bitset<> b2{4, 1ul};
    assert(3 == b1.find_next(1));
}

int main()
{
    // Part A Tests
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

    // Part B Tests
    test_Resize();
    test_Clear();
    test_PushBack();
    test_PopBack();
    test_Append();

    // Part C Tests
    test_Subset();
    test_ProperSubset();
    test_FindFirst();
    test_FindNext();
}
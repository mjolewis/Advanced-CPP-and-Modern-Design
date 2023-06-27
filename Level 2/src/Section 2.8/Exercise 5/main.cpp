//
// Created by Michael Lewis on 6/25/23.
//

#include <array>

#include "BitMatrix.hpp"

void test_ValueConstructor()
{
    BitMatrix<4, 4> m1{9};
    assert(9 == m1[0].to_ulong());
    assert(9 == m1[1].to_ulong());
    assert(9 == m1[2].to_ulong());
    assert(9 == m1[3].to_ulong());
    assert(4 == m1.getBitMatrix().size());

    BitMatrix<4, 4> m2{8};
    assert(8 == m2[0].to_ulong());
    assert(8 == m2[1].to_ulong());
    assert(8 == m2[2].to_ulong());
    assert(8 == m2[3].to_ulong());
    assert(4 == m2.getBitMatrix().size());

    BitMatrix<5, 6> m3{16};
    assert(16 == m3[0].to_ulong());
    assert(16 == m3[1].to_ulong());
    assert(16 == m3[2].to_ulong());
    assert(16 == m3[3].to_ulong());
    assert(6 == m3.getBitMatrix().size());

    BitMatrix<5, 6> m4{24};
    assert(24 == m4[0].to_ulong());
    assert(24 == m4[1].to_ulong());
    assert(24 == m4[2].to_ulong());
    assert(24 == m4[3].to_ulong());
    assert(6 == m4.getBitMatrix().size());
}

void test_CopyCtor()
{
    BitMatrix<4, 4> m1Source{9};
    BitMatrix<4, 4> m1Copy{m1Source};
    assert(9 == m1Copy[0].to_ulong());
    assert(9 == m1Copy[1].to_ulong());
    assert(9 == m1Copy[2].to_ulong());
    assert(9 == m1Copy[3].to_ulong());
    assert(4 == m1Copy.getBitMatrix().size());

    BitMatrix<4, 4> m2Source{8};
    BitMatrix<4, 4> m2Copy{m2Source};
    assert(8 == m2Copy[0].to_ulong());
    assert(8 == m2Copy[1].to_ulong());
    assert(8 == m2Copy[2].to_ulong());
    assert(8 == m2Copy[3].to_ulong());
    assert(4 == m2Copy.getBitMatrix().size());

    BitMatrix<5, 6> m3Source{16};
    BitMatrix<5, 6> m3Copy{m3Source};
    assert(16 == m3Copy[0].to_ulong());
    assert(16 == m3Copy[1].to_ulong());
    assert(16 == m3Copy[2].to_ulong());
    assert(16 == m3Copy[3].to_ulong());
    assert(6 == m3Copy.getBitMatrix().size());

    BitMatrix<5, 6> m4Source{24};
    BitMatrix<5, 6> m4Copy{m4Source};
    assert(24 == m4Source[0].to_ulong());
    assert(24 == m4Source[1].to_ulong());
    assert(24 == m4Source[2].to_ulong());
    assert(24 == m4Source[3].to_ulong());
    assert(6 == m4Source.getBitMatrix().size());
}

void test_MoveConstructor()
{
    BitMatrix<4, 4> m1{BitMatrix<4, 4>{9}};
    assert(9 == m1[0].to_ulong());
    assert(9 == m1[1].to_ulong());
    assert(9 == m1[2].to_ulong());
    assert(9 == m1[3].to_ulong());
    assert(4 == m1.getBitMatrix().size());

    BitMatrix<4, 4> m2{BitMatrix<4, 4>{8}};
    assert(8 == m2[0].to_ulong());
    assert(8 == m2[1].to_ulong());
    assert(8 == m2[2].to_ulong());
    assert(8 == m2[3].to_ulong());
    assert(4 == m2.getBitMatrix().size());

    BitMatrix<5, 6> m3{BitMatrix<5, 6>{16}};
    assert(16 == m3[0].to_ulong());
    assert(16 == m3[1].to_ulong());
    assert(16 == m3[2].to_ulong());
    assert(16 == m3[3].to_ulong());
    assert(6 == m3.getBitMatrix().size());

    BitMatrix<5, 6> m4{BitMatrix<5, 6>{24}};
    assert(24 == m4[0].to_ulong());
    assert(24 == m4[1].to_ulong());
    assert(24 == m4[2].to_ulong());
    assert(24 == m4[3].to_ulong());
    assert(6 == m4.getBitMatrix().size());
}

// Set all bits to true
void test_SetBits()
{
    BitMatrix<4, 3> m1{BitMatrix<4, 3>{}};
    m1.set();
    assert(15 == m1[0].to_ulong());
    assert(15 == m1[1].to_ulong());
    assert(15 == m1[2].to_ulong());

    m1.set(2, 2, false);
    assert(11 == m1[2].to_ulong());
}

// Reset all bits to false
void test_ResetBits()
{
    BitMatrix<4, 3> m1{BitMatrix<4, 3>{8}};
    m1.reset();
    assert(0 == m1[0].to_ulong());
    assert(0 == m1[1].to_ulong());
    assert(0 == m1[2].to_ulong());

    BitMatrix<4, 3> m2{BitMatrix<4, 3>{8}};
    m2.reset(3, 2);
    assert(0 == m2[2].to_ulong());
}

// Inverts true bits to false bits and false bits to true bits
void test_FlipBits()
{
    BitMatrix<4, 3> m1{BitMatrix<4, 3>{8}};
    m1.flip();
    assert(7 == m1[0].to_ulong());
    assert(7 == m1[1].to_ulong());
    assert(7 == m1[2].to_ulong());

    BitMatrix<4, 3> m2{BitMatrix<4, 3>{}};
    m2.flip(2, 2);
    assert(4 == m2[2].to_ulong());
}

// Check if no bits are set
void test_NoBitsSet()
{
    BitMatrix<4, 3> m1{BitMatrix<4, 3>{8}};
    assert(false == m1[0].none());
    assert(false == m1[1].none());
    assert(false == m1[2].none());

    BitMatrix<4, 3> m2{BitMatrix<4, 3>{0}};
    assert(true == m2[0].none());
    assert(true == m2[1].none());
    assert(true == m2[2].none());

    BitMatrix<4, 3> m3{BitMatrix<4, 3>{7}};
    assert(false == m3[0].none());
    assert(false == m3[1].none());
    assert(false == m3[2].none());
}

// Check if all bits are set
void test_AllBitsSet()
{
    BitMatrix<3, 3> m1{BitMatrix<3, 3>{7}};
    assert(true == m1[0].all());
    assert(true == m1[1].all());
    assert(true == m1[2].all());

    BitMatrix<4, 3> m2{BitMatrix<4, 3>{0}};
    assert(false == m2[0].all());
    assert(false == m2[1].all());
    assert(false == m2[2].all());

    BitMatrix<4, 3> m3{BitMatrix<4, 3>{8}};
    assert(false == m3[0].all());
    assert(false == m3[1].all());
    assert(false == m3[2].all());
}

// Check if any of the bits are set
void test_AnyBitsSet()
{
    BitMatrix<3, 3> m1{BitMatrix<3, 3>{7}};
    assert(true == m1[0].any());
    assert(true == m1[1].any());
    assert(true == m1[2].any());

    BitMatrix<4, 3> m2{BitMatrix<4, 3>{0}};
    assert(false == m2[0].any());
    assert(false == m2[1].any());
    assert(false == m2[2].any());

    BitMatrix<4, 3> m3{BitMatrix<4, 3>{8}};
    assert(true == m3[0].any());
    assert(true == m3[1].any());
    assert(true == m3[2].any());
}

// Count the number of bits set in each std::bitset within the BitMatrix
void test_CountBitsSet()
{
    BitMatrix<3, 3> m1{BitMatrix<3, 3>{7}};
    assert(3 == m1[0].count());
    assert(3 == m1[1].count());
    assert(3 == m1[2].count());

    BitMatrix<4, 3> m2{BitMatrix<4, 3>{0}};
    assert(0 == m2[0].count());
    assert(0 == m2[1].count());
    assert(0 == m2[2].count());

    BitMatrix<4, 3> m3{BitMatrix<4, 3>{8}};
    assert(1 == m3[0].count());
    assert(1 == m3[1].count());
    assert(1 == m3[2].count());
}

// Bitwise AND
void test_BitwiseAND()
{
    BitMatrix<4, 3> m1{BitMatrix<4, 3>{9}};
    BitMatrix<4, 3> m2{BitMatrix<4, 3>{7}};
    m1 &= m2;

    assert(1 == m1[0]);
    assert(1 == m1[1]);
    assert(1 == m1[2]);

    assert(7 == m2[0]);
    assert(7 == m2[1]);
    assert(7 == m2[2]);

}

// Bitwise OR
void test_BitwiseOR()
{
    BitMatrix<4, 3> m1{BitMatrix<4, 3>{9}};
    BitMatrix<4, 3> m2{BitMatrix<4, 3>{7}};
    m1 |= m2;

    assert(15 == m1[0]);
    assert(15 == m1[1]);
    assert(15 == m1[2]);

    assert(7 == m2[0]);
    assert(7 == m2[1]);
    assert(7 == m2[2]);
}

// Bitwise XOR
void test_BitwiseXOR()
{
    BitMatrix<4, 3> m1{BitMatrix<4, 3>{9}};
    BitMatrix<4, 3> m2{BitMatrix<4, 3>{7}};
    m1 ^= m2;
    assert(14 == m1[0]);
    assert(14 == m1[1]);
    assert(14 == m1[2]);

    assert(7 == m2[0]);
    assert(7 == m2[1]);
    assert(7 == m2[2]);
}

int main()
{
    test_ValueConstructor();
    test_CopyCtor();
    test_MoveConstructor();
    test_SetBits();
    test_ResetBits();
    test_FlipBits();
    test_NoBitsSet();
    test_AllBitsSet();
    test_AnyBitsSet();
    test_CountBitsSet();
    test_BitwiseAND();
    test_BitwiseOR();
    test_BitwiseXOR();

    std::cout << "*** ALL TESTS COMPLETE ***" << std::endl;

    return 0;
}
//
// A simple test program to test boolean and unary conditions on a std::bitset<1> adapter
//
// Created by Michael Lewis on 7/8/23.
//

#include <cassert>

#include "Proposition.hpp"

// Test equaility between two Propositions
void test_Equality()
{
    Proposition p1;
    Proposition p2;
    assert(p1.operator==(p2));

    Proposition p3(true);
    Proposition p4(true);
    assert(p3.operator==(p4));

    Proposition p5(true);
    Proposition p6(false);
    assert(false == p5.operator==(p6));

    Proposition p7(false);
    Proposition p8(false);
    assert(p7.operator==(p8));

    Proposition p9(false);
    Proposition p10(true);
    assert(false == p9.operator==(p10));
}

// Test inequality between two Propositions
void test_Inequality()
{
    Proposition p1;
    Proposition p2;
    assert(false == p1.operator!=(p2));

    Proposition p3(true);
    Proposition p4(true);
    assert(false == p3.operator!=(p4));

    Proposition p5(true);
    Proposition p6(false);
    assert(p5.operator!=(p6));

    Proposition p7(false);
    Proposition p8(false);
    assert(false == p7.operator!=(p8));

    Proposition p9(false);
    Proposition p10(true);
    assert(p9.operator!=(p10));
}

// Test binary AND. Note makes use of the conversion operator () when asserting
void test_AND()
{
    Proposition p1;
    Proposition p2;
    assert(false == p1.operator&(p2)());

    Proposition p3(true);
    Proposition p4(true);
    assert(p3.operator&(p4)());

    Proposition p5(true);
    Proposition p6(false);
    assert(false == p5.operator&(p6)());

    Proposition p7(false);
    Proposition p8(false);
    assert(false == p7.operator&(p8)());

    Proposition p9(false);
    Proposition p10(true);
    assert(false == p9.operator&(p10)());
}

// Test binary OR. Note makes use of the conversion operator () when asserting
void test_OR()
{
    Proposition p1;
    Proposition p2;
    assert(false == p1.operator|(p2)());

    Proposition p3(true);
    Proposition p4(true);
    assert(p3.operator|(p4)());

    Proposition p5(true);
    Proposition p6(false);
    assert(p5.operator|(p6)());

    Proposition p7(false);
    Proposition p8(false);
    assert(false == p7.operator|(p8)());

    Proposition p9(false);
    Proposition p10(true);
    assert(p9.operator|(p10)());
}

// Test binary XOR. Note makes use of the conversion operator () when asserting
void test_XOR()
{
    Proposition p1;
    Proposition p2;
    assert(false == p1.operator^(p2)());

    Proposition p3(true);
    Proposition p4(true);
    assert(false == p3.operator^(p4)());

    Proposition p5(true);
    Proposition p6(false);
    assert(p5.operator^(p6)());

    Proposition p7(false);
    Proposition p8(false);
    assert(false == p7.operator^(p8)());

    Proposition p9(false);
    Proposition p10(true);
    assert(p9.operator^(p10)());
}

// Test conditional operator. Note makes use of the conversion operator () when asserting
void test_Conditional()
{
    Proposition p1;
    Proposition p2;
    assert((p1 % p2)());

    Proposition p3(true);
    Proposition p4(true);
    assert((p3 % p4)());

    Proposition p5(true);
    Proposition p6(false);
    assert(false == (p5 % p6)());

    Proposition p7(false);
    Proposition p8(false);
    assert((p7 % p8)());

    Proposition p9(false);
    Proposition p10(true);
    assert((p9 % p10)());
}

// Test bi-conditional operator. Note makes use of the conversion operator () when asserting
void test_BiConditional()
{
    Proposition p1;
    Proposition p2;
    assert((p1 <=> p2)());

    Proposition p3(true);
    Proposition p4(true);
    assert((p3 <=> p4)());

    Proposition p5(true);
    Proposition p6(false);
    assert(false == (p5 <=> p6)());

    Proposition p7(false);
    Proposition p8(false);
    assert((p7 <=> p8)());

    Proposition p9(false);
    Proposition p10(true);
    assert(false == (p9 <=> p10)());
}

// Test conversion operator. This operator converts a Proposition into a boolean.
void test_Conversion()
{
    Proposition p1;
    bool c1 = p1();
    assert(false == c1);

    Proposition p2{true};
    bool c2 = p2();
    assert(true == c2);
}

// DeMorgan's law satisfies the following conditions
// NOT (A OR B) == NOT(A) AND NOT(B)
// NOT (A AND B) == NOT(A) OR NOT(B)
void test_DeMorgansLaw()
{
    // NOT (A OR B) == NOT(A) AND NOT(B)
    Proposition p1(false);
    Proposition p2(false);
    assert(!(p1 | p2) == (!p1 & !p2));

    Proposition p3(true);
    Proposition p4(false);
    assert(!(p3 | p4) == (!p3 & !p4));

    Proposition p5(false);
    Proposition p6(true);
    assert(!(p5 | p6) == (!p5 & !p6));

    Proposition p7(true);
    Proposition p8(true);
    assert(!(p7 | p8) == (!p7 & !p8));

    // NOT (A AND B) == NOT(A) OR NOT(B)
    Proposition p9(false);
    Proposition p10(false);
    assert(!(p9 & p10) == (!p9 | !p10));

    Proposition p11(true);
    Proposition p12(false);
    assert(!(p11 & p12) == (!p11 | !p12));

    Proposition p13(false);
    Proposition p14(true);
    assert(!(p13 & p14) == (!p13 | !p14));

    Proposition p15(true);
    Proposition p16(true);
    assert(!(p15 & p16) == (!p15 | !p16));
}

// // Distributive law satisfies the following conditions
// A AND(B OR C) == (A AND B) OR (A OR C)
// A OR(B AND C) == (A OR B) AND (A OR C)
void test_DistributiveLaw()
{
    // A AND(B OR C) == (A AND B) OR (A OR C)
    Proposition p1(false);
    Proposition p2(false);
    Proposition p3(false);
    assert((p1 & (p2 | p3)) == ((p1 & p2) | (p1 & p3)));

    Proposition p4(true);
    Proposition p5(false);
    Proposition p6(false);
    assert((p4 & (p5 | p6)) == ((p4 & p5) | (p4 & p6)));

    Proposition p7(true);
    Proposition p8(true);
    Proposition p9(false);
    assert((p7 & (p8 | p9)) == ((p7 & p8) | (p7 & p9)));

    Proposition p10(true);
    Proposition p11(true);
    Proposition p12(true);
    assert((p10 & (p11 | p12)) == ((p10 & p11) | (p10 & p12)));

    // A OR(B AND C) == (A OR B) AND (A OR C)
    Proposition p13(false);
    Proposition p14(false);
    Proposition p15(false);
    assert((p13 | (p14 & p15)) == ((p13 | p14) & (p13 | p15)));

    Proposition p16(true);
    Proposition p17(false);
    Proposition p18(false);
    assert((p16 | (p17 & p18)) == ((p16 | p17) & (p16 | p18)));

    Proposition p19(true);
    Proposition p20(true);
    Proposition p21(false);
    assert((p19 | (p20 & p21)) == ((p19 | p20) & (p19 | p21)));

    Proposition p22(true);
    Proposition p23(true);
    Proposition p24(true);
    assert((p22 | (p23 & p24)) == ((p22 | p23) & (p22 | p24)));
}

// A tautology always returns true for all assignments of truth values to its statement letters A,B and C
// Truth table for 3 elements = 2^3 = 8
// [A -> (B -> C)] <-> [(A & B) -> C]
void test_Tautology()
{
    Proposition p1(true);
    Proposition p2(true);
    Proposition p3(true);
    assert(true == ((p1 % (p2 % p3)) <=> ((p1 & p2) % p3))());

    Proposition p4(true);
    Proposition p5(true);
    Proposition p6(false);
    assert(true == ((p4 % (p5 % p6)) <=> ((p4 & p5) % p6))());

    Proposition p7(true);
    Proposition p8(false);
    Proposition p9(true);
    assert(true == ((p7 % (p8 % p9)) <=> ((p7 & p8) % p9))());

    Proposition p10(true);
    Proposition p11(false);
    Proposition p12(false);
    assert(true == ((p10 % (p11 % p12)) <=> ((p10 & p11) % p12))());

    Proposition p13(false);
    Proposition p14(true);
    Proposition p15(true);
    assert(true == ((p13 % (p14 % p15)) <=> ((p13 & p14) % p15))());

    Proposition p16(false);
    Proposition p17(true);
    Proposition p18(false);
    assert(true == ((p16 % (p17 % p18)) <=> ((p16 & p17) % p18))());

    Proposition p19(false);
    Proposition p20(false);
    Proposition p21(true);
    assert(true == ((p19 % (p20 % p21)) <=> ((p19 & p20) % p21))());

    Proposition p22(false);
    Proposition p23(false);
    Proposition p24(false);
    assert(true == ((p22 % (p23 % p24)) <=> ((p22 & p23) % p24))());
}

int main()
{
    test_Equality();
    test_Inequality();
    test_AND();
    test_OR();
    test_XOR();
    test_Conditional();
    test_BiConditional();
    test_Conversion();
    test_DeMorgansLaw();
    test_DistributiveLaw();
    test_Tautology();

    return 0;
}
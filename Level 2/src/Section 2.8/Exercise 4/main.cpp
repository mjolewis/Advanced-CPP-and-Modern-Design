//
// std::vector<bool> acts as a space efficient dynamic bitset in the STL library.
// Although this data structure exists, programmers should favor std::bitset and boost::dynamic_bitset.
//
// Here, we will illustrate common functionality between std::vector<bool>, std::bitset,
// and boost::dynamic_bitset interfaces
//
// Created by Michael Lewis on 6/25/23.
//

#include <iostream>
#include <vector>

// Bitwise AND
void test_BitwiseAND()
{
    std::vector<bool> b1{true, false, true};
    std::vector<bool> b2{true, false, false};
    for (int i = 0; i < b1.size(); ++i)
    {
        std::cout << (b1.at(i) & b2.at(i));
    }

    std::cout << "\n";
}

// Bitwise OR
void test_BitwiseOR()
{
    std::vector<bool> b1{true, false, true};
    std::vector<bool> b2{true, false, false};
    for (int i = 0; i < b1.size(); ++i)
    {
        std::cout << (b1.at(i) | b2.at(i));
    }

    std::cout << "\n";
}

// Bitwise OR
void test_BitwiseXOR()
{
    std::vector<bool> b1{true, false, true};
    std::vector<bool> b2{true, false, false};
    for (int i = 0; i < b1.size(); ++i)
    {
        std::cout << (b1.at(i) ^ b2.at(i));
    }

    std::cout << "\n";
}

// Toggle all the bits of std::vector<bool>
void test_Flip()
{
    std::vector<bool> b1{true, false, true};

    b1.flip();
    assert(b1.at(0) == false);
    assert(b1.at(1) == true);
    assert(b1.at(2) == false);
}

// Add elements to the end of the std::vector<bool>
void test_PushBack()
{
    std::vector<bool> b1{true, false, true};
    b1.push_back(true);

    assert(b1.at(0) == true);
    assert(b1.at(1) == false);
    assert(b1.at(2) == true);
    assert(b1.at(3) == true);
    assert(4 == b1.size());
}

// Remove the last element of the std::vector<bool>
void test_PopBack()
{
    std::vector<bool> b1{true, false, true};
    b1.pop_back();

    assert(b1.at(0) == true);
    assert(b1.at(1) == false);
    assert(2 == b1.size());
}

// Clear the contents of the std::vector<bool>
void test_Clear()
{
    std::vector<bool> b1{true, false, true};
    b1.clear();

    assert(b1.empty());
}

// Change the number of elements stored in the std::vector<bool>
void test_Resize()
{
    std::vector<bool> b1{true, false, true};
    b1.resize(4);
    assert(4 == b1.size());
    assert(b1.at(0) == true);
    assert(b1.at(1) == false);
    assert(b1.at(2) == true);
    assert(b1.at(3) == false);
}

// Intersection are the indices that have a common value between both vectors
void test_Intersection()
{
    std::vector<bool> b1{true, true, false};
    std::vector<bool> b2{false, true, false};

    for (int i = 0; i < b1.size(); ++i)
    {
        bool bit = b1.at(i) == b2.at(i);
        std::cout << bit;
    }
}

int main()
{
    // Part B
    test_BitwiseAND();
    test_BitwiseOR();
    test_BitwiseXOR();
    test_Flip();
    test_PushBack();
    test_PopBack();
    test_Clear();
    test_Resize();

    // Part B
    test_Intersection();
}
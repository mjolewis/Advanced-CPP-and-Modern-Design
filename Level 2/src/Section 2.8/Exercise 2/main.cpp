//
// Created by Michael Lewis on 6/25/23.
//

#include <bitset>
#include <functional>
#include <iostream>

int main()
{
    std::bitset<4> bs1{0b1110};
    std::bitset<4> bs2{0b1010};

    // Toggle all the bits of bs1 and bs2
    bs1.flip();
    bs2.flip();

    // Bitwise XOR
    std::cout << "(bs1 ^ bs2)=" << (bs1 ^ bs2) << std::endl;

    // Bitwise OR
    std::cout << "(bs1 | bs2)=" << (bs1 | bs2) << std::endl;

    // Bitwise AND
    std::cout << "(bs1 & bs2)" << (bs1 & bs2) << std::endl;

    // Left shift one bit
    std::cout << "(bs1 << 1)=" << (bs1 << 1) << std::endl;
    std::cout << "(bs2 << 1)=" << (bs2 << 1) << std::endl;

    // Right shift one bit
    std::cout << "(bs1 >> 1)=" << (bs1 >> 1) << std::endl;
    std::cout << "(bs2 >> 1)=" << (bs2 >> 1) << std::endl;

    // Hash the bitsets
    std::hash<std::bitset<4>> hash1;
    std::hash<std::bitset<4>> hash2;
    std::cout << "std::hash<bs1>=" << hash1(bs1) << std::endl;
    std::cout << "std::hash<bs1>=" << hash1(bs2) << std::endl;

    // Create a bitset from a binary literal. Convert it into a
    auto blit = 0b1000;
    std::bitset<4> bs3(blit);
    std::cout << bs3 << std::endl;
    std::cout << bs3.to_ulong() << std::endl;

    // Create a byte from a binary literal
    std::byte byte1{0b1001};
    std::cout << std::to_integer<int>(byte1) << std::endl;

    // Create from a byte from an integer
    std::byte byte2{8};
    std::cout << std::to_integer<int>(byte2) << std::endl;

    // Create a byte from binary logical operators on existing bytes.
    std::cout << "(byte1 |= byte2)=" << std::to_integer<int>(byte1 |= byte2) << std::endl;
    std::cout << "(byte1 &= byte2)="  << std::to_integer<int>(byte1 &= byte2) << std::endl;
    std::cout << "(byte1 ^= byte2)="  << std::to_integer<int>(byte1 ^= byte2) << std::endl;

    // Perform bitwise AND on a byte
    std::cout << "(byte1 & byte2)="  << std::to_integer<int>(byte1 & byte2) << std::endl;

    // Perform bitwise OR on a byte
    std::cout << "(byte1 | byte2)="  << std::to_integer<int>(byte1 | byte2) << std::endl;

    // Perform left shift on a byte
    std::byte byte3{0b1000};
    std::cout << "(byte3 << 1)="  << std::to_integer<int>(byte3 << 1) << std::endl;
    std::cout << "(byte3 << 2)="  << std::to_integer<int>(byte3 << 2) << std::endl;
    std::cout << "(byte3 << 3)="  << std::to_integer<int>(byte3 << 3) << std::endl;
    std::cout << "(byte3 << -1)="  << std::to_integer<int>(byte3 << -1) << std::endl;
    std::cout << "(byte3 << 1000)="  << std::to_integer<int>(byte3 << 1000) << std::endl;

    // Perform right shift on a byte
    std::byte byte4{0b1000};
    std::cout << "(byte4 >> 1)="  << std::to_integer<int>(byte4 >> 1) << std::endl;
    std::cout << "(byte4 >> 2)="  << std::to_integer<int>(byte4 >> 2) << std::endl;
    std::cout << "(byte4 >> 3)="  << std::to_integer<int>(byte4 >> 3) << std::endl;
    std::cout << "(byte4 >> -1)="  << std::to_integer<int>(byte4 >> -1) << std::endl;
    std::cout << "(byte4 >> 1000)="  << std::to_integer<int>(byte4 >> 1000) << std::endl;

    // Can you think of examples/applications where bytes and bitsets can be used,
    // for example raw memory access and savings and performance improvements?
    // Response:
    // I think bytes and bitsets can be very useful when working with real time market data.
    // Messages from exchanges can be binary encoded and use bit masking to provide information
    // regarding what type of message is being sent. For example, is the message an quote
    // from an open auction, close auction, or continuous trading. This is a common
    // pattern that I've seen when dealing with financial market data. As a developer,
    // I often have to decode these messages by unpacking the bits within the message.

    return 0;
}

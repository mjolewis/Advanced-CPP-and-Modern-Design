//
// Adapter Classes for Bitsets to implement boolean algebra.
//
// Created by Michael Lewis on 7/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PROPOSITION_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PROPOSITION_HPP

#include <bitset>
#include <ostream>

class Proposition
{
private:
    std::bitset<1> data;

public:
    Proposition() = default;
    Proposition(bool value);  // Conversion ctor https://en.cppreference.com/w/cpp/language/converting_constructor
    explicit Proposition(const std::bitset<1>& bitset);

    // Operator overloads
    bool operator()() const noexcept;
    bool operator==(const Proposition& other) const noexcept;
    bool operator!=(const Proposition& other) const noexcept;
    Proposition operator&(const Proposition& other) const noexcept;
    Proposition operator|(const Proposition& other) const noexcept;
    Proposition operator^(const Proposition& other) const noexcept;
    Proposition operator!() const noexcept;

    // Friends
    friend Proposition operator%(const Proposition& lhs, const Proposition& rhs)  noexcept;
    friend Proposition operator<=>(const Proposition& lhs, const Proposition& rhs)  noexcept;
    friend std::ostream& operator<<(std::ostream& out, const Proposition& proposition);
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_PROPOSITION_HPP

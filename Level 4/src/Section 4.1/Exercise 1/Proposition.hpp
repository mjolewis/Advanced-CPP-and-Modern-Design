//
// Created by Michael Lewis on 7/8/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PROPOSITION_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PROPOSITION_HPP

#include <bitset>

class Proposition
{
private:
    std::bitset<1> data;

public:
    Proposition() = default;
    explicit Proposition(bool value);
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
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_PROPOSITION_HPP

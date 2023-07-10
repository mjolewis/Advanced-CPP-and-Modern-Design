//
// Created by Michael Lewis on 7/8/23.
//

#include "Proposition.hpp"

/**
 * Overloaded ctor
 * @param value A true or false value to be stored in the std::bitset<1>
 */
Proposition::Proposition(bool value) : data{value}
{

}

/**
 * Overloaded ctor
 * @param bitset Another bitset<1> to store in this Proposition
 */
Proposition::Proposition(const std::bitset<1>& bitset)
{
    data = bitset;
}

/**
 * Conversion operator
 * @return The bool representation of this Proposition
 */
bool Proposition::operator()() const noexcept
{
    return data[0];
}

/**
 * Equality comparison between two Propositions
 * @param other The Proposition used as the rhs in the comparison
 * @return True if the two Propositions are equal; false otherwise.
 */
bool Proposition::operator==(const Proposition& other) const noexcept
{
    return data == other.data;
}

/**
 * Inequality comparison between two Propositions
 * @param other The Proposition used as the rhs in the comparison
 * @return True if the two Propositions are not equal; false otherwise.
 */
bool Proposition::operator!=(const Proposition& other) const noexcept
{
    return data != other.data;
}

/**
 * Binary AND comparison between two Propositions
 * @param other The Proposition used as the rhs in the comparison
 * @return A new Proposition containing the result of binary AND operation
 */
Proposition Proposition::operator&(const Proposition& other) const noexcept
{
    return Proposition{data & other.data};
}

/**
 * Binary OR comparison between two Propositions
 * @param other The Proposition used as the rhs in the comparison
 * @return A new Proposition containing the result of binary OR operation
 */
Proposition Proposition::operator|(const Proposition& other) const noexcept
{
    return Proposition{data | other.data};
}

/**
 * Binary XOR comparison between two Propositions
 * @param other The Proposition used as the rhs in the comparison
 * @return A new Proposition containing the result of binary XOR operation
 */
Proposition Proposition::operator^(const Proposition& other) const noexcept
{
    return Proposition{data ^ other.data};
}

/**
 * Unary negation of this Proposition
 * @return A new Proposition containing the result of unary negation of this Proposition
 */
Proposition Proposition::operator!() const noexcept
{
    Proposition negate = Proposition{data};
    negate.data.flip();
    return negate;
}

// ********** Friend function definitions **********

/**
 * Conditional comparison between two Propositions (e.g. "lhs implies rhs" or "if lhs, then rhs")
 * @param lhs The Proposition used as the lhs in the comparison
 * @param rhs The Proposition used as the rhs in the comparison
 * @return A new Proposition containing the result of the conditional operation
 */
Proposition operator%(const Proposition& lhs, const Proposition& rhs) noexcept
{
    if ((lhs.data == true) && (rhs.data == false)) return Proposition{false};
    return Proposition{true};
}

/**
 * Bi-Conditional comparison between two Propositions (e.g. "lhs iff rhs”)
 * @param lhs The Proposition used as the lhs in the comparison
 * @param rhs The Proposition used as the rhs in the comparison
 * @return A new Proposition containing the result of the conditional operation
 */
Proposition operator<=>(const Proposition& lhs, const Proposition& rhs) noexcept
{
    if (lhs.data != rhs.data) return Proposition{false};
    return Proposition{true};
}


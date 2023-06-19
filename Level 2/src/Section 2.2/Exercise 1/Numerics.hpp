//
// Created by Michael Lewis on 6/19/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NUMERICS_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_NUMERICS_HPP

#include <type_traits>

/**
 * A simple mathematical library to model vector spaces
 */
class Numerics
{
private:
    // Marked impl functions as private to simplify the interface exposed to clients
    template<typename T>
    static T AdditionImpl(const T& t1, const T& t2, std::true_type);

    template<typename T>
    static T AdditionImpl(const T& t1, const T& t2, std::false_type);

    template<typename T>
    static void AdditiveInverseImpl(T& t1, std::true_type);

    template<typename T>
    static void AdditiveInverseImpl(T& t1, std::false_type);

    template<typename T>
    static T MultiplicationImpl(const T& t1, const T& t2, std::true_type);

    template<typename T>
    static T MultiplicationImpl(const T& t1, const T& t2, std::false_type);

public:
    template<typename T>
    static T Addition(const T& t1, const T& t2);

    template<typename T>
    static void AdditiveInverse(T& t1);

    template<typename T>
    static T Multiplication(const T& t1, const T& t2);
};

// ** Start Template Declarations **
#ifndef NUMERICS_CPP
#include "Numerics.cpp"
#endif // NUMERICS_CPP
// ** End Templates Declarations **

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_NUMERICS_HPP

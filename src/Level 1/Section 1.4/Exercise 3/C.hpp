//
// Created by Michael Lewis on 6/3/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP

/**
 * Instrucor provided class to illustrate function wrappers and bind
 */
class C
{
// Function object with extra member functions
private:
    double _data;
public:
    explicit C(double data) : _data(data) {}

    double operator () (double factor) const
    {
        return _data + factor;
    }

    double translate (double factor) const
    {
        return _data + factor;
    }

    double translate2 (double factor1, double factor2) const
    {
        return _data + factor1 + factor2;
    }

    static double Square(double x)
    {
        return x*x;
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_C_HPP

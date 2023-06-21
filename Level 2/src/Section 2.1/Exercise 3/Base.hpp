//
// Created by Michael Lewis on 6/19/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP

/**
 * Base class used to illustrate type properties and type relationships.
 *
 * In this case, the Base class has no relationships with any derived classes.
 */
class Base
{
private:
    int y;

public:
    constexpr Base() = default;
    void draw() {};
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_BASE_HPP

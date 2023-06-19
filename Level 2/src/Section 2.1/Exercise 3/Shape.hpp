//
// Created by Michael Lewis on 6/19/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP

/**
 * Non polymorphic concrete class used to illustrate type properties and type relationships.
 */
class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() = 0;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_SHAPE_HPP

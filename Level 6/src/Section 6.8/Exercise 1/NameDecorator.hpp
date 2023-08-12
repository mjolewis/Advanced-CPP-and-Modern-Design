//
// An concrete Decorator responsible for decorating Shape names
//
// Created by Michael Lewis on 8/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NAMEDECORATOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_NAMEDECORATOR_HPP

#include <memory>
#include <string>

#include "ShapeDecorator.hpp"
#include "Shape.hpp"

class NameDecorator : public ShapeDecorator
{
private:
    std::string name;

public:
    NameDecorator();
    NameDecorator(const std::shared_ptr<Shape>& shape, std::string name);
    NameDecorator(const NameDecorator& other) = default;
    NameDecorator(NameDecorator&& other) = default;
    ~NameDecorator() override = default;

    // Operator Overloads
    NameDecorator& operator=(const NameDecorator& other) = default;
    NameDecorator& operator=(NameDecorator&& other) = default;

    // Accessors and Mutators
    std::string getName() const;
    void setName(std::string _name);

    // Function Overrides
    void print() const override;
    std::shared_ptr<Shape> clone() const override;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_NAMEDECORATOR_HPP

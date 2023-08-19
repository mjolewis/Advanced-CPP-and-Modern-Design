//
// Modern C++ Factory Pattern, which uses universal function wrappers to provide
// flexibility when constructing objects as well as to help reduce boilerplate
// code. This approach allows us to have a single factory and defer to clients in
// terms of how objects should be constructing by allowing them to leverage any type
// of std::function, function object, or std::bind mechanism during construction.
//
// Note - This Factory is not copy or move constructable. Nor is it copy or move assignable. These
// capabilities will only be supported if there's an eventual need for them
//
// Created by Michael Lewis on 8/19/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NEWSHAPEFACTORY_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_NEWSHAPEFACTORY_HPP

#include <functional>
#include <memory>

#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

// Aliases
using CirclePtr = std::shared_ptr<Circle>;
using LinePtr = std::shared_ptr<Line>;
using PointPtr = std::shared_ptr<Point>;

using CircleFunction = std::function<CirclePtr ()>;
using LineFunction = std::function<LinePtr ()>;
using PointFunction = std::function<PointPtr ()>;

class NewShapeFactory
{
private:
    CircleFunction circleFunc;
    LineFunction lineFunc;
    PointFunction pointFunc;

public:
    NewShapeFactory();
    NewShapeFactory(CircleFunction&& _circleFunc, LineFunction&& _lineFunc, PointFunction&& _pointFunc);
    NewShapeFactory(const NewShapeFactory& other) = delete;
    NewShapeFactory(NewShapeFactory&& other) = delete;
    virtual ~NewShapeFactory() = default;

    // Operator Overloads
    NewShapeFactory& operator=(const NewShapeFactory& other) = delete;
    NewShapeFactory& operator=(NewShapeFactory&& other) = delete;

    void addCircleFunction(CircleFunction&& _circleFunc);
    void addLineFunction(LineFunction&& _lineFunc);
    void addPointFunction(PointFunction&& _pointFunc);

    // Factory Functions
    CirclePtr createCircle() const;
    LinePtr createLine() const;
    PointPtr createPoint() const;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_NEWSHAPEFACTORY_HPP

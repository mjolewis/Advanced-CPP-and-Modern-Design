//
// A Polyline is a continuous line composed of one or more connected straight line
// segments. As such, it can be viewed as a composite Shape.
//
// Note - This is a generic class so that any container can be provided by clients to
// store the composite shape. It's construction is also implemented using the
// Template Method Pattern, which delegates to Points.
//
// Created by Michael Lewis on 8/20/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POLYLINE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POLYLINE_HPP

#include <memory>

#include "ShapeComposite.hpp"

class Point;

template<typename T,
        template<typename S, typename Alloc> class Container,
        typename TAlloc = std::allocator<std::shared_ptr<Point>>>
class PolyLine : public ShapeComposite<Point, Container, TAlloc>
{
public:
    PolyLine();
    ~PolyLine() override = default;
};

// ********** Template Definitions **********
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POLYLINE_CPP
#include "PolyLine.cpp"
#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POLYLINE_CPP

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_POLYLINE_HPP

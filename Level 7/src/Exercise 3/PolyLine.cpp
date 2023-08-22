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
#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_POLYLINE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_POLYLINE_CPP

#include "PolyLine.hpp"

/**
 * Default ctor
 * @tparam T The data type contained in this, which is specialized for a Line
 * @tparam Container A generic container so that clients can specify the type of container to use
 * @tparam TAlloc A generic allocator that must be suitable for the container provided by the client
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
PolyLine<T, Container, TAlloc>::PolyLine() : ShapeComposite<T, Container, TAlloc>{}
{

}

#endif

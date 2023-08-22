//
// Illustration of the Composite pattern, which allows clients to treat individual objects
// and compositions uniformly. It can be viewed as tree like structures that represents part-whole hierarchies.
//
// Created by Michael Lewis on 8/7/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_CPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_SHAPECOMPOSITE_CPP

#include <memory>

#include "ShapeComposite.hpp"

/**
 * Default ctor
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
ShapeComposite<T, Container, TAlloc>::ShapeComposite() : shapes{}
{

}

/**
 * Add a Shape leaf or composite into a list of other Shapes.
 * @param shape The Shape that will be added to the list.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
void ShapeComposite<T, Container, TAlloc>::addShape(const std::shared_ptr<T>& shape)
{
    shapes.push_back(shape);
}

/**
 * Returns an iterator to the first element of the list.
 * @return An iterator to the first element of the list.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
ShapeComposite<T, Container, TAlloc>::iterator ShapeComposite<T, Container, TAlloc>::begin() noexcept
{
    return shapes.begin();
}

/**
 * Returns an iterator to the element following the last element of the list.
 * @return Iterator to the element following the last element.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
ShapeComposite<T, Container, TAlloc>::iterator ShapeComposite<T, Container, TAlloc>::end() noexcept
{
    return shapes.end();
}

/**
 * Returns an iterator to the first element of the list.
 * @return An iterator to the first element of the list.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
ShapeComposite<T, Container, TAlloc>::const_iterator ShapeComposite<T, Container, TAlloc>::begin() const
{
    return shapes.begin();
}

/**
 * Returns an iterator to the element following the last element of the list.
 * @return Iterator to the element following the last element.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
ShapeComposite<T, Container, TAlloc>::const_iterator ShapeComposite<T, Container, TAlloc>::end() const
{
    return shapes.end();
}

/**
 * Returns an iterator to the first element of the list.
 * @return An iterator to the first element of the list.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
ShapeComposite<T, Container, TAlloc>::const_iterator ShapeComposite<T, Container, TAlloc>::cBegin() const noexcept
{
    return shapes.cbegin();
}

/**
 * Returns an iterator to the element following the last element of the list.
 * @return Iterator to the element following the last element.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
ShapeComposite<T, Container, TAlloc>::const_iterator ShapeComposite<T, Container, TAlloc>::cEnd() const noexcept
{
    return shapes.cend();
}

/**
 * Returns the number of elements in the container, i.e. std::distance(begin(), end()).
 * @return The number of elements in the container.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
size_t ShapeComposite<T, Container, TAlloc>::count() const
{
    return shapes.size();
}

/**
 * Print ShapeComposites. This allows us to individually print each leaf node within a ShapeComposite.
 * Meaning that a ShapeComposite can contain both leaf and composite nodes and continue to print out each
 * leaf node.
 */
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
void ShapeComposite<T, Container, TAlloc>::print() const
{
    for (const auto& it : shapes)
    {
        it->print();
    }
}

#endif

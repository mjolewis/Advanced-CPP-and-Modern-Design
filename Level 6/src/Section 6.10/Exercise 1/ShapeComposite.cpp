//
// Composite pattern, to allow clients to treat individual objects and compositions uniformly.
// It can be viewed as tree like structures that represents part-whole hierarchies.
//
// Created by Michael Lewis on 8/15/23.
//


#include "ShapeComposite.hpp"
#include "ShapeVisitor.hpp"

typedef std::list<std::shared_ptr<Shape>>::iterator iterator;
typedef std::list<std::shared_ptr<Shape>>::const_iterator const_iterator;

/**
 * Default ctor
 */
ShapeComposite::ShapeComposite() : shapes{}
{

}

/**
 * Add a Shape leaf or composite into a list of other Shapes.
 * @param shape The Shape that will be added to the list.
 */
void ShapeComposite::addShape(const std::shared_ptr<Shape>& shape)
{
    shapes.push_back(shape);
}

/**
 * Returns an iterator to the first element of the list.
 * @return An iterator to the first element of the list.
 */
iterator ShapeComposite::begin() noexcept
{
    return shapes.begin();
}

/**
 * Returns an iterator to the element following the last element of the list.
 * @return Iterator to the element following the last element.
 */
iterator ShapeComposite::end() noexcept
{
    return shapes.end();
}

/**
 * Returns an iterator to the first element of the list.
 * @return An iterator to the first element of the list.
 */
const_iterator ShapeComposite::begin() const
{
    return shapes.begin();
}

/**
 * Returns an iterator to the element following the last element of the list.
 * @return Iterator to the element following the last element.
 */
const_iterator ShapeComposite::end() const
{
    return shapes.end();
}

/**
 * Returns an iterator to the first element of the list.
 * @return An iterator to the first element of the list.
 */
const_iterator ShapeComposite::cBegin() const noexcept
{
    return shapes.cbegin();
}

/**
 * Returns an iterator to the element following the last element of the list.
 * @return Iterator to the element following the last element.
 */
const_iterator ShapeComposite::cEnd() const noexcept
{
    return shapes.cend();
}

/**
 * Returns the number of elements in the container, i.e. std::distance(begin(), end()).
 * @return The number of elements in the container.
 */
size_t ShapeComposite::count() const
{
    return shapes.size();
}

/**
 * Print ShapeComposites. This allows us to individually print each leaf node within a ShapeComposite.
 * Meaning that a ShapeComposite can contain both leaf and composite nodes and continue to print out each
 * leaf node.
 */
void ShapeComposite::print() const
{
    for (const auto& it : shapes)
    {
        it->print();
    }
}

/**
 * Accepts a visitor and forwards the current object to the specified visitor.
 * @note This is a form of double dispatching
 * @param visitor The visitor to visit
 */
void ShapeComposite::accept(ShapeVisitor& visitor)
{
    for (const auto& shape : shapes)
    {
        shape->accept(visitor);
    }
    visitor.visit(*this); // Pass control to visitor
}


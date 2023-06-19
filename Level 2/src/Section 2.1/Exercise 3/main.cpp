//
// Simple test cases to illustrate the use cases of type traits
//
// Created by Michael Lewis on 6/19/23.
//

#include <iostream>
#include <type_traits>

#include "Shape.hpp"
#include "Base.hpp"
#include "Point.hpp"

/**
 * Log type type properties of the given argument.
 *
 * Note - std::boolalpha converts a 0 or 1 into a true or false.
 */
template<typename T>
void typeProperties(const T& t)
{
    std::cout << "Is empty class:" << std::boolalpha << std::is_empty<T>::value << std::endl;
    std::cout << "Is polymorphic class:" << std::boolalpha << std::is_polymorphic<T>::value << std::endl;
    std::cout << "Is abstract class:" << std::boolalpha << std::is_abstract<T>::value << std::endl;
    std::cout << "\n" << std::endl;
}

/**
 * Tests the general and specific properties of base and derived classes
 */
void test_typeProperties()
{
    std::cout << "\n*** Test type properties ***" << std::endl;

    Shape* sh;
    typeProperties(sh);

    Shape* point = new Point();
    typeProperties(*point);
    delete point;

    Base base;
    typeProperties(base);

    Point point1;
    typeProperties(point1);
}

/**
 * Illustrate simple use case of evaluating whether or not two types are the same
 */
void test_isSameClass()
{
    std::cout << "\n*** Test is_same type trait ***" << std::endl;

    // Minor dev productivity optimization
    std::cout << std::boolalpha;

    std::cout << "Are a Shape and Point the same?" << std::is_same<Shape, Point>::value << std::endl;
    std::cout << "Are a Shape and Base the same?" << std::is_same<Shape, Base>::value << std::endl;
    std::cout << "Are a Base and Point the same?" << std::is_same<Shape, Point>::value << std::endl;
    std::cout << "Are a Point and Point the same?" << std::is_same<Point, Point>::value << std::endl;
    std::cout << "Are a Shape and Shape the same?" << std::is_same<Shape, Shape>::value << std::endl;
    std::cout << "Are a Base and Base the same?" << std::is_same<Base, Base>::value << std::endl;
}

/**
 * Find the classes that are base and derived versions of each other
 */
void test_isBaseOf()
{
    std::cout << "\n*** Test is_base_of type trait ***" << std::endl;

    // Minor dev productivity optimization
    std::cout << std::boolalpha;

    std::cout << "Is Shape base of Base?" << std::is_base_of<Shape, Base>::value << std::endl;
    std::cout << "Is Shape base of Point?" << std::is_base_of<Shape, Point>::value << std::endl;
    std::cout << "Is Base base of Shape?" << std::is_base_of<Base, Shape>::value << std::endl;
    std::cout << "Is Base base of Point?" << std::is_base_of<Base, Point>::value << std::endl;
    std::cout << "Is Point base of Base?" << std::is_base_of<Point, Base>::value << std::endl;
    std::cout << "Is Point base of Shape?" << std::is_base_of<Point, Shape>::value << std::endl;
}

/**
 * Find the classes that can be converted to each other
 */
void test_isConvertable()
{
    std::cout << "\n*** Test is_convertible type trait ***" << std::endl;

    // Minor dev productivity optimization
    std::cout << std::boolalpha;

    std::cout << "Is Shape convertible to Base?" << std::is_convertible<Shape, Base>::value << std::endl;
    std::cout << "Is Shape convertible to Point?" << std::is_convertible<Shape, Point>::value << std::endl;
    std::cout << "Is Base convertible to Shape?" << std::is_convertible<Base, Shape>::value << std::endl;
    std::cout << "Is Base convertible to Point?" << std::is_convertible<Base, Point>::value << std::endl;
    std::cout << "Is Point convertible to Base?" << std::is_convertible<Point, Base>::value << std::endl;
    std::cout << "Is Point convertible to Shape?" << std::is_convertible<Point, Shape>::value << std::endl;
    std::cout << "Is Point* convertible to Shape*?" << std::is_convertible<Point*, Shape*>::value << std::endl;
    std::cout << "Is Shape* convertible to Point*?" << std::is_convertible<Shape*, Point*>::value << std::endl;
}

int main()
{
    test_typeProperties();
    test_isSameClass();
    test_isBaseOf();
    test_isConvertable();
    return 0;
}
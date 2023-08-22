//
// Template Method Pattern
//
// This allows you to define the skeleton of an algorithm in a base class while optionally
// allowing derived classes to specialize any of the steps. However, the base class function
// is final, so derived classes can only modify behavior of the steps but not alter their
// ordering, which allows the algorithm designer to enforce a contract that the desired steps
// will always occur in the proper sequence
//
// Created by Michael Lewis on 8/20/23.
//

#include <unordered_set>
#include <list>
#include <vector>
#include <memory>

#include "ConsoleShapeFactory.hpp"

// Creates a Line using the Template Method Pattern
void test_TemplateMethod_Line()
{
    std::cout << "\n*** Line with Template Method Pattern ***" << std::endl;
    ConsoleShapeFactory factory;
    Line line = factory.createLine();
    std::cout << line << std::endl;
}

// Creates a Polyline using the Template Method Pattern
void test_PolyLine_List()
{
    std::cout << "\n*** Polyline with List and Template Method Pattern ***" << std::endl;
    ConsoleShapeFactory factory;
    PolyLine polyLine = factory.createPolyLine<Point, std::list, std::allocator<std::shared_ptr<Point>>>();
    polyLine.print();
}

void test_PolyLine_Vector()
{
    std::cout << "\n*** Polyline with Vector and Template Method Pattern ***" << std::endl;
    ConsoleShapeFactory factory;
    PolyLine polyLine = factory.createPolyLine<Point, std::vector, std::allocator<std::shared_ptr<Point>>>();
    polyLine.print();
}

int main()
{
    test_TemplateMethod_Line();
    test_PolyLine_List();
    test_PolyLine_Vector();
    return 0;
}
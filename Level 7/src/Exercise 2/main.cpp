//
// Factory Pattern using modern C++
//
// Created by Michael Lewis on 8/19/23.
//

#include <iostream>
#include <functional>
#include <memory>

#include "NewShapeFactory.hpp"
#include "ConsoleShapeFactory.hpp"

// Aliases
using CirclePtr = std::shared_ptr<Circle>;
using LinePtr = std::shared_ptr<Line>;
using PointPtr = std::shared_ptr<Point>;

// Test shapes built by the default ctor, which uses the shapes default ctor to actually construct shapes
void test_DefaultShapes()
{
    NewShapeFactory newShapeFactory;
    CirclePtr circle = newShapeFactory.createCircle();
    LinePtr line = newShapeFactory.createLine();
    PointPtr point = newShapeFactory.createPoint();

    std::cout << "*** Default Shapes ***" << std::endl;
    std::cout << *circle << std::endl;
    std::cout << *line << std::endl;
    std::cout << *point << std::endl;
}

// Test shapes built by custom universal function wrappers
void test_CustomShapes()
{
    auto circleFunc = []() -> CirclePtr {
        Point centerPoint{2, 2};
        double radius = 1;
        return std::make_shared<Circle>(Circle{centerPoint, radius});
    };

    auto lineFunc = []() -> LinePtr {
        Point start{3, 4};
        Point end{5, 6};
        return std::make_shared<Line>(Line{start, end});
    };

    auto pointFunc = []() -> PointPtr { return std::make_shared<Point>(Point{7, 7}); };

    NewShapeFactory newShapeFactory{circleFunc, lineFunc, pointFunc};
    CirclePtr circle = newShapeFactory.createCircle();
    LinePtr line = newShapeFactory.createLine();
    PointPtr point = newShapeFactory.createPoint();

    std::cout << "\n*** Custom Shapes ***" << std::endl;
    std::cout << *circle << std::endl;
    std::cout << *line << std::endl;
    std::cout << *point << std::endl;
}

// Test adding new shape factory functions to the shape factory
void test_AddingShapes()
{
    NewShapeFactory newShapeFactory;
    CirclePtr circle = newShapeFactory.createCircle();
    LinePtr line = newShapeFactory.createLine();
    PointPtr point = newShapeFactory.createPoint();

    std::cout << "\n*** Default Shapes ***" << std::endl;
    std::cout << *circle << std::endl;
    std::cout << *line << std::endl;
    std::cout << *point << std::endl;

    auto circleFunc = []() -> CirclePtr {
        Point centerPoint{2, 2};
        double radius = 1;
        return std::make_shared<Circle>(Circle{centerPoint, radius});
    };

    auto lineFunc = []() -> LinePtr {
        Point start{3, 4};
        Point end{5, 6};
        return std::make_shared<Line>(Line{start, end});
    };

    auto pointFunc = []() -> PointPtr { return std::make_shared<Point>(Point{7, 7}); };

    std::cout << "\n*** Adding New Shape Factories ***" << std::endl;
    newShapeFactory.addCircleFunction(circleFunc);
    newShapeFactory.addLineFunction(lineFunc);
    newShapeFactory.addPointFunction(pointFunc);

    circle = newShapeFactory.createCircle();
    line = newShapeFactory.createLine();
    point = newShapeFactory.createPoint();

    std::cout << *circle << std::endl;
    std::cout << *line << std::endl;
    std::cout << *point << std::endl;
}

// Build shapes using function objects
void test_ShapeFactory_FunctionObjects()
{
    std::cout << "\n*** Custom Shapes Using Function Objects ***" << std::endl;

    NewShapeFactory newShapeFactory{Circle(), Line(), Point()};
    CirclePtr circle = newShapeFactory.createCircle();
    LinePtr line = newShapeFactory.createLine();
    PointPtr point = newShapeFactory.createPoint();

    std::cout << *circle << std::endl;
    std::cout << *line << std::endl;
    std::cout << *point << std::endl;
}

// Use std::bind to reuse old GOF factory methods and bind those factories to a universal function wrapper
void test_BindingShapeFactories()
{
    std::cout << "\n*** Bind Shape Factories ***" << std::endl;

    ConsoleShapeFactory consoleShapeFactory;

    auto circleFunc = [&]()
    {
        return std::make_shared<Circle>(std::bind(&ConsoleShapeFactory::createCircle, &consoleShapeFactory)());
    };

    auto lineFunc = [&]()
    {
        return std::make_shared<Line>(std::bind(&ConsoleShapeFactory::createLine, &consoleShapeFactory)());
    };

    auto pointFunc = [&]()
    {
        return std::make_shared<Point>(std::bind(&ConsoleShapeFactory::createPoint, &consoleShapeFactory)());
    };

    NewShapeFactory newShapeFactory{circleFunc, lineFunc, pointFunc};
    CirclePtr circle = newShapeFactory.createCircle();
    LinePtr line = newShapeFactory.createLine();
    PointPtr point = newShapeFactory.createPoint();

    std::cout << *circle << std::endl;
    std::cout << *line << std::endl;
    std::cout << *point << std::endl;
}

// Part D - Illustrate how to modify shapes using std::bind and lambdas
// Note - Per https://quantnet.com/threads/7-2-b-a-little-bit-confused-about-std-bind-function.29217/post-241438
// using std::bind is not actually necessary
void test_ModifyShapes_Bind_Lambda()
{
    std::cout << "\n*** Default Initialize Shapes using GOF ***" << std::endl;

    ConsoleShapeFactory consoleShapeFactory;

    // Default initialized circle using GOF, which is subsequently modified using modern C++ techniques
    auto circleFunc = [&]()
    {
        /*
         * Using std::bind is possible here, but not strictly necessary. As an example, you
         * could use it like so:
         * auto circle = std::bind(&ConsoleShapeFactory::createCircle, &consoleShapeFactory)();
         */

        auto circle = consoleShapeFactory.createCircle();
        Point centerPoint = Point{9, 9};
        double radius = 3;
        circle.CenterPoint(centerPoint);
        circle.Radius(radius);
        return std::make_shared<Circle>(circle);
    };

    // Default initialized line using GOF, which is subsequently modified using modern C++ techniques
    auto lineFunc = [&]()
    {
        /*
         * Using std::bind is possible here, but not strictly necessary. As an example, you
         * could use it like so:
         * auto line = std::bind(&ConsoleShapeFactory::createLine, &consoleShapeFactory)();
         */

        auto line = consoleShapeFactory.createLine();
        Point start = Point{9, 9};
        Point end = Point{9, 9};
        line.p1(start);
        line.p2(end);
        return std::make_shared<Line>(line);
    };

    // Default initialized point using GOF, which is subsequently modified using modern C++ techniques
    auto pointFunc = [&]()
    {
        /*
         * Using std::bind is possible here, but not strictly necessary. As an example, you
         * could use it like so:
         * auto line = std::bind(&ConsoleShapeFactory::createLine, &consoleShapeFactory)();
         */

        auto point = consoleShapeFactory.createPoint();
        point.X(9);
        point.Y(9);
        return std::make_shared<Point>(point);
    };

    NewShapeFactory newShapeFactory;
    newShapeFactory.addCircleFunction(circleFunc);
    newShapeFactory.addLineFunction(lineFunc);
    newShapeFactory.addPointFunction(pointFunc);

    CirclePtr circle = newShapeFactory.createCircle();
    LinePtr line = newShapeFactory.createLine();
    PointPtr point = newShapeFactory.createPoint();

    std::cout << "\n*** Modified Shapes using Modern C++ lambdas ***" << std::endl;
    std::cout << *circle << std::endl;
    std::cout << *line << std::endl;
    std::cout << *point << std::endl;
}

int main()
{
    test_DefaultShapes();
    test_CustomShapes();
    test_AddingShapes();
    test_ShapeFactory_FunctionObjects();
    test_BindingShapeFactories();
    test_ModifyShapes_Bind_Lambda();

    /*
     * Part C:
     * Brainstorming question: consider the suitability of this design to other
     * pattern such as Strategy and Command? How does the new design compare
     * with the corresponding GOF design?
     *
     * Response:
     * Strategy Pattern Replacement:
     * This modern C++ approach very closely resembles the intent of the Strategy pattern
     * while also maintaining the additional benefit of reducing the probability of small
     * class explosion. Strategies are a very nice GOF algorithm, but you can often end up
     * with classes that are very small because there's some minor difference in the desired
     * behavior. Instead of having to create an additional class for this minor change, we
     * can now simply pass in a universal function to achieve the same result.
     *
     * Command Pattern Replacement:
     * Commands are simply an object-oriented solution to callback functions. However, similar
     * to the Strategy Pattern, they may only provide a small difference in functionality or,
     * more commonly, simply be a class with a very small interface. So small, in fact, that
     * a functional replacement has many advantages in terms of reducing boilerplate code.
     * With modern C++, we can now replace Commands with a universal function wrapper and
     * eliminate such boilerplate code. After all, a command is just an object with an Execute
     * method that is invoked to produce a desired behavior. Universal function wrappers serve
     * the same purpose but in a much more expressive way.
     */

    /*
     * Part D:
     * Brainstorm on how to integrate existing OOP code using lambda functions
     * (using wrappers, for example) and std::bind. In particular, investigate
     * how to modify objects using captured variables after they have been
     * default initialized using GOF factories
     *
     * Response:
     * See unit test above. However, we can use existing GOF patterns that are bridged into
     * modern C++ techniques using lambda captures to capture either the default initialized shapes
     * or the default initialized shape factories (such as above) into a lambda expression.
     * The lambda expression can subsequently modify these shapes and be used as a bridge into
     * a universal function wrapper to facilitate the modern Factory Pattern.
     */
    return 0;
}

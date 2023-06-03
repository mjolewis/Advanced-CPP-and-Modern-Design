//
// Created by Michael Lewis on 6/2/23.
//

#include "Circle.hpp"
#include "Line.hpp"
#include "Valve.hpp"
#include "Utils.hpp"

/**
 * Test variadic polymorphic and non-polymorphic behavior
 */
void test_Rotate()
{
    double factor = 2.0;

    // Create objects whose class implements rotate
    auto circle = Circle();
    auto line = Line();
    auto valve = Valve();

    // Test variadic rotate function
    Utils::rotate(factor, circle, line, valve);
    Utils::rotate(factor, valve, circle, line);
    Utils::rotate(factor, line, valve, circle);
    Utils::rotate(factor, line, circle, valve);
    Utils::rotate(factor, circle, valve, line);
    Utils::rotate(factor, valve, line, circle);
}

/*
 * Question: Why can't we include valves in this array? And why can we include valves in the variadic approach
 *      std::array<Shape*, 5>
 *      shapeList{ &circle, &line, &circle, &circle, &line };
 *      double factor2 = 20.0;
 *      for (auto& elem : shapeList) elem->rotate(factor2);
 * Answer: We can't include valves in the non-variadic approach because a valve does not implement Shape.
 * And the array can only hold Shapes due to type safety mechanisms. However, we can include valve in the
 * variadic approach because the variadic rotate is capable of receiving any generic type.
 */

int main()
{
    test_Rotate();
    return 0;
}
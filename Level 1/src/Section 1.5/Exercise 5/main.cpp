//
// Created by Michael Lewis on 6/8/23.
//

#include "ConsoleBuilder.hpp"
#include "MonitorBuilder.hpp"

/**
 * Leverages the GOF Builder pattern to simulate displaying a line onto a console
 */
void test_Console()
{
    ConsoleBuilder builder{};
    const auto& products = builder.getProduct();
    const std::shared_ptr<Shape>& line = std::get<0>(products);
    const std::shared_ptr<IODevice>& console = std::get<1>(products);
    line->display(*console);
}

/**
 * Leverages the GOF Builder pattern to simulate displaying a circle onto a monitor
 */
void test_Monitor()
{
    MonitorBuilder builder{};
    const auto& products = builder.getProduct();
    const std::shared_ptr<Shape>& circle = std::get<0>(products);
    const std::shared_ptr<IODevice>& monitor = std::get<1>(products);
    circle->display(*monitor);
}

int main()
{
    test_Console();
    test_Monitor();
    return 0;
}
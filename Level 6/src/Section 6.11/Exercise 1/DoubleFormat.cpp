//
// Concrete Observer that will print the value of the Subjects counter in double format
//
// Created by Michael Lewis on 8/16/23.
//

#include <iomanip>
#include <iostream>

#include "DoubleFormat.hpp"
#include "Counter.hpp"

/**
 * Receives updates whenever the subject changes state and prints the counter out in double format
 * @param subject The subject that changed state
 */
void DoubleFormat::update(const Subject &subject)
{
    Counter counter = dynamic_cast<const Counter&>(subject);
    double d = counter.getCounter();
    std::string s = std::to_string(d);
    std::cout << "Double Format: " << s << std::endl;
}

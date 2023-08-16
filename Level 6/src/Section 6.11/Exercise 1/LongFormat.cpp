//
// Concrete Observer that will print the value of the Subjects counter in long format
//
// Created by Michael Lewis on 8/16/23.
//

#include <iomanip>
#include <iostream>

#include "LongFormat.hpp"
#include "Counter.hpp"

/**
 * Receives updates whenever the subject changes state and prints the counter out in long format
 * @param subject The subject that changed state
 */
void LongFormat::update(const Subject &subject)
{
    Counter counter = dynamic_cast<const Counter&>(subject);
    long l = counter.getCounter();
    std::string s = std::to_string(l);
    std::cout << "Long Format: " << s << std::endl;
}

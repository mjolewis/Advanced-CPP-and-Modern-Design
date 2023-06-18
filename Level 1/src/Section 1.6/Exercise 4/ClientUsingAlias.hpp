//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CLIENTUSINGALIAS_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CLIENTUSINGALIAS_HPP

#include <iostream>

#include "Storage.hpp"

template<typename T>
using Storage_Alias = std::list<T, std::allocator<T>>;

/**
 * Example of a modern C++ approach using an Alias Template.
 *
 * This approach essentially deprecates the use of typedef
 * as we no longer need to perform the works arounds such as
 * creating a Storage struct simply to implement a typedef template
 */
template<typename T>
class ClientUsingAlias
{
private:
    Storage_Alias<T> data; // typename no longer manager with alias templating
public:
    ClientUsingAlias(int n, const T& val) : data(n, val) {}
    void print() const {
        std::for_each(data.begin(), data.end(),
                      [](const T& n) { std::cout << n << ","; });
        std::cout << '\n';
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CLIENTUSINGALIAS_HPP

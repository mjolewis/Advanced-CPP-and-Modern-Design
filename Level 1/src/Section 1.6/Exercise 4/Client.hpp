//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_CLIENT_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_CLIENT_HPP

#include <iostream>

#include "Storage.hpp"

template <typename T>
class Client
{
// An example of Composition
private:
    typename Storage<T>::type data; // typename mandatory
public:
    Client(int n, const T& val) : data(n, val) {}
    void print() const {
        std::for_each(data.begin(), data.end(),
                      [](const T& n) { std::cout << n << ","; });
        std::cout << '\n';
    }
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_CLIENT_HPP

//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_STORAGE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_STORAGE_HPP

#include <list>

// C++ 98 approach
// Data storage types
template <typename T> struct Storage
{
// Possible ADTs and their memory allocators
// typedef std::vector<T, CustomAllocator<T>> type;
// typedef std::vector<T, std::allocator<T>> type;

    typedef std::list<T, std::allocator<T>> type;
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_STORAGE_HPP

//
// Created by Michael Lewis on 6/11/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_S_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_S_HPP

struct S
{
    int x;
    struct Foo
    {
        int i; int j; int a[3];
    }b;  // Note - b is of type Foo
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_S_HPP

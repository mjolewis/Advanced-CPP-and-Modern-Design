//
// Test cases for testing smart pointers with STL algorithms
// Created by Michael Lewis on 6/23/23.
//

#include <iostream>
#include <list>

#include "Base.hpp"
#include "Derived.hpp"

// Create lists of shared_ptr<Base> and unique_ptr<Base> to see how they differ in terms of how
// they are deallocated when the Base class dtor is not public
void test_PartA()
{
    {
        // Scope for share pointers to Base
        using SmartPointer = std::shared_ptr<Base>;
        SmartPointer d1{new Derived{}};
        SmartPointer d2{new Derived{}};
        SmartPointer d3{new Derived{}};
        std::list<SmartPointer> smartPointers = {d1, d2, d3};
    }

    {
        // Scope for unique pointers to Base
        // This code does not compile because the way std::unique handles the deleter. As an example, the
        // function signature is as follows Template<class T,class Deleter = std::default_delete<T>> class unique_ptr;
        // Thus, unique_ptr<Base> implies that the deleter is of type Base and, in this case, the Base dtor is
        // protected and can't be accessed. To get around this, you can provide a custom deleter
//        UniquePointer d1(new Derived());
//        UniquePointer d2{new Derived{}};
//        UniquePointer d3{new Derived{}};
//        std::list<UniquePointer> smartPointers = {d1, d2, d3};
    }
}

// Factory function to create shared_ptr<Base>
std::shared_ptr<Base> sharedPtrFactory()
{
    return std::shared_ptr<Base>{new Derived{}};
}

// Use a shared_ptr factory to create shared_ptr<Base> and add them to a list
// As you can see when running the test, the derived and base destructors are called,
// which indicates that there are no memory leaks when using the shared_ptr
void test_PartB()
{
    using SharedPtr = std::shared_ptr<Base>;
    {
        std::list<SharedPtr> sharedPtrs;
        for (int i = 0; i < 5; ++i)
        {
            sharedPtrs.push_back(sharedPtrFactory());
        }
    }
}

int main()
{
    test_PartA();
    test_PartB();
    return 0;
}

//
// Created by Michael Lewis on 6/11/23.
//

#include <memory>

#include "Base.hpp"
#include "Derived.hpp"
#include "Derived2.hpp"

/**
 * Tests polymorphism to illustrate derived functionality being invoked
 * because derived class override base structure functionality
 */
void test_Derived()
{
    std::shared_ptr<Base> derivedPtr =  std::make_shared<Derived>(Derived());
    derivedPtr->print();
    derivedPtr->draw();
}

/**
 * Tests polymorphism to illustrate base functionality being invoked
 * because derived class doesn't override base structure functionality
 */
void test_Derived2()
{
    std::shared_ptr<Base> derivedPtr2 = std::make_shared<Derived2>(Derived2());
    derivedPtr2->print();
    derivedPtr2->draw();
}

int main()
{
    test_Derived();
    test_Derived2();
    return 0;
}
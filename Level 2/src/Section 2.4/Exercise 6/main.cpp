//
// Illustrate use of weak pointers, which act as an observer of a shared pointer. One of the main purposes of
// weak pointers is to use them with shared resources without assuming ownership. This is helpful in avoid
// dangling pointers.
//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>
#include <memory>

int main()
{
    // Part A - Create a shared pointer and a weak pointer to observe the use count
    std::shared_ptr<double> sp1(new double(1));
    std::cout << "sp1 use count=" << sp1.use_count() << std::endl;
    std::weak_ptr<double>wp1 = sp1;
    std::cout << "sp1 use count=" << sp1.use_count() << std::endl;

    // Part B - Assign a weak pointer to a shared pointer and check that the weak pointer is not empty.
    std::shared_ptr<double> sp2(wp1);
    std::cout << "wp1 use count=" << sp2.use_count() << ", it's value is: " << *sp2 << std::endl;

    // Part C - Assign a weak pointer to another weak pointer; assign a weak pointer
    // to shared pointer. What is the use count in both cases?
    std::weak_ptr<double> wp2 = wp1;
    std::cout << "wp2 use count=" << wp2.use_count() << std::endl;
    std::shared_ptr<double> sp3(wp2);
    std::cout << "wp2 use count=" << wp2.use_count() << ". sp3 use count= " << sp3.use_count() << std::endl;
}
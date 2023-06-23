//
// The objective of this exercise is to show shared ownership using smart pointers in C++.
//
// Created by Michael Lewis on 6/22/23.
//

#include <iostream>
#include <memory>

#include "C1.hpp"
#include "C2.hpp"
#include "Point.hpp"

// Part B - Create instances of a shared_ptr<double> and share it with C1 and C2 to track the use count
// Note: Use count normally can't be observed to go to 0 as it happens when the last shared_ptr pointing
// to it goes out of scope. As a result, the use count logged to the console below will only decrement to 1.
// It will go to 0 only after test_PartB() fully terminates.
void test_PartB()
{
    std::cout << "*** Start Part B" << std::endl;

    std::shared_ptr<double> sharedPtr(new double{2.0});
    std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;

    {
        C1 c1(sharedPtr);
        std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;

        {
            C2 c2(sharedPtr);
            std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;
        }

        std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;
    }

    std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;

    std::cout << "*** End Part B" << std::endl;
}

// Part C - Create instances of a shared_ptr<Point> and share it with C1 and C2 to track the use count
// Note: Use count normally can't be observed to go to 0 as it happens when the last shared_ptr pointing
// to it goes out of scope. As a result, the use count logged to the console below will only decrement to 1.
// It will go to 0 only after test_PartC() fully terminates.
void test_PartC()
{
    std::cout << "*** Start Part C" << std::endl;

    std::shared_ptr<Point> sharedPtr(new Point{});
    std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;

    {
        C1 p1(sharedPtr);
        std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;

        {
            C2 p2(sharedPtr);
            std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;
        }

        std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;
    }

    std::cout << "Actual Use Count=" << sharedPtr.use_count() << std::endl;

    std::cout << "*** End Part C" << std::endl;
}

// Extending parts A to C to assigning, copy and compare two shared pointers sp1 and sp2.
void test_PartD()
{
    std::cout << "*** Start Part D" << std::endl;
    {
        // Assign sp1 to sp2
        std::shared_ptr<double> sp1(new double(1));
        std::shared_ptr<double> sp2 = sp1;
        std::cout << "SP1 use count after being assigned to SP2=" << sp1.use_count() << std::endl;
    }

    {
        // Copy sp1 to sp2
        std::shared_ptr<double> sp1(new double(1));
        std::shared_ptr<double> sp2 = std::shared_ptr<double>(sp1);
        std::cout << "SP1 use count after being copied to SP2=" << sp1.use_count() << std::endl;
    }

    {
        // Compare sp1 to sp2
        std::shared_ptr<double> sp1(new double(1));
        std::shared_ptr<double> sp2(new double(2));
        std::cout << "SP1 == SP2? " << std::boolalpha << (sp1.get() == sp2.get()) << std::endl;
        std::cout << "SP1 != SP2? " << std::boolalpha << (sp1.get() != sp2.get()) << std::endl;
        std::cout << "SP1 < SP2? " << std::boolalpha << (sp1.get() < sp2.get()) << std::endl;
        std::cout << "SP1 <= SP2? " << std::boolalpha << (sp1.get() <= sp2.get()) << std::endl;
        std::cout << "SP1 > SP2? " << std::boolalpha << (sp1.get() > sp2.get()) << std::endl;
        std::cout << "SP1 >= SP2? " << std::boolalpha << (sp1.get() >= sp2.get()) << std::endl;
    }

    {
        // Transfer ownership from sp1 to sp2.
        std::shared_ptr<double> sp1(new double(1));
        std::shared_ptr<double> sp2(new double(2));
        sp2=std::move(sp1);
        std::cout << "Transfer ownership from SP1 to SP2. Use count of SP1="
        << sp1.use_count() <<". Use count of SP2=" << sp2.use_count() << std::endl;
    }

    {
        // Determine if a shared_ptr is the sole owner of a resource
        std::shared_ptr<double> sp1(new double(1));
        std::cout << std::boolalpha << "sp1.unique():" << sp1.unique() << std::endl;
        std::shared_ptr<double> sp2(sp1);
        std::cout << std::boolalpha << "sp1.unique():" << sp1.unique() << std::endl;

    }

    {
        // Swap sp1 and sp2
        std::shared_ptr<double> sp1(new double(1));
        std::shared_ptr<double> sp2(new double(2));
        std::cout << "SP1=" << *sp1 << ", SP2=" << *sp2 << ". Pre-Swap" << std::endl;
        sp1.swap(sp2);
        std::cout << "SP1=" << *sp1 << ", SP2=" << *sp2 << ". Post-Swap" << std::endl;
    }

    {
        // Give up ownership of shared_ptr
        std::shared_ptr<double> sp1(new double(1));
        sp1.reset();
        sp1 = nullptr;
        std::cout << "Use count after giving up ownership:" << sp1.use_count() << std::endl;
    }

    std::cout << "*** End Part D" << std::endl;
}

int main()
{
    test_PartB();
    test_PartC();
    test_PartD();
    return 0;
}
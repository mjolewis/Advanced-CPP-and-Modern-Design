//
// Created by Michael Lewis on 6/23/23.
//

#include <iostream>
#include <memory>

int main()
{
    // Part A
    // This code throws a runtime error with exit code 139 which indicates a Segmentation Fault.
    // This means that the program was trying to access a memory location not allocated to it.
    // In the case below, d is a null pointer after being assigned to d2.
    {
        using std::auto_ptr;
        // Define auto_ptr pointers instead of raw pointers
        std::auto_ptr<double> d(new double(1.0));

        // Dereference
        *d = 2.0;

        // Change ownership of auto_ptr
        // (after assignment, d is undefined)
        auto_ptr <double> d2 = d;
        *d2 = 3.0;

        std::cout << "Is d a nullptr?" << std::boolalpha << (d.get()==nullptr) << std::endl;
//        std::cout <<"Auto values: "<< *d.get() <<", "<< *d2.get();
    }

    // Part B - Port the previous code to use std::unique_ptr
    // According to https://en.cppreference.com/w/cpp/memory/unique_ptr
    // std::unique_ptr is not CopyConstructible or CopyAssignable. These are in fact
    // implicitly deleted because std::unique_ptr satisfies MoveConstructible and MoveAssignable
    {
        // Define auto_ptr pointers instead of raw pointers
        std::unique_ptr<double> d(new double(1.0));

        // Dereference
        *d = 2.0;

        // Change ownership of auto_ptr
        // (The copy assignment here is a compile time error as specified above)
//        std::unique_ptr<double> d2 = d;
//        *d2 = 3.0;

//        std::cout <<"Auto values: "<< *d.get() <<", "<< *d2.get();
    }

    return 0;
}

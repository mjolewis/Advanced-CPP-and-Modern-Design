//
// Simple test cases to illustrate the use cases of type traits
//
// Created by Michael Lewis on 6/19/23.
//

#include <iostream>
#include <memory>
#include <type_traits>

/**
 * Illustrate simple use cases of type traits
 */
template<typename T>
void test_types(const T&& type)
{
    if (std::is_pointer<T>())
    {
        std::cout << "Pointer" << std::endl;
    }
    else if (std::is_null_pointer<T>::value)
    {
        std::cout << "Null Pointer" << std::endl;
    }
    else if (std::is_lvalue_reference<T>::value)
    {
        std::cout << "L-Value Reference" << std::endl;
    }
    else if (std::is_rvalue_reference<T>::value)
    {
        std::cout << "R-Value Reference" << std::endl;
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}

/**
 * Determine if a type is a member function pointer or if it is a pointer to a non-static member object.
 */
void test_PointerType()
{
    // Helper class used by test_PointerType
    class Shape
    {
    public:
        bool isMember() { return true; }
    };

    static_assert(std::is_member_function_pointer<decltype(&Shape::isMember)>::value);
    static_assert(std::is_member_object_pointer_v<int(Shape::*)>);
}

/**
 * Sample function provided by Homework to check if t is a pointer
 */
template <typename T>
void IsPointer(const T& t)
{
    if (std::is_pointer<T>::value)
    {
        std::cout << "This is a pointer type argument\n";
    }
    else
    {
        std::cout << "_not_ a pointer type argument\n";
    }
}

/**
 * Illustrate the fact that shared pointers are not of a pointer type
 */
void test_sharedPointer()
{
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(32);
    IsPointer(sharedPtr);  // Not a pointer type.

    IsPointer(sharedPtr.get());  // Is a pointer type
}

int main()
{
    test_types(new int{32});
    test_types(nullptr);
    test_types<const int&>(32);
    test_types<int&&>(3);
    test_PointerType();
    test_sharedPointer();
    return 0;
}
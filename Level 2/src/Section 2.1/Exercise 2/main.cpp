//
// Simple tests to illustrate the use cases of bridge functionality through type traits
//
// Created by Michael Lewis on 6/19/23.
//

#include <iostream>
#include <memory>
#include <type_traits>

/**
 * Implementation of specific type trait functionality based on the type being a pointer type
 */
template<typename T>
void isPointerImpl(const T& value, std::true_type)
{
    std::cout << "Value of dereferenced pointer:" << *value << std::endl;
}

/**
 * Implementation of specific type trait functionality based on the type being a scaler type
 */
template<typename T>
void isPointerImpl(const T& value, std::false_type)
{
    std::cout << "Value of scalar type:" << value << std::endl;
}

/**
 * Generic function that directs control flow based on type traits. This is an example of a switchable bridge technique.
 */
template<typename T>
void isPointer(const T& value)
{
    isPointerImpl(value, std::is_pointer<T>());
}

int main()
{
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(32);
    isPointer(sharedPtr.get());
    isPointer(7);
    return 0;
}

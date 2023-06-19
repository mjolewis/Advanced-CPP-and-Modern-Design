//
// Illustrates Array categories of type traits
//
// Created by Michael Lewis on 6/19/23.
//

#include <array>
#include <vector>
#include <iostream>
#include <type_traits>

/**
 * Illustrates std::is_array type trait
 */
void test_Array_Types()
{
    // Compound type
    class ObjectType{};

    std::cout << std::boolalpha;  // Minor developer productivity optimization

    std::cout << std::is_array<std::array<int, 2>>::value << std::endl;
    std::cout << std::is_array<ObjectType[]>::value << std::endl;
    std::cout << std::is_array<int>::value << std::endl;
    std::cout << std::is_array<int[]>::value << std::endl;
    std::cout << std::is_array<double>::value << std::endl;
    std::cout << std::is_array<double[]>::value << std::endl;
    std::cout << std::is_array<float>::value << std::endl;
    std::cout << std::is_array<float[]>::value << std::endl;
    std::cout << std::is_array<ObjectType>::value << std::endl;
    std::cout << std::is_array<std::vector<int>>::value << std::endl;
}

/**
 * Find the rank and extent of an array
 *
 * Rank is the number of dimensions
 * Extent is the number of elements along a specific dimension
 */
void test_rankAndExtent()
{
    std::cout << std::boolalpha;  // Minor developer productivity optimization

    using ArrayType = int [][3][4][5];
    std::cout << "Rank of [][3][4][5]:" << std::rank<ArrayType>::value << std::endl;
    std::cout << "Extent of first dimension [][3][4][5]:" << std::extent<ArrayType>::value << std::endl;
    std::cout << "Extent of second dimension [][3][4][5]:" << std::extent<ArrayType, 1>::value << std::endl;
    std::cout << "Extent of third dimension [][3][4][5]:" << std::extent<ArrayType, 2>::value << std::endl;
    std::cout << "Extent of fourth dimension [][3][4][5]:" << std::extent<ArrayType, 3>::value << std::endl;
}

/**
 * Use std::remove_extent to remove the first dimension of a multidimensional array
 */
void test_removeExtent()
{
    std::cout << std::boolalpha;  // Minor developer productivity optimization

    std::cout << "*** Removing first dimension of int [][3][4][5] ***" << std::endl;
    using ArrayType = int [][3][4][5];
    using RemovedType = std::remove_extent<ArrayType>::type;
    std::cout << "ArrayType=int [][3][4][5]. Is it the same as the array after removing extent?" << std::is_same<ArrayType, RemovedType>::value << std::endl;

    using NewArrayType = int[3][4][5];
    std::cout << "NewArrayType=int[3][4][5]. Is it the same as the array after removing extent?" << std::is_same<NewArrayType, RemovedType>::value << std::endl;
}

/**
 * Use std::remove_all_extents to remove all dimensions of a multidimensional array
 */
void test_removeAllExtent()
{
    std::cout << std::boolalpha;  // Minor developer productivity optimization

    std::cout << "*** Remove All Extent ***" << std::endl;
    using ArrayType = int [][3][4][5];
    using RemovedType = std::remove_all_extents<ArrayType>::type;
    std::cout << "ArrayType=int [][3][4][5]. Is it the same as the array after removing all extents?" << std::is_same<ArrayType, RemovedType>::value << std::endl;

    using IntegerType = int;
    std::cout << "IntegerType=int. Is it the same as the array after removing all extents?" << std::is_same<IntegerType, RemovedType>::value << std::endl;
}

int main()
{
    test_Array_Types();
    test_rankAndExtent();
    test_removeExtent();
    test_removeAllExtent();
    return 0;
}
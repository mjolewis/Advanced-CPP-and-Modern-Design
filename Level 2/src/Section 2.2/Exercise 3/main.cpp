//
// Test conversions between types using advanced type trait capabilities
//
// Created by Michael Lewis on 6/19/23.
//

#include <iostream>
#include <type_traits>
#include <vector>
#include <array>

// Aliases will be used to improve code readability
using UnsignedInt = std::make_unsigned<int>::type;
using SignedInt = std::make_signed<UnsignedInt>::type;

/**
 * Specific implementation to convert unsigned and signed types held in a container.
 *
 * For illustration purposes, the function is void and we simply log the results of the conversion
 */
template<typename T>
void signedUnsignedImpl(T& t, std::true_type)
{
    for (auto element : t)
    {
        using OldType = decltype(element);
        if (std::is_signed<OldType>::value)
        {
            using NewType = typename std::make_unsigned<OldType>::type;
            std::cout << std::boolalpha << "Is old type signed?" << std::is_signed<OldType>::value;
            std::cout << ". Is new type unsigned?" << std::is_unsigned<NewType>::value << std::endl;
        }
        else
        {
            using NewType = typename std::make_signed<OldType>::type;
            std::cout << std::boolalpha << "Is old type unsigned?" << std::is_unsigned<OldType>::value;
            std::cout << ". Is new type signed?" << std::is_signed<NewType>::value << std::endl;
        }
    }
}

/**
 * Specific implementation to convert unsigned and signed types.
 *
 * For illustration purposes, the function is void and we simply log the results of the conversion
 */
template<typename T>
void signedUnsignedImpl(T& t, std::false_type)
{
    if (std::is_signed<T>::value)
    {
        using NewType = typename std::make_unsigned<T>::type;
        std::cout << std::boolalpha << "Is old type signed?" << std::is_signed<T>::value;
        std::cout << ". Is new type unsigned?" << std::is_unsigned<NewType>::value << std::endl;
    }
    else
    {
        using NewType = typename std::make_signed<T>::type;
        std::cout << std::boolalpha << "Is old type unsigned?" << std::is_unsigned<T>::value;
        std::cout << ". Is new type signed?" << std::is_signed<NewType>::value << std::endl;
    }
}

/**
 * Generic interface to cast to and from signed integer and unsigned integer
 */
template<typename T>
void signedUnsigned(T& t)
{
    signedUnsignedImpl(t, std::is_compound<T>());
}

/**
 * Specific implementation to add and remove const qualifier. This function is capable of handling
 * both fundamental and compound types.
 *
 * For illustration purposes, the function is void and we simply log the results of the conversion
 */
template<typename T>
void addRemoveConst(T& t)
{
    if (std::is_const<T>::value)
    {
        using NewType = typename std::remove_const<T>::type;
        std::cout << std::boolalpha << "Old type was const qualified. Is new type const?" << std::is_const<NewType>::value << std::endl;
    }
    else
    {
        using NewType = typename std::add_const<T>::type;
        std::cout << std::boolalpha << "Old type was not const qualified. Is new type const?" << std::is_const<NewType>::value << std::endl;
    }
}

/**
 * Specific implementation to add and remove pointer. This function is capable of handling
 * both fundamental and compound types.
 *
 * For illustration purposes, the function is void and we simply log the results of the conversion
 */
template<typename T>
void addRemovePointer(T& t)
{
    if (std::is_pointer<T>::value)
    {
        using NewType = typename std::remove_pointer<T>::type;
        std::cout << std::boolalpha << "Old type was pointer. Is new type pointer?" << std::is_pointer<NewType>::value << std::endl;
    }
    else
    {
        using NewType = typename std::add_pointer<T>::type;
        std::cout << std::boolalpha << "Old type was not pointer. Is new type pointer?" << std::is_pointer<NewType>::value << std::endl;
    }
}

/**
 * Specific implementation to add and remove volatile. This function is capable of handling
 * both fundamental and compound types.
 *
 * For illustration purposes, the function is void and we simply log the results of the conversion
 */
template<typename T>
void addRemoveVolatile(T& t)
{
    if (std::is_volatile<T>::value)
    {
        using NewType = typename std::remove_volatile<T>::type;
        std::cout << std::boolalpha << "Old type was volatile. Is new type volatile?" << std::is_volatile<NewType>::value << std::endl;
    }
    else
    {
        using NewType = typename std::add_volatile<T>::type;
        std::cout << std::boolalpha << "Old type was not volatile. Is new type volatile?" << std::is_volatile<NewType>::value << std::endl;
    }
}

/**
 * Acts as the director for test cases that convert to and from signed and unsigned integers
 */
void test_mapUnsignedAndSignedIntegers()
{
    // Change the sign on integral types
    SignedInt signedInt = -10;
    signedUnsigned(signedInt);

    UnsignedInt unsignedInt = 10;
    signedUnsigned(unsignedInt);

    // Change the sign on container types
    using UnsignedIntVec = std::vector<UnsignedInt>;
    using SignedIntVec = std::vector<SignedInt>;

    SignedIntVec signedIntVec = {-1, -2, -3};
    signedUnsigned(signedIntVec);

    UnsignedIntVec unsignedIntVec = {1, 2, 3};
    signedUnsigned(unsignedIntVec);
}

/**
 * Acts as the director for test cases that add and remove const qualifier
 */
void test_add_remove_const()
{
    const int constInt = 1;
    addRemoveConst(constInt);

    int nonConstInt = 1;
    addRemoveConst(nonConstInt);

    const std::vector<int> constVec = {1, 2, 3};
    addRemoveConst(constVec);

    std::vector<int> nonConstVec = {4, 5, 6};
    addRemoveConst(nonConstVec);

    const std::array<int, 3> constArr = {1, 2, 3};
    addRemoveConst(constArr);

    std::array<int, 3> nonConstArr = {4, 5, 6};
    addRemoveConst(nonConstArr);
}

/**
 * Acts as the director for test cases that add and remove pointers
 */
void test_add_remove_pointer()
{
    int* intPointer = new int{1};
    addRemovePointer(intPointer);

    int nonIntPointer = 1;
    addRemovePointer(nonIntPointer);

    auto* pointerVec = new std::vector{1, 2, 3};
    addRemovePointer(pointerVec);

    std::vector<int> nonPointerVec = {4, 5, 6};
    addRemovePointer(nonPointerVec);

    auto* pointerArr = new std::array{1, 2, 3};
    addRemovePointer(pointerArr);

    std::array<int, 3> nonPointerArr = {4, 5, 6};
    addRemovePointer(nonPointerArr);
}

/**
 * Acts as the director for test cases that add and remove volatile specifier
 */
void test_add_remove_volatile()
{
    volatile int volatileInt = 1;
    addRemoveVolatile(volatileInt);

    int nonVolatileInt = 1;
    addRemoveVolatile(nonVolatileInt);

    volatile std::vector<int> volatileVec = {1, 2, 3};
    addRemoveVolatile(volatileVec);

    std::vector<int> nonVolatileVec = {4, 5, 6};
    addRemoveVolatile(nonVolatileVec);

    volatile std::array volatileArray = {1, 2, 3};
    addRemoveVolatile(volatileArray);

    std::array<int, 3> nonVolatileArray = {4, 5, 6};
    addRemoveVolatile(nonVolatileArray);
}

/**
 * Discuss the difference between direct list initialisation and
 * copy list initialisation in C++17/20 compared to C++11. In which
 * case does auto deduction reduce to std::initializer_list?
 * Give a code example. Under which circumstances can we get ill-formed expressions?
 *
 * Partial Response: We can get ill-formed expressions when using a copy ctor if the copy ctor has been
 * explicitly or implicitly deleted (e.g. adding move ctor but not copy ctor) or is simply not accessible through
 * access modifiers.
 *
 * When comparing C++11 and C++17, we can also see the C++17 added support for initializing rvalues (e.g. prvalue and
 * xvalue types)
 *
 * auto deduction reduces to std::initializer_list where the corresponding constructor accepts
 * an std::initializer_list parameter, a braced-init-list is used as the right operand of assignment
 * or as a function call argument, and the corresponding assignment operator/function
 * accepts an std::initializer_list parameter (source: https://en.cppreference.com/w/cpp/utility/initializer_list)
 * There are interesting cases for lambdas where auto deduction fails. See below for example.
 */
 void test_initialization()
{
     int copy = 5; // copy initialization

     // copy initialization results in compile time error because explicit constructors aren't candidate constructors
//     std::vector<int> copyVec = 5;

     int direct = {5}; // direct initialization

    // Direct initialization is successful unlike the corresponding copy initialization of the vector above
     std::vector<int> directVec = {5};

     // Compile error because cannot deduce the return type of from initialization list
     // According to Scott Meyer, auto in a function return type or a lambda parameter implies
     // template type deduction, not auto type deduction. And, auto type deduction usually assumes
     // std::initializer_list and template type deduction does not.
//     auto nonDeducable = []() { return {0}; }();
}

/**
 * Exemplar template to motivate the use case of CTAD.
 */
template<typename T, typename U>
class CTAD
{
public:
    std::tuple<T, U> myTuple;

    CTAD() = default;
    CTAD(T t, U u) { myTuple = {t, u}; }

    auto getMyTuple() const { return myTuple; };
};

/**
* Discuss how Class Template Argument Deduction (CTAD)) reduces code verbosity.
* Give a non-trivial example using std::tuple and a user-defined class.
 *
 * Response: As you can see below, CTAD eliminates the need to specify every template argument,
 * which can greatly simplify template code. Without this feature, specifying templates can often
 * become difficult to do and also hard to read as the template argument list grows to unmanageable levels.
*/
void test_CTAD()
{
    CTAD ctad{1, 2.0};
    auto tuple = ctad.getMyTuple();

    CTAD<int, double> ctadVerbose{1, 2.0};
    auto tupleVerbose = ctad.getMyTuple();

    assert(std::get<0>(tuple) == std::get<0>(tupleVerbose));
    assert(std::get<1>(tuple) == std::get<1>(tupleVerbose));
}

/**
 * Investigate the applicability of decltype and std::is_same when comparing the type of a result with a “target” type.
 *
 * Decltype can be used to yield the type of the input expression. For example, the input expression in this case
 * is an int. using decltype(int) will yield an int type for the result variable. It is therefore useful when
 * knowing the type is hard (e.g. in templates) yet we need to use that type for a downstream identifier.
 */
void test_decltype_isSame()
{
    int target = 1;
    decltype(target) result = 2;
    std::cout << std::boolalpha << std::is_same<int, decltype(result)>::value << std::endl;
}

/**
 * Main entry point to run all test cases
 */
int main()
{
    test_mapUnsignedAndSignedIntegers();
    test_add_remove_const();
    test_add_remove_pointer();
    test_add_remove_volatile();
    test_initialization();
    test_CTAD();
    test_decltype_isSame();
    return 0;
}
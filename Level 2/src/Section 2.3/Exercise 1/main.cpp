//
// Illustrate use cases of user defined deprecated entities
// @Note:
//  https://en.cppreference.com/w/cpp/language/attributes/deprecated highlights
//  the fact that use of a deprecated entity is allowed but discouraged and the
//  Compilers typically issue warnings. This means
//  that the program will in fact compile when a client uses a deprecated entity.
//
// Created by Michael Lewis on 6/21/23.
//

#include <iostream>

[[deprecated("Deprecated global variable")]]
double pi = 3.14;

/**
 * Deprecated free function is usable but ill advised. It's use will generate warnings
 */
[[deprecated("Deprecated free function")]]
void freeFunc()
{
    std::cout << "Deprecated free function" << std::endl;
}

/**
 * Deprecated class is usable but ill advised. It's use will generate warnings
 */
class [[deprecated("deprecated class")]] DeprecatedClass
{
public:
    DeprecatedClass() { std::cout << "Deprecated class" << std::endl; }
};

/**
 * Class with a deprecated member function. Function is usable but ill advised. It's use will generate warnings
 */
class C
{
public:
    C() = default;

    // Deprecated member function
    [[deprecated("Deprecated member function")]]
    void deprecatedMemberFunc() { std::cout << "Deprecated member function" << std::endl;}
};

/**
 * Deprecated enum is usable but ill advised. It's use will generate warnings
 */
enum [[deprecated("Deprecated enum")]] Side{BUY, SELL};

/**
 * Deprecated enum class is usable but ill advised. It's use will generate warnings
 */
enum class[[deprecated("Deprecated enum class")]] OrderType{ MARKET, LIMIT };

/**
 * Deprecated template class is usable but ill advised. It's use will generate warnings
 */
template<typename T>
class TemplateClass
{
public:
    TemplateClass() { std::cout << "Generalized template class" << std::endl; }
};

/**
 * Deprecated template class specialization is usable but ill advised. It's use will generate warnings
 */
template<>
class [[deprecated("Deprecated template class specialization")]] TemplateClass<int>
{
public:
    TemplateClass<int>() { std::cout << "Deprecated template class specialization" << std::endl;}
};

/**
 * Deprecated named lambda is usable but ill advised. It's use will generate warnings
 */
[[deprecated("Deprecated named lambda")]]
auto squareFunc = [] (auto x) { std::cout << "Deprecated named lambda" << std::endl;};

int main()
{
    freeFunc();
    DeprecatedClass deprecatedClass{};
    C c{};
    c.deprecatedMemberFunc();
    std::cout << "Global variable PI=" << pi << std::endl;
    Side buy{BUY};
    Side sell{SELL};
    OrderType marketOrder{OrderType::MARKET};
    OrderType limit{OrderType::LIMIT};
    TemplateClass<int> deprecatedTemplateClass{};
    squareFunc(2);
    return 0;
}
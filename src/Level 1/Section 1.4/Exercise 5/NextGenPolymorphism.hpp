//
// Created by Michael Lewis on 6/3/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_NEXTGENPOLYMORPHISM_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_NEXTGENPOLYMORPHISM_HPP

#include <functional>

// using declaration to simplify code readability
template<typename T>
using FunctionType = std::function<T (const T& t)>;

/**
 * Illustrates a next generation design pattern using function wrappers to replace
 * virtual polymorphism.
 */
template<typename T>
class NextGenPolymorphism
{
private:
    FunctionType<T> func;
    T factor;

public:
    NextGenPolymorphism() = delete;
    constexpr NextGenPolymorphism(const FunctionType<T>& func, const T& factor) : factor{factor} {this->func = func;}
    virtual ~NextGenPolymorphism() = default;

    constexpr T execute(T value) const { return func(value) * factor; }
    void setFunction(const FunctionType<T>& _func) { func = _func; }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_NEXTGENPOLYMORPHISM_HPP

//
// Code provided in lecture notes.
//
// This illustrates a next generation design for the Template Method Pattern
// using universal funtion wrappers.
//
// Created by Michael Lewis on 8/23/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_TMPPROCESSOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_TMPPROCESSOR_HPP

#include <functional>

// Alias for universal function wrappers
template<typename T>
using FactoryFunction = std::function<T ()>;

template<typename T>
using ComputeFunction = std::function<T (const T& t)>;

template<typename T>
using DispatchFunction = std::function<void (T& t)>;


// Class with Input-Processing-Output
template <typename T>
class TmpProcessor
{ // No inheritance used

private:
    FactoryFunction<T> _factory;
    ComputeFunction<T> _compute;
    DispatchFunction<T> _dispatch;

public:
    TmpProcessor(const FactoryFunction<T>& factory,
                 const ComputeFunction<T>& compute,
                 const DispatchFunction<T>& dispatch)
            : _factory(factory), _compute(compute), _dispatch(dispatch) {}

    // The template method pattern
    virtual void algorithm() final
    {
        T val = _factory();
        T val2 = _compute(val);
        _dispatch(val2);
    }
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_TMPPROCESSOR_HPP

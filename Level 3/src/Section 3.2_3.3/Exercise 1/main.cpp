//
// Illustrate prototypical features and restrictions of atomic operations on shared pointers
//
// Created by Michael Lewis on 7/1/23.
//

#include <atomic>
#include <cassert>
#include <iostream>
#include <memory>
#include <type_traits>

// Example struct provide by lecture material
struct X
{
    double val;

    X() : val(0.0) {}
    void operator ()() const {
        std::cout << "An X " << val << std::endl;
    }
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

int main()
{
    // Part A - Create an instance x of class PointerType and give it a value.
    PointerType x{new X};
    x->val = 3;
    x->operator()();

    // Part B - Create a second instance x2 and atomically store it value in x.
    PointerType x2{new X};
    x2->val = 5;
    // Per CPP Reference:
    // Atomically replaces the value pointed to by obj with the value of desr as if by obj->store(desr)
    // void atomic_store( std::atomic<T>* obj, typename std::atomic<T>::value_type desr )
    std::atomic_store(&x, x2);
    assert(5 == x->val);
    x->operator()();
    x2->operator()();

    // Part C - Create an instance x3 and exchange it with both x and x2.
    PointerType x3{new X};
    x3->val = 7;
    std::atomic_exchange(&x, x3);
    std::atomic_exchange(&x2, x3);
    assert(7 == x->val);
    assert(7 == x2->val);
    x->operator()();
    x2->operator()();
    x3->operator()();

    // Part D - Keep tabs on the use count of these instances.
    assert(3 == x.use_count());
    assert(3 == x2.use_count());
    assert(3 == x3.use_count());

    // Part E - Why is atomic<std::shared_ptr> not possible?
    // According to CPP Reference, atomic<std::shared_ptr> is now possible in C++ 20. However,
    // it was formerly not possible because a shared_ptr is not trivially copyable, which is a precondition
    // of the std::atomic. To show this, we can use the is_trivially_copyable type trait.
    using PTR = std::shared_ptr<double>;
    assert(false == std::is_trivially_copyable<PTR>::value);

    // Part F - Are shared pointers lock-free?
    assert(false == atomic_is_lock_free(&x));
    assert(false == atomic_is_lock_free(&x2));
    assert(false == atomic_is_lock_free(&x3));

    return 0;
}
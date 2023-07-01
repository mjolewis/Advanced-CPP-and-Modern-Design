//
// Illustrate core concepts of std::atomic including creating, checking atomic types, exchanging values,
// and loading values to return the current value of the atomic.
//
// Created by Michael Lewis on 6/30/23.
//

#include <atomic>
#include <cassert>
#include <stdatomic.h>

int main()
{
    // Part A - Create atomic objects of type long long, bool and int.
    // Note the use of C++ 11 type aliases (e.g. replaces std::atomic<long long>, std::atomic<bool>, std::atomic<int>)
    std::atomic_llong l{8ll};
    std::atomic_bool b{true};
    std::atomic_int i{7};

    // Part B - Check if the atomic TYPES are lock free
    assert(atomic_is_lock_free(&l));
    assert(atomic_is_lock_free(&b));
    assert(atomic_is_lock_free(&i));

    // Part C - Atomically replace the value of one atomic object by another atomic object.
    // Note, you can use b.store if you don't need to capture the old value.
    auto result = b.exchange(false);
    assert(true == result);
    assert(false == b.load());

    // Part D - Atomically load an atomic object and return its current value.
    auto l1 = l.load();
    assert(8 == l1);
}
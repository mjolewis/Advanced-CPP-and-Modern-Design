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
    std::atomic<long long> l{8ll};
    std::atomic<bool> b{true};
    std::atomic<int> i{7};

    // Part B - Check if the atomic TYPES are lock free
    assert(atomic_is_lock_free(&l));
    assert(atomic_is_lock_free(&b));
    assert(atomic_is_lock_free(&i));

    // Part C - Atomically replace the value of one atomic object by another atomic object.
    b.exchange(false);
    assert(false == b.load());

    // Part D - Atomically load an atomic object and return its current value.
    auto l1 = l.load();
    assert(8 == l1);
}
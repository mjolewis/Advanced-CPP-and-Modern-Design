//
// Created by Michael Lewis on 7/13/23.
//

#include <algorithm>
#include <cassert>
#include <functional>
#include <tuple>
#include <vector>

using Range = std::tuple<size_t, size_t>;
using Result = std::tuple<Range, bool>;
using Vector = std::vector<int>;
using value_type = int;
using UnaryPredicate = std::function<int (int)>;

// searches for the first and last index that are less than or equal to and greater than the target value
Result find_sequential_greater(const Vector& v, value_type x)
{
    for (std::size_t j = 0; j < v.size(); ++j)
    {
        if (v[j] <= x && v[j+1] > x)
        {
            return std::make_tuple(std::make_tuple(j, j+1), true);
        }
    }
    return std::make_tuple(std::make_tuple(999, 999), false);
}

// find_if searches for an element for which predicate p returns true
std::tuple<long, bool> find_if(const Vector::const_iterator& first, const Vector::const_iterator& last, UnaryPredicate& p)
{
    auto currentIterator = first;
    // The first iterator it in the range [first, last) satisfying predicate or last if there is no such iterator
    auto it = std::find_if(currentIterator, last, p);
    auto index = std::distance(first, it);
    if (it == last) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// find searches for an element equal to value (using operator==)
std::tuple<long, bool> find(const Vector::const_iterator& first, const Vector::const_iterator& last, int value)
{
    auto currentIterator = first;
    auto it = std::find(currentIterator, last, value);
    auto index = std::distance(first, it);
    if (it == last) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// Search for first element x such that i ≤ x
std::tuple<long, bool> lower_bound(const Vector::const_iterator& first, const Vector::const_iterator& last, int value)
{
    auto currentIterator = first;
    auto it = std::lower_bound(currentIterator, last, value);
    auto index = std::distance(first, it);
    if (it == last) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// Search first element that is greater than value
std::tuple<long, bool> upper_bound(const Vector::const_iterator& first, const Vector::const_iterator& last, int value)
{
    auto currentIterator = first;
    auto it = std::upper_bound(currentIterator, last, value);
    auto index = std::distance(first, it);
    if (it == last) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// Returns a range containing all elements equivalent to value in the range [first, last).
// The range is the first index of the element that is not less than value and the second is the index
// of the first element greater than value.
Result equal_range(const Vector::const_iterator& first, const Vector::const_iterator& last, int value)
{
    auto currentIterator = first;
    // Returns a range containing all elements equivalent to value in the range [first, last).
    auto pair = std::equal_range(currentIterator, last, value);
    size_t index1 = std::distance(first, pair.first);
    size_t index2 = std::distance(first, pair.second);
    if (pair.first != last && pair.second != last)
    {
        return std::make_tuple(std::make_tuple(index1, index2), true);
    }

    return std::make_tuple(std::make_tuple(index1, index2), false);
}

// find_if_not searches for an element for which predicate q returns false
std::tuple<long, bool> find_if_not(const Vector::const_iterator& first, const Vector::const_iterator& last, UnaryPredicate& p)
{
    auto currentIterator = first;
    auto it = std::find_if_not(currentIterator, last, p);
    auto index = std::distance(first, it);
    if (it == last) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// Test functionality for finding the first and last index that are less than or equal to and greater than the target value
void test_find_sequential_greater()
{
    Vector v1{1, 2, 3, 3, 5};
    value_type target = 3;
    Result result = find_sequential_greater(v1, target);
    auto first = std::get<0>(std::get<0>(result));
    auto second = std::get<1>(std::get<0>(result));
    auto found = std::get<1>(result);
    assert(3 == first);
    assert(4 == second);
    assert(found);
}

// Test functionality for finding a target value as specified by a given predicate
void test_find_if()
{
    Vector v1{1, 2, 3, 3, 5};
    UnaryPredicate p = [](int element) -> bool { return element == 5; };
    auto result = find_if(v1.cbegin(), v1.cend(), p);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(4 == index);
    assert(found);

    p = [](int element) -> bool { return element == 10; };
    result = find_if(v1.cbegin(), v1.cend(), p);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(std::distance(v1.cbegin(), v1.cend()) == index);
    assert(!found);
}

// Test functionality for finding a target value
void test_find()
{
    Vector v1{1, 2, 3, 3, 5};
    value_type target = 3;
    auto result = find(v1.cbegin(), v1.cend(), target);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(2 == index);
    assert(found);

    target = 19;
    result = find(v1.cbegin(), v1.cend(), target);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(5 == index);
    assert(!found);
}

// Test functionality for finding the lower bound
void test_lower_bound()
{
    Vector v1{1, 2, 3, 3, 5};
    value_type target = 2;
    auto result = lower_bound(v1.cbegin(), v1.cend(), target);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(1 == index);
    assert(found);

    target = 19;
    result = find(v1.cbegin(), v1.cend(), target);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(5 == index);
    assert(!found);
}

// Test functionality for finding the upper bound
void test_upper_bound()
{
    Vector v1{1, 2, 3, 3, 5};
    value_type target = 2;
    auto result = upper_bound(v1.cbegin(), v1.cend(), target);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(2 == index);
    assert(found);

    target = 19;
    result = find(v1.cbegin(), v1.cend(), target);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(5 == index);
    assert(!found);
}

// Test functionality for finding a range of indices where the elements equal the specified value
void test_equal_range()
{
    Vector v1{1, 2, 2, 2, 5};
    value_type target = 2;
    Result result = equal_range(v1.cbegin(), v1.cend(), target);
    auto first = std::get<0>(std::get<0>(result));
    auto second = std::get<1>(std::get<0>(result));
    auto found = std::get<1>(result);
    assert(1 == first);
    assert(4 == second);
    assert(found);

    target = 19;
    result = equal_range(v1.cbegin(), v1.cend(), target);
    first = std::get<0>(std::get<0>(result));
    second = std::get<1>(std::get<0>(result));
    found = std::get<1>(result);
    assert(5 == first);
    assert(5 == second);
    assert(!found);
}

// Test functionality for finding indeces where the specified predicate is false
void test_find_if_not()
{
    Vector v1{1, 2, 3, 3, 5};
    UnaryPredicate p = [](int element) -> bool { return element == 5; };
    auto result = find_if_not(v1.cbegin(), v1.cend(), p);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(0 == index);
    assert(found);

    p = [](int element) -> bool { return true; };
    result = find_if_not(v1.cbegin(), v1.cend(), p);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(std::distance(v1.cbegin(), v1.cend()) == index);
    assert(!found);
}

int main()
{
    test_find_sequential_greater();
    test_find_if();
    test_find();
    test_lower_bound();
    test_upper_bound();
    test_equal_range();
    test_find_if_not();
}
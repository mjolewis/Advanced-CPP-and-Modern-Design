//
// Exemplar tests that illustrate how to use several key searching algorithms as provided by the standard
// template algorithms library in conjunction with Boost ublas.
//
// Created by Michael Lewis on 7/31/23.
//

#include <cstddef>
#include <functional>
#include <tuple>
#include <vector>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

using Range = std::tuple<size_t, size_t>;
using Result = std::tuple<Range, bool>;
using Vector = vector<int>;
using value_type = int;
using UnaryPredicate = std::function<int (int)>;

// find searches for an element equal to value (using operator==)
std::tuple<long, bool> find(const Vector& v, int value)
{
    auto currentIterator = v.cbegin();
    auto it = std::find(currentIterator, v.cend(), value);
    auto index = std::distance(v.cbegin(), it);
    if (it == v.cend()) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
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

// searches for the first and last index that are less than or equal to and greater than the target value
Result find_sequential_greater(const Vector& v, value_type x)
{
    std::size_t index = 0;
    UnaryPredicate p = [&](int element) -> bool {return element <= x && v[++index] > x; };

    std::tuple<long, bool> result = find_if(v.cbegin(), v.cend(), p);
    index = std::get<0>(result);
    return std::make_tuple(std::make_tuple(index, index + 1), std::get<1>(result));
}

// Search for first element x such that i ≤ x
std::size_t lower_bound(const Vector::const_iterator& first, const Vector::const_iterator& last, int value)
{
    auto currentIterator = first;
    auto it = std::lower_bound(currentIterator, last, value);
    return std::distance(first, it);
}

// Search first element that is greater than value
std::size_t upper_bound(const Vector::const_iterator& first, const Vector::const_iterator& last, int value)
{
    auto currentIterator = first;
    auto it = std::upper_bound(currentIterator, last, value);
    return std::distance(first, it);
}

// searches for the first and last index that are less than or equal to and greater than the target value
Result find_sequential_greater_lower_and_upper_bound(const Vector& v, value_type x)
{
    size_t lowerBound = lower_bound(v.cbegin(), v.cend(), x);
    size_t upperBound = upper_bound(v.cbegin(), v.cend(), x);
    if (upperBound == lowerBound + 1)
    {
        return std::make_tuple(std::make_tuple(lowerBound, upperBound), true);
    }
    return std::make_tuple(std::make_tuple(lowerBound, upperBound), false);
}

// Returns a range containing all elements equivalent to value in the range [first, last).
// The range is the first index of the element that is not less than value and the second is the index
// of the first element greater than value.
Result equal_range(const Vector& v, value_type x)
{
    auto currentIterator = v.cbegin();
    // Returns a range containing all elements equivalent to value in the range [first, last).
    auto pair = std::equal_range(currentIterator, v.cend(), x);
    size_t index1 = std::distance(v.cbegin(), pair.first);
    size_t index2 = std::distance(v.cbegin(), pair.second);
    if (pair.first != v.cend() && pair.second != v.cend())
    {
        return std::make_tuple(std::make_tuple(index1, index2), true);
    }

    return std::make_tuple(std::make_tuple(index1, index2), false);
}

// find_if_not searches for an element for which predicate q returns false
std::tuple<long, bool> find_if_not(const Vector& v, UnaryPredicate& p)
{
    auto currentIterator = v.cbegin();
    auto it = std::find_if_not(currentIterator, v.cend(), p);
    auto index = std::distance(v.cbegin(), it);
    if (it == v.cend()) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// Test functionality for finding a target value
void test_find()
{
    vector<double> v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 4;
    v1(4) = 5;
    value_type target = 3;
    auto result = find(v1, target);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(2 == index);
    assert(found);

    target = 19;
    result = find(v1, target);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(5 == index);
    assert(!found);
}

// Test functionality for finding the first and last index that are less than or equal to and greater than the target value
void test_find_sequential_greater()
{
    vector<double> v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 4;
    v1(4) = 5;
    value_type target = 3;
    Result result = find_sequential_greater(v1, target);
    auto first = std::get<0>(std::get<0>(result));
    auto second = std::get<1>(std::get<0>(result));
    auto found = std::get<1>(result);
    assert(2 == first);
    assert(3 == second);
    assert(found);
}

// Test functionality for finding the first and last index that are less than or equal to and greater than the target value
void test_find_sequential_greater_lower_and_upper_bound()
{
    vector<double> v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 4;
    v1(4) = 5;
    value_type target = 3;
    Result result = find_sequential_greater_lower_and_upper_bound(v1, target);
    auto first = std::get<0>(std::get<0>(result));
    auto second = std::get<1>(std::get<0>(result));
    auto found = std::get<1>(result);
    assert(2 == first);
    assert(3 == second);
    assert(found);
}

// Test functionality for finding the first and last index that are less than or equal to and greater than the target value
void test_equal_range()
{
    vector<double> v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 4;
    v1(4) = 5;
    value_type target = 3;
    Result result = equal_range(v1, target);
    auto first = std::get<0>(std::get<0>(result));
    auto second = std::get<1>(std::get<0>(result));
    auto found = std::get<1>(result);
    assert(2 == first);
    assert(3 == second);
    assert(found);
}

// Test functionality for finding indices where the specified predicate is false
void test_find_if_not()
{
    vector<double> v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 4;
    v1(4) = 5;
    UnaryPredicate p = [](int element) -> bool { return element == 5; };
    auto result = find_if_not(v1, p);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(0 == index);
    assert(found);

    p = [](int element) -> bool { return true; };
    result = find_if_not(v1, p);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(std::distance(v1.cbegin(), v1.cend()) == index);
    assert(!found);
}

int main()
{
    // Part A - Now implement the same functionality using std::find_if. Also create a wrapper for std::find
    test_find();
    test_find_sequential_greater();

    // Part B - Implement the O (log n) algorithms std::lower_bound and std::upper_bound
    // to affect the same functionality as in part a). Again, you need (as always) to create a wrapper function.
    test_find_sequential_greater_lower_and_upper_bound();

    // Part C - Implement the O (log n) algorithm std::equal_range to effect the
    // same functionality as in part b). Again, you need (as always) to create a wrapper function.
    test_equal_range();

    // Part D - Test the algorithm std::find_if_not() on an example of your choice.
    test_find_if_not();

    return 0;
}

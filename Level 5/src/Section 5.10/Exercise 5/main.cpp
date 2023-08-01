//
// Illustrate how to use Policy Based Design via Template-Template Parameter concept.
// Template-Template Parameters allows us to generalize search functions that can be used
// by any vector libraries that are STL-compatible (e.g. STL, ublas, etc). This improves our
// other approach that would otherwise require duplicate libraries specialized for each type
// of vector.
//
// Created by Michael Lewis on 7/31/23.
//

#include <cstddef>
#include <functional>
#include <tuple>
#include <vector>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using Range = std::tuple<size_t, size_t>;
using Result = std::tuple<Range, bool>;
using Vector_Ublas = boost::numeric::ublas::vector<double>;
using Vector_STL = std::vector<double>;
using value_type = double;
using UnaryPredicate = std::function<double (double)>;

// find searches for an element equal to value (using operator==)
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
std::tuple<long, bool> find(const Container<T, TAlloc>& container, T value)
{
    auto currentIterator = container.begin();
    auto end = container.cend();
    auto it = std::find(currentIterator, end, value);
    auto index = std::distance(container.cbegin(), it);
    if (it == end) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// find_if searches for an element for which predicate p returns true
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
std::tuple<long, bool> find_if(const Container<T, TAlloc> container, UnaryPredicate& p)
{
    auto currentIterator = container.cbegin();
    auto end = container.cend();
    // The first iterator it in the range [first, last) satisfying predicate or last if there is no such iterator
    auto it = std::find_if(currentIterator, end, p);
    auto index = std::distance(container.cbegin(), it);
    if (it == end) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// searches for the first and last index that are less than or equal to and greater than the target value
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
Result find_sequential_greater(const Container<T, TAlloc>& container, T x)
{
    std::size_t index = 0;
    UnaryPredicate p = [&](int element) -> bool {return element <= x && container[++index] > x; };

    std::tuple<long, bool> result = find_if(container, p);
    index = std::get<0>(result);
    return std::make_tuple(std::make_tuple(index, index + 1), std::get<1>(result));
}

// Search for first element x such that i ≤ x
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
std::size_t lower_bound(const Container<T, TAlloc>& container, T value)
{
    auto currentIterator = container.cbegin();
    auto it = std::lower_bound(currentIterator, container.cend(), value);
    return std::distance(container.cbegin(), it);
}

// Search first element that is greater than value
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
std::size_t upper_bound(const Container<T, TAlloc>& container, T value)
{
    auto currentIterator = container.cbegin();
    auto it = std::upper_bound(currentIterator, container.cend(), value);
    return std::distance(container.cbegin(), it);
}

// searches for the first and last index that are less than or equal to and greater than the target value
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
Result find_sequential_greater_lower_and_upper_bound(const Container<T, TAlloc>& container, T value)
{
    size_t lowerBound = lower_bound(container, value);
    size_t upperBound = upper_bound(container, value);
    if (upperBound > lowerBound)
    {
        return std::make_tuple(std::make_tuple(lowerBound, upperBound), true);
    }
    return std::make_tuple(std::make_tuple(lowerBound, upperBound), false);
}

// Returns a range containing all elements equivalent to value in the range [first, last).
// The range is the first index of the element that is not less than value and the second is the index
// of the first element greater than value.
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
Result equal_range(const Container<T, TAlloc>& container, T value)
{
    auto begin = container.cbegin();
    auto currentIterator = container.cbegin();
    auto end = container.cend();
    // Returns a range containing all elements equivalent to value in the range [first, last).
    auto pair = std::equal_range(currentIterator, end, value);
    size_t index1 = std::distance(begin, pair.first);
    size_t index2 = std::distance(begin, pair.second);
    if (pair.first != end && pair.second != end)
    {
        return std::make_tuple(std::make_tuple(index1, index2), true);
    }

    return std::make_tuple(std::make_tuple(index1, index2), false);
}

// find_if_not searches for an element for which predicate q returns false
template<typename T, template<typename S, typename Alloc> class Container, typename TAlloc>
std::tuple<long, bool> find_if_not(const Container<T, TAlloc>& container, UnaryPredicate& p)
{
    auto begin = container.cbegin();
    auto currentIterator = container.cbegin();
    auto end = container.cend();
    auto it = std::find_if_not(currentIterator, end, p);
    auto index = std::distance(begin, it);
    if (it == end) return std::make_tuple(index, false);
    return std::make_tuple(index, true);
}

// Test functionality for finding a target value
void test_find()
{
    Vector_Ublas v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 3;
    v1(4) = 5;
    value_type target = 3;
    auto result = find(v1, target);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(2 == index);
    assert(found);

    Vector_STL v2{1, 2, 3, 3, 5};
    result = find(v2, target);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(2 == index);
    assert(found);
}

// Test functionality for finding the first and last index that are less than or equal to and greater than the target value
void test_find_sequential_greater()
{
    Vector_Ublas v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 3;
    v1(4) = 5;
    value_type target = 3;
    Result result = find_sequential_greater(v1, target);
    auto first = std::get<0>(std::get<0>(result));
    auto second = std::get<1>(std::get<0>(result));
    auto found = std::get<1>(result);
    assert(3 == first);
    assert(4 == second);
    assert(found);

    Vector_STL v2{1, 2, 3, 3, 5};
    result = find_sequential_greater(v2, target);
    first = std::get<0>(std::get<0>(result));
    second = std::get<1>(std::get<0>(result));
    found = std::get<1>(result);
    assert(3 == first);
    assert(4 == second);
    assert(found);
}

// Test functionality for finding the first and last index that are less than or equal to and greater
// than the target value
// Note - std::lower_bound requires that the element is strictly less than the target. This differs from
// the approach outlined in the homework material for find_sequential_greater_than where we provide our own
// evaluation criteria and the lower bound is set to be less than or equal. As a result, the range below is
// slightly different due to this other specification provided by the homework material (see 4.2.1 homework)
void test_find_sequential_greater_lower_and_upper_bound()
{
    Vector_Ublas v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 3;
    v1(4) = 5;
    value_type target = 3;
    Result result = find_sequential_greater_lower_and_upper_bound(v1, target);
    auto first = std::get<0>(std::get<0>(result));
    auto second = std::get<1>(std::get<0>(result));
    auto found = std::get<1>(result);
    assert(2 == first);
    assert(4 == second);
    assert(found);

    Vector_STL v2{1, 2, 3, 3, 5};
    result = find_sequential_greater_lower_and_upper_bound(v2, target);
    first = std::get<0>(std::get<0>(result));
    second = std::get<1>(std::get<0>(result));
    found = std::get<1>(result);
    assert(2 == first);
    assert(4 == second);
    assert(found);
}

// Test functionality for finding the first and last index that are less than or equal to and greater
// than the target value
// Note - std::equal_range is implemented with std::lower_bound and std::upper_bound, which requires that the
// element is strictly less than the target.
void test_equal_range()
{
    Vector_Ublas v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 3;
    v1(4) = 5;
    value_type target = 3;
    Result result = equal_range(v1, target);
    auto first = std::get<0>(std::get<0>(result));
    auto second = std::get<1>(std::get<0>(result));
    auto found = std::get<1>(result);
    assert(2 == first);
    assert(4 == second);
    assert(found);

    Vector_STL v2{1, 2, 3, 3, 5};
    result = equal_range(v2, target);
    first = std::get<0>(std::get<0>(result));
    second = std::get<1>(std::get<0>(result));
    found = std::get<1>(result);
    assert(2 == first);
    assert(4 == second);
    assert(found);
}

// Test functionality for finding indices where the specified predicate is false
void test_find_if_not()
{
    Vector_Ublas v1{5};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 3;
    v1(4) = 5;
    UnaryPredicate p = [](int element) -> bool { return element == 5; };
    auto result = find_if_not(v1, p);
    auto index = std::get<0>(result);
    auto found = std::get<1>(result);
    assert(0 == index);
    assert(found);

    Vector_STL v2{1, 2, 3, 3, 5};
    result = find_if_not(v2, p);
    index = std::get<0>(result);
    found = std::get<1>(result);
    assert(0 == index);
    assert(found);
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

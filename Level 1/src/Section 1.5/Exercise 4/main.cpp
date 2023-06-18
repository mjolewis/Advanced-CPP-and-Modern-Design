//
// Created by Michael Lewis on 6/7/23.
//

#include <algorithm>
#include <optional>
#include <numeric>
#include <vector>

/**
 * Find the index that is less than or equal to a target only
 * if the target is also less than the value at index + 1.
 *
 * Based on the conversation in https://quantnet.com/threads/exercise-4-must-use-std-find-and-distance.24844/
 * I believe we can use a different approach other than std::find and std::distance. As a result,
 * I chose std::find_if because this algorithm allows me to pass in a custom predicate that
 * will satisfy the condition. This simplifies the code versus having to use two algorithms to do
 * one task.
 */
template<typename Container, typename T>
auto findByPredicate(const Container& container, T target)
{
    auto it = container.cbegin();
    auto end = container.cend();

    // Track the current index while validating the predicate
    int idx = -1;
    auto test = [&] (T value) -> T {
        ++idx;
        return value <= target && target < *(++it);
    };

    // Return the index if the predicate is satisfied. Otherwise, return final element in the vector
    return (std::find_if(it, end, test) != end) ? std::optional<T>(idx) : *--end;
}

/**
 * Calculate the maximum and relative error between two vectors.
 * Return the values as a std::tuple
 */
template<typename Container, typename T>
auto getErrors(Container first, Container second, int startIdx, int endIdx)
{
    if (first.size() != second.size()) throw std::invalid_argument("Input vectors should be same size");

    Container distances;
    auto currentIdx = startIdx;
    for (currentIdx; currentIdx <= endIdx; ++currentIdx)
    {
        // std::move saves two operations:
        // The copy constructor and destructor for the temporary value don't need to be invoked
        distances.push_back(std::move(std::abs(first.at(currentIdx) - second.at(currentIdx))));
    }

    // Find the index of the max norm in the resulting vector
    const auto& maxNorm = std::max_element(distances.cbegin(), distances.cend());

    Container indices;
    for (int i = 0; i < distances.size(); ++i)
    {
        if (distances.at(i) == *maxNorm) indices.push_back(std::move(i));
    }

    // Calculate relative error
    auto relativeError = *maxNorm / first.at(indices.at(0));

    return std::make_tuple(*maxNorm, relativeError, indices);
}

/**
 * Test cases for finding a value that satisfies a specified predicate
 */
void test_findByPredicate()
{
    std::vector<int> vec1{1, 2, 3, 4, 5};
    auto optionalIndex1 = findByPredicate<std::vector<int>, int>(vec1, 3);
    assert(2 == optionalIndex1.value());

    std::vector<int> vec2{1, 1, 2, 3, 4};
    auto optionalIndex2 = findByPredicate<std::vector<int>, int>(vec2, 1);
    assert(1 == optionalIndex2.value());

    std::vector<int> vec3{1, 1, 2, 2, 4};
    auto optionalIndex3 = findByPredicate<std::vector<int>, int>(vec3, 2);
    assert(3 == optionalIndex3.value());

    std::vector<int> vec4{1, 3, 5, 8, 9};
    auto optionalIndex4 = findByPredicate<std::vector<int>, int>(vec4, 6);
    assert(2 == optionalIndex4.value());

    std::vector<int> vec5{1, 2, 3, 4, 5};
    auto optionalIndex5 = findByPredicate<std::vector<int>, int>(vec5, 8);
    assert(5 == optionalIndex5.value());
}

/**
 * Test cases for finding max error and relative error of two vectors
 */
void test_maximumError()
{
    std::vector<double> v1{1.0, 2.5, 3.5, 4.5, 6.0, 10.0, 11.25 };
    std::vector<double> v2{2.5, 3.5, 4.0, 4.25, 5.0, 7.5, 10.5};
    auto result = getErrors<std::vector<double>, double>(v1, v2, 2, 6);
    assert(2.5 == std::get<0>(result));
    assert(2.5 / 4.5 == std::get<1>(result));
    assert(3 == std::get<2>(result).at(0));

    // Test results where the vectors have the same max error. Results should include all indices
    std::vector<double> v3{4, 5, 6};
    std::vector<double> v4{7, 8, 9};
    result = getErrors<std::vector<double>, double>(v3, v4, 0, 2);
    assert(3 == std::get<0>(result));
    assert(0.75 == std::get<1>(result));
    assert(0 == std::get<2>(result).at(0));
    assert(1 == std::get<2>(result).at(1));
    assert(2 == std::get<2>(result).at(2));
}

int main()
{
    test_findByPredicate();
    test_maximumError();
    return 0;
}
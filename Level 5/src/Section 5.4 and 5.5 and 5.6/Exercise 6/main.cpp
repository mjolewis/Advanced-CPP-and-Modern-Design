//
// Illustrate how to examine attributes of an unordered set filled with user defined types
//
// Created by Michael Lewis on 7/27/23.
//

#include <cstddef>
#include <iostream>
#include <unordered_set>

#include "Order.hpp"
#include "Point.hpp"

// An interface to inspect properties of an std::unordered_set
template <typename Key, typename Hash, typename EqPred>
void BucketInformation(const std::unordered_set<Key, Hash, EqPred>& c)
{
    // Part A - Show the number of buckets and the maximum number of possible buckets.
    std::size_t numBuckets = c.bucket_count();
    std::cout << "Number of buckets:" << numBuckets << std::endl;

    std::size_t maxBuckets = c.max_bucket_count();
    std::cout << "Max number of buckets:" << maxBuckets << std::endl;

    // Part B - Show current load factor and the current maximum load factor.
    float loadFactor = c.load_factor();
    std::cout << "Load factor:" << loadFactor << std::endl;

    float maxLoadFactor = c.max_load_factor();
    std::cout << "Max load factor:" << maxLoadFactor << std::endl;

    // Part C - Show the size of each bucket
    for (int i = 0; i < numBuckets; ++i)
    {
        std::size_t bucketSize = c.bucket_size(i);
        std::cout << "Bucket size:" << bucketSize << std::endl;
    }
}

int main()
{
    std::cout << "\n*** Adding Points to Unordered Set ***" << std::endl;

    // Part A - Add elements to this unordered set.
    std::unordered_set<Point, Point, Point> points;
    points.insert(Point{1, 1});
    points.insert(Point{2, 2});
    points.insert(Point{3, 3});
    points.insert(Point{4, 4});
    points.insert(Point{5, 5});
    points.insert(Point{6, 6});

    // Part B - Examine the bucket information for this unordered set.
    BucketInformation(points);

    // Now test for Orders
    std::cout << "\n*** Adding Points to Unordered Set ***" << std::endl;

    std::unordered_set<Order, Order, Order> orders;
    orders.insert(Order{1l, 'D', 1, 173.43, 1000.0});
    orders.insert(Order{2l, 'D', 1, 17.43, 850.0});
    orders.insert(Order{3l, 'D', 1, 23.00, 10000.0});
    orders.insert(Order{4l, 'D', 1, 77.00, 11111.0});

    BucketInformation(orders);

    return 0;
}
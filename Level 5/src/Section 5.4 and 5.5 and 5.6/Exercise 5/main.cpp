//
// Created by Michael Lewis on 7/27/23.
//

#include <cstddef>
#include <iostream>
#include <functional>
#include <unordered_set>

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
    for (auto bucket : c)
    {
        std::size_t bucketSize = c.bucket_size(bucket);
        std::cout << "Bucket size:" << bucketSize << std::endl;
    }
}


int main()
{
    std::unordered_set<int, std::hash<int>, std::equal_to<>> set{1, 1, 2, 3, 4, 5, 6};
    BucketInformation(set);

    // Part D - Rehash the container so that it has a bucket size of at least some given size.
    set.rehash(24);
    std::cout << "\n *** New Bucket Information after Rehash ***" << std::endl;
    BucketInformation(set);

    return 0;
}
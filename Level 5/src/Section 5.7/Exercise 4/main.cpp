//
// Illustrate how to use bimap with multiple different collection types and custom comparators
//
// Created by Michael Lewis on 7/28/23.
//

#include <iostream>
#include <functional>
#include <string>

#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>

// using namespace to improve code readability
using namespace boost::bimaps;

// Part A and B - Create Bimamps and print their contents
void test_bimaps_and_default_comparators()
{
    // Part A - Create bimaps where
    // Domain is: Set, Multiset, Unordered set
    // Range is:  Set, Multiset, Unordered set
    typedef bimap<set_of<std::string>, set_of<double>> SetToSet;
    typedef bimap<set_of<std::string>, multiset_of<double>> SetToMultiSet;
    typedef bimap<set_of<std::string>, unordered_set_of<double>> SetToUnorderedSet;

    typedef bimap<multiset_of<std::string>, set_of<double>> MultiSetToSet;
    typedef bimap<multiset_of<std::string>, multiset_of<double>> MultiSetToMultiSet;
    typedef bimap<multiset_of<std::string>, unordered_set_of<double>> MultiSetToUnorderedSet;

    typedef bimap<unordered_set_of<std::string>, set_of<double>> UnorderedSetToSet;
    typedef bimap<unordered_set_of<std::string>, multiset_of<double>> UnorderedSetToMultiset;
    typedef bimap<unordered_set_of<std::string>, unordered_set_of<double>> UnorderedSetToUnorderedSet;

    // Part B - Create instances of each bimap shown above and print their values
    typedef SetToSet::value_type Bm1;
    typedef SetToMultiSet::value_type Bm2;
    typedef SetToUnorderedSet::value_type Bm3;
    typedef MultiSetToSet::value_type Bm4;
    typedef MultiSetToMultiSet::value_type Bm5;
    typedef MultiSetToUnorderedSet::value_type Bm6;
    typedef UnorderedSetToSet::value_type Bm7;
    typedef UnorderedSetToMultiset::value_type Bm8;
    typedef UnorderedSetToUnorderedSet::value_type Bm9;

    SetToSet setToSet;
    setToSet.insert(Bm1("setToSet", 1));
    for (SetToSet::const_iterator it = setToSet.begin(), end = setToSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    SetToMultiSet setToMultiSet;
    setToMultiSet.insert(Bm2("setToMultiSet", 2));
    for (SetToMultiSet::const_iterator it = setToMultiSet.begin(), end = setToMultiSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    SetToUnorderedSet setToUnorderedSet;
    setToUnorderedSet.insert(Bm3("SetToUnorderedSet", 3));
    for (SetToUnorderedSet::const_iterator it = setToUnorderedSet.begin(), end = setToUnorderedSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    MultiSetToSet multiSetToSet;
    multiSetToSet.insert(Bm4("MultiSetToSet", 4));
    for (MultiSetToSet::const_iterator it = multiSetToSet.begin(), end = multiSetToSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    MultiSetToMultiSet multiSetToMultiSet;
    multiSetToMultiSet.insert(Bm5("MultiSetToMultiSet", 5));
    for (MultiSetToMultiSet::const_iterator it = multiSetToMultiSet.begin(), end = multiSetToMultiSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    MultiSetToUnorderedSet multiSetToUnorderedSet;
    multiSetToUnorderedSet.insert(Bm6("MultiSetToUnorderedSet", 6));
    for (MultiSetToUnorderedSet::const_iterator it = multiSetToUnorderedSet.begin(), end = multiSetToUnorderedSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    UnorderedSetToSet unorderedSetToSet;
    unorderedSetToSet.insert(Bm7("UnorderedSetToSet", 7));
    for (UnorderedSetToSet::const_iterator it = unorderedSetToSet.begin(), end = unorderedSetToSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    UnorderedSetToMultiset unorderedSetToMultiset;
    unorderedSetToMultiset.insert(Bm8("UnorderedSetToMultiset", 8));
    for (UnorderedSetToMultiset::const_iterator it = unorderedSetToMultiset.begin(), end = unorderedSetToMultiset.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    UnorderedSetToUnorderedSet unorderedSetToUnorderedSet;
    unorderedSetToUnorderedSet.insert(Bm9("UnorderedSetToUnorderedSet", 9));
    for (UnorderedSetToUnorderedSet::const_iterator it = unorderedSetToUnorderedSet.begin(), end = unorderedSetToUnorderedSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }
}

// Part C - Modify the code in part b) to support different kinds of comparitors (for example, std::greater<>)
void test_bimaps_and_custom_comparators()
{
    std::cout << "\n\n*** Starting Part C ***" << std::endl;

    typedef bimap<set_of<std::string, std::greater<>>, set_of<double, std::greater<>>> SetToSet;
    typedef bimap<set_of<std::string, std::greater<>>, multiset_of<double, std::greater<>>> SetToMultiSet;
    typedef bimap<set_of<std::string, std::greater<>>, unordered_set_of<double>> SetToUnorderedSet;

    typedef bimap<multiset_of<std::string, std::greater<>>, set_of<double, std::greater<>>> MultiSetToSet;
    typedef bimap<multiset_of<std::string, std::greater<>>, multiset_of<double, std::greater<>>> MultiSetToMultiSet;
    typedef bimap<multiset_of<std::string, std::greater<>>, unordered_set_of<double>> MultiSetToUnorderedSet;

    typedef bimap<unordered_set_of<std::string>, set_of<double>> UnorderedSetToSet;
    typedef bimap<unordered_set_of<std::string>, multiset_of<double>> UnorderedSetToMultiset;
    typedef bimap<unordered_set_of<std::string>, unordered_set_of<double>> UnorderedSetToUnorderedSet;

    // Part B - Create instances of each bimap shown above and print their values
    typedef SetToSet::value_type Bm1;
    typedef SetToMultiSet::value_type Bm2;
    typedef SetToUnorderedSet::value_type Bm3;
    typedef MultiSetToSet::value_type Bm4;
    typedef MultiSetToMultiSet::value_type Bm5;
    typedef MultiSetToUnorderedSet::value_type Bm6;
    typedef UnorderedSetToSet::value_type Bm7;
    typedef UnorderedSetToMultiset::value_type Bm8;
    typedef UnorderedSetToUnorderedSet::value_type Bm9;

    SetToSet setToSet;
    setToSet.insert(Bm1("setToSet1", 1));
    setToSet.insert(Bm1("setToSet2", 11));
    for (SetToSet::const_iterator it = setToSet.begin(), end = setToSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    SetToMultiSet setToMultiSet;
    setToMultiSet.insert(Bm2("setToMultiSet1", 2));
    setToMultiSet.insert(Bm2("setToMultiSet2", 22));
    for (SetToMultiSet::const_iterator it = setToMultiSet.begin(), end = setToMultiSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    SetToUnorderedSet setToUnorderedSet;
    setToUnorderedSet.insert(Bm3("SetToUnorderedSet1", 3));
    setToUnorderedSet.insert(Bm3("SetToUnorderedSet2", 33));
    for (SetToUnorderedSet::const_iterator it = setToUnorderedSet.begin(), end = setToUnorderedSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    MultiSetToSet multiSetToSet;
    multiSetToSet.insert(Bm4("MultiSetToSet1", 4));
    multiSetToSet.insert(Bm4("MultiSetToSet2", 44));
    for (MultiSetToSet::const_iterator it = multiSetToSet.begin(), end = multiSetToSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    MultiSetToMultiSet multiSetToMultiSet;
    multiSetToMultiSet.insert(Bm5("MultiSetToMultiSet1", 5));
    multiSetToMultiSet.insert(Bm5("MultiSetToMultiSet2", 55));
    for (MultiSetToMultiSet::const_iterator it = multiSetToMultiSet.begin(), end = multiSetToMultiSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    MultiSetToUnorderedSet multiSetToUnorderedSet;
    multiSetToUnorderedSet.insert(Bm6("MultiSetToUnorderedSet1", 6));
    multiSetToUnorderedSet.insert(Bm6("MultiSetToUnorderedSet2", 66));
    for (MultiSetToUnorderedSet::const_iterator it = multiSetToUnorderedSet.begin(), end = multiSetToUnorderedSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    UnorderedSetToSet unorderedSetToSet;
    unorderedSetToSet.insert(Bm7("UnorderedSetToSet1", 7));
    unorderedSetToSet.insert(Bm7("UnorderedSetToSet2", 77));
    for (UnorderedSetToSet::const_iterator it = unorderedSetToSet.begin(), end = unorderedSetToSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    UnorderedSetToMultiset unorderedSetToMultiset;
    unorderedSetToMultiset.insert(Bm8("UnorderedSetToMultiset1", 8));
    unorderedSetToMultiset.insert(Bm8("UnorderedSetToMultiset2", 88));
    for (UnorderedSetToMultiset::const_iterator it = unorderedSetToMultiset.begin(), end = unorderedSetToMultiset.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }

    UnorderedSetToUnorderedSet unorderedSetToUnorderedSet;
    unorderedSetToUnorderedSet.insert(Bm9("UnorderedSetToUnorderedSet1", 9));
    unorderedSetToUnorderedSet.insert(Bm9("UnorderedSetToUnorderedSet2", 99));
    for (UnorderedSetToUnorderedSet::const_iterator it = unorderedSetToUnorderedSet.begin(), end = unorderedSetToUnorderedSet.end(); it != end; ++it)
    {
        std::cout << it->left << "<--->" << it->right << std::endl;
    }
}

int main()
{
    test_bimaps_and_default_comparators();
    test_bimaps_and_custom_comparators();

    return 0;
}
//
// Simple illustration of how to use boost::bimap
//
// Created by Michael Lewis on 7/28/23.
//

#include <iostream>
#include <string>

#include <boost/bimap.hpp>

typedef boost::bimap<std::string, int> people;
typedef people::value_type position;

int main()
{
    // Setup - create a bimap representing people/persons (a pair consisting of a string (name) and an integer (age)).
    boost::bimap<std::string, int> people;

    // Part A - Populate the bimap with some names using insert(). Does C++11 emplace() work with Bimap?
//    people.emplace("Michael", 30); emplace is not a function on a bimap
    people.insert(position("Michael", 30));
    people.insert(position("Avi", 31));
    people.insert(position("Andy", 32));

    // Part B - Print the left and right maps of the bimap (first and second views).
    for (auto it = people.begin(), end = people.end(); it != end; ++it)
    {
        std::cout << it->left << " --> " << it->right << std::endl;
    }

    for (auto it = people.begin(), end = people.end(); it != end; ++it)
    {
        std::cout << it->right << " --> " << it->left << std::endl;
    }

    // Part C - Search for age based on name and search for name based on age.
    // Use function at(). Take exception handling into consideration.
    std::cout << "Age of Michael is:" << people.left.at("Michael") << std::endl;
    std::cout << "Name of person aged 31:" << people.right.at(31) << std::endl;

    // Part D - Iterate in the bimap using the third view (that is, a set of relations).
    for(auto it = people.begin(), iend = people.end(); it != iend; ++it )
    {
        std::cout << it->left << " <--> " << it->right << std::endl;
    }

    return 0;
}
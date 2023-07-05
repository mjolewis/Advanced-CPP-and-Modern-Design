//
// Illustrate standard functionality of a std::forward_list. This container differs from a std::list
// in that it is backed by a singly-linked list whereas std::list is backed by a doubly-linked list.
// This implies that there is less overhead with a std::forward_list so long as you don't need to traverse
// backwards in your algorithm.
//
// Created by Michael Lewis on 7/4/23.
//

#include <iostream>
#include <forward_list>
#include <iterator>

// Find the size of the given forward list
template<typename T>
long size(const std::forward_list<T>& list)
{
    return std::distance(list.cbegin(), list.cend());
}

// Erase elements in the forward list after a specified position
template<typename T>
void eraseAfter(std::forward_list<T>& list, int position)
{
    int curPos = 0;
    auto curIt = list.cbegin();
    while (curPos <= position)
    {
        curIt = ++curIt;
        ++curPos;
    }

    list.erase_after(curIt);
}

// Erase the elements following first until last.
template<typename T>
void eraseAfter(std::forward_list<T>& list,
                typename std::forward_list<T>::const_iterator& first, typename std::forward_list<T>::const_iterator& last)
{
    list.erase_after(first, last);
}

int main()
{
    // Part A - Create default list, a list with n elements and a given value,
    // and a list that is built from an initializer list (two forms).

    std::forward_list<double> fl1{}; // default list
    std::forward_list<double> fl2(4, 1);  // four copies of the number 1
    std::forward_list<double> fl3{std::initializer_list<double>{1, 2, 3, 4}}; // Initializer list
    std::forward_list<double> fl4{1, 2, 3, 4}; // Initializer list

    // Part B - Forward lists have no member functions to give their size.
    // Write you own function in terms of std::distance().
    long distance = std::distance(fl4.cbegin(), fl4.cend());
    long d1 = size(fl1);
    long d2 = size(fl2);
    long d3 = size(fl3);
    long d4 = size(fl4);

    std::cout << "Size of fl1=" << d1 << std::endl;
    std::cout << "Size of fl2=" << d2 << std::endl;
    std::cout << "Size of fl3=" << d3 << std::endl;
    std::cout << "Size of fl4=" << d4 << std::endl;

    // Part C -  Create code to insert values after a given position based on value,
    // value and a count, two iterators and initializer list.
    // The code makes direct calls to std::forward_list::insert_after.
    fl4.insert_after(fl4.cbegin(), 5.0);
    fl4.insert_after(fl4.cbegin(), 2, 6.0);
    fl4.insert_after(fl4.cbegin(), fl2.cbegin(), fl2.cend());
    fl4.insert_after(fl4.cbegin(), {11.0, 12.0});

    // Expected output = 1, 11, 12, 1, 1, 1, 6, 6, 5, 1, 2, 3, 4
    for (auto element : fl4) std::cout << element << ", ";
    std::cout << "\n" << std::endl;

    // Part D - Create functions to erase values after a given position.
    eraseAfter<double>(fl4, 5);  // Removes element at index 6
    for (auto element : fl4)
    {
        std::cout << element << ", ";
    }
    std::cout << "\n" << std::endl;

    // Part D - Create functions to erase values in a range of iterators.
    auto first = ++fl4.cbegin();
    auto last = fl4.cend();
    eraseAfter<double>(fl4, first, last); // leave only the first two elements
    for (auto element : fl4)
    {
        std::cout << element << ", ";
    }

    // Part E - Create examples to show how splice works
    auto pos = ++fl4.cbegin();

    // Move elements from fl3 into fl4 after the specified position
    fl4.splice_after(pos, fl3);

    // Moves elements from fl2 into fl4 after the specified position. The elements moved are those after
    // the specified iterator associated with fl2.
    fl4.splice_after(pos, fl2, ++fl2.cbegin());

    std::forward_list<double> fl5{99, 99, 99}; // Initializer list
    // Moves elements from fl5 into fl4 after the specified position. The elements moved are those within
    // the specified range of iterators associated with fl5 e.g. (begin, end).
    fl4.splice_after(pos, fl5, ++fl5.cbegin(), fl5.cend());

    std::cout << "\n" << std::endl;
    for (auto element : fl4)
    {
        std::cout << element << ", ";
    }

    // Part E - Show how merge functionality works.
    // Note, it's job is to merge two sorted lists. If we don't provide a comparator,
    // we need to sort the lists manually. Otherwise, the merge will merge the elements
    // from the *other list into this list directly before the first element that is larger
    // than the first element in *this list. For example, list1 = {3,4,7} list2={6,99,4}
    // would result in {3,4,6,7,99,4} without being sorted first.
    std::forward_list<double> fl6{3,4,7}; // Initializer list
    std::forward_list<double> fl7{6,99,4}; // Initializer list
    fl6.sort();
    fl7.sort();
    fl6.merge(fl7);
    std::cout << "\n" << std::endl;
    for (auto element : fl6)
    {
        std::cout << element << ", ";
    }

    // Provide a custom Comparator that compares each element and merges based on whichever
    // element is greater
    std::forward_list<double> fl8{3,5,7}; // Initializer list
    std::forward_list<double> fl9{6,99,4}; // Initializer list
    fl8.sort();
    fl9.sort();
    fl8.merge(fl9, [](double& lhs, double& rhs) -> bool {return lhs >= rhs;});
    std::cout << "\n" << std::endl;
    for (auto element : fl8)
    {
        std::cout << element << ", ";
    }

    return 0;
}

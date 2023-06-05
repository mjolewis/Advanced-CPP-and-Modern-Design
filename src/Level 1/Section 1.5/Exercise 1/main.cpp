//
// Created by Michael Lewis on 6/3/23.
//

#include <iostream>
#include <span>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "boost/date_time.hpp"

// Alias to a tuple to improve readability
using PersonType = std::tuple<std::string, std::string, boost::gregorian::date>;

/**
 * A tuple capable of constructing multiple Person records
 */
std::tuple<std::string, std::string, boost::gregorian::date> Person(int id)
{
    switch (id)
    {
        case 0: return { "Michael", "Manhattan", boost::gregorian::date{2023, 06, 03} };
        case 1: return { "Avi", "Manhattan", boost::gregorian::date{2023, 06, 03} };
        case 2: return { "Dr. Duffy", "Amsterdam", boost::gregorian::date{2023, 06, 03} };
        default: throw std::invalid_argument("id");
    }
}

/**
 * Variadic template that recursively prints the attributes of a tuple
 */
template<typename Tuple, std::size_t... Is>
void printImpl(const Tuple& t, std::index_sequence<Is...>)
{
    ((std::cout << (Is == 0 ? "\n" : ", ") << std::get<Is>(t)), ...);
}

/**
 * Deduces the size of a tuple and converts it into a sequence from [0,N) and forwards it for printing
 */
template<typename Tuple>
void print(const Tuple& t)
{
    printImpl(t, std::make_index_sequence<std::tuple_size_v<PersonType>>{});
}

/**
 * Simple test to get and modify tuple elements
 */
void test_personTuple()
{
    auto person1 = Person(0);
    std::cout << "Person1 name=" << std::get<0>(person1) << std::endl;
    assert("Michael" == std::get<0>(person1));

    // Modify elements of person1
    std::get<0>(person1) = "Luca";
    std::cout << "Person1 new name=" << std::get<0>(person1) << std::endl;
    assert("Luca" == std::get<0>(person1));
}

/**
 * Print multiple tuples using variadic templates
 *
 * Use std::tuple_size_v to get the size of the tuple
 * instead of having to manually pass in the number of
 * elements in the tuple, which is error prone.
 *
 * Use std::make_index_sequence to convert the size
 * of the tuple into a sequence that can be passed into print
 */
void test_printTuple()
{
    std::cout << "\n*** Unsorted tuple ***";
    for (int i = 0; i < 3; ++i)
    {
        print(Person(i));
    }
}

/**
 * Sort a vector of Tuples where the comparator sorts by the persons name.
 */
void test_sortPersonContainer()
{
    // Create a vector of People using list initialization
    std::vector<PersonType> people = { Person(0), Person(1), Person(2) };

    auto comparator =  [] (const PersonType& person1, const PersonType& person2) -> bool {
        return std::get<0>(person1) < std::get<0>(person2); };

    std::sort(people.begin(), people.end(), comparator);
    std::cout << "\n\n*** Sorted tuple by name ***";
    for (const PersonType& person : people) print(person);
}

/**
 * Create a span view for a vector and array of people.
 *
 * Question: Is a span view read only?
 * Answer: No. A span view doesn't own the memory, so the memory
 * can't be be modified; however, the elements can be modified.
 */
void test_spanView_VectorVsFixedArray()
{
    // Create a vector of People using list initialization
    std::vector<PersonType> peopleVector = { Person(0), Person(1), Person(2) };

    // Create an array of People using list initialization
    std::array<PersonType, 3> peopleArray = { Person(0), Person(1), Person(2) };

    // Create the span view
    std::cout << "\n\n*** Original Vector Span ***";
    std::span<PersonType> vectorSpan(peopleVector);
    for (auto& person : vectorSpan) print(person);
    assert("Michael" ==  std::get<0>(vectorSpan[0]));

    // Modify the span view
    std::cout << "\n\n*** Modified Vector Span ***";
    vectorSpan[0] = Person(1);
    for (auto& person : vectorSpan) print(person);
    assert("Avi" == std::get<0>(vectorSpan[0]));

    // Create the span view
    std::cout << "\n\n*** Original Array Span ***";
    std::span<PersonType, 3> arraySpan(peopleArray);
    for (auto& person : arraySpan) print(person);
    assert("Michael" ==  std::get<0>(arraySpan[0]));

    // Modify the span view
    std::cout << "\n\n*** Modified Array Span ***";
    arraySpan[0] = Person(2);
    for (auto& person : arraySpan) print(person);
    assert("Dr. Duffy" == std::get<0>(arraySpan[0]));
}

/**
 * Print contents of a span view using a Range Based loop
 */
template<typename T>
void print_span_rangeBasedLoops(std::span<T> span)
{
    for (auto& element : span) print(element);
}

/**
 * Print contents of a span view using Iterators
 */
template<typename T>
void print_span_iterators(std::span<T> span)
{
    const auto& end = span.end();
    for (auto it = span.begin(); it != end; ++it) print(*it);
}

/**
 * Print contents of a span view using index operator
 */
template<typename T>
void print_span_indexOperator(std::span<T> span)
{
    for (int i = 0; i < span.size(); ++i) print(span[i]);
}

/**
 * A simple test to print span views using different iterating mechanisms
 */
void test_print_spans()
{
    // Create a vector of People using list initialization
    std::vector<PersonType> peopleVector = { Person(0), Person(1), Person(2) };

    // Create a span
    std::span<PersonType> span(peopleVector);

    std::cout << "\n\n*** Print Span: Range Based Loop ***";
    print_span_rangeBasedLoops(span);

    std::cout << "\n\n*** Print Span: Iterators ***";
    print_span_iterators(span);

    std::cout << "\n\n*** Print Span: Index Operator ***";
    print_span_indexOperator(span);
}

/**
 * Returns the last element of the span
 */
template<typename T>
T getLastElement(std::span<T> span)
{
    return span.back();
}

/**
 * Returns the first element of the span
 */
template<typename T>
T getFirstElement(std::span<T> span)
{
    return span.front();
}

/**
 * Get the last element of a tuple
 */
void test_getLastElement()
{
    std::vector<PersonType> people = { Person(0), Person(1), Person(2) };
    std::span<PersonType> span(people);
    auto last = getLastElement(span);
    assert(Person(2) == last);
}

/**
 * Get the first element of a tuple
 */
void test_getFirstElement()
{
    std::vector<PersonType> people = { Person(0), Person(1), Person(2) };
    std::span<PersonType> span(people);
    auto front = getFirstElement(span);
    assert(Person(0) == front);
}

/**
 * Test subspan of Person tuple
 */
void test_subspan()
{
    std::vector<PersonType> people = { Person(0), Person(1), Person(2) };
    std::span<PersonType> s1{people};
    assert(3 == s1.size());
    assert("Michael" == std::get<0>(getFirstElement(s1)));

    std::span<PersonType> s2{s1.subspan(1, s1.size() - 1)};
    assert(2 == s2.size());
    assert("Avi" == std::get<0>(getFirstElement(s2)));
}

/**
 * Helper function to print byte views
 */
void print_byteView(std::span<const std::byte> const bytes)
{
    for (auto const b : bytes)
    {
        std::cout << std::setw(2)
                  << std::hex
                  << std::uppercase
                  << std::setfill('0')
                  << std::to_integer<int>(b) << ' ';
    }
}

/**
 * Create byte views of spans
 */
void test_byteViews()
{
    // Bytes stuff
    float data[1]{ 3.141592f };

    auto const const_bytes = std::as_bytes(std::span{ data });

    std::cout << "\n\nByte View" << std::endl;
    print_byteView(const_bytes);

    // Bytes with doubles
    auto const writable_bytes = std::as_writable_bytes(std::span{ data });

    // Change the sign bit that is the MSB (IEEE 754 Floating-Point Standard).
    writable_bytes[3] |= std::byte{ 0b1000'0000 };

    std::cout << "\n\nWritable Byte View" << std::endl;
    print_byteView(writable_bytes);
}

int main()
{
    test_personTuple();
    test_printTuple();
    test_sortPersonContainer();
    test_spanView_VectorVsFixedArray();
    test_print_spans();
    test_getLastElement();
    test_getFirstElement();
    test_subspan();
    test_byteViews();
    return 0;
}
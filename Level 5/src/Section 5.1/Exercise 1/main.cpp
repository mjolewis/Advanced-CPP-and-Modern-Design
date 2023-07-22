//
// Illustrate basic use cases of the boost string algorithm library.
//
// Created by Michael Lewis on 7/21/23.
//

#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>

// Part A - Trim leading and trailing blanks. Test both copy and modified trim
void test_trim_blanks()
{
    std::string s1{"    Hello12 3 !  "};
    std::cout << "S1 Before Trim: " << s1 << std::endl;

    boost::trim(s1);
    std::cout << "S1 Trimmed: " << s1 << std::endl;

    std::string s2{"  This will be a copy!! 123   "};
    std::cout << "S2 Before Trim: " << s2 << std::endl;

    std::string s2_copy = boost::trim_copy(s2);
    std::cout << "S2 After Trim Original: " << s2 << std::endl;
    std::cout << "S2 After Trim Copy: " << s2_copy << std::endl;
}

// Part B
void test_trim_with_predicates()
{
    std::cout << "\n*** Trim with Predicates ***" << std::endl;
    std::string s1{"AAA Trimming AAA"};
    std::string s2{"Trimming right BBB"};
    std::string s3{"AAAAAAA Trimming left"};

    boost::trim_if(s1, boost::is_any_of("AAA"));
    boost::trim_right_if(s2, boost::is_any_of("BBB"));
    boost::trim_left_if(s3, boost::is_any_of("A"));

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
}

// Part C - Test if a string starts or ends with a certain string.
// Consider both case-sensitive and case-insensitive variants.
void test_start_or_end_with_string()
{
    std::cout << "\n*** Predicates Start or Ends With ***" << std::endl;
    std::string s1{"AAA Trimming capital a"};
    std::string s2{"Trimming capital b BBB"};
    std::string s3{"AaAa Trimming case insensitive"};
    std::string s4{"Trimming case insensitive BbBb"};

    std::cout << std::boolalpha << boost::starts_with(s1, "AAA ") << std::endl;
    std::cout << std::boolalpha << boost::ends_with(s2, "BBB") << std::endl;
    std::cout << std::boolalpha << boost::istarts_with(s3, "aaaa") << std::endl;
    std::cout << std::boolalpha << boost::iends_with(s4, "bbbb") << std::endl;
}

// Part D - Test if a string contains another string.
// Consider both case-sensitive and case-insensitive variants.
void test_containment()
{
    std::cout << "\n*** Contains ***" << std::endl;
    std::string s1{"This is the parent string"};
    std::string s2{"parent"};
    std::string s3{"PARENT"};
    std::string s4{"child"};

    std::cout << std::boolalpha << boost::contains(s1, s2) << std::endl;
    std::cout << std::boolalpha << boost::icontains(s1, s3) << std::endl;
    std::cout << std::boolalpha << boost::icontains(s1, s4) << std::endl;
}

// Part D - Test if two strings are equal.
void test_equality()
{
    std::cout << "\n*** Equality ***" << std::endl;
    std::string s1{"This string will be equal"};
    std::string s2{"This string will be equal"};
    std::string s3{"THIS STRING WILL be equal"};
    std::string s4{"This string will NOT be equal"};

    std::cout << std::boolalpha << boost::equals(s1, s2) << std::endl;
    std::cout << std::boolalpha << boost::iequals(s1, s3) << std::endl;
    std::cout << std::boolalpha << boost::iequals(s2, s3) << std::endl;
    std::cout << std::boolalpha << boost::iequals(s1, s4) << std::endl;
    std::cout << std::boolalpha << boost::iequals(s2, s4) << std::endl;
}

int main()
{
    test_trim_blanks();
    test_trim_with_predicates();
    test_start_or_end_with_string();
    test_containment();
    test_equality();
    return 0;
}
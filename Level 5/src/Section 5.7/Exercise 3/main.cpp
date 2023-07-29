//
// Illustrate how to create association objects using boost::bimap
//
// Created by Michael Lewis on 7/28/23.
//

#include <iostream>
#include <tuple>
#include <string>

#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>

int main()
{
    // Part A - Create a 1 N association between book title and author. Model book price in Bimap.
    typedef boost::bimap
            <boost::bimaps::multiset_of<std::string>,           // author
                    boost::bimaps::set_of<std::string>,         // title
                            boost::bimaps::with_info<double>    // price
            > BMType;

    typedef BMType::value_type Book;

    BMType bm;
    bm.insert(Book("Michael Lewis", "Quant Dev 101", 110));
    bm.insert(Book("Michael J Lewis", "Quant Dev 201", 120));
    bm.insert(Book("Michael JJ Lewis", "Quant Dev 301", 130));

    // Part B - Print the price of a book from a given author.
    BMType::left_const_iterator it = bm.left.find("Michael Lewis");
    std::cout << it->info << std::endl;

    // Part C - Now create an association attribute containing a tuple consisting of book abstract and its price.
    typedef boost::bimap
            <boost::bimaps::multiset_of<std::string>,                            // author
                    boost::bimaps::set_of<std::string>,                          // title
                    boost::bimaps::with_info<std::tuple<std::string, double>>    // abstract, price
            > BMType2;

    typedef BMType2::value_type Book2;

    BMType2 bm2;
    bm2.insert(Book2("Michael Lewis", "Quant Dev 101", std::make_tuple("Learn how to be a quant dev", 110)));
    std::cout << std::get<0>(bm2.right.info_at("Quant Dev 101")) << std::endl;

    return 0;
}
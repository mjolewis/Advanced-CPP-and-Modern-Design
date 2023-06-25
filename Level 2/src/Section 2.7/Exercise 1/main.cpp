//
// Illustrate common error conditions and their common causes
//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>
#include <fstream>
#include <string>

#include "boost/system/error_code.hpp"

// This function tests Parts A-C
// Accepts a file and opens it for reading. If the file isn't open, then return a
// Boost no such file or directory error. Otherwise, log the contents of the file and return
// and empty Boost error condition.
boost::system::error_condition readFileAndReturnBoostError(const std::string& file)
{
    std::fstream in(file.c_str(), std::fstream::in);
    if (!in.is_open())
    {
        return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);
    }
    else
    {
        std::cout << in.rdbuf() << std::endl;
    }

    // Clean up resources
    in.close();

    // Return a no error condition
    return boost::system::error_condition();
}

// This function tests Parts A-C
// Accepts a file and opens it for reading. If the file isn't open, then return a
// Boost no such file or directory error. Otherwise, log the contents of the file and return
// and empty Boost error condition.
std::error_condition readFileAndReturnStdError(const std::string& file)
{
    std::fstream in(file.c_str(), std::fstream::in);
    if (!in.is_open())
    {
        return std::make_error_condition(std::errc::no_such_file_or_directory);
    }
    else
    {
        std::cout << in.rdbuf() << std::endl;
    }

    // Clean up resources
    in.close();

    // Return a no error condition
    return std::error_condition();
}

int main()
{
    // Part A-C
    std::string file = "No such file";
    std::cout << readFileAndReturnBoostError(file).message() << std::endl;

    file = "/Users/mlewis/CLionProjects/Baruch/Advanced-CPP-and-Modern-Design/Level 2/src/Section 2.7/Exercise 1/main.cpp";
    std::cout << readFileAndReturnBoostError(file).message() << std::endl;

    // Part D
    file = "No such file";
    std::cout << readFileAndReturnStdError(file).message() << std::endl;

    file = "/Users/mlewis/CLionProjects/Baruch/Advanced-CPP-and-Modern-Design/Level 2/src/Section 2.7/Exercise 1/main.cpp";
    std::cout << readFileAndReturnStdError(file).message() << std::endl;

    return 0;
}

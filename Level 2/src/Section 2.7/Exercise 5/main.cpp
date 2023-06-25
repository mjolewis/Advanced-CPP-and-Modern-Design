//
// The objective of this exercise is to catch a (simulated) exception thrown when
// setting the exception mask of an input file stream
//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <system_error>

int main()
{
    std::ifstream file(std::string("DOESNOTEXIST.txt"));
    try
    {
        // Set the exception mask of the file stream
        // In this case 1) logical error on I/O operation or
        // 2) read/write error on I/O operation
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    }
    catch (const std::ios_base::failure& e)
    {
        if (e.code() == std::io_errc::stream)
        {
            std::error_code ec1{e.code()};
            std::error_code ec2{ec1}; // Illustrate the fact that an EC can be constructed using another EC
            std::cerr << ec2.value() << ":" << ec2.message() << ":" << std::string{ec2.category().name()} << std::endl;
        }
    }
    catch (...)
    {
        std::cout <<"catch all\n";
    }
}
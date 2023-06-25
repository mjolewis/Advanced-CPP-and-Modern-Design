//
// Illustrate how to create portable error conditions based POSIX error codes
//
// Created by Michael Lewis on 6/24/23.
//

#include <iostream>
#include <system_error>

int main()
{
    {
        // Part A
        std::error_condition io{std::errc::io_error};
        std::error_condition network{std::errc::network_unreachable};
        std::error_condition file{std::errc::no_such_file_or_directory};
        std::error_condition socket{std::errc::not_a_socket};
        std::error_condition permission{std::errc::permission_denied};

        std::cout << "io:" << io.message() << std::endl;
        std::cout << "network:" << network.message() << std::endl;
        std::cout << "file:" << file.message() << std::endl;
        std::cout << "socket:" << socket.message() << std::endl;
        std::cout << "permission:" << permission.message() << std::endl;
    }

    {
        // Part B
        std::error_condition e128{128, std::generic_category()};
        std::cout << "e128:" << e128.message() << std::endl;
    }

    {
        // Part C
        std::error_condition e = std::make_error_condition(std::io_errc{});
        std::cout << "errc:" << e.message() << std::endl;
    }

    return 0;
}
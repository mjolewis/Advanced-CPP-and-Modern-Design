cmake_minimum_required(VERSION 3.23)
project(Advanced_CPP_and_Modern_Design)

set(CMAKE_CXX_STANDARD 20)

# Start Boost dependency
set(BOOST_INCLUDE /usr/local/Cellar/boost/1.81.0)
set(BOOST_LIBRARY /usr/local/Cellar/boost/1.81.0)
find_package(Boost 1.81.0)
include_directories(${Boost_INCLUDE_DIR})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
# End Boost dependency

add_executable(Advanced_CPP_and_Modern_Design
        "Section 6.1/Exercise 1/main.cpp"
        "Section 6.1/Exercise 1/Shape.hpp"
        "Section 6.1/Exercise 1/Shape.cpp"
        "Section 6.1/Exercise 1/Point.hpp"
        "Section 6.1/Exercise 1/Point.cpp"
        "Section 6.1/Exercise 1/Line.hpp"
        "Section 6.1/Exercise 1/Line.cpp"
        "Section 6.1/Exercise 1/Circle.hpp"
        "Section 6.1/Exercise 1/Circle.cpp")

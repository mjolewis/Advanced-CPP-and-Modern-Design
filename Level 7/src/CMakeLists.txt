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
        "Exercise 1/main.cpp"
        "Exercise 1/Circle.cpp"
        "Exercise 1/Circle.hpp"
        "Exercise 1/ConsoleShapeFactory.cpp"
        "Exercise 1/ConsoleShapeFactory.hpp"
        "Exercise 1/Line.cpp"
        "Exercise 1/Line.hpp"
        "Exercise 1/Point.cpp"
        "Exercise 1/Point.hpp"
        "Exercise 1/Shape.hpp"
        "Exercise 1/ShapeFactory.hpp"
)
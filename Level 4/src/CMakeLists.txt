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
        #"Section 4.1/Exercise 1/main.cpp"
        #"Section 4.1/Exercise 1/Proposition.cpp"
        #"Section 4.1/Exercise 1/Proposition.hpp"
        #"Section 4.1/Exercise 2/main.cpp"
        #"Section 4.1/Exercise 2/Vector.cpp"
        #"Section 4.1/Exercise 2/Vector.hpp")
        #"Section 4.1/Exercise 3/main.cpp"
        #"Section 4.1/Exercise 3/Matrix.cpp"
        #"Section 4.1/Exercise 3/Matrix.hpp")
        #"Section 4.1/Exercise 4/main.cpp"
        #"Section 4.1/Exercise 4/Proposition.cpp"
        #"Section 4.1/Exercise 4/Proposition.hpp"
        #"Section 4.1/Exercise 4/Matrix.cpp"
        #"Section 4.1/Exercise 4/Matrix.hpp"
        #"Section 4.1/Exercise 5/main.cpp"
        #"Section 4.1/Exercise 5/Vector.cpp"
        #"Section 4.1/Exercise 5/Vector.hpp"
        #"Section 4.1/Exercise 5/Matrix.hpp"
        #"Section 4.1/Exercise 5/Matrix.cpp"
        #"Section 4.2/Exercise 1/main.cpp"
        "Section 4.2/Exercise 2/main.cpp")
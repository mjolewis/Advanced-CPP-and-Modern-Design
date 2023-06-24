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
        #"src/Section 2.1/Exercise 2/main.cpp"
        #"src/Section 2.1/Exercise 3/Shape.hpp"
        #"src/Section 2.1/Exercise 3/Base.hpp"
        #"src/Section 2.1/Exercise 3/Point.hpp"
        #"src/Section 2.1/Exercise 3/main.cpp"
        #"src/Section 2.1/Exercise 4/main.cpp"
        #"src/Section 2.1/Exercise 4/Shape.hpp"
        #"src/Section 2.1/Exercise 4/Point.hpp"
        #"src/Section 2.2/Exercise 1/main.cpp"
        #"src/Section 2.2/Exercise 1/Numerics.cpp"
        #"src/Section 2.2/Exercise 1/Numerics.hpp"
        #"src/Section 2.2/Exercise 2/main.cpp"
        #"src/Section 2.2/Exercise 3/main.cpp"
        #"src/Section 2.3/Exercise 1/main.cpp"
        #"src/Section 2.3/Exercise 2/main.cpp"
        #"src/Section 2.3/Exercise 3/main.cpp"
        #"src/Section 2.3/Exercise 4/main.cpp"
        #"src/Section 2.4/Exercise 1/main.cpp"
        #"src/Section 2.4/Exercise 2/main.cpp"
        #"src/Section 2.4/Exercise 2/C1.hpp"
        #"src/Section 2.4/Exercise 2/C2.hpp"
        #"src/Section 2.4/Exercise 2/Point1.hpp"
        "src/Section 2.4/Exercise 3/Base.hpp"
        "src/Section 2.4/Exercise 3/main.cpp" "src/Section 2.4/Exercise 3/Derived.hpp")
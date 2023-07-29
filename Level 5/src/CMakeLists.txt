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
        #"Section 5.1/Exercise 1/main.cpp"
        #"Section 5.1/Exercise 1/main.cpp"
        #"Section 5.1/Exercise 3/main.cpp")
        #"Section 5.1/Exercise 4/main.cpp"
        #"Section 5.2 and 5.3/Exercise 1/main.cpp"
        #"Section 5.2 and 5.3/Exercise 1/main.cpp"
        #"Section 5.2 and 5.3/Exercise 3/main.cpp"
        #"Section 5.2 and 5.3/Exercise 4/main.cpp"
        #"Section 5.2 and 5.3/Exercise 5/main.cpp"
        #"Section 5.2 and 5.3/Exercise 6/main.cpp"
        #"Section 5.2 and 5.3/Exercise 7/main.cpp"
        #"Section 5.2 and 5.3/Exercise 8/main.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/main.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/Hasher.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/BoostHasher.hpp")
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/Point.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/Point.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/main.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/LineSegment.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/LineSegment.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 1/PointHasher.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 3/main.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 3/Point.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 3/Point.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 3/StopWatch.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 3/StopWatch.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 3/PointHasher.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 4/main.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 4/Point.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 4/Point.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 4/Order.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 4/Order.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 5/main.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 6/main.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 6/Point.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 6/Point.hpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 6/Order.cpp"
        #"Section 5.4 and 5.5 and 5.6/Exercise 6/Order.hpp"
        #"Section 5.7/Exercise 1/main.cpp"
        #"Section 5.7/Exercise 1/main.cpp"
        #"Section 5.7/Exercise 3/main.cpp"
        #"Section 5.7/Exercise 4/main.cpp"
        #"Section 5.8/Exercise 1/main.cpp"
        #"Section 5.8/Exercise 1/main.cpp"
        #"Section 5.9/Exercise 1/main.cpp"
        #"Section 5.9/Exercise 1/MyStruct.cpp"
        #"Section 5.9/Exercise 1/MyStruct.hpp")
        #"Section 5.9/Exercise 2/main.cpp"
        #"Section 5.9/Exercise 2/MyStruct.cpp"
        #"Section 5.9/Exercise 2/MyStruct.hpp"
        #"Section 5.9/Exercise 3/main.cpp"
        #"Section 5.9/Exercise 3/BootstrapCheck.cpp"
        #"Section 5.9/Exercise 3/BootstrapCheck.hpp"
        "Section 5.9/Exercise 4/main.cpp" "Section 5.9/Exercise 4/SumCombiner.cpp" "Section 5.9/Exercise 4/SumCombiner.hpp")
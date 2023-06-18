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
        #"src/Section 1.1/Exercise 1/main.cpp"
        #"src/Section 1.1/Exercise 2/main.cpp"
        #"src/Section 1.2/Exercise 1/main.cpp"
        #"src/Section 1.2/Exercise 2/main.cpp"
        #"src/Section 1.2/Exercise 3/main.cpp"
        #"src/Section 1.3/Exercise 1/main.cpp"
        #"src/Section 1.3/Exercise 2/main.cpp"
        #"src/Section 1.4/Exercise 1/main.cpp"
        #"src/Section 1.4/Exercise 2/main.cpp"
        #"src/Section 1.4/Exercise 3/main.cpp"
        #"src/Section 1.4/Exercise 4/main.cpp"
        #"src/Section 1.4/Exercise 5/main.cpp"
        #"src/Section 1.5/Exercise 1/main.cpp"
        #"src/Section 1.5/Exercise 2/main.cpp"
        #"src/Section 1.5/Exercise 3/main.cpp"
        #"src/Section 1.5/Exercise 4/main.cpp"
        #"src/Section 1.5/Exercise 5/Builder.hpp"
        #"src/Section 1.5/Exercise 5/main.cpp"
        #"src/Section 1.5/Exercise 5/IODevice.hpp"
        #"src/Section 1.5/Exercise 5/Shape.hpp"
        #"src/Section 1.5/Exercise 5/Circle.hpp" "src/Section 1.5/Exercise 5/Circle.cpp"
        #"src/Section 1.5/Exercise 5/Console.hpp" "src/Section 1.5/Exercise 5/Console.cpp"
        #"src/Section 1.5/Exercise 5/ConsoleBuilder.hpp" "src/Section 1.5/Exercise 5/ConsoleBuilder.cpp"
        #"src/Section 1.5/Exercise 5/Line.hpp" "src/Section 1.5/Exercise 5/Line.cpp"
        #"src/Section 1.5/Exercise 5/Monitor.hpp" "src/Section 1.5/Exercise 5/Monitor.cpp"
        #"src/Section 1.5/Exercise 5/MonitorBuilder.hpp" "src/Section 1.5/Exercise 5/MonitorBuilder.cpp"
        #"src/Section 1.6/Exercise 1/Base.hpp"
        #"src/Section 1.6/Exercise 1/Derived.hpp"
        #"src/Section 1.6/Exercise 1/Derived2.hpp"
        #"src/Section 1.6/Exercise 1/main.cpp"
        #"src/Section 1.6/Exercise 2/TmpClass.cpp" "src/Section 1.6/Exercise 2/TmpClass.hpp" "src/Section 1.6/Exercise 2/main.cpp"
        #"src/Section 1.6/Exercise 3/Point.hpp" "src/Section 1.6/Exercise 3/main.cpp" "src/Section 1.6/Exercise 3/S.hpp")
        "src/Section 1.6/Exercise 4/Client.hpp"
        "src/Section 1.6/Exercise 4/Storage.hpp"
        "src/Section 1.6/Exercise 4/main.cpp"
        "src/Section 1.6/Exercise 4/ClientUsingAlias.hpp"
        )

cmake_minimum_required(VERSION 3.23)
project(Advanced_CPP_and_Modern_Design)

#find_program(CMAKE_C_COMPILER NAMES $ENV{CC} gcc PATHS ENV PATH NO_DEFAULT_PATH)
#find_program(CMAKE_CXX_COMPILER NAMES $ENV{CXX} g++ PATHS ENV PATH NO_DEFAULT_PATH)

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

#set(CMAKE_EXE_LINKER_FLAGS -L/usr/local/opt/llvm/lib)
#set(CMAKE_CXX_FLAGS -I/usr/local/opt/llvm/include)

# OpenMP Dependency
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fopenmp")

add_executable(Advanced_CPP_and_Modern_Design
        #"src/Section 3.1/Exercise 3.1.1A/main.cpp")
        #"src/Section 3.1/Exercise 3.1.1B/main.cpp")
        #"src/Section 3.1/Exercise 3.1.1C_and_D/main.cpp")
        #"src/Section 3.1/Exercise 3.1.1E_and_F/main.cpp")
        #"src/Section 3.1/Exercise 3.1.2A/main.cpp")
        #"src/Section 3.1/Exercise 3.1.2B/main.cpp")
        #"src/Section 3.1/Exercise 3.1.2C/main.cpp")
        #"src/Section 3.1/Exercise 3.1.3A/main.cpp")
        #"src/Section 3.1/Exercise 3.1.3C/main.cpp")
        #"src/Section 3.1/Exercise 3.1.3D/main.cpp")
        #"src/Section 3.1/Exercise 3.1.3E/main.cpp")
        #"src/Section 3.1/Exercise 3.1.3F/main.cpp")
        #"src/Section 3.1/Exercise 3.1.3G/main.cpp")
        #"src/Section 3.1/Exercise 3.1.4/main.cpp"
        #"src/Section 3.1/Exercise 3.1.4/ConcurrentQueue.cpp"
        #"src/Section 3.1/Exercise 3.1.4/ConcurrentQueue.hpp"
        #"src/Section 3.1/Exercise 3.1.4/Producer.cpp"
        #"src/Section 3.1/Exercise 3.1.4/Producer.hpp"
        #"src/Section 3.1/Exercise 3.1.4/Consumer.cpp"
        #"src/Section 3.1/Exercise 3.1.4/Consumer.hpp")
        #"src/Section 3.1/Exercise 3.1.5/main.cpp")
        #"src/Section 3.2_3.3/Exercise 1/main.cpp")
        #"src/Section 3.2_3.3/Exercise 2/main.cpp")
        #"src/Section 3.2_3.3/Exercise 3/main.cpp"
        #"src/Section 3.2_3.3/Exercise 3/ActiveObject.cpp"
        #"src/Section 3.2_3.3/Exercise 3/ActiveObject.hpp")
        #"src/Section 3.2_3.3/Exercise 4/main.cpp")
        #"src/Section 3.2_3.3/Exercise 5/main.cpp"
        #"src/Section 3.2_3.3/Exercise 5/Customer.cpp"
        #"src/Section 3.2_3.3/Exercise 5/Customer.hpp"
        #"src/Section 3.2_3.3/Exercise 5/Barber.cpp"
        #"src/Section 3.2_3.3/Exercise 5/Barber.hpp"
        #"src/Section 3.2_3.3/Exercise 5/ConcurrentQueue.cpp"
        #"src/Section 3.2_3.3/Exercise 5/ConcurrentQueue.hpp")
        #"src/Section 3.4/Exercise 1/main.cpp")
        #"src/Section 3.4/Exercise 2/main.cpp")
        #"src/Section 3.4/Exercise 3/main.cpp")
        #"src/Section 3.4/Exercise 4/main.cpp")
        #"src/Section 3.4/Exercise 5/main.cpp"
        #"src/Section 3.4/Exercise 6/main.cpp"
        #"src/Section 3.5/Exercise 1/main.cpp"
        "src/Section 3.5/Exercise 2/main.cpp"
        "src/Section 3.5/Exercise 2/Command.hpp")
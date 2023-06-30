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
        #"src/Section 3.1/Exercise 1A/main.cpp"
        #"src/Section 3.1/Exercise 1B/main.cpp"
        #"src/Section 3.1/Exercise 3.1C_and_D/main.cpp"
        #"src/Section 3.1/Exercise 3.1E_and_F/main.cpp"
        #"src/Section 3.2/Exercise 2A/main.cpp")
        #"src/Section 3.2/Exercise 2B/main.cpp")
        #"src/Section 3.2/Exercise 2C/main.cpp")
        #"src/Section 3.3/Exercise 3.3A/main.cpp"
        #"src/Section 3.3/Exercise 3.3C/main.cpp"
        #"src/Section 3.3/Exercise 3.3D/main.cpp"
        #"src/Section 3.3/Exercise 3.3E/main.cpp"
        #"src/Section 3.3/Exercise 3.3F/main.cpp"
        "src/Section 3.3/Exercise 3.3G/main.cpp")
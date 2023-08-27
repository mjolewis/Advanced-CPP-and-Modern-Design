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
#        "Exercise 1/main.cpp"
#        "Exercise 1/Circle.cpp"
#        "Exercise 1/Circle.hpp"
#        "Exercise 1/ConsoleShapeFactory.cpp"
#        "Exercise 1/ConsoleShapeFactory.hpp"
#        "Exercise 1/Line.cpp"
#        "Exercise 1/Line.hpp"
#        "Exercise 1/Point.cpp"
#        "Exercise 1/Point.hpp"
#        "Exercise 1/Shape.hpp"
#        "Exercise 1/ShapeFactory.hpp"
#        "Exercise 2/NewShapeFactory.cpp"
#        "Exercise 2/Circle.hpp"
#        "Exercise 2/Circle.cpp"
#        "Exercise 2/Line.hpp"
#        "Exercise 2/Line.cpp"
#        "Exercise 2/Point.hpp"
#        "Exercise 2/Point.cpp"
#        "Exercise 2/Shape.hpp"
#        "Exercise 2/NewShapeFactory.hpp"
#        "Exercise 2/main.cpp"
#        "Exercise 2/ConsoleShapeFactory.hpp"
#        "Exercise 2/ConsoleShapeFactory.cpp"
#        "Exercise 3/Circle.cpp"
#        "Exercise 3/Circle.hpp"
#        "Exercise 3/ConsoleShapeFactory.hpp"
#        "Exercise 3/ConsoleShapeFactory.cpp"
#        "Exercise 3/Line.cpp"
#        "Exercise 3/Line.hpp"
#        "Exercise 3/Point.cpp"
#        "Exercise 3/Point.hpp"
#        "Exercise 3/Shape.hpp"
#        "Exercise 3/ShapeFactory.hpp"
#        "Exercise 3/ShapeFactory.cpp"
#        "Exercise 3/PolyLine.cpp"
#        "Exercise 3/PolyLine.hpp"
#        "Exercise 3/ShapeComposite.cpp"
#        "Exercise 3/ShapeComposite.hpp"
#        "Exercise 3/main.cpp"
#        "Exercise 4/main.cpp"
#        "Exercise 4/TmpProcessor.hpp"
#        "Exercise 5/StatelessPoint/main.cpp"
#        "Exercise 5/StatelessPoint/DistanceStrategy.hpp"
#        "Exercise 5/StatelessPoint/DistanceStrategy.cpp"
#        "Exercise 5/StatelessPoint/Point.hpp"
#        "Exercise 5/StatelessPoint/Point.cpp"
#        "Exercise 5/StatelessPoint/Shape.hpp"
#        "Exercise 5/StatefulPoint/main.cpp"
#        "Exercise 5/StatefulPoint/DistanceStrategy.hpp"
#        "Exercise 5/StatefulPoint/DistanceStrategy.cpp"
#        "Exercise 5/StatefulPoint/Point.hpp"
#        "Exercise 5/StatefulPoint/Point.cpp"
#        "Exercise 5/StatefulPoint/Shape.hpp"
#        "Exercise 6/Exercise A/main.cpp"
#        "Exercise 6/Exercise A/Counter.hpp"
#        "Exercise 6/Exercise A/Subject.hpp"
        "Exercise 6/Exercise B/main.cpp"
        "Exercise 6/Exercise B/Counter.hpp"
        "Exercise 6/Exercise B/Subject.hpp"
)
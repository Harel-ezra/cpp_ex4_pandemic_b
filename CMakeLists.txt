cmake_minimum_required(VERSION 3.19)
project(pandemic_b)

set(CMAKE_CXX_STANDARD 14)

add_executable(pandemic_b StudentTest3.cpp TestRunner.cpp doctest.h sources/Board.hpp sources/Board.cpp sources/City.hpp sources/City.cpp sources/Color.hpp sources/Color.cpp sources/Player.hpp sources/Player.cpp
        sources/Dispatcher.hpp sources/Dispatcher.cpp sources/FieldDoctor.hpp sources/FieldDoctor.cpp sources/GeneSplicer.hpp sources/GeneSplicer.cpp
        sources/Medic.hpp sources/Medic.cpp sources/OperationsExpert.hpp sources/OperationsExpert.cpp sources/Researcher.hpp sources/Researcher.cpp
        sources/Scientist.hpp sources/Scientist.cpp sources/Virologist.hpp sources/Virologist.cpp)
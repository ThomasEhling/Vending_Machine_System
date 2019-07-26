cmake_minimum_required(VERSION 3.13)
project(VMsystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(VMsystem main.cpp includes/DataStore.hpp AbstractFactory.cpp includes/AbstractFactory.hpp VM.cpp includes/VM.hpp Strategy.cpp includes/Strategy.hpp includes/Globals.hpp MDA.cpp includes/MDA.hpp test/scenario.cpp test/scenario.hpp)
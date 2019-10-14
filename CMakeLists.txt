cmake_minimum_required(VERSION 3.14)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(Assignment1 main.cpp matrix.cpp matrix.hpp probMatrix.cpp probMatrix.hpp exceptions.hpp transMatrix.cpp transMatrix.hpp rankMatrix.cpp rankMatrix.hpp markovMatrix.cpp markovMatrix.hpp)
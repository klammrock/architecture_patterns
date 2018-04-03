cmake_minimum_required(VERSION 3.1)
project(singleton)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(singleton main.cpp MeyersSingleton.cpp DoubleCheckedLockingSingleton.cpp)

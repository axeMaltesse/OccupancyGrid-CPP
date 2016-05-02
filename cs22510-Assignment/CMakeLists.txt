cmake_minimum_required(VERSION 3.3)
project(luw19cs22510)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11")

set(SOURCE_FILES main.cpp OccupancyGrid.cpp OccupancyGrid.h Position.h)
add_executable(luw19cs22510 ${SOURCE_FILES})
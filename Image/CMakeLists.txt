cmake_minimum_required(VERSION 3.3)
project(Imge_s)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Image.cpp Image.h Dim2u.cpp Dim2u.h Position2u.cpp Position2u.h)
add_executable(Imge_s ${SOURCE_FILES})
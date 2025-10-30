cmake_minimum_required(VERSION 4.0)
project(ErrorHandling)

set(CMAKE_CXX_STANDARD 20)

add_executable(ErrorHandling main.cpp
        FileUtils.cpp
        FileUtils.h
        GeometryUtils.cpp
        GeometryUtils.h
        Exceptions.cpp
        Exceptions.h)


configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/data.txt"
        "${CMAKE_CURRENT_BINARY_DIR}/data.txt"
        COPYONLY
)
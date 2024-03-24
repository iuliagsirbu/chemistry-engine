cmake_minimum_required(VERSION 3.27)
project(chemistry_engine)

set(CMAKE_CXX_STANDARD 17)

add_executable(chemistry_engine main.cpp
        element.cpp
        include/element.h
        compound.cpp
        include/compound.h
        reaction.cpp
        include/reaction.h)

include_directories(.)
include_directories(include)
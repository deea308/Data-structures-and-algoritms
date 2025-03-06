cmake_minimum_required(VERSION 3.27)
project(sortedMap)

set(CMAKE_CXX_STANDARD 17)

add_executable(sortedMap
        SMIterator.cpp
        SortedMap.cpp
        ShortTest.h
        ShortTest.cpp
        ExtendedTest.cpp
        App.cpp)

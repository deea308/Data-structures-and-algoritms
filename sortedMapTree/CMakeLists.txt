cmake_minimum_required(VERSION 3.27)
project(sortedMapTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(sortedMapTree
        SortedMap.cpp
        SMIterator.cpp
        ShortTest.cpp
        ExtendedTest.cpp
        App.cpp)

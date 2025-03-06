cmake_minimum_required(VERSION 3.27)
project(newSortedSet)
MATH(EXPR stack_size "64 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_CXX_STANDARD 17)

add_executable(newSortedSet
        App.cpp
        ExtendedTest.cpp
        ShortTest.cpp
        SortedSet.cpp
        SortedSetIterator.cpp)

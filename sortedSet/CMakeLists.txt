cmake_minimum_required(VERSION 3.27)
project(sortedSet)
MATH(EXPR stack_size "64 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_CXX_STANDARD 17)

add_executable(sortedSet
        App.cpp
        ExtendedTest.cpp
        ShortTest.cpp
        SortedSet.cpp
        SortedSetIterator.cpp)

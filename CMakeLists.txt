cmake_minimum_required(VERSION 3.0)
project(BowlingKata)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

set(SOURCE_FILES
    src/Line.cpp
    src/Score.cpp)

set(TEST_SOURCE_FILES
    test/BownlingScoreTest.cpp
    test/catch.hpp
    test/TestRunnrer.cpp)

add_executable(TextRunner ${SOURCE_FILES} ${TEST_SOURCE_FILES})
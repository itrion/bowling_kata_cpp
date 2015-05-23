cmake_minimum_required(VERSION 3.0)
project(BowlingKata)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++")

set(SOURCE_FILES
    src/Line.cpp
    src/Score.cpp
    src/Roll.cpp
    src/Frame.cpp)

set(TEST_SOURCE_FILES
    test/BownlingScoreTest.cpp
    test/catch.hpp
    test/TestRunnrer.cpp
    test/FrameCreationTest.cpp)

add_executable(TextRunner ${SOURCE_FILES} ${TEST_SOURCE_FILES} src/SpareRoll.cpp src/SpareRoll.h src/StrikeRoll.cpp src/StrikeRoll.h src/FrameBuilder.cpp src/FrameBuilder.h)
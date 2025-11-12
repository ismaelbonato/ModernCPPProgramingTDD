cmake_minimum_required(VERSION 3.10)
project(SoundexTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GoogleTest requires at least C++14
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

# Use GTest::gtest_main to provide the main() function
add_executable(SoundexTest_V10 SoundexTest.cpp)
target_link_libraries(SoundexTest_V10 GTest::gtest_main pthread)

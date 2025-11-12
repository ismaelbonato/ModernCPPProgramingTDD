cmake_minimum_required(VERSION 3.10)
project(RetweetCollectionTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GoogleTest requires at least C++14
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})


# Use GTest::gtest_main to provide the main() function
add_executable(RetweetCollectionTest RetweetCollectionTest.cpp)
target_link_libraries(RetweetCollectionTest GTest::gtest_main pthread)

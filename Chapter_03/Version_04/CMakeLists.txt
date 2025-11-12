cmake_minimum_required(VERSION 3.10)
project(RetweetCollectionTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GoogleTest requires at least C++14
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

# Get the folder name to use in target name
get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Use GTest::gtest_main to provide the main() function
add_executable(RetweetCollectionTest_${FOLDER_NAME} RetweetCollectionTest.cpp)
target_link_libraries(RetweetCollectionTest_${FOLDER_NAME} GTest::gtest_main pthread)

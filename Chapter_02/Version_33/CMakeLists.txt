cmake_minimum_required(VERSION 3.10)
project(SoundexTest)

set(CMAKE_CXX_STANDARD 23)

# GoogleTest requires at least C++14
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES 
    SoundexTest.cpp
    #Soundex.cpp
)

# Use GTest::gtest_main to provide the main() function
add_executable(SoundexTest ${SOURCE_FILES})
target_link_libraries(SoundexTest GTest::gtest_main pthread)

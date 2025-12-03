cmake_minimum_required(VERSION 3.10)
project(SoundexApp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTING "Build tests" ON)

set(SOURCE_FILES
    src/Soundex.cpp
    src/CharUtil.cpp
    src/StringUtil.cpp
)

add_executable(SoundexApp ${SOURCE_FILES} main.cpp)
target_include_directories(SoundexApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Get the folder name to use in target name
get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

if(BUILD_TESTING)
    # GoogleTest requires at least C++14
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    set(TEST_FILES
        tests/SoundexTest.cpp
        tests/CharUtilTest.cpp
        tests/StringUtilTest.cpp
    )

    add_executable(SoundexTest_${FOLDER_NAME} ${TEST_FILES} ${SOURCE_FILES})
    target_include_directories(SoundexTest_${FOLDER_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
    target_link_libraries(SoundexTest_${FOLDER_NAME} GTest::gtest_main pthread)
endif()


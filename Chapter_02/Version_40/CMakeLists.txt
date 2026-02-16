cmake_minimum_required(VERSION 3.10)
project(SoundexApp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(CODE_COVERAGE "Enable coverage reporting" ON)
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
get_filename_component(CHAPTER_NAME ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(CHAPTER_NAME ${CHAPTER_NAME} NAME)

if(BUILD_TESTING)
    # GoogleTest requires at least C++14
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    set(TEST_FILES
        tests/SoundexTest.cpp
        tests/CharUtilTest.cpp
        tests/StringUtilTest.cpp
    )

    add_executable(${CHAPTER_NAME}_${FOLDER_NAME}_Test ${TEST_FILES} ${SOURCE_FILES})
    target_include_directories(${CHAPTER_NAME}_${FOLDER_NAME}_Test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
    target_link_libraries(${CHAPTER_NAME}_${FOLDER_NAME}_Test GTest::gtest_main pthread)

    enable_testing()
    add_test(NAME SoundexTests COMMAND ${CHAPTER_NAME}_${FOLDER_NAME}_Test)

    if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang") # gcovr -r .. --html -o coverage.html
        message(STATUS "Building test target with code coverage flags")
        target_compile_options(${CHAPTER_NAME}_${FOLDER_NAME}_Test PRIVATE -fprofile-arcs -ftest-coverage --coverage -O0 -g)
        target_link_options(${CHAPTER_NAME}_${FOLDER_NAME}_Test PRIVATE -fprofile-arcs -ftest-coverage --coverage)
    endif()
endif()


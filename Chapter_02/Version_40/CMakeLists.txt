cmake_minimum_required(VERSION 3.10)
project(SoundexApp)

set(CMAKE_CXX_STANDARD 23)

option(BUILD_TESTING "Build tests" OFF)


set(SOURCE_FILES
    #Soundex.cpp
    src/CharUtil.cpp
    src/StringUtil.cpp
)

if(BUILD_TESTING)
    # GoogleTest requires at least C++14
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    set(TEST_FILES
        tests/SoundexTest.cpp
        tests/CharUtilTest.cpp
        tests/StringUtilTest.cpp
    )

    add_executable(SoundexTest ${TEST_FILES} ${SOURCE_FILES})
    target_include_directories(SoundexTest PRIVATE ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(SoundexTest GTest::gtest_main pthread)

else()
    add_executable(SoundexApp ${SOURCE_FILES} main.cpp)
    target_include_directories(SoundexApp PRIVATE ${CMAKE_SOURCE_DIR}/src)
endif()


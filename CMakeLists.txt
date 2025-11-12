cmake_minimum_required(VERSION 3.10)
project(ModernCPPProgrammingTDD)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Automatically discover and add all Chapter_* subdirectories
file(GLOB CHAPTER_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Chapter_*")
foreach(CHAPTER_DIR ${CHAPTER_DIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CHAPTER_DIR})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${CHAPTER_DIR}/CMakeLists.txt)
            add_subdirectory(${CHAPTER_DIR})
        endif()
    endif()
endforeach()

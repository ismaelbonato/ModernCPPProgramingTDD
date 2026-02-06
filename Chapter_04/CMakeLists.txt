cmake_minimum_required(VERSION 3.10)
project(Chapter_04)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build all versions
file(GLOB VERSION_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Version_*")
list(SORT VERSION_DIRS)
foreach(VERSION_DIR ${VERSION_DIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${VERSION_DIR})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${VERSION_DIR}/CMakeLists.txt)
            message(STATUS "Adding ${VERSION_DIR}")
            # Each version must have unique target names to avoid conflicts
            add_subdirectory(${VERSION_DIR})
        endif()
    endif()
endforeach()

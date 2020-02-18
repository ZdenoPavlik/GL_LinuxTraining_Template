# Main cmake configuration and build script for the Intercom subproject
# author  Zdenko Pavlik
#
# Copyright (c) 2017, 2018, GS Elektromedizinische Geraete G. Stemple GmbH.
# All rights reserved.


cmake_minimum_required(VERSION 3.5)
set(APPNAME "Playground")
#add_compile_options(-pthread)
#add_compile_options(-l libpthread)
#add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set (SOURCES
    src/main.cpp
    src/Library/Bookshelf.cpp
    src/Library/Book/Book.cpp
    src/Persons/Author.cpp
    src/Persons/Librarian.cpp
)

set(HEADERS
    src/Library/Bookshelf.hpp
    src/Library/Book/Book.hpp
    src/Persons/AbstractPerson.hpp
    src/Persons/Author.hpp
    src/Persons/Librarian.hpp
)

project(${APPNAME}  LANGUAGES CXX)
add_executable(${APPNAME} ${HEADERS} ${SOURCES})

TARGET_LINK_LIBRARIES(${APPNAME}
			pthread
                    )

include_directories(src)

# Threads
find_package(Threads REQUIRED)
include_directories(${Threads_INCLUDE_DIRS})
link_directories(${Threads_LIBRARY_DIRS})

# GTest
find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})
link_directories(${GTest_LIBRARY_DIRS})

# Gmock - sudo apt-get install -y google-mock
#find_package(GMock REQUIRED)
#include_directories(${GMock_INCLUDE_DIRS})
#link_directories(${GMock_LIBRARY_DIRS})

# Boost
find_package(Boost COMPONENTS system python filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

#add_subdirectory(src)
add_subdirectory(test)

# author  Zdenko Pavlik

cmake_minimum_required(VERSION 3.5)
project(basic_test)

enable_testing()

include_directories(..)
include_directories(../src)
include_directories(test)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
set (SOURCES
    ../src/Library/Book/Book.cpp
    Library/BookshelfTest/BookshelfTest.cpp
    Library/DummyTest.cpp
    ../src/Persons/AbstractPerson.hpp
    Persons/MockedPerson.hpp
    Persons/PersonTesting.cpp
)

set(HEADERS
    stdafx_test.h
    Persons/MockedPerson.hpp
)

add_executable( runUnitTests ${HEADERS} ${SOURCES})
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gmock pthread gtest_main)
add_test( runUnitTests runUnitTests )
cmake_minimum_required(VERSION 3.14)
project(gtest_example)

set(CMAKE_CXX_STANDARD 11)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

add_subdirectory(src)

set(GOOGLE_TEST_DIR "tests/googletest")
add_subdirectory(${GOOGLE_TEST_DIR})
include_directories(${GOOGLE_TEST_DIR}/googletest/include)
enable_testing()
add_subdirectory(tests)

set(TEST_COVERAGE_FLAGS "")
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(TEST_COVERAGE_FLAGS "-fprofile-arcs -ftest-coverage")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TEST_COVERAGE_FLAGS}")
message(STATUS, "CXXFLAGS: ${CMAKE_CXX_FLAGS}")

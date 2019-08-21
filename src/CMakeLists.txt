add_executable(gtest_example)
target_sources(
        gtest_example

        PRIVATE
        main.cpp
        Example.cpp
        Example.h
)

add_library(gtest_example_library)
target_sources(
        gtest_example_library

        PRIVATE
        Example.cpp

        PUBLIC
        Example.h
)
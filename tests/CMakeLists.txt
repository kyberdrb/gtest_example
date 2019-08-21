add_executable(unit_tests ExampleTestSuite.cpp)
target_link_libraries(
        unit_tests
        gtest_main
        gtest_example_library
)

add_test(
        unit_tests

        NAME unit
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)

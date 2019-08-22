# gtest_example
Example project with integrated Google Test Framework with step-by-step tutorial

Below are listed the branches in order in which they were created.

Underneath a step can be a notice

To check detailed steps, see the commits and their descriptions for the particular branch.

1. add_gitignore
1. create_example_project
1. separate_sources_from_entire_project

    Manually move source and header files from `add_executable` or `add_library` 
    to `target_sources` command.
  
1. prepare_project_for_google_test
    1. build_lib_from_src
    1. define_gnu_install_dirs
1. integrate_google_test
1. configure_test_module
1. integrate_test_module_to_project
1. add_test_case

    Every new test case is added only to targets `unit_tests`
    in order for the tests to be decoupled from the production code.
  
1. enable_test_coverage
1. create_dedicated_test_configuration_in_clion

---  

## Troubleshooting

'set_target_properties' is only generating error "Cannot determine link language for target XYZ"
when the PRIVATE section with the source files, e.g. cpp in 'target_sources' for the binary or library target is missing.
When the source files are missing, the linker cannot infer the language from the source file extensions.
The header files extensions in PUBLIC section of 'target_sources' command are ignored.
see 'https://cmake.org/pipermail/cmake/2006-July/010380.html'

The solution is to add the command

    set_target_properties(<TARGET_NAME> PROPERTIES LINKER_LANGUAGE <LANGUAGE>)
    
e.g.

    ... 
    add_library(gtest_example_library)
    set_target_properties(gtest_example_library PROPERTIES LINKER_LANGUAGE CXX)
    ...
    
after the `add_executable` or `add_library` command.

## \[OPTIONAL\] Create a dedicated testing configuration in CLion

CLion provides the opportunity to create a dedicated unit test configuration.

1. Go to `Run -> Edit Configurations`
1. Click on the 'plus sign' icon '+' button in the left upper corner.
1. Select `Google Test`.
1. Fill the parameters:
    - **Name:** enter a name of the test suite
    - **Test kind:** Suite/Test
    - **Target:** unit_tests
1. Save changes by clicking on `OK`.
1. Select the Google Test configuration in the drop down menu in the upper right corner of CLion.
It should be listed as the last option.
1. Run the unit test configuration.
The results will be displayed at the bottom of the window in a tree structure.

Now we have 2 options to run the unit tests in CLion:
- standard 'unit_tests' configuration with text results, and
- special Google Test configuration with graphical results
I personally prefer the traditional text output.
At the same time I realize that in larger projects the tree structure
might be much quicker to navigate.

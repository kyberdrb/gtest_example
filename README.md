# gtest_example
Example project with integrated Google Test Framework with step-by-step tutorial

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
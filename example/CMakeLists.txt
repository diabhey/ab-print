cmake_minimum_required (VERSION 3.11.0 FATAL_ERROR)

set(example_files
        printtest.cpp
        )

add_executable(example ${example_files} )
target_link_libraries(example ab-print)
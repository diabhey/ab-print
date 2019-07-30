cmake_minimum_required (VERSION 3.10.0 FATAL_ERROR)

set(example_files
        example.cpp
        )

add_executable(example ${example_files} )
# Enabling clang tidy checks
if(CLANG_TIDY_EXE)
  set_target_properties(
    example PROPERTIES
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
  )
endif()
target_link_libraries(example ab-print)

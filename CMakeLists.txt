cmake_minimum_required (VERSION 3.11.0 FATAL_ERROR)

project (ab-print VERSION 1.0.0 LANGUAGES CXX)

# installation directories
set (AB_PRINT_INSTALL_INCLUDE_DIR "include" CACHE STRING "The installation include directory")

# define a header-only library
add_library (ab-print INTERFACE)

target_include_directories (ab-print INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${AB_PRINT_INSTALL_INCLUDE_DIR}>
)

# require C++17
target_compile_features (ab-print INTERFACE cxx_std_17)

# testing
enable_testing ()
option (AB_PRINT_BUILD_TESTS "Build test programs" OFF)
if (AB_PRINT_BUILD_TESTS)
  add_subdirectory (tests/)
endif ()

# example
option (AB_PRINT_BUILD_EXAMPLES "Build example programs" ON)
if (AB_PRINT_BUILD_EXAMPLES)
  add_subdirectory (example/)
endif ()

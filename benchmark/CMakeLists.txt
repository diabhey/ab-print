cmake_minimum_required (VERSION 3.10.0 FATAL_ERROR)

set(benchmark_files
        bench.cpp
        )

# build google benchmark (target: benchmark)
# do not build tests of benchmarking lib
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(google/)

add_executable(bench ${benchmark_files} )

target_link_libraries(bench benchmark ab-print)

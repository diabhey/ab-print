/**
 * @file bench.cpp
 * @author bigillu
 * @brief benchmarking the ab::print lib
 * @version 0.1
 * @date 2019-08-06
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "print.hpp"
#include <benchmark/benchmark.h>
#include <iostream>
#include <string>
#include <vector>

using namespace benchmark;

static void benchmark_abprint(benchmark::State &state) {
  std::vector<std::string> vecString{"Testing", "ab-print", "now"};

  for (auto _ : state) {
    ab::print(std::cout, vecString);
  }
}
// Register the function as a benchmark
BENCHMARK(benchmark_abprint);

// Define another benchmark
static void benchmark_cout(benchmark::State &state) {
  std::vector<std::string> vecString{"Testing", "ab-print", "now"};

  for (auto _ : state) {
    std::cout << "{ ";
    for (auto i : vecString) {
      std::cout << i << " ";
    }
    std::cout << " } " << '\n';
  }
}
BENCHMARK(benchmark_cout);

BENCHMARK_MAIN();
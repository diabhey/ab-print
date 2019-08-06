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

static void BM_Print(benchmark::State &state) {
  for (auto _ : state)
    ab::print(std::cout,
              std::vector<std::string>{"Testing", "ab-print", "now"});
}
// Register the function as a benchmark
BENCHMARK(BM_Print);

// Define another benchmark
static void BM_Cout(benchmark::State &state) {
  std::vector<std::string> vecString{"Testing", "ab-print", "now"};
  for (auto _ : state) {

    std::cout << "{ ";
    for (auto i : vecString) {
      std::cout << i << " ";
    }
    std::cout << " } " << '\n';
  }
}
BENCHMARK(BM_Cout);

BENCHMARK_MAIN();
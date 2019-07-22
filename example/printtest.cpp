/**
 * @file printtest.cpp
 * @author Bigillu
 * @brief Test application for the Printer library
 * @version 0.1
 * @date 2019-06-08
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include "print.hpp"

/**
 * @brief Entry point into the test application
 *
 */
int main() {
  // Testing basic data types
  ab::print(std::cout, "\n char:", char{'a'}, "\n int", int{7}, "\n double",
            double{2.2});
  // Testing sequential containers
  ab::print(std::cout, "\n vector:", std::vector<int>{1, 2, 3, 4, 5},
            "\n deque:", std::deque<int>{1, 2, 3, 4, 5},
            "\n list:", std::list<int>{1, 2, 3, 4, 5},
            "\n array:", std::array<int, 5>{1, 2, 3, 4, 5});
  // Testing associative containers
  ab::print(std::cout, "\n set:", std::set<std::string>{"One", "Two", "Three"},
            "\n multiset:", std::multiset<int, std::greater<int>>{1, 1, 1},
            "\n map:",
            std::map<std::string, int>{{"One", 1}, {"Two", 2}, {"three", 3}},
            "\n multimap:",
            std::multimap<std::string, int>{
                {"GroupOne", 1}, {"GroupOne", 2}, {"GroupOne", 3}});
  return EXIT_SUCCESS;
}

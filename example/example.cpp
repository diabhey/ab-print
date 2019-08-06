/**
 * @file example.cpp
 * @author Bigillu
 * @brief Test application for the ab::print library
 * @version 0.1
 * @date 2019-06-08
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "print.hpp"
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

/**
 * @brief Entry point into the example application
 *
 */
int main() {
  // Printing basic data types
  ab::print(std::cout, "***Basic Data Types***");
  ab::print(std::cout, "\n char:", char{'a'}, "\n int", int{7}, "\n double",
            double{2.2}, '\n');
  // Printing sequential containers
  ab::print(std::cout, "***Sequential Containers***");
  ab::print(std::cout, "\n vector:", std::vector<int>{1, 2, 3, 4, 5},
            "\n deque:", std::deque<int>{1, 2, 3, 4, 5},
            "\n list:", std::list<int>{1, 2, 3, 4, 5},
            "\n array:", std::array<int, 5>{1, 2, 3, 4, 5}, '\n');
  // Printing associative containers
  ab::print(std::cout, "***Associative Containers***");
  ab::print(std::cout, "\n set:", std::set<std::string>{"One", "Two", "Three"},
            "\n multiset:", std::multiset<int, std::greater<int>>{1, 1, 1},
            "\n map:",
            std::map<std::string, int>{{"One", 1}, {"Two", 2}, {"three", 3}},
            "\n multimap:",
            std::multimap<std::string, int>{
                {"GroupOne", 1}, {"GroupOne", 2}, {"GroupOne", 3}},
            "\n unordered map:",
            std::unordered_map<std::string, std::string>{
                {"RED", "#FF0000"}, {"GREEN", "#00FF00"}, {"BLUE", "#0000FF"}},
            '\n');
  // Printing custom data types
  {
    class Coord {
    public:
      explicit Coord(std::pair<int, int> coord) : mCoord(std::move(coord)) {}
      // The custom type (class or struct) must have a print member function or
      // any member function that calls the ab::print() internally. It is upto
      // the user to format it.
      void print(std::ostream &s = std::cout) {
        ab::print(s, "***Custom Data Types***\n");
        ab::print(s, "Coord: ", mCoord);
      }

    private:
      std::pair<int, int> mCoord;
    };
    Coord s(std::make_pair(5, 6));
    s.print();
  }
  return EXIT_SUCCESS;
}

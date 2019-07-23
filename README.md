# ab-print
A generic header-only print library for C++. It can be considered as a flexible alternative to iostreams.

```c++
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <print.hpp>

int main() {
  ab::print(std::cout, "\n vector:", std::vector<int>{1, 2, 3, 4, 5},
            "\n deque:", std::deque<int>{1, 2, 3, 4, 5},
            "\n list:", std::list<int>{1, 2, 3, 4, 5},
            "\n array:", std::array<int, 5>{1, 2, 3, 4, 5});
  return EXIT_SUCCESS;
}
```

To get started, see [Requirements](#requirements) and [Installation](#installation).
See [Usage](#usage) for a full example.

## Requirements
The library requires C++1z to build, including compiler and standard library support.
The following minimum versions are required to build the library:

* GCC 7
* Clang 6.0

## Installation

This describes the installation process using cmake. As pre-requisites, you'll need git and cmake installed.
```bash
# Check out the library.
$ git clone https://github.com/bigillu/ab-print.git
# Make a build directory to place the build output.
$ mkdir build && cd build
# Generate a Makefile with cmake.
$ cmake ..
# Build the library.
$ make
```
This builds the `abprint` library and `example`.

## Usage
### Example
The ab-print library has a simple straight forward API. `ab::print(std::cout, data types...)`.
Find below a full example that demonstrates the usage for different data types.

```c++
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <print.hpp>

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
```
To run the above example,
```bash
cd build/example
./example
```

## Author
bigillu (Abhimanyu Selvan) is the primary author and maintainer of this library.
Twitter @a_bigillu

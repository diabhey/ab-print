/**
 * @file print.hpp
 * @author Bigillu
 * @brief Generic Print Library
 * @version 0.1
 * @date 2019-06-08
 *
 * @copyright Copyright (c) 2019
 *
 */

// #include <experimental/source_location>
#include <ostream>
#include <utility>

namespace ab {

namespace typetraits {
// Trait to determine if it is a STL container
template <typename T, typename = void>
struct is_container : std::false_type {};

template <typename... Ts>
struct is_container_helper {
  typedef void type;
};

/**
 * @brief is_container template specialization
 * Determines if the type is a container or not,
 *
 * @tparam T the "type" that is passed
 *
 * NOTE: typename T::allocator_type check has been removed
 * in order to be able to deduce the std::array<> type because
 * the std::array does not have a allocator_type
 */
template <typename T>
struct is_container<
    T,
    typename is_container_helper<
        typename T::value_type, typename T::size_type, typename T::iterator,
        typename T::const_iterator, decltype(std::declval<T>().size()),
        decltype(std::declval<T>().begin()), decltype(std::declval<T>().end()),
        decltype(std::declval<T>().cbegin()),
        decltype(std::declval<T>().cend())>::type> : public std::true_type {};

// Typedefs that combine traits with std::enable_if.
// This is done for convinience and to avoide excessive typing.
template <typename T>
using if_integral = std::enable_if<
    std::is_integral<T>::value || std::is_floating_point<T>::value, T>;

template <typename T>
using if_container = std::enable_if<is_container<T>::value, T>;

template <typename T>
using if_non_integral = std::enable_if<not(std::is_integral<T>::value ||
                                           std::is_floating_point<T>::value ||
                                           is_container<T>::value),
                                       T>;
}  // namespace typetraits

// Overloaded << operator to print std::pair. It will
// also be triggered while using std::map
template <typename Key, typename Value>
std::ostream &operator<<(std::ostream &os, const std::pair<Key, Value> p) {
  os << "{ " << p.first << ", " << p.second << " }";
  return os;
}

/**
 * @brief print() specialization for integral types
 *
 */
template <typename T, typename = typename typetraits::if_integral<T>::type>
void print(std::ostream &stream, const T value) {
  stream << value << " ";
}

/**
 * @brief print() specialization for non-integral types (ex, std::string)
 * passing a std::string by reference is cheaper than passing by value
 */
template <typename T, typename = typename typetraits::if_non_integral<T>::type>
void print(std::ostream &stream, const T &value) {
  stream << value << " ";
}

/**
 * @brief print() specialization for STL containers
 * Both sequential and associative containers are taken into
 * account
 */
template <typename T>
auto print(std::ostream &stream, const T &value) ->
    typename std::enable_if<typetraits::is_container<T>::value>::type {
  stream << "{ ";
  for (typename T::const_iterator it = value.begin(); it != value.end(); ++it) {
    stream << *it << " ";
  }
  stream << " } ";
}

/**
 * @brief Called when the parameter pack is empty
 *
 * @tparam Function function object to be called.
 */
template <typename Function>
void printArgs(Function f) {
  // Parameter pack is empty.
}

/**
 * @brief Generic recursive print function
 *
 * @tparam Function function object to be called
 * @tparam First First argument of the pack
 * @tparam Rest The remaining arguments of the pack
 */
template <typename Function, typename FirstArg, typename... Rest>
void printArgs(Function f, FirstArg first, Rest... rest) {
  f(first);
  printArgs(f, rest...);
}

/**
 * @brief Generic print function
 *
 * @tparam Args list of arguments
 * @param stream Ostream object reference
 * @param args list of args of different types
 */
template <class... Args>
void print(std::ostream &stream, Args... args) {
  // stream << location.file_name() << "::" << location.function_name() << "("
  //  << location.line() << ") - ";
  printArgs([&](auto arg) { print(stream, arg); }, args...);
  stream << '\n';
}
}  // namespace ab
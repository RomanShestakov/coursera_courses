#include "max1.hpp"
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <type_traits>

using namespace std::string_literals;

template <typename T> std::add_rvalue_reference_t<T> declval();

template <typename T> struct Tricky {
  Tricky() = delete;
  const volatile T foo();
};

int main() {
  int a = 42;
  int b = 3;

  std::cout << "max:" << ::max(a, b) << std::endl;

  int a1[::max(sizeof(char), 1000u)];
  std::array<std::string, ::max(sizeof(char), 1000u)> arr;
  std::cout << "array size:" << std::size(a1) << " " << arr.size() << std::endl;
  // void *vp = nullptr;
  foo(&a);

  // decltype

  std::string x;
  decltype(x) y;
  y = "test";
  auto z = "test"s;

  //
  decltype(declval<Tricky<int>>().foo()) t = 0;

  std::cout << t << std::endl;

  // decltype(auto)

  int xx = 1;
  decltype(auto) yy = xx;

  // int &
  decltype(auto) yref = (xx);

  std::cout << yy << std::endl;
}

#pragma once
#include <concepts>

template <typename T1, typename T2>
constexpr auto max(T1 a, T2 b)
  requires std::totally_ordered<T1> && std::totally_ordered<T2>
{
  return b < a ? a : b;
}

template <typename T> T foo(T *p) {
  // undeclared(p);

  static_assert(sizeof(int) < 10, "int is too small");
  return *p;
}

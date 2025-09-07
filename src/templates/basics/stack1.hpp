#pragma once

#include <cassert>
#include <vector>

template <typename T> class Stack {
private:
  std::vector<T> elems;

public:
  void push(T const &elem);
  void pop();
  T const &top() const;
  bool empty() const { return elems.empty(); }
};

#include "stack1_impl.hpp"

#pragma once
#include "stack1.hpp"

template <typename T> void Stack<T>::push(T const &elem) {
  elems.push_back(elem);
}

template <typename T> void Stack<T>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T> T const &Stack<T>::top() const {
  assert(!elems.empty());
  return elems.back();
}

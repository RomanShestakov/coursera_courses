#include "stack1.hpp"
#include <iostream>

int main() {
  Stack<int> s;

  // s.pop();

  s.push(1);
  s.push(2);

  std::cout << s.top() << std::endl;

  s.pop();
  s.pop();

  return 0;
}

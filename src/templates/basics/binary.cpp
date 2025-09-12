#include <iostream>

template <unsigned long N> struct binary {
  static unsigned const value = binary<N / 10>::value * 2 + N % 10;
};

template <> struct binary<0> {
  static unsigned const value = 0;
};

int main() {
  std::cout << "binary 1:" << binary<1>::value << std::endl;
  std::cout << "binary 11:" << binary<11>::value << std::endl;
  std::cout << "binary 101:" << binary<101>::value << std::endl;
  std::cout << "binary 111:" << binary<111>::value << std::endl;
  std::cout << "binary 1001:" << binary<1001>::value << std::endl;

  return 0;
}

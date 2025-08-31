
#include "gtest/gtest.h"
#include <string>
#include <vector>

using namespace std;

namespace wb {

// Напишите функцию, которая
// называется Factorial
// возвращает int
// принимает int и возвращает факториал своего аргумента. Гарантируется, что
// аргумент функции по модулю не превышает 10. Для отрицательных аргументов
// функция должна возвращать 1. Аргумент функции Результат
// 1
// 1
// -2
// 1
// 4
// 24
long factorial(int n) {
  long a = 1;

  if (n < 0)
    return 1;

  for (int i = n; i >= 0; i--) {
    a *= (i < 2) ? 1 : i;
  }

  return a;
}

bool isPolindrom(const std::string &in) {
  for (size_t i = 0; i < in.size() / 2; i++) {
    if (in[i] != in[in.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

std::vector<std::string> palindromFilter(const std::vector<std::string> &words,
                                         size_t minLength) {
  std::vector<std::string> result;
  for (auto word : words) {
    if (word.size() >= minLength && isPolindrom(word)) {
      result.emplace_back(word);
    }
  }
  return result;
}

} // namespace wb

using namespace wb;
TEST(factorial, case1) {
  EXPECT_EQ(3628800, factorial(10));
  EXPECT_EQ(1, factorial(-2));
  EXPECT_EQ(1, factorial(1));
  EXPECT_EQ(24, factorial(4));
}

TEST(isPolindron, case2) {
  EXPECT_EQ(true, isPolindrom("madam"));
  EXPECT_EQ(false, isPolindrom("gentleman"));
}

TEST(polindromfilter, case3) {
  std::vector<std::string> expected{"abacaba"};
  EXPECT_EQ(expected, palindromFilter({"abacaba", "aba"}, 5));
}

TEST(polindromfilter, case4) {
  std::vector<std::string> expected{"abacaba", "aba"};
  EXPECT_EQ(expected, palindromFilter({"abacaba", "aba"}, 2));
}

TEST(polindromfilter, case5) {
  std::vector<std::string> expected{"weew"};
  EXPECT_EQ(expected, palindromFilter({"weew", "bro", "code"}, 4));
}

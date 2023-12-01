
#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

namespace wb {


// Напишите функцию, которая
// называется Factorial
// возвращает int
// принимает int и возвращает факториал своего аргумента. Гарантируется, что аргумент функции по модулю не превышает 10. Для отрицательных аргументов функция должна возвращать 1.
// Аргумент функции
// Результат
// 1
// 1
// -2
// 1
// 4
// 24
long factorial (int n) {
    long a = 1;

    if( n < 0) return 1;

    for( int i = n; i >= 0; i-- ) {
        a *= ( i < 2) ? 1 : i;
    }

    return a;
}

}

using namespace wb;
TEST(factorial, case1) {
    EXPECT_EQ( 3628800, factorial( 10 ) );
    EXPECT_EQ( 1, factorial( -2 ) );
    EXPECT_EQ( 1, factorial( 1 ) );
    EXPECT_EQ( 24, factorial( 4 ) );
}

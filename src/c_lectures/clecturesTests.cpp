
#include "gtest/gtest.h"

extern "C" {
    int gcd( int a, int b);
}

TEST(gcd, case1) {
    EXPECT_EQ( 1, gcd( 39, 13) );
}

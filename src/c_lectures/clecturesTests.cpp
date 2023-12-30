
#include "gtest/gtest.h"
// #include <algorithm>
// #include <numeric>
// #include <unordered_set>
// #include <vector>
// #include <unordered_map>
// #include <limits>

extern "C" {
#include "clectures.h"
}

TEST(gcd, case1) {
    EXPECT_EQ( 1, gcd( 39, 13) );
}

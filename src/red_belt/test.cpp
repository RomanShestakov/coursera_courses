
#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <limits>
#include <memory>
#include "red_belt.h"

namespace red_belt {


    TEST(strSplit, case1) {
        std::string s{ "The quick brown fox jumps over the lazy dog" };
        std::vector< std::string_view> expected
            { "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
        EXPECT_EQ( expected, split( s ) );
    }

  TEST(strSplit2, case1) {
        std::string s{ "/home/dir1/dir2//.././/dir3/" };
        std::vector< std::string_view> expected
            { "home", "dir1", "dir2", "", "..", ".", "", "dir3", ""};
      EXPECT_EQ( expected, split( s, '/' ) );
    }

}

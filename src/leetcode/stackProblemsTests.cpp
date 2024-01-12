
#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <limits>
#include <memory>
#include "stackProblems.h"

namespace leetcode {

    // Input: path = "/home/"
    // Output: "/home"
    TEST(simplifyPath, case1) {
        std::string expected{ "/home" };
        EXPECT_EQ( expected, simplifyPath( "/home/" ) );
    }

    // Input: path = "/../"
    // Output: "/"
    TEST(simplifyPath, case2) {
        std::string expected{ "/" };
        EXPECT_EQ( expected, simplifyPath( "/../" ) );
    }

    // Input: path = "/home//foo/"
    // Output: "/home/foo"
    TEST(simplifyPath, case3) {
        std::string expected{ "/home/foo" };
        EXPECT_EQ( expected, simplifyPath( "/home//foo" ) );
    }


}

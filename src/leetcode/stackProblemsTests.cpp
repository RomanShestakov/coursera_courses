
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

    // Input: s = "leEeetcode"
    // Output: "leetcode"
    // Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
    // Example 2:

    // Input: s = "abBAcC"
    // Output: ""
    // Explanation: We have many possible scenarios, and all lead to the same answer. For example:
    // "abBAcC" --> "aAcC" --> "cC" --> ""
    // "abBAcC" --> "abBA" --> "aA" --> ""
    // Example 3:

    //std::string makeGood( std::string s);
    TEST(makeGood, case1) {
        std::string expected{ "leetcode" };
        EXPECT_EQ( expected, makeGood( "leEeetcode" ) );
    }

    // Input: s = "abBAcC"
    // Output: ""
    TEST(makeGood, case2) {
        std::string expected{ "" };
        EXPECT_EQ( expected, makeGood( "abBAcC" ) );
    }

}

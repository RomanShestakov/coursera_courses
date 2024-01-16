
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

    // Input
    // ["RecentCounter", "ping", "ping", "ping", "ping"]
    // [[], [1], [100], [3001], [3002]]
    // Output
    // [null, 1, 2, 3, 3]
    TEST(recentCalls, case1) {
        RecentCounter counter;
        EXPECT_EQ( 1, counter.ping( 1 ) );
        EXPECT_EQ( 2, counter.ping( 100 ) );
        EXPECT_EQ( 3, counter.ping( 3001 ) );
        EXPECT_EQ( 3, counter.ping( 3002 ) );
    }

    // Input
    // ["MovingAverage", "next", "next", "next", "next"]
    // [[3], [1], [10], [3], [5]]
    // Output
    // [null, 1.0, 5.5, 4.66667, 6.0]
    TEST(movingAverage, case1) {
        MovingAverage mv( 3 );
        EXPECT_NEAR( 1.0, mv.next( 1 ), 0.00001 );
        EXPECT_NEAR( 5.5, mv.next( 10 ), 0.00001 );
        EXPECT_NEAR( 4.66667, mv.next( 3 ), 0.00001 );
        EXPECT_NEAR( 6.0, mv.next( 5 ), 0.00001 );
    }



    // // Input: temperatures = [73,74,75,71,69,72,76,73]
    // // Output: [1,1,4,2,1,1,0,0]
    // TEST(dailyTemperatures, case21) {
    //     std::vector<int> v = {73,74,75,71,69,72,76,73};
    //     std::vector<int> expected = {1,1,4,2,1,1,0,0};
    //     EXPECT_EQ( expected, dailyTemperatures( v ) );
    // }


}

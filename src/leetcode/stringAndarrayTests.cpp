
#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <limits>
#include "stringAndarray.h"


namespace leetcode {

    TEST(twoSum, case1) {
        std::vector<int> v = {2,7,11,15};
        std::vector<int> result = twoSum( v, 9);
        EXPECT_TRUE( ( 1 == result[ 0 ] && 0 == result[ 1] ) || ( 0 == result[ 0 ]) && 1 == result[ 1 ] );
    }

    TEST(twoSum1, case1) {
        std::vector<int> v = {2,7,11,15};
        std::vector<int> result = twoSum1( v, 9);
        EXPECT_TRUE( ( 1 == result[ 0 ] && 0 == result[ 1] ) || ( 0 == result[ 0 ]) && 1 == result[ 1 ] );
    }


    TEST(reverseString, case2) {
        std::vector<char> v = {'h','e','l','l','o'};
        std::vector<char> expected = {'o','l','l','e','h'};
        reverseString( v );
        EXPECT_EQ( expected, v );
    }

    TEST(sortedSqr, case1) {
        std::vector<int> v = {-4,-1,0,3,10};
        std::vector<int> expected = {0,1,9,16,100};
        EXPECT_EQ( expected, sortedSquares( v ) );
    }


    TEST(sortedSqr, case2) {
        std::vector<int> v = {-4,-1,0,3,10};
        std::vector<int> expected = {0,1,9,16,100};
        EXPECT_EQ( expected, sortedSquares1( v ) );
    }


    TEST(findLength, case1) {
        std::vector<int> v = {3, 1, 2, 7, 4, 2, 1, 1, 5};
        int expected = 4;
        EXPECT_EQ( expected, findLength( v, 8 ) );
    }


    TEST(findLongestString, case1) {
        std::string v = "1101100111";
        int expected = 5;
        EXPECT_EQ( expected, findLongestString( v ) );
    }

    TEST(findLongestString1, case1) {
        std::string v = "1101100111";
        int expected = 5;
        EXPECT_EQ( expected, findLongestString1( v ) );
    }


    TEST(numSubarrayProductLessThanK, case1) {
        std::vector<int> v = {10, 5, 2, 6};
        int expected = 8;
        EXPECT_EQ( expected, numSubarrayProductLessThanK( v, 100 ) );
    }


    TEST(largestSumOfsubarrays, case1) {
        //testing::internal::CaptureStdout();
        std::vector<int> v = {3, -1, 4,12,-8,5,6};
        int expected = 18;
        EXPECT_EQ( expected, largestSumOfsubarrays( v, 4 ) );
        //std::string output = testing::internal::GetCapturedStdout();

        //std::cerr << output << std::endl;

    }

    TEST(largestSumOfsubarrays1, case1) {
        std::vector<int> v = {3, -1, 4,12,-8,5,6};
        int expected = 18;
        EXPECT_EQ( expected, largestSumOfsubarrays1( v, 4 ) );
    }

    TEST(findMaxAverage, case1) {
        std::vector<int> v = {1,12,-5,-6,50,3};
        double expected = 12.75;
        EXPECT_EQ( expected, findMaxAverage( v, 4 ) );
    }


    TEST(longestOnes, case1) {
        std::vector<int> v = {1,1,1,0,0,0,1,1,1,1,0};
        double expected = 6;
        EXPECT_EQ( expected, longestOnes( v, 2 ) );
    }

    TEST(longestOnes, case2) {
        std::vector<int> v = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        double expected = 10;
        EXPECT_EQ( expected, longestOnes( v, 3 ) );
    }


    TEST(answerQueries, case1) {
        std::vector<int> v = {1, 6, 3, 2, 7, 2};
        std::vector<std::vector<int>> q = {{0, 3}, {2, 5}, {2, 4}};
        std::vector<bool> expected = {true, false, true};
        EXPECT_EQ( expected, answerQueries( v, q, 14 ) );
    }


    TEST(waystoSplitarray, case1) {
        std::vector<int> v = {10,4,-8,7};
        int expected = 2;
        EXPECT_EQ( expected, waysToSplitArray( v ) );
    }


    // TEST(minstartValue, case1) {
    //     std::vector<int> v = {-3,2,-3,4,2};
    //     int expected = 5;
    //     EXPECT_EQ( expected, minStartValue( v ) );
    // }

    // TEST(minstartValue, case2) {
    //     std::vector<int> v = {1,2};
    //     int expected = 1;
    //     EXPECT_EQ( expected, minStartValue( v ) );
    // }


    // Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
    // Output: [-1,-1,-1,5,4,4,-1,-1,-1]
    // TEST(getAverages, case2) {
    //     std::vector<int> v = {7,4,3,9,1,8,5,2,6};
    //     std::vector< int > expected = {-1,-1,-1,5,4,4,-1,-1,-1};
    //     EXPECT_EQ( expected, getAverages( v, 3 ) );
    // }

    // Input: s = "ab-cd"
    // Output: "dc-ba"
    TEST(reverseStr, case1) {
        std::string s = "ab-cd";
        std::string expected = "dc-ba";
        EXPECT_EQ( expected, reverseStr( s ) );
    }


    // Input: nums = [0,1,0,3,12]
    // Output: [1,3,12,0,0]

    TEST(moveZero, case1) {
        std::vector<int> v = {0,1,0,3,12};
        std::vector<int> expected = {1,3,12,0,0};
        moveZeros( v );
        EXPECT_EQ( expected, v );
    }


    TEST(minSubArrayLen, case1) {
        std::vector<int> v = {2,3,1,2,4,3};
        int expected = 2;
        EXPECT_EQ( expected, minSubArrayLen( 7, v ) );
    }

    TEST(minSubArrayLen, case2) {
        std::vector<int> v = {1,4,4};
        int expected = 1;
        EXPECT_EQ( expected, minSubArrayLen( 4, v ) );
    }


    TEST(maxVowels, case1) {
        std::string s = "abciiidef";
        int expected = 3;
        EXPECT_EQ( expected, maxVowels( s, 3 ) );
    }


    TEST(equalSubstring, case1) {
        std::string s = "abcd";
        std::string t = "bcdf";
        int expected = 3;
        EXPECT_EQ( expected, equalSubstring( s, t, 3 ) );
    }



    // For example, given s = "eceba" and k = 2, return 3. The longest substring with at most 2 distinct characters is "ece".

    //int longestsubst( std::string s, int k) {

    TEST(longestsubst, case1) {
        std::string s = "eceba";
        int expected = 3;
        EXPECT_EQ( expected, longestsubst( s, 2 ) );
    }



    // Input: nums = [1,1,1], k = 2
    // Output: 2
    // Example 2:

    TEST(subarraySum, case1) {
        std::vector<int> v = {1,1,1};
        int expected = 2;
        EXPECT_EQ( expected, subarraySum( v, 2 ) );
    }


    // Input: nums = [1,2,3], k = 3
    // Output: 2

    TEST(subarraySum, case2) {
        std::vector<int> v = {1, 2, 3};
        int expected = 2;
        EXPECT_EQ( expected, subarraySum( v, 3 ) );
    }



    TEST(subarraySum1, case1) {
        std::vector<int> v = {1,1,1};
        int expected = 2;
        EXPECT_EQ( expected, subarraySum1( v, 2 ) );
    }

    TEST(subarraySum1, case2) {
        std::vector<int> v = {1, 2, 3};
        int expected = 2;
        EXPECT_EQ( expected, subarraySum1( v, 3 ) );
    }



    // Input: nums = [1,1,2,1,1], k = 3
    // Output: 2
    // Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
    // Example 2:

    // Input: nums = [2,4,6], k = 1
    // Output: 0
    // Explanation: There is no odd numbers in the array.
    // Example 3:

    // Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    // Output: 16


    TEST(numberOfSubarrays, case1) {
        std::vector<int> v = {1,1,2,1,1};
        int expected = 2;
        EXPECT_EQ( expected, numberOfSubarrays( v, 3 ) );
    }

    TEST(numberOfSubarrays, case2) {
        std::vector<int> v = {2,4,6};
        int expected = 0;
        EXPECT_EQ( expected, numberOfSubarrays( v, 1 ) );
    }

    TEST(numberOfSubarrays, case3) {
        std::vector<int> v = {2,2,2,1,2,2,1,2,2,2};
        int expected = 16;
        EXPECT_EQ( expected, numberOfSubarrays( v, 2 ) );
    }



    // Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
    // Output: [[1,2,10],[4,5,7,8]]
    //vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    TEST(findWinners, case1) {
        std::vector<std::vector<int>> v = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
        auto result = findWinners( v );
        std::vector<std::vector<int>> expected = {{1,2,10},{4,5,7,8}};
        EXPECT_EQ( expected, result );
    }



    // Input: nums = [5,7,3,9,4,9,8,3,1]
    // Output: 8
    // Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.
    // Example 2:

    // Input: nums = [9,9,8,8]
    // Output: -1
    // Explanation: There is no number that occurs only once.
    //int largestUniqueNumber(vector<int>& nums) {

    TEST(largestUniqueNumber, case1) {
        std::vector<int> v = {5,7,3,9,4,9,8,3,1};
        int expected = 8;
        EXPECT_EQ( expected, largestUniqueNumber( v ) );
    }



    // Input: text = "nlaebolko"
    // Output: 1
    // Example 2:
    //int maxNumberOfBalloons(string text) {
    TEST(maxNumberOfBalloons, case1) {
        std::string s = "nlaebolko";
        int expected = 1;
        EXPECT_EQ( expected, maxNumberOfBalloons( s ) );
    }




    // Input: strs = ["eat","tea","tan","ate","nat","bat"]
    // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    TEST(groupAnagrams, case1) {
        std::vector<std::string> v = {"eat","tea","tan","ate","nat","bat"};
        std::vector<std::vector<std::string>> expected = {{"bat"},{"nat","tan"},{"ate","eat","tea"}};

        auto r = groupAnagrams( v );

        for( auto& v : r ) {
            std::sort( v.begin(), v.end());
        }

        for( auto& v : expected ) {
            std::sort( v.begin(), v.end());
        }

        EXPECT_EQ( expected, r );
    }


    TEST(minimumCardPickup, case1) {
        std::vector<int> v = {3,4,2,3,4,7};
        int expected = 4;
        EXPECT_EQ( expected, minimumCardPickup( v ) );
    }


    //[229,398,269,317,420,464,491,218,439,153,482,169,411,93,147,50,347,210,251,366,401]
    // answer = 973
    TEST(maximumSum, case1) {
        std::vector<int> v = {229,398,269,317,420,464,491,218,439,153,482,169,411,93,147,50,347,210,251,366,401};
        int expected = 973;
        EXPECT_EQ( expected, maximumSum( v ) );
    }


    // Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
    // Output: 1
    // Explanation: There is 1 equal row and column pair:
    // - (Row 2, Column 1): [2,7,7]
    //int equalPairs(vector<vector<int>>& grid) {
    TEST(equalPairs, case1) {
        std::vector<std::vector<int>> v = {{3,2,1},{1,7,6},{2,7,7}};
        int expected = 1;
        EXPECT_EQ( expected, equalPairs( v ) );
    }

    //bool canConstruct(string ransomNote, string magazine) {
    // Input:  ransomNote = "aa", magazine = "aab"
    //     Output: true
    TEST(canConstruct, case1) {
        std::string ransomNote = "aa";
        std::string magazine = "aab";
        int expected = true;
        EXPECT_EQ( expected, canConstruct( ransomNote, magazine ) );
    }


    // Input: jewels = "aA", stones = "aAAbbbb"
    // Output: 3
    // Example 2:
    // Input: jewels = "z", stones = "ZZ"
    // Output: 0
    //int numJewelsInStones(string jewels, string stones) {

    TEST(numJewelsInStones, case1) {
        std::string jewels = "aA";
        std::string stones = "aAAbbbb";
        int expected = 3;
        EXPECT_EQ( expected, numJewelsInStones( jewels, stones ) );
    }


    // Input: s = "abcabcbb"
    // Output: 3
    //     Explanation: The answer is "abc", with the length of 3.
    TEST(lengthOfLongestSubstring, case1) {
        std::string s = "abcabcbb";
        int expected = 3;
        EXPECT_EQ( expected, lengthOfLongestSubstring( s ) );
    }


    // Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    // Output: "Sao Paulo"
    // Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
    TEST(destCity, case1) {
        std::vector<std::vector<std::string>> v = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
        std::string expected = "Sao Paulo";
        EXPECT_EQ( expected, destCity( v ) );
    }


    TEST(isPathCrossing, case1) {
        std::string s = "NSEW";
        bool expected = true;
        EXPECT_EQ( expected, isPathCrossing( s ) );
    }

    TEST(isPathCrossing, case2) {
        std::string s = "NESWW";
        bool expected = true;
        EXPECT_EQ( expected, isPathCrossing( s ) );
    }


    //int  sumOfUnique(vector<int>& nums) {
    TEST(sumOfUnique, case1) {
        std::vector<int> v = {1,2,3,2};
        int expected = 4;
        EXPECT_EQ( expected, sumOfUnique( v ) );
    }



    // Input: arr =  [2,2,3,4]
    // Output: 2
    // Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
    // Example 2:

    // Input: arr =  [1,2,2,3,3,3]
    // Output: 3
    // Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
    // Example 3:

    // Input: arr = [2,2,2,3,3]
    // Output: -1
    // Explanation: There are no lucky numbers in the array.

    //int findLucky(vector<int>& arr) {
    TEST(findLucky, case1) {
        std::vector<int> v = {2,2,3,4};
        int expected = 2;
        EXPECT_EQ( expected, findLucky( v ) );
    }


    TEST(findLucky, case2) {
        std::vector<int> v = {1,2,2,3,3,3};
        int expected = 3;
        EXPECT_EQ( expected, findLucky( v ) );
    }

    TEST(findLucky, case3) {
        std::vector<int> v = {2,2,2,3,3};
        int expected = -1;
        EXPECT_EQ( expected, findLucky( v ) );
    }

    TEST(findLucky, case4) {
        std::vector<int> v = {1,2,2,3,3, 3};
        int expected = 3;
        EXPECT_EQ( expected, findLucky( v ) );
    }



    // Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
    // Example 1:
    // Input: arr = [1,2,2,1,1,3]
    // Output: true
    // Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
    // Example 2:

    // Input: arr = [1,2]
    // Output: false
    // Example 3:

    // Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
    // Output: true
    //bool uniqueOccurrences(vector<int>& arr) {

    TEST(uniqueOccurrences, case1) {
        std::vector<int> v = {1,2,2,1,1,3};
        bool expected = true;
        EXPECT_EQ( expected, uniqueOccurrences( v ) );
    }

    TEST(uniqueOccurrences, case2) {
        std::vector<int> v = {1,2 };
        bool expected = false;
        EXPECT_EQ( expected, uniqueOccurrences( v ) );
    }

    TEST(frequencySort, case2) {
        std::string s = "tree";
        std::string expected = "eert";
        EXPECT_EQ( expected, frequencySort( s ) );
    }


    //int numIdenticalPairs(vector<int>& nums) {
    TEST(numIdenticalPairs, case1) {
        std::vector<int> v = {1,2,3,1,1,3};
        int expected = 4;
        EXPECT_EQ( expected, numIdenticalPairs( v ) );
    }


    // Input: nums = [4,2,4,5,6]
    // Output: 17
    // Explanation: The optimal subarray here is [2,4,5,6].
    // Example 2:

    // Input: nums = [5,2,1,2,5,2,1,2,5]
    // Output: 8
    // Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

    //int maximumUniqueSubarray(vector<int>& nums) {

    TEST(maximumUniqueSubarray, case1) {
        std::vector<int> v = {4,2,4,5,6};
        int expected = 17;
        EXPECT_EQ( expected, maximumUniqueSubarray( v ) );
    }


    // // Input: nums = [5,2,1,2,5,2,1,2,5]
    // // Output: 8
    TEST(maximumUniqueSubarray, case2) {
        std::vector<int> v = {5,2,1,2,5,2,1,2,5};
        int expected = 8;
        EXPECT_EQ( expected, maximumUniqueSubarray( v ) );
    }



    // //bool checkInclusion(string s1, string s2) {
    // TEST(checkInclusion, case1) {
    //     std::string s1 = "adc";
    //     std::string s2 = "dcda";
    //     bool expected = true;
    //     EXPECT_EQ( expected, checkInclusion( s1, s2 ) );
    // }


    // Input: s = "egg", t = "add"
    // Output: true
    // Example 2:

    // Input: s = "foo", t = "bar"
    // Output: false
    // Example 3:

    // Input: s = "paper", t = "title"
    // Output: true

    //bool isIsomorphic(string s, string t) {
    TEST(isIsomorphic, case1) {
        std::string s1 = "egg";
        std::string s2 = "add";
        bool expected = true;
        EXPECT_EQ( expected, isIsomorphic( s1, s2 ) );
    }

    TEST(isIsomorphic, case2) {
        std::string s1 = "foo";
        std::string s2 = "bar";
        bool expected = false;
        EXPECT_EQ( expected, isIsomorphic( s1, s2 ) );
    }

    TEST(isIsomorphic, case3) {
        std::string s1 = "paper";
        std::string s2 = "title";
        bool expected = true;
        EXPECT_EQ( expected, isIsomorphic( s1, s2 ) );
    }



    // Input: pattern = "abba", s = "dog cat cat dog"
    // Output: true
    // Example 2:

    // Input: pattern = "abba", s = "dog cat cat fish"
    // Output: false
    // Example 3:

    // Input: pattern = "aaaa", s = "dog cat cat dog"
    // Output: false

    //bool wordPattern(string pattern, string s) {
    TEST(wordPattern, case3) {
        std::string s1 = "abba";
        std::string s2 = "dog cat cat dog";
        bool expected = true;
        EXPECT_EQ( expected, wordPattern( s1, s2 ) );
    }



    // Input: order = "cba", s = "abcd"
    // Output: "cbad"
    // Explanation:
    // "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
    // Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
    // Example 2:

    // Input: order = "cbafg", s = "abcd"
    // Output: "cbad"
    //string customSortString(string order, string s) {

    TEST(customSortString, case1) {
        std::string order = "cba";
        std::string s2 = "abcd";
        std::string expected = "cbad";
        EXPECT_EQ( expected, customSortString( order, s2 ) );
    }

    TEST(customSortString, case2) {
        std::string order = "exv";
        std::string s2 = "xwvee";
        std::string expected = "eexvw";
        EXPECT_EQ( expected, customSortString( order, s2 ) );
    }


    TEST(customSortString1, case1) {
        std::string order = "cba";
        std::string s2 = "abcd";
        std::string expected = "cbad";
        EXPECT_EQ( expected, customSortString1( order, s2 ) );
    }

    TEST(customSortString1, case2) {
        std::string order = "exv";
        std::string s2 = "xwvee";
        std::string expected = "eexvw";
        EXPECT_EQ( expected, customSortString1( order, s2 ) );
    }



//    // Input: word1 = "abc", word2 = "bca"
//    bool closeStrings(std::string word1, std::string word2);
    TEST(closeStrings, case1) {
        std::string word1 = "abc";
        std::string word2 = "bca";
        bool expected = true;
        EXPECT_EQ( expected, closeStrings( word1, word2 ) );
    }


    // Input: nums = [0,1]
    // Output: 2
    // Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
    // Example 2:

    // Input: nums = [0,1,0]
    // Output: 2
    // Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
    TEST(findMaxLength, case1) {
        std::vector<int> v = {5,2,1,2,5,2,1,2,5};
        int expected = 2;
        EXPECT_EQ( expected, findMaxLength( v ) );
    }


}

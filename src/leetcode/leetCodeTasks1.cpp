
#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <vector>


namespace leetcode {

    using namespace std;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.



// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]


using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<std::pair<int,int>> v;
    v.reserve(nums.size());

    for( int i = 0; i < nums.size(); ++i) {
        v.push_back( {nums[ i ], i } );
    }

    std::sort(v.begin(), v.end(), [&](auto& a, auto& b ){ return a.first < b.first; } );

    int l = 0;
    int r = v.size() - 1;

    while( l < r ) {
        int sum = v[ l ].first + v[ r ].first;
        if( sum == target) {
            break;
        }
        else if ( sum > target ) {
            r--;
        }
        else {
            l++;
        }
    }

    return {v[l].second, v[r].second};
}


// vector<int> twoSum1(vector<int>& nums, int target) {

//     std::vector<int> idx(nums.size());
//     iota(idx.begin(), idx.end(), 0);
//     std::sort(idx.begin(), idx.end(), [&nums]( auto a, auto b ){ return a < b;} );




// reverse string
// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]


    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        char tmp;

        while( l < r ){
            tmp = s[ l ];
            s[ l++ ] = s[ r ];
            s[ r-- ] = tmp;

        }
    }
}



// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums =  [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]


// O(n * log(n)) solution
std::vector<int> sortedSquares(std::vector<int>& nums) {
    for( int i = 0; i < nums.size(); ++i) {
        nums[ i ] = nums[ i ] * nums[ i ];
    }
    std::sort( nums.begin(), nums.end());
    return nums;
}


// O(N) solution
std::vector<int> sortedSquares1(std::vector<int>& nums) {
    std::vector<int> v( nums.size() );
    int l = 0;
    int r = nums.size() - 1;
    int sqrt;

    for( int i = nums.size() - 1; i >= 0; --i) {
        if( abs( nums[ l ] ) < abs( nums[ r ]) ) {
            sqrt = nums[ r-- ];
        }
        else {
            sqrt = nums[ l++ ];
        }
        v[ i ] = sqrt * sqrt;
    }
    return v;
}


// sliding window

// Example 1: Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k. This is the problem we have been talking about above. We will now formally solve it.

int findLength( const std::vector<int>& v, int k ) {
    int l = 0;
    int r = 0;
    int total = 0;

    for( int i = 0; i < v.size(); ++i ) {
        total += v[ r++ ];

        while( total > k ) {
            total -= v[ l++ ];
        }
    }

    return std::max( 0, r - l + 1 );
}



// Example 2: You are given a binary string s (a string containing only "0" and "1"). You may choose up to one "0" and flip it to a "1". What is the length of the longest substring achievable that contains only "1"?

// For example, given s = "1101100111", the answer is 5. If you perform the flip at index 2, the string becomes 1111100111.
int findLongestString( const std::string& v ) {
    int total = 0;
    bool flip = false;
    std::vector<int> a;

    for( int r = 0 ; r < v.size(); ++r) {
        if( v[ r ] == '1' ) {
            total++;
        } else if( !flip ) {
            total++;
            flip = true;
        } else {
            a.push_back(total);
            total = 0;
            flip = false;
        }
    }

    return *std::max_element(a.begin(), a.end());
}


using namespace leetcode;
TEST(twoSum, case1) {
    std::vector<int> v = {2,7,11,15};
    std::vector<int> expected = {0,1};
    EXPECT_EQ( expected, twoSum( v, 9) );
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


#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <vector>


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



TEST(twoSum, case1) {

    std::vector<int> v = {2,7,11,15};
    std:vector<int> expected = {0,1};
    EXPECT_EQ( expected, twoSum( v, 9) );
}

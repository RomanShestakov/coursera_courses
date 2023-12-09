
#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

namespace leetcode {


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



vector<int> twoSum1(vector<int>& nums, int target) {
    std::unordered_map<int,int> m;

    for(int i = 0; i < nums.size(); i++) {
        int comp = target - nums[ i ];
        auto it = m.find( comp );
        if(  it != m.end() ) {
            return { i, it -> second};
        }

        m[ nums[ i ] ] = i;
    }

    return { -1, -1};
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


// Because the string can only contain "1" and "0", another way to look at this problem is "what is the longest substring that contains at most one "0"?". Th
// different solution
// "1101100111"
int findLongestString1( const std::string& v ) {

    int l = 0;
    int curr = 0;
    int a = 0;

    for( int r = 0; r < v.size(); r++ ) {

        if( v[ r ] == '0' ) {
            curr++;
        }

        while( curr > 1 ) {
            if( v[ l ] == '0' ) {
                curr--;
            }
            l++;
        }

        a = std::max( a, r - l + 1);
        //std::cout << "r:" << r << "l:" << l << "curr:" << curr << std::endl;
    }

    return a;
}



// Given an array of positive integers nums and an integer k, return the number of subarrays where the product of all the elements in the subarray is strictly less than k.

// For example, given the input nums = [10, 5, 2, 6], k = 100, the answer is 8. The subarrays with products less than k are:

// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

int numSubarrayProductLessThanK( const std::vector<int>& nums, int k) {
    int l = 0;
    int total = 1;
    int count = 0;

    if( k <= 1 ) return 0;

    for(int r = 0; r < nums.size(); r++) {
        total *= nums[ r ];

        while( total >= k ) {
            total /= nums[ l++ ];
        }

        count += r -l +1;
    }

    return count;
}



//Example 4: Given an integer array nums and an integer k, find the sum of the subarray with the largest sum whose length is k.
//{3, -1, 4,12,-8,5,6};

int largestSumOfsubarrays( const std::vector<int>& nums, int k) {
    int sum = 0;
    int answ = 0;

    for(int r = 0; r < k; r++) {
        sum += nums[ r ];
    }

    answ = sum;

    for(int r = k; r < nums.size(); r++) {
        sum += nums[ r ] - nums[ r - k ];
        answ = std::max(answ, sum);
    }

    return answ;
}


// second solution
int largestSumOfsubarrays1( const std::vector<int>& nums, int k) {

    int l = 0;
    int sum = 0;
    int answ = 0;

    for(int r = 0; r < nums.size(); r++) {

        if( r < k ) {
            sum += nums[ r ];
        }
        else {
            sum += nums[ r ] - nums[ r - k ];
        }

        answ = std::max( sum, answ);
    }

    return answ;
}


// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.



// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

double findMaxAverage(vector<int>& nums, int k) {
    double sum;
    double a;

    for( int i = 0; i < k; i++ ) {
        sum += nums[ i ];
    }

    a = sum / k;

    for( int i = k; i < nums.size(); i++ ) {
        sum += nums[ i ] - nums[ i - k];
        double m = sum / k;
        a= std::max( a, m );
    }

    return a;
}


//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int a = 0;
    int curr = 0;

    for( int r = 0; r < nums.size(); r++ ) {

        if( nums[ r ] == 0 ) {
            curr++;
        }
        while( curr > k && l < r) {
            if( nums[ l ] == 0 ) {
                curr--;
            }
            l++;
        }

        a = std::max(a, r -l + 1);
    }
    return a;
}


// leetcode solution
// int longestOnes(vector<int>& nums, int k) {
//     int left = 0, right;
//     int n = nums.size();
//     for (right = 0; right < n; right++) {
//         // If we included a zero in the window we reduce the value of k.
//         // Since k is the maximum zeros allowed in a window.
//         if (nums[right] == 0) {
//             k--;
//         }
//         // A negative k denotes we have consumed all allowed flips and window has
//         // more than allowed zeros, thus increment left pointer by 1 to keep the window size same.
//         if (k < 0) {
//             // If the left element to be thrown out is zero we increase k.
//             k += 1 - nums[left];
//             left++;
//         }
//     }
//     return right - left;
// }


// Example 1: Given an integer array nums, an array queries where queries[i] = [x, y] and an integer limit, return a boolean array that represents the answer to each query. A query is true if the sum of the subarray from x to y is less than limit, or false otherwise.

// For example, given nums = [1, 6, 3, 2, 7, 2], queries = [[0, 3], [2, 5], [2, 4]], and limit = 13, the answer is [true, false, true]. For each query, the subarray sums are [12, 14, 12].

std::vector<bool> answerQueries( std::vector<int> & nums, std::vector<std::vector<int>>& q, int limit ) {
    std::vector<int> sums = { nums[0] };
    std::vector< bool > a;

    for(int i = 1; i < nums.size(); i++ ) {
        sums.push_back(  nums[ i ] + sums[ i - 1] );
    }

    for( auto el : q ){
        int s = sums[ el[ 1 ] ] - sums[ el[ 0 ] ] + nums[ el[ 0 ] ];
        a.push_back( ( s < limit ) );
    }

    return a;
}



// You are given a 0-indexed integer array nums of length n.

// nums contains a valid split at index i if the following are true:

// The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
// There is at least one element to the right of i. That is, 0 <= i < n - 1.
// Return the number of valid splits in nums.

// Example 1:

// Input: nums = [10,4,-8,7]
// Output: 2
// Explanation:
// There are three ways of splitting nums into two non-empty parts:
// - Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
// - Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
// - Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
// Thus, the number of valid splits in nums is 2.

int waysToSplitArray(std::vector<int>& nums ) {
    std::vector<long> sums = { nums[0]};
    int a = 0;

    for(int i = 1; i < nums.size(); i++ ) {
        sums.push_back( sums.back() + nums[ i ] );
    }

    for(int i = 0 ; i < sums.size() - 1; i++ ) {
        // if( sums[ i ] >= sums[ nums.size() - 1 ] - sums[ i + 1 ] + nums[ i + 1] ) {
        //     a++;
        // }
        // better solution
        if( sums[ i ] >= sums.back() - sums[ i ] ) {
            a++;
        }

    }

    return a;
}




// TODO

// Given an array of integers nums, you start with an initial positive value startValue.

// In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

// Return the minimum positive value of startValue such that the step by step sum is never less than 1.



// Example 1:

// Input: nums = [-3,2,-3,4,2]
// Output: 5
// Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
// step by step sum
// startValue = 4 | startValue = 5 | nums
//   (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
//   (1 +2 ) = 3  | (2 +2 ) = 4    |   2
//   (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
//   (0 +4 ) = 4  | (1 +4 ) = 5    |   4
//   (4 +2 ) = 6  | (5 +2 ) = 7    |   2

// int minStartValue( std::vector< int>& nums ) {
// }



// ou are given a 0-indexed array nums of n integers, and an integer k.

// The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.

// Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

// The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

// For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.


// Example 1:


// Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
// Output: [-1,-1,-1,5,4,4,-1,-1,-1]
// Explanation:
// - avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
// - The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
//   Using integer division, avg[3] = 37 / 7 = 5.
// - For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
// - For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
// - avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.
// Example 2:

// Input: nums = [100000], k = 0
// Output: [100000]
// Explanation:
// - The sum of the subarray centered at index 0 with radius 0 is: 100000.
//   avg[0] = 100000 / 1 = 100000.
// Example 3:

// Input: nums = [8], k = 100000
// Output: [-1]
// Explanation:
// - avg[0] is -1 because there are less than k elements before and after index 0.

// vector<int> getAverages(vector<int>& nums, int k) {
// }





// Given a string s, reverse the astring according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.



// Example 1:

// Input: s = "ab-cd"
// Output: "dc-ba"
// Example 2:

// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:

// Input: s = "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
std::string reverseStr( std::string s ) {

    int l = 0;
    int r = s.size() - 1;


    auto isLetter = [](char c){ return ( c >= 'a' && c<= 'z') || (c>= 'A' && c <= 'Z'); };

    while( l < r ) {

        while( !isLetter( s[ l ] ) && l < r ) {
            l++;
        }


        while( !isLetter( s[ r ] ) && r > l ) {
            r--;
        }

        char tmp = s[ l ];
        s[ l ] = s[ r ];
        s[ r ] = tmp;

        //std::cout << s[ l ] << isLetter( s[ l ] ) << std::endl;

        l++;
        r--;
    }

    return s;
}




// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.



// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
void moveZeros( std::vector<int>& nums) {
    int firstNonZero = 0;

    // move all not zeros to from
    // fill the rest with zeros

    for( int i = 0; i < nums.size(); i++ ) {
        if( nums[ i ] != 0 ) {
            nums[ firstNonZero++] = nums[ i ];
        }
    }

    for( int i = firstNonZero; i< nums.size(); i++ ) {
        nums[ i ] = 0 ;
    }

}




// Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

// For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
// Return the resulting string.



// Example 1:

// Input: word = "abcdefd", ch = "d"
// Output: "dcbaefd"
// Explanation: The first occurrence of "d" is at index 3.
// Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
// Example 2:

// Input: word = "xyxzxe", ch = "z"
// Output: "zxyxxe"
// Explanation: The first and only occurrence of "z" is at index 3.
// Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
// Example 3:

// Input: word = "abcd", ch = "z"
// Output: "abcd"
// Explanation: "z" does not exist in word.
// You should not do any reverse operation, the resulting string is "abcd".



// Given an array of positive integers nums and a positive integer target, return the minimal length of a
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.



// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

 int minSubArrayLen(int target, vector<int>& nums) {
    std::vector< int> sums = { nums[ 0 ]};
    for( int i = 1; i < nums.size(); i++ ) {
        sums.push_back( sums.back() + nums[ i ] );
    }
    if( sums.back() < target ) return 0;
    int a = nums.size();
    int l = 0;
    for( int r = 0; r < sums.size(); r++ ) {
        if( sums[ r ] < target ) {
            continue;
        }
        while( l <= r ) {
            if( sums[ r ] - sums[ l ] + nums[ l ] >= target ) {
                a = min( r - l + 1, a);
                l++;
            }
            else
            break;
        }
    }
    return a;
}


// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.



// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.


int maxVowels(string s, int k) {
    int l = 0;
    int a = 0;
    int curr = 0;

    std::string ss = "aeiou";

    auto isVowel = [ &ss ]( char c ){ return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
    for( int r = 0; r < s.size(); r++ ) {
        if( isVowel( s[ r ] ) ) {
            curr++;
        }
        // 0 - 2

        if( r >= k ) {
            if( isVowel( s[ l ] ) ) {
                curr--;
            }
            l++;
        }

        a = max( a, curr);

    }

    return a;
}

// You are given two strings s and t of the same length and an integer maxCost.

// You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

// Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.



// Example 1:

// Input: s = "abcd", t = "bcdf", maxCost = 3
// Output: 3
// Explanation: "abc" of s can change to "bcd".
// That costs 3, so the maximum length is 3.
// Example 2:

// Input: s = "abcd", t = "cdef", maxCost = 3
// Output: 1
// Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
// Example 3:

// Input: s = "abcd", t = "acde", maxCost = 0
// Output: 1
// Explanation: You cannot make any change, so the maximum length is 1.

int equalSubstring(string s, string t, int maxCost) {

    // calc diffs between s and t

    //iter over diff to collect sums

    // collect results

    std::vector< int> diffs;

    for( int i = 0; i< s.size(); i++ ) {
        diffs.push_back( abs( s[ i ] - t[ i ]));
    }

    int curr = 0;
    int a = 0;
    int l = 0;
    for( int r = 0; r < diffs.size(); r++ ) {
        curr += diffs[ r ];

        while( curr > maxCost && l <= r ) {
            curr -= diffs[ l++ ];
        }

        a = max( r -l +1, a );

    }

    return a;

}


// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

// Example 1:

// Input: gain = [-5,1,5,0,-7]
// Output: 1
// Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
// Example 2:

// Input: gain = [-4,-3,-2,-1,4,3,2]
// Output: 0
// Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.



// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.
// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
// Example 2:

// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
// Example 3:

// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0




// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3


// Given a string s consisting of lowercase English letters, return the first letter to appear twice.

// Note:

// A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
// s will contain at least one letter that appears twice.


// Example 1:

// Input: s = "abccbaacz"
// Output: "c"
// Explanation:
// The letter 'a' appears on the indexes 0, 5 and 6.
// The letter 'b' appears on the indexes 1 and 4.
// The letter 'c' appears on the indexes 2, 3 and 7.
// The letter 'z' appears on the index 8.
// The letter 'c' is the first letter to appear twice, because out of all the letters the index of its second occurrence is the smallest.


//Example 3: Given an integer array nums, find all the unique numbers x in nums that satisfy the following: x + 1 is not in nums, and x - 1 is not in nums.
std::vector< int > uniqNumber( std::vector< int > nums ) {
    std::unordered_set<int> set (nums.begin(), nums.end());
    std::vector< int > v;
    for( int n : nums ) {
        if( set.find( n + 1 ) == set.end() && set.find( n - 1 ) == set.end() ) {
            v.push_back( n);
        }
    }

    return v;
}



// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.



// Example 1:

// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.
// Example 2:

// Input: sentence = "leetcode"
// Output: false



// Example 1: You are given a string s and an integer k. Find the length of the longest substring that contains at most k distinct characters.
// For example, given s = "eceba" and k = 2, return 3. The longest substring with at most 2 distinct characters is "ece".

int longestsubst( std::string s, int k) {

    int a = 0;
    int l = 0;

    std::unordered_map< char, int > m;

    for( int r = 0; r < s.size(); r++ ) {
        m[ s[ r ] ]++;

        std::cout << r << " + " << s[ r ] << " " << m[ s[ r ] ]<< std::endl;

        while( m.size() > k && l < r ) {
            m[ s[ l ] ]--;
            if( m[ s[ l ] ] == 0 ) {
                m.erase( s[ l ] );
            }
            std::cout << l << " -- " << s[ l ] << " " << m[ s[ l ] ]<< std::endl;
            l++;
        }

        a = max( a, r - l + 1 );
    }

    return a;
}


// Example 2: 2248. Intersection of Multiple Arrays

// Given a 2D array nums that contains n arrays of distinct integers, return a sorted array containing all the numbers that appear in all n arrays.

// For example, given nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]], return [3, 4]. 3 and 4 are the only numbers that are in all arrays.





// Example 3: 1941. Check if All Characters Have Equal Number of Occurrences

// Given a string s, determine if all characters have the same frequency.

// For example, given s = "abacbc", return true. All characters appear twice. Given s = "aaabb", return false. "a" appears 3 times, "b" appears 2 times. 3 != 2.



// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

// 1 1 1
//   1 1
//     1

// 1 2 3 4 5 6
// 1

// 1 2 3
//   2 3
//     3

// brute force
int subarraySum( std::vector< int >& nums, int k ) {
    int a = 0;

    for( int i = 0; i < nums.size(); i++ ){

        for( int j = 0; j <= i; j++ ) {

            int s = 0;

            for( int l = j; l <= i; l++ ) {
                s += nums[ l ];
            }

            if( s == k ) {
                a++;
            }
        }
    }
    return a;

}




// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2


// 1 2 3
int subarraySum1( std::vector< int >& nums, int k ) {
    std::unordered_map< int, int> m;
    int curr = 0;
    int a = 0 ;
    m[ 0 ] = 1;

    for( int i = 0; i < nums.size(); i++ ) {
        curr += nums[ i ];
        a+=m[ curr - k];
        m[ curr ]++;
    }

    return a;

}



// Example 5: 1248. Count Number of Nice Subarrays

// Given an array of positive integers nums and an integer k. Find the number of subarrays with exactly k odd numbers in them.

// For example, given nums = [1, 1, 2, 1, 1], k = 3, the answer is 2. The subarrays with 3 odd numbers in them are [1, 1, 2, 1, 1] and [1, 1, 2, 1, 1].

// Example 1:

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



int numberOfSubarrays(vector<int>& nums, int k) {
    std::vector< int > v;

    for( int i = 0; i < nums.size(); i++ ) {
        nums[ i ] % 2 == 0 ? v.push_back( 0 ) : v.push_back( 1 );
    }

    std::unordered_map< int, int > m;
    m[ 0 ] = 1;

    int curr = 0;
    int a = 0;

    for( int n : v ) {
        curr += n;
        a += m[ curr - k ];
        m[ curr ]++;
    }

    return a;
}



// 930. Binary Subarrays With Sum
// Medium
// Topics
// Companies
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.



// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15



// You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

// Return a list answer of size 2 where:

// answer[0] is a list of all players that have not lost any matches.
// answer[1] is a list of all players that have lost exactly one match.
// The values in the two lists should be returned in increasing order.

// Note:

// You should only consider the players that have played at least one match.
// The testcases will be generated such that no two matches will have the same outcome.


// Example 1:

// Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
// Output: [[1,2,10],[4,5,7,8]]
// Explanation:
// Players 1, 2, and 10 have not lost any matches.
// Players 4, 5, 7, and 8 each have lost one match.
// Players 3, 6, and 9 each have lost two matches.
// Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
// Example 2:

// Input: matches = [[2,3],[1,3],[5,4],[6,4]]
// Output: [[1,2,5,6],[]]
// Explanation:
// Players 1, 2, 5, and 6 have not lost any matches.
// Players 3 and 4 each have lost two matches.
// Thus, answer[0] = [1,2,5,6] and answer[1] = [].

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    std::unordered_map<int, int > m;

    for( auto el: matches ) {
        auto winner = el[ 0 ];
        auto looser = el[ 1 ];

        if( m.find(winner) == m.end()) {
            m[ winner ] = 0;
        }

        m[ looser ]++;
    }

    std::vector<int> a;
    std::vector<int> b;

    for( auto[ pl, sc]  : m ) {
        if( sc == 0 ) {
            a.push_back( pl );
        }
        else if( sc == 1 ){
            b.push_back( pl );
        }
    }

    std::sort( a.begin(), a.end());
    std::sort( b.begin(), b.end());

    return { a, b };
}



// Given an integer array nums, return the largest integer that only occurs once. If no integer occurs once, return -1.
// Example 1:

// Input: nums = [5,7,3,9,4,9,8,3,1]
// Output: 8
// Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.
// Example 2:

// Input: nums = [9,9,8,8]
// Output: -1
// Explanation: There is no number that occurs only once.
int largestUniqueNumber(vector<int>& nums) {
    std::map<int, int> m;

    for( auto n : nums ) {
        m[ n ]++;
    }

    for( auto it = m.rbegin(); it != m.rend(); it++ ) {
        if( it -> second == 1 ) {
            return it -> first;
        }
    }

    return -1;
}



// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.



// Example 1:



// Input: text = "nlaebolko"
// Output: 1
// Example 2:
int maxNumberOfBalloons(string text) {
        std::unordered_map< char, int> m { {'b', 0},
                                          {'a', 0},
                                          {'l',0},
                                          {'o',0},
                                          {'n',0}};


        for( auto c : text ) {
            if( m.find( c ) != m.end() ) {
                m[ c ]++;
            }
        }

        std::vector<int> v;
        for( auto& el : m ) {
            if( el.first == 'l' || el.first == 'o' ) {
                v.push_back( el.second / 2 );
            }
            v.push_back( el.second );
        }

        return *std::min_element( v.begin(), v.end() );

    }


using namespace leetcode;

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
    vector<vector<int>> v = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    auto result = findWinners( v );
    vector<vector<int>> expected = {{1,2,10},{4,5,7,8}};
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

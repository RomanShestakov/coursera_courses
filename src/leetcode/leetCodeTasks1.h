
#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <limits>
#include <map>
#include <sstream>

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

    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> twoSum1(std::vector<int>& nums, int target);




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


    void reverseString(std::vector<char>& s);



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
    std::vector<int> sortedSquares(std::vector<int>& nums);


    // O(N) solution
    std::vector<int> sortedSquares1(std::vector<int>& nums);


    // sliding window

    // Example 1: Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k. This is the problem we have been talking about above. We will now formally solve it.

    int findLength( const std::vector<int>& v, int k );



    // Example 2: You are given a binary string s (a string containing only "0" and "1"). You may choose up to one "0" and flip it to a "1". What is the length of the longest substring achievable that contains only "1"?

    // For example, given s = "1101100111", the answer is 5. If you perform the flip at index 2, the string becomes 1111100111.
    int findLongestString( const std::string& v );


    // Because the string can only contain "1" and "0", another way to look at this problem is "what is the longest substring that contains at most one "0"?". Th
    // different solution
    // "1101100111"
    int findLongestString1( const std::string& v );



    // Given an array of positive integers nums and an integer k, return the number of subarrays where the product of all the elements in the subarray is strictly less than k.

    // For example, given the input nums = [10, 5, 2, 6], k = 100, the answer is 8. The subarrays with products less than k are:

    // [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

    int numSubarrayProductLessThanK( const std::vector<int>& nums, int k);



    //Example 4: Given an integer array nums and an integer k, find the sum of the subarray with the largest sum whose length is k.
    //{3, -1, 4,12,-8,5,6};

    int largestSumOfsubarrays( const std::vector<int>& nums, int k);


    // second solution
    int largestSumOfsubarrays1( const std::vector<int>& nums, int k);


    // You are given an integer array nums consisting of n elements, and an integer k.

    // Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.



    // Example 1:

    // Input: nums = [1,12,-5,-6,50,3], k = 4
    // Output: 12.75000
    // Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

    double findMaxAverage(std::vector<int>& nums, int k);


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

    int longestOnes(std::vector<int>& nums, int k);


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

    std::vector<bool> answerQueries( std::vector<int> & nums, std::vector<std::vector<int>>& q, int limit );



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

    int waysToSplitArray(std::vector<int>& nums );



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
    std::string reverseStr( std::string s );




    // Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    // Note that you must do this in-place without making a copy of the array.



    // Example 1:

    // Input: nums = [0,1,0,3,12]
    // Output: [1,3,12,0,0]
    // Example 2:

    // Input: nums = [0]
    // Output: [0]
    void moveZeros( std::vector<int>& nums);




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

    int minSubArrayLen(int target, std::vector<int>& nums);

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


    int maxVowels(std::string s, int k);

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

    int equalSubstring(std::string s, std::string t, int maxCost);

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
    std::vector< int > uniqNumber( std::vector< int > nums );



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

    int longestsubst( std::string s, int k);


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
    int subarraySum( std::vector< int >& nums, int k );




    // Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
    // A subarray is a contiguous non-empty sequence of elements within an array.
    // Example 1:

    // Input: nums = [1,1,1], k = 2
    // Output: 2
    // Example 2:

    // Input: nums = [1,2,3], k = 3
    // Output: 2


    // 1 2 3
    int subarraySum1( std::vector< int >& nums, int k );



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



    int numberOfSubarrays(std::vector<int>& nums, int k);



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

    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches);



    // Given an integer array nums, return the largest integer that only occurs once. If no integer occurs once, return -1.
    // Example 1:

    // Input: nums = [5,7,3,9,4,9,8,3,1]
    // Output: 8
    // Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.
    // Example 2:

    // Input: nums = [9,9,8,8]
    // Output: -1
    // Explanation: There is no number that occurs only once.
    int largestUniqueNumber(std::vector<int>& nums);



    // Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

    // You can use each character in text at most once. Return the maximum number of instances that can be formed.



    // Example 1:



    // Input: text = "nlaebolko"
    // Output: 1
    // Example 2:
    int maxNumberOfBalloons(std::string text);



    // Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    // An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



    // Example 1:

    // Input: strs = ["eat","tea","tan","ate","nat","bat"]
    // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    // Example 2:

    // Input: strs = [""]
    // Output: [[""]]
    // Example 3:

    // Input: strs = ["a"]
    // Output: [["a"]]

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);



    // You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

    // Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.



    // Example 1:

    // Input: cards = [3,4,2,3,4,7]
    // Output: 4
    // Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
    // Example 2:

    // Input: cards = [1,0,5,3]
    // Output: -1
    // Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.



    int minimumCardPickup(std::vector<int>& cards);




    // Example 3: 2342. Max Sum of a Pair With Equal Sum of Digits

    // Given an array of integers nums, find the maximum value of nums[i] + nums[j], where nums[i] and nums[j] have the same digit sum (the sum of their individual digits). Return -1 if there is no pair of numbers with the same digit sum.


    // Example 1:

    // Input: nums = [18,43,36,13,7]
    // Output: 54
    // Explanation: The pairs (i, j) that satisfy the conditions are:
    // - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
    // - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
    // So the maximum sum that we can obtain is 54.
    // Example 2:

    // Input: nums = [10,12,19,14]
    // Output: -1
    // Explanation: There are no two numbers that satisfy the conditions, so we return -1.


    //[229,398,269,317,420,464,491,218,439,153,482,169,411,93,147,50,347,210,251,366,401]
    // answer = 973

    // how to find sum of digits
    // int getDigitSum(int num) {
    //         int digitSum = 0;
    //         while (num > 0) {
    //             digitSum += num % 10;
    //             num /= 10;
    //         }

    //         return digitSum;
    //     }

    int maximumSum(std::vector<int>& nums);



    // Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

    // A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
    // Example 1:


    // Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
    // Output: 1
    // Explanation: There is 1 equal row and column pair:
    // - (Row 2, Column 1): [2,7,7]
    int equalPairs(std::vector<std::vector<int>>& grid);



    // Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

    // Each letter in magazine can only be used once in ransomNote.



    // Example 1:

    // Input: ransomNote = "a", magazine = "b"
    // Output: false
    // Example 2:

    // Input: ransomNote = "aa", magazine = "ab"
    // Output: false
    // Example 3:

    // Input: ransomNote = "aa", magazine = "aab"
    //     Output: true

    bool canConstruct(std::string ransomNote, std::string magazine);



    // You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

    // Letters are case sensitive, so "a" is considered a different type of stone from "A".



    // Example 1:

    // Input: jewels = "aA", stones = "aAAbbbb"
    // Output: 3
    // Example 2:

    // Input: jewels = "z", stones = "ZZ"
    // Output: 0

    int numJewelsInStones(std::string jewels, std::string stones);

    // Given a string s, find the length of the longest substring without repeating characters.
    // Example 1:
    // Input: s = "abcabcbb"
    // Output: 3
    //     Explanation: The answer is "abc", with the length of 3.

    int lengthOfLongestSubstring(std::string s);



    // You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

    // It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.



    // Example 1:

    // Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    // Output: "Sao Paulo"
    // Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

    std::string destCity(std::vector<std::vector<std::string>>& paths);


    // Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

    // Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.


    //string destCity(vector<vector<string>>& paths) {
    struct Point {
        int x;
        int y;

        bool operator== ( const Point& point ) const {
        return point.x == x && point.y == y ;
    }

    friend std::ostream& operator<<( std::ostream& os, const Point& point ) {
        return os << "x:" << point.x << " y:" << point.y;
}
};

struct Hasher {
    std::hash< int > hasher_;

    size_t operator()( const Point& point ) const {
    const size_t coeff = 2'999'551;
    return coeff * coeff * hasher_( point.x ) + coeff * coeff * hasher_( point.y );
}
};

bool isPathCrossing(std::string path);


// You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.

// Return the sum of all the unique elements of nums.



// Example 1:

// Input: nums = [1,2,3,2]
// Output: 4
// Explanation: The unique elements are [1,3], and the sum is 4.
// Example 2:

// Input: nums = [1,1,1,1,1]
// Output: 0
// Explanation: There are no unique elements, and the sum is 0.
// Example 3:

// Input: nums = [1,2,3,4,5]
// Output: 15
// Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.


int  sumOfUnique(std::vector<int>& nums);


// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.
// Example 1:

// Input: arr = [2,2,3,4]
// Output: 2
// Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
// Example 2:

// Input: arr = [1,2,2,3,3,3]
// Output: 3
// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
// Example 3:

// Input: arr = [2,2,2,3,3]
// Output: -1
// Explanation: There are no lucky numbers in the array.
int findLucky(std::vector<int>& arr);


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
bool uniqueOccurrences(std::vector<int>& arr);



// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.



// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

    std::string frequencySort(std::string s);


// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j.
// Example 1:

// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
// Example 2:

// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.
// Example 3:

// Input: nums = [1,2,3]
// Output: 0
int numIdenticalPairs(std::vector<int>& nums);


// leetcode solution
// int numIdenticalPairs(vector<int>& nums) {
//     unordered_map<int, int> counts;
//     int ans = 0;

//     for (int num: nums) {
//         ans += counts[num];
//         counts[num]++;
//     }

//     return ans;
// }


// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).



// Example 1:

// Input: nums = [4,2,4,5,6]
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].
// Example 2:

// Input: nums = [5,2,1,2,5,2,1,2,5]
// Output: 8
// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

int maximumUniqueSubarray(std::vector<int>& nums);

// optimal solution
// int maximumUniqueSubarray(vector<int>& nums) {
//        int result = 0, currentSum = 0, start = 0;
//        unordered_set<int> seen;
//        for (int end = 0; end < nums.size(); end++) {
//            // increment start until subarray has unique elements
//            while (seen.find(nums[end]) != seen.end()) {
//                seen.erase(nums[start]);
//                currentSum -= nums[start];
//                start++;
//            }
//            currentSum += nums[end];
//            seen.insert(nums[end]);
//            // update result with maximum sum found so far
//            result = max(result, currentSum);
//        }
//        return result;
//    }



// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.



// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// // adc
// // "dcda"
// bool checkInclusion(string s1, string s2) {
//     std::unordered_set< char > s( s1.begin(), s1.end() );
//     std::unordered_map< char, std::vector< int >> m;



//     //bool curr = false;
//     for( int r = 0 ; r < s2.size(); r++ ){
//         if( s.find( s1[ r ] ) != s.end() ) {
//             m[ s1[ r ] ].push_back( r );
//         }
//     }

//     int distance = s1.size();

//     // return false;
// }



// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true

bool isIsomorphic(std::string s, std::string t);

// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.



// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false

bool wordPattern(std::string pattern, std::string s);




// You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

// Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.



// Example 1:

// Input: order = "cba", s = "abcd"
// Output: "cbad"
// Explanation:
// "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
// Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
// Example 2:

// Input: order = "cbafg", s = "abcd"
// Output: "cbad"
    std::string customSortString(std::string order, std::string s);

// leetcode solution
    std::string customSortString1(std::string order, std::string s);

}

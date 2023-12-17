

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
#include "leetCodeTasks1.h"

namespace leetcode {


    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int,int>> v;
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



    std::vector<int> twoSum1(std::vector<int>& nums, int target) {
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



    void reverseString(std::vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        char tmp;

        while( l < r ){
            tmp = s[ l ];
            s[ l++ ] = s[ r ];
            s[ r-- ] = tmp;

        }
    }


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


    double findMaxAverage(std::vector<int>& nums, int k) {
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


    int longestOnes(std::vector<int>& nums, int k) {
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



    int minSubArrayLen(int target, std::vector<int>& nums) {
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
                    a = std::min( r - l + 1, a);
                    l++;
                }
                else
            break;
            }
        }
        return a;
    }


    int maxVowels(std::string s, int k) {
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

            a = std::max( a, curr);

        }

        return a;
    }


    int equalSubstring(std::string s, std::string t, int maxCost) {

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

            a = std::max( r -l +1, a );

        }

        return a;

    }


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

            a = std::max( a, r - l + 1 );
        }

        return a;
    }


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


    int numberOfSubarrays(std::vector<int>& nums, int k) {
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



    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
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



    int largestUniqueNumber(std::vector<int>& nums) {
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


    int maxNumberOfBalloons(std::string text) {
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



    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {

        std::vector<std::vector<std::string>> a;
        std::unordered_map< std::string, std::vector<std::string>> m;

        for( auto& str : strs ) {
            auto s = str;
            std::sort( s.begin(), s.end());
            m[ s ].push_back( str );
        }

        for( auto el : m ) {
            a.push_back( el.second);
        }

        return a;
    }



    int minimumCardPickup(std::vector<int>& cards) {

        std::unordered_map< int, std::vector<int>> m;

        for( int i = 0; i < cards.size(); i++ ) {
            m[ cards[ i ] ].push_back( i );
        }

        int a = std::numeric_limits<int>::max();

        for( auto& [ k, arr] : m ) {
            for( int i = 1; i < arr.size(); i++ ) {
                a = std::min( a, arr[ i ] - arr[ i - 1 ] + 1 );
            }
        }

        a = a == std::numeric_limits<int>::max() ? -1 : a;
        return a;

    }


    int maximumSum(std::vector<int>& nums) {
        std::unordered_map< int, std::vector<int>> m;

        std::string s;
        for( int i = 0; i < nums.size(); i++ ) {
            s = std::to_string( nums[ i ]);
            int acc = 0;
            for( auto c : s ) {
                int n = c - 48;
                acc += n;
                m[ acc ].push_back( nums[ i ] );
            }
        }

        int a = -1;

        for( auto el : m ) {
            int curr = 0 ;
            if( el.second.size() > 1 ) {
                std::sort( el.second.begin(), el.second.end(), std::greater<int>());
                a = std::max( a, el.second[ 0 ] + el.second[ 1 ]);
            }
        }

        return a;

    }



    int equalPairs(std::vector<std::vector<int>>& grid) {
        std::unordered_map< std::string, int> rows;
        std::unordered_map< std::string, int> columns;

        for( int r = 0; r < grid.size(); r ++ ) {
            std::stringstream ss;
            for( int c = 0; c < grid[ r ].size(); c++ ) {
                ss << std::to_string( grid[ r ][ c ] ) << ',';
            }
            rows [ ss.str() ]++;
            std::cout << "r:" << ss.str() << std::endl;
        }

        for( int r = 0; r < grid.size(); r ++ ) {
            std::stringstream ss;
            for( int c = 0; c < grid[ r ].size(); c++ ) {
                ss << std::to_string( grid[ c ][ r ] ) << ',';
            }
            columns [ ss.str() ]++;
            std::cout << "c:" << ss.str() << std::endl;
        }

        int a = 0;
        for( auto el : rows ) {
            if( columns.find( el.first ) != columns.end() ) {
                a += el.second * columns[ el.first ];
            }
        }

        return a;
    }



    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map< char, int > m;

        for( auto c : magazine ) {
            m[ c ]++;
        }

        for( auto n : ransomNote ) {
            if( m.find( n ) != m.end() ) {
                m[ n ]--;
                if( m[ n ] == 0 ) {
                    m.erase( n );
                }
            }
            else {
                return false;
            }
        }
        return true;
    }



    int numJewelsInStones(std::string jewels, std::string stones) {
        std::unordered_set<char> s( jewels.begin(), jewels.end() );
        int a = 0;
        for( auto c : stones  ) {
            if( s.find( c ) != s.end() ) {
                a++;
            }
        }

        return a;
    }



    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set< char > set;

        int a = 0;
        int curr = 0;
        int l = 0;

        for( int r = 0; r < s.size(); r++ ) {
            if( set.find( s[ r ] ) == set.end() ) {
                set.insert( s[ r ] );
                curr++;
            }
            else
                {
                    while( l < r ) {
                        if( s[ l ] == s[ r ] ) {
                            l++;
                            break;
                        }
                        curr--;
                        set.erase( s[ l ] );
                        l++;
                    }
                }

            a = std::max( a, curr );

        }

        return a;
    }



    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::unordered_map< std::string, std::string> m;

        for( auto path : paths ) {
            m[ path[ 0 ] ] = path[ 1 ];
        }

        for( auto& [ k, v] : m ) {
            if( m.find( v ) == m.end() ) {
                return v;
            }
        }

        return "";
    }



    bool isPathCrossing(std::string path) {
        std::unordered_set< Point, Hasher > s;

        Point point{ 0, 0 };
        s.insert( point );

        for( char c : path ) {
            switch( c ) {
                case 'N': point.y++; break;
                case 'S': point.y--; break;
                case 'E': point.x++; break;
                case 'W': point.x--; break;
                default:
                std::cout << "unexpected_value:" << c << std::endl;
            }

            auto it = s.find( point );
            if(  it != s.end() ) {
                std::cout <<*it << std::endl;
                return true;
            } else {
                auto ref = s.insert( point );
                std::cout << *ref.first << std::endl;
            }
        }

        return false;
    }


    int  sumOfUnique(std::vector<int>& nums) {
        std::unordered_map<int, int > m;//( nums.begin(), nums.end() );
        for( auto n : nums ) {
            m[ n ]++;
        }
        return std::accumulate( m.begin(), m.end(), 0, []( int sum, auto& a ){ return a.second == 1 ? sum + a.first : sum; });
    }


    int findLucky(std::vector<int>& arr) {
        std::unordered_map< int, int > m;
        for( auto n : arr ) {
            m[ n ]++;
        }

        auto it = m.begin();
        int a = -1;
        while( it != m.end() ) {

            it = std::find_if( it, m.end(), []( auto& el ){ return el.second == el.first; } );
            if( it != m.end() ) {
                a = std::max( a, it -> first );
                it++;
            }
        }

        return a;
    }


    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map< int, int > m;
        std::unordered_set<int> s;

        for( auto n : arr ) {
            m[ n ]++;
        }

        for( auto&[ k, v ] : m ){
            if( s.find( v ) != s.end() ) {
                return false;
            }
            s.insert( v );
        }

        return true;

    }


    std::string frequencySort(std::string s) {
        std::unordered_map< char, int> m;

        for( auto c : s ) {
            m[ c ]++;
        }

        std::vector< std::pair<char, int>> v( m.begin(), m.end());
        std::sort( v.begin(), v.end(), []( auto& a, auto&b ){ return a.second > b.second; } );

        //std::string ss( v.size(), ' ');
        //std::transform( v.cbegin(), v.cend(), ss.begin(), []( auto& a){ return a.first; } );

        std::stringstream ss;
        for( auto&[ c, n ] : v ) {
            ss << std::string( n, c );
        }

        return ss.str();
    }


    int numIdenticalPairs(std::vector<int>& nums) {
        std::unordered_map< int, std::vector< int >> m;

        for( int i = 0; i < nums.size(); i++ ) {
            m[ nums[ i ] ].push_back( i );
        }

        int a = 0;

        for( auto&[ n, v ] : m ) {
            for( int i = 1; i < v.size(); i++ ) {
                a += v.size() - i;
            }

        }

        return a;
    }


    int maximumUniqueSubarray(std::vector<int>& nums) {
        std::unordered_map<int, int > m;

        int curr = 0;
        int l = 0;
        int a = 0;
        for( int r = 0; r < nums.size(); r++ ) {
            m[ nums[ r ] ]++;
            curr += nums[ r ];
            while( m[ nums[ r ] ] > 1 && l < r ) {
                curr -= nums[ l ];
                m[ nums[ l++ ] ]--;
            }

            a = std::max( a, curr );
        }

        return a;
    }

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



    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> m;
        std::unordered_map< char, char> m1;

        if( s.size() != t.size() ) {
            return false;
        }

        for( int i = 0; i < s.size(); i++) {
            auto it = m.find( s[ i ] );
            auto it1 = m1.find( t[ i ] );

            if( it == m.end() && it1 == m1.end() ) {
                m[ s[ i ] ] = t[ i ];
                m1[ t[ i ] ] = s[ i ];
            }
            else if ( ( it != m.end() && it1 == m1.end() ) || ( it == m.end() && it1 != m1.end() ) ) {
                return false;
            }
            else {
                if( it -> second != t[ i ] && it1 -> second != s[ i ] ) {
                    return false;
                }
            }
        }
        return true;
    }


    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map< char, std::string> m;
        std::unordered_map< std::string, char> m1;

        std::stringstream ss( s );
        std::vector< std::string > v;

        std::string w;
        while( ss >> w ) {
            v.push_back( w );
        }

        if( v.size() != pattern.size() ) {
            return false;
        }

        for( int i = 0; i < pattern.size(); i++ ) {
            auto it = m.find( pattern[ i ] );
            auto it1 = m1.find( v[ i ] );

            if( it == m.end() && it1 == m1.end() ) {
                m[ pattern[ i ] ] = v[ i ];
                m1[ v[ i ] ] = pattern[ i ];
            }
            else if( ( it != m.end() && it1 == m1.end() ) ||
                     ( it == m.end() && it1 != m1.end()) ) {
                         return false;
                     }
            else {
                if( it -> second != v[ i ] ) {
                    return false;
                }
            }
        }
        return true;
    }


    std::string customSortString(std::string order, std::string s) {

        auto less = [ &order ]( char a, char b) {
            std::unordered_map< char, int > m;
            for( int r = 0; r < order.size(); r++ ) {
                if( m.find( order[ r ] ) == m.end() ) {
                    m[ order[ r ] ] = r;
                }
            }

            auto it = m.find( a );
            auto it1 = m.find( b );

            if( it != m.end() && it1 != m.end() ) {
                return it -> second < it1 -> second;
            }
            else if( it != m.end() && it1 == m.end() ) {
                return true;
            }

            return false;
        };

        std::sort( s.begin(), s.end(), less );

        return s;
    }


    // leetcode solution
    std::string customSortString1(std::string order, std::string s) {
        sort(s.begin(), s.end(), [&order](char lhs, char rhs) {
            return order.find(lhs) < order.find(rhs);
        });

        return s;
    }

}

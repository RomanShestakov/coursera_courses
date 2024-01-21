#include<algorithm>
#include<iostream>
#include<iterator>
#include<string>
#include<string_view>
#include<stack>
#include<vector>
#include<deque>
#include<sstream>
#include<set>
#include<cctype>
#include"stackProblems.h"

namespace leetcode {

    std::vector<std::string_view> split( std::string_view s, char delim ) {
        std::vector< std::string_view > v;

        while( s.front() == delim ) {
            s.remove_prefix(1);
        }

        while( true ) {
            size_t pos = s.find( delim );
            v.push_back( s.substr( 0, pos ) );
            if( pos == s.npos ) {
                break;
            } else {
                s.remove_prefix(pos + 1 );
            }
        }

        return v;

    }

    template< typename T, typename Container = std::deque < T >>
    struct stack_iter : std::stack< T, Container > {
        using std::stack< T, Container >::c;
        auto begin() { return c.begin() ; }
        auto end() { return c.end() ; }
    };

    std::string simplifyPath( std::string path ){
        auto words = split( path, '/' );
        stack_iter<std::string_view> s;

        for( auto w : words ) {
            if( w == "" || w == "." ) continue;
            if( w == ".." ) { if( !s.empty() ) s.pop(); continue; }
            s.push( w );
        }

        std::stringstream ss;
        for( auto it = s.begin(); it != s.end(); it++ ) {
            ss << '/' << *it;
        }

        auto res = ss.str();
        return res.size() ? res : "/";
    }


    std::string makeGood( std::string s) {
        stack_iter< char > stack;
        if( !s.empty() ) stack.push( s[ 0 ] );
        for( int i = 1; i < s.size(); i++ ) {
            if( !stack.empty() ) {
                char c = stack.top();
                if( c != s[ i ] && std::toupper( c ) == std::toupper( s[ i ] ) ) {
                    stack.pop();
                    continue;
                }
            }
            stack.push( s[ i ] );
        }

        std::stringstream ss;
        for( auto c : stack ) {
            ss << c;
        }

        auto res = ss.str();

        return res;
    }


    // leetcode solution - it is possible to use vector as a stack!
    std::string makeGood1(std::string s) {
        // Use stack to store the visited characters.
        std::vector<char> stack;

        // Iterate over 's'.
        for (auto currChar : s) {
            // If the current character make a pair with the last character in the stack,
            // remove both of them. Otherwise, we add the current character to stack.
            if (!stack.empty() && abs(stack.back() - currChar) == 32)
                stack.pop_back();
            else
                stack.push_back(currChar);
        }

        // Returns the string concatenated by all characters left in the stack.
        std::string ans(stack.begin(), stack.end());
        return ans;
    }



    // leetcode solution
    std::vector<int> dailyTemperatures( std::vector<int>& t ){
        std::vector< int> a ( t.size() );
        std::vector< int > s;
        for( int i = 0; i < t.size(); i++) {
            while( !s.empty() && t[ s.back() ] < t[ i ] ) {
                int j = s.back();
                a[ j ] = i - j;
                s.pop_back();
            }

            s.push_back( i );
        }

        return a;
    }

    // no efficient
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k){
        std::deque<int> d(nums.begin(), nums.begin() + k);
        std::vector< int > a;

        // how to init deque wit back_inseter
        // std::deque<int> d;
        // std::copy( nums.begin(), nums.begin() + k, std::back_inserter( d ) );

        // for( auto e : d ) {
        //     std::cout << "D:" << e << std::endl;
        // }

        a.push_back( *std::max_element( d.begin(), d.end()));

        for( int i = k; i < nums.size(); ++i ) {
            d.push_back( nums[ i ] );
            d.pop_front();
            a.push_back( *std::max_element( d.begin(), d.end()));
        }

        return a;
    }


    // leetcode
    std::vector<int> maxSlidingWindow1(std::vector<int>& nums, int k) {
        std::multiset<int>st;
        std::vector<int>ans;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            if(i-k>=0){
                st.erase(st.find(nums[i-k]));
            }
            if(i>=k-1){
                ans.push_back(*st.rbegin());
            }
        }
        return ans;
    }


    std::vector<int> maxSlidingWindow2(std::vector<int>& nums, int k){
        std::vector<int> a;
        std::deque<int> d;

        for( int i = 0; i < nums.size(); i++ ) {
            while( !d.empty() && nums[ i ] > nums[ d.back() ]) {
                d.pop_back();
            }

            d.push_back( i );

            if( d.front() + k == i )  {
                d.pop_front();
            }

            if( i >= k - 1 ) {
                a.push_back( nums[ d.front()] );
            }
        }

        return a;
    }



    int longestSubarray(std::vector<int>& nums, int limit){
        std::deque<int> incr;
        std::deque<int> decr;
        int left = 0;
        int a = 0;

        for( int i = 0; i < nums.size(); i++ ) {
            while( !incr.empty() && incr.back() > nums[ i ] ) {
                incr.pop_back();
            }
            while( !decr.empty() && decr.back() < nums[ i ] ) {
                decr.pop_back();
            }

            incr.push_back( nums[ i ]);
            decr.push_back( nums[ i ]);

            while( decr.front() - incr.front() > limit ) {
                if( nums[ left ] == decr.front() ) {
                    decr.pop_front();
                }
                if( nums[left] == incr.front() ) {
                    incr.pop_front();
                }

                left++;
            }

            a = std::max( a, i - left + 1 );
        }

        return a;
    }

}

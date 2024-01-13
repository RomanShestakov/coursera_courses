#include<iostream>
#include<string>
#include<string_view>
#include<stack>
#include<vector>
#include<deque>
#include<sstream>
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

}

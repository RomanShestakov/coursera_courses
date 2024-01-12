#include<iostream>
#include<string>
#include<string_view>
#include<stack>
#include<vector>
#include<deque>
#include<sstream>
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
        auto back() { return c.back() ; }
    };

    std::string simplifyPath( std::string path ){
        auto words = split( path, '/' );
        stack_iter<std::string_view> s;

        for( auto w : words ) {
            if( w == "" || w == "." ) continue;
            if( w == ".." ) {
                if( !s.empty() ) s.pop();
                continue;
            }
            s.push( w );
        }

        std::stringstream ss;
        for( auto it = s.begin(); it != s.end(); it++ ) {
            ss << '/' << *it;
        }

        auto res = ss.str();
        return res.size() ? res : "/";
    }


}

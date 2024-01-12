#include<iostream>
#include <string_view>
#include <vector>
#include <string>
#include <stack>

namespace red_belt {

    std::vector<std::string_view> split( std::string_view s ) {
        std::vector< std::string_view > v;

        size_t pos = 0;
        const size_t pos_end = s.npos;

        while( true ) {
            size_t space = s.find( " ", pos );
            v.push_back(
                ( pos == pos_end
                  ? s.substr( pos )
                  : s.substr( pos, space - pos ) ) );

            if( space == pos_end ) {
                break;
            } else {
                pos = space + 1;
            }
        }

        return v;

    }


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


}

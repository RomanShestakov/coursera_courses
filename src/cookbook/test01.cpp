
#include "gtest/gtest.h"
#include <algorithm>
#include <cctype>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <limits>
#include <memory>
#include "cookbook.h"

// to be able to use string literals e.g. "forty"s
using namespace std::string_literals;

namespace cookbook {

    template <typename F, typename T>
    auto apply( F&& f, T value ) {
        return f( value );
    }

    TEST(ch1, auto_init ) {

        auto i = 42;
        auto d = 42.5;
        auto s = "test";

        auto b = new char[ 10 ]{ 0 };
        auto s1 = std::string{ "tests" };

        auto upper = []( const char c) { return _toupper( c ); };
        auto add = []( auto const a, auto const b ) { return a + b; };

        // cleanup
        delete[] b;
    }


   TEST(ch1, decl_auto ) {
       auto f = foo{ 42 };
       decltype( auto ) x = proxy_get( f );
   }

    // see c++ cookbook, p.12
    struct {
        template< typename T, typename U >
           auto operator()( T const a, U const b) const { return a + b ;}
    } L;

   TEST(ch1, generic_lambda ) {

       auto ladd = []( auto const a, auto const b) { return a + b; };

       // struct {
       //     template< typename T, typename U >
       //     auto operator()( T const a, U const b) const { return a + b ;}
       // } L;

       EXPECT_EQ( 42, ladd( 40, 2 ) );
       EXPECT_EQ( "fortytwo", ladd( "forty"s, "two"s ) );
   }


}

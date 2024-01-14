
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

}

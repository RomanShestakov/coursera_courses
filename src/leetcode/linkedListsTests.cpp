
#include "gtest/gtest.h"
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <limits>
#include <memory>
#include "linkedListsProblems.h"


namespace leetcode {


    TEST(hasCycle, case1) {

        auto a = std::make_unique< ListNode >( 3 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 0 );
        auto d = std::make_unique< ListNode >( -4 );

        auto head = a.get();
        a -> addNode( b.get() ) -> addNode( c.get() ) -> addNode( d.get() );
        d -> next = b.get();

        EXPECT_TRUE( hasCycle( head ) );

        EXPECT_TRUE( hasCycle1( head ) );

    }


    TEST(hasCycle1, case1) {

        auto a = std::make_unique< ListNode >( 3 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 0 );
        auto d = std::make_unique< ListNode >( -4 );

        auto head = a.get();
        a -> addNode( b.get() ) -> addNode( c.get() ) -> addNode( d.get() );
        d -> next = b.get();

        EXPECT_TRUE( hasCycle1( head ) );

    }

}

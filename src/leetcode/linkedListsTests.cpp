
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


    TEST(kthNode, case1) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
addNode( c.get() ) ->
addNode( d.get() ) ->
addNode( e.get() );;

        EXPECT_EQ( d -> val, kthNode( head, 2 ) -> val );

    }



    // Input: head = [1,2,3,4,5]
    // Output: [3,4,5]
    // Explanation: The middle node of the list is node 3.

    //    ListNode* middleNode(ListNode* head) ;

    TEST(middleNode, case1) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->addNode( c.get() ) ->addNode( d.get() ) ->addNode( e.get() );

        // return middle node
        EXPECT_EQ( c -> val, middleNode( head ) -> val );


        // add extra node
        auto f = std::make_unique< ListNode >( 6 );
        e -> addNode( f.get() );
        EXPECT_EQ( d -> val, middleNode( head ) -> val );

    }


    //Remove Duplicates from Sorted List

    // Input: head = [1,1,2]
    // Output: [1,2]
    TEST(deleteDuplicates, case1) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 1 );
        auto c = std::make_unique< ListNode >( 2 );

        auto head = a.get();
        a -> addNode( b.get() ) ->addNode( c.get() );

        std::vector< int > expected {1,2};
        std::vector< int > result;

        deleteDuplicates( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // Input: head = [1,1,2,3,3]
    // Output: [1,2,3]

    TEST(deleteDuplicates, case2) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 1 );
        auto c = std::make_unique< ListNode >( 2 );
        auto d = std::make_unique< ListNode >( 3 );
        auto e = std::make_unique< ListNode >( 3 );

        auto head = a.get();
        a -> addNode( b.get() ) ->addNode( c.get() ) ->addNode( d.get() ) ->addNode( e.get() );

        std::vector< int > expected {1,2, 3};
        std::vector< int > result;

        deleteDuplicates( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


}


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
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() );
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
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() );
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
             addNode( e.get() );

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
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

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
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

        std::vector< int > expected {1,2, 3};
        std::vector< int > result;

        deleteDuplicates( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }



    TEST( reverseList, case1) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

        std::vector< int > expected { 5, 4, 3, 2, 1};
        std::vector< int > result;

        auto h = reverseList( head );

        // std::cout << "reverted head:" << head -> val << std::endl;

        while( h ) {
            result.push_back( h -> val);
            h = h -> next;
        }

        EXPECT_EQ( expected, result );
    }


    TEST( reverseListRec, case1) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

        std::vector< int > expected { 5, 4, 3, 2, 1};
        std::vector< int > result;

        auto h = reverseListRec( head );

        std::cout << "Reverse head" << h-> val << std::endl;

        while( h ) {
            result.push_back( h -> val);
            h = h -> next;
        }

        EXPECT_EQ( expected, result );
    }



    // // // Input: head = [1,2,3,4]
    // // // Output: [2,1,4,3]
    // // // Example 2:

    // // // Input: head = []
    // // // Output: []
    // // // Example 3:

    // // // Input: head = [1]
    // // // Output: [1]

    // // ListNode* swapPairs(ListNode* head);

    TEST( swapPairs, case1) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );


        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() );

        std::vector< int > expected { 2,1, 4,3};
        std::vector< int > result;

        auto h = swapPairs( head );

      //  std::cout << "reverted head:" << h -> val << std::endl;

        while( h ) {
            result.push_back( h -> val);
            h = h -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // Input: head = [5,4,2,1]
    // Output: 6
    //int pairSum(ListNode* head);
    TEST( pairSum, case1) {

        auto a = std::make_unique< ListNode >( 5 );
        auto b = std::make_unique< ListNode >( 4 );
        auto c = std::make_unique< ListNode >( 2 );
        auto d = std::make_unique< ListNode >( 1 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() );

        int expected  = 6;

        EXPECT_EQ( expected, pairSum( head ) );
    }



    TEST( reverseN, case1) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

        std::vector< int > expected {3,2,4,5};
        std::vector< int > result;

        auto [h, succ] = reverseN( b.get(), 2 );

        while( h ) {
            result.push_back( h -> val);
            h = h -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //   }
    // Input: head = [1,2,3,4,5], left = 2, right = 4
    // Output: [1,4,3,2,5]
    TEST( reverseBetween, case1) {

        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

        std::vector< int > expected { 1,4,3,2,5};
        std::vector< int > result;

        head = reverseBetween( head, 2, 4 );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // Input: head = [1], left = 1, right = 1
    // Output: [1]
    TEST( reverseBetween, case2) {

        auto a = std::make_unique< ListNode >( 1 );
        auto head = a.get();

        std::vector< int > expected { 1};
        std::vector< int > result;

        auto h = reverseBetween( head, 1, 1 );

        while( h ) {
            result.push_back( h -> val);
            h = h -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // Input: head = [3,5], left = 1, right = 2
    // Output: [5,3]
    TEST( reverseBetween, case3) {
        auto a = std::make_unique< ListNode >( 3 );
        auto b = std::make_unique< ListNode >( 5 );
        auto head = a.get();
        a -> addNode( b.get() );
        std::vector< int > expected {5,3};
        std::vector< int > result;

        auto h = reverseBetween( head, 1, 2 );
        while( h ) {
            result.push_back( h -> val);
            h = h -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // // Input: head = [3,5], left = 1, right = 1
    // // Output: [3,5]
    TEST( reverseBetween, case4) {

        auto a = std::make_unique< ListNode >( 3 );
        auto b = std::make_unique< ListNode >( 5 );
        auto head = a.get();
        a -> addNode( b.get() );

        std::vector< int > expected {3,5};
        std::vector< int > result;

        auto h = reverseBetween( head, 1, 1 );
        while( h ) {
            result.push_back( h -> val);
            h = h -> next;
        }

        EXPECT_EQ( expected, result );
    }


    TEST( deleteMiddle, case1) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 3 );
        auto c = std::make_unique< ListNode >( 4 );
        auto d = std::make_unique< ListNode >( 7 );
        auto e = std::make_unique< ListNode >( 1 );
        auto f = std::make_unique< ListNode >( 2 );
        auto g = std::make_unique< ListNode >( 6 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() ) ->
             addNode( f.get() ) ->
             addNode( g.get() );

        std::vector< int > expected {1,3,4,1,2,6};
        std::vector< int > result;

        head = deleteMiddle( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }




    //    ListNode* removeNthFromEnd(ListNode* head, int n);
    TEST( removeNthFromEnd, case1) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

      std::vector< int > expected {1,2,3,5};
        std::vector< int > result;

      head = removeNthFromEnd( head, 2 );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    TEST( removeNthFromEnd1, case1) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

      std::vector< int > expected {1,2,3,5};
        std::vector< int > result;

      head = removeNthFromEnd1( head, 2 );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }

    TEST( removeNthFromEnd2, case1) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 4 );
        auto e = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

      std::vector< int > expected {1,2,3,5};
        std::vector< int > result;

      int n = 2;
      head = removeNthFromEnd2( head, n );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }

}

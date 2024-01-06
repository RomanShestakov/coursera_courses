
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

      //int n = 2;
        head = removeNthFromEnd2( head, 2 );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // Input: head = [1,2,3,3,4,4,5]
    // Output: [1,2,5]
    TEST( deleteDuplicates2, case1) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 3 );
        auto e = std::make_unique< ListNode >( 4 );
        auto f = std::make_unique< ListNode >( 4 );
        auto g = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() ) ->
             addNode( f.get() ) ->
             addNode( g.get() );

        std::vector< int > expected {1,2,5};
        std::vector< int > result;

        head = deleteDuplicates2( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    //[1,1,1,2,3]
    TEST( deleteDuplicates2, case2) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 1 );
        auto c = std::make_unique< ListNode >( 1 );
        auto d = std::make_unique< ListNode >( 2 );
        auto e = std::make_unique< ListNode >( 3 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

        std::vector< int > expected {2,3};
        std::vector< int > result;

        head = deleteDuplicates2( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    //[1,2,2]
    TEST( deleteDuplicates2, case3) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 2 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ;


        std::vector< int > expected {1};
        std::vector< int > result;

        head = deleteDuplicates2( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }

    //[1,1]
    TEST( deleteDuplicates2, case4) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 1 );

        auto head = a.get();
        a -> addNode( b.get() );

        std::vector< int > expected {};
        std::vector< int > result;

        head = deleteDuplicates2( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    TEST( deleteDuplicates3, case1) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 3 );
        auto d = std::make_unique< ListNode >( 3 );
        auto e = std::make_unique< ListNode >( 4 );
        auto f = std::make_unique< ListNode >( 4 );
        auto g = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() ) ->
             addNode( f.get() ) ->
             addNode( g.get() );

        std::vector< int > expected {1,2,5};
        std::vector< int > result;

        head = deleteDuplicates3( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }

    //[1,1,1,2,3]
    TEST( deleteDuplicates3, case2) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 1 );
        auto c = std::make_unique< ListNode >( 1 );
        auto d = std::make_unique< ListNode >( 2 );
        auto e = std::make_unique< ListNode >( 3 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() );

        std::vector< int > expected {2,3};
        std::vector< int > result;

        head = deleteDuplicates3( head );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // //[ 0, 1, 2] -> [ 0, 2, 1]
    // TEST( swap, case1) {
    //     auto a = std::make_unique< ListNode >( 0 );
    //     auto b = std::make_unique< ListNode >( 1 );
    //     auto c = std::make_unique< ListNode >( 2 );

    //     auto head = a.get();
    //     a -> addNode( b.get() ) -> addNode( c.get() );

    //     std::vector< int > expected {0, 2,1};
    //     std::vector< int > result;

    //     swap( a, b );

    //     while( head ) {
    //         std::cout << head -> val << std::endl;
    //         result.push_back( head -> val);
    //         head = head -> next;
    //     }

    //     EXPECT_EQ( expected, result );
    // }



//f 0
    TEST( swapNodes, case1) {
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

        std::vector< int > expected {5,2,3,4,1};
        std::vector< int > result;

        head = swapNodes( head, 1 );

        //r( int i = 0; i < 6;i++ ) {
        while( head ) {
            //d::cout << head -> val << std::endl;
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }

//    #if 0
    // // Input: head = [1,2,3,4,5], k = 2
    // // Output: [1,4,3,2,5]
    TEST( swapNodes, case2) {
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

        std::vector< int > expected {1,4,3,2,5};
        std::vector< int > result;

        head = swapNodes( head, 2 );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }
      //ndif


    //[7,9,6,6,7,8,3,0,9,5]
    // k = 5
    TEST( swapNodes, case3) {
        auto a = std::make_unique< ListNode >( 7 );
        auto b = std::make_unique< ListNode >( 9 );
        auto c = std::make_unique< ListNode >( 6 );
        auto d = std::make_unique< ListNode >( 6 );
        auto e = std::make_unique< ListNode >( 7 );
        auto f = std::make_unique< ListNode >( 8 );
        auto g = std::make_unique< ListNode >( 3 );
        auto h = std::make_unique< ListNode >( 0 );
        auto j = std::make_unique< ListNode >( 9 );
        auto k = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() ) ->
             addNode( f.get() ) ->
             addNode( g.get() ) ->
             addNode( h.get() ) ->
             addNode( j.get() ) ->
             addNode( k.get() );

        //      [7,9,6,6,8,7,3,0,9,5]
        std::vector< int > expected {7,9,6,6,8,7,3,0,9,5};
        std::vector< int > result;

        head = swapNodes( head, 5 );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }
//ndif


    TEST( swapNodes2, case) {
        auto a = std::make_unique< ListNode >( 7 );
        auto b = std::make_unique< ListNode >( 9 );
        auto c = std::make_unique< ListNode >( 6 );
        auto d = std::make_unique< ListNode >( 6 );
        auto e = std::make_unique< ListNode >( 7 );
        auto f = std::make_unique< ListNode >( 8 );
        auto g = std::make_unique< ListNode >( 3 );
        auto h = std::make_unique< ListNode >( 0 );
        auto j = std::make_unique< ListNode >( 9 );
        auto k = std::make_unique< ListNode >( 5 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() ) ->
             addNode( f.get() ) ->
             addNode( g.get() ) ->
             addNode( h.get() ) ->
             addNode( j.get() ) ->
             addNode( k.get() );

        //      [7,9,6,6,8,7,3,0,9,5]
        std::vector< int > expected {7,9,6,6,8,7,3,0,9,5};
        std::vector< int > result;

        head = swapNodes2(head, 5 );

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }



//  bool isPalindrome(ListNode* head);
    TEST( isPalindrome, case1){
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 2 );
        auto d = std::make_unique< ListNode >( 1 );
        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() );

        EXPECT_EQ( true, isPalindrome( head ) );
    }

    TEST( isPalindrome, case2){
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto head = a.get();
        a -> addNode( b.get() );
        EXPECT_EQ( false,isPalindrome( head ) );
    }


    TEST( isPalindrome1,case1){
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 2 );
        auto d = std::make_unique< ListNode >( 1 );
        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() );

        EXPECT_EQ( true, isPalindrome1(head ) );
    }

    TEST( isPalindrome1,case2){
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto head = a.get();
        a -> addNode( b.get() );
        EXPECT_EQ( false,isPalindrome1( head ));
    }





    // Input: head = [5,2,6,3,9,1,7,3,8,4]
    // Output: [5,6,2,3,9,1,4,8,3,7]
    TEST( reverseEvenLengthGroups, case) {
        auto a = std::make_unique< ListNode >( 5 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 6 );
        auto d = std::make_unique< ListNode >( 3 );
        auto e = std::make_unique< ListNode >( 9 );
        auto f = std::make_unique< ListNode >( 1 );
        auto g = std::make_unique< ListNode >( 7 );
        auto h = std::make_unique< ListNode >( 3 );
        auto j = std::make_unique< ListNode >( 8 );
        auto k = std::make_unique< ListNode >( 4 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() ) ->
             addNode( f.get() ) ->
             addNode( g.get() ) ->
             addNode( h.get() ) ->
             addNode( j.get() ) ->
             addNode( k.get() );

        //[5,6,2,3,9,1,4,8,3,7]
        std::vector< int > expected { 5,6,2,3,9,1,4,8,3,7};
        std::vector< int > result;

        head = reverseEvenLengthGroups(head);

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // Input: head = [1,1,0,6]
    // Output: [1,0,1,6]
    TEST( reverseEvenLengthGroups, case2) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 1 );
        auto c = std::make_unique< ListNode >( 0 );
        auto d = std::make_unique< ListNode >( 6 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() );

        //[1,0,1,6]
        std::vector< int > expected {1,0,1,6};
        std::vector< int > result;

        head = reverseEvenLengthGroups(head);

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }



    //[1,5,0,2,4,7,3,6]
    // [1,0,5,2,4,7,6,3]

    TEST( reverseEvenLengthGroups, case3) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 5 );
        auto c = std::make_unique< ListNode >( 0 );
        auto d = std::make_unique< ListNode >( 2 );
        auto e = std::make_unique< ListNode >( 4 );
        auto f = std::make_unique< ListNode >( 7 );
        auto g = std::make_unique< ListNode >( 3 );
        auto h = std::make_unique< ListNode >( 6 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() ) ->
             addNode( f.get() ) ->
             addNode( g.get() ) ->
             addNode( h.get() );


        //[5,6,2,3,9,1,4,8,3,7]
        std::vector< int > expected { 1,0,5,2,4,7,6,3 };
        std::vector< int > result;

        head = reverseEvenLengthGroups(head);

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // Input: head = [1,2,6,3,4,5,6], val = 6
    // Output: [1,2,3,4,5]
    TEST( removeelements, case1) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 2 );
        auto c = std::make_unique< ListNode >( 6 );
        auto d = std::make_unique< ListNode >( 3 );
        auto e = std::make_unique< ListNode >( 4 );
        auto f = std::make_unique< ListNode >( 5 );
        auto g = std::make_unique< ListNode >( 6 );


        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() ) ->
             addNode( e.get() ) ->
             addNode( f.get() ) ->
             addNode( g.get() ) ;


        // [1,2,3,4,5]
        std::vector< int > expected { 1,2,3,4,5 };
        std::vector< int > result;

        head = removeElements(head, 6);

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }


    // Input: head = [7,7,7,7], val = 7
    // Output: []
    TEST( removeelements, case2) {
        auto a = std::make_unique< ListNode >( 7 );
        auto b = std::make_unique< ListNode >( 7 );
        auto c = std::make_unique< ListNode >( 7 );
        auto d = std::make_unique< ListNode >( 7 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() ) ->
             addNode( d.get() );

        // [1,2,3,4,5]
        std::vector< int > expected {};
        std::vector< int > result;

        head = removeElements(head, 7);

        while( head ) {
            result.push_back( head -> val);
            head = head -> next;
        }

        EXPECT_EQ( expected, result );
    }



    //    int getDecimalValue(ListNode* head){
    // Input: head = [1,0,1]
    // Output: 5
    TEST( getDecimalValue, case1) {
        auto a = std::make_unique< ListNode >( 1 );
        auto b = std::make_unique< ListNode >( 0 );
        auto c = std::make_unique< ListNode >( 1 );

        auto head = a.get();
        a -> addNode( b.get() ) ->
             addNode( c.get() );

        EXPECT_EQ( 5, getDecimalValue( head ) );
    }

}

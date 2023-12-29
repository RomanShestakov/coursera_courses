
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <limits>
#include <memory>
#include <map>
#include <sstream>
#include <functional>
#include "linkedListsProblems.h"

namespace leetcode {

    bool hasCycle(ListNode *head) {

        std::unordered_set< ListNode* > s;
        while( head && head -> next ){

            std::cout << head ->val << std::endl;

            if( s.find( head ) != s.end() ) {
                return true;
            }

            s.insert( head );
            head = head -> next;
        }

        return false;
    }


   bool hasCycle1(ListNode *head) {

        if( !head ) return false;

        ListNode* fast = head -> next;
        ListNode* slow = head;

        while( slow != fast ) {
            if( fast == NULL || fast -> next == NULL ) {
                return false;
            }
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return true;
    }


    ListNode* kthNode(ListNode *head, int k) {
        auto slow = head;
        ListNode* fast = head;

        for( int i = 0; i < k; i++ ) {
            fast = fast -> next;
        }


        while( fast ) {
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow;

    }


    ListNode* middleNode(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while( fast && fast -> next ) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        return slow;
    }


    ListNode* deleteDuplicates(ListNode* head) {
        auto node = head;
        while( node && node -> next ) {
            if( node -> val == node -> next -> val ) {
                node -> next = node -> next -> next;
            }
            else {
                node = node -> next;
            }
        }

        return head;
    }


    // 1 -> 2 -> 3
    // 3 -> 2 -> 1
    ListNode* reverseList(ListNode* head) {
        auto curr = head;
        ListNode* prev = nullptr;

        while( curr ) {

            std::cout << curr -> val << std::endl;
            auto next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }


    // 1 2 3 4 5
    ListNode* reverseListRec(ListNode* head){
        // base case
        if( !head -> next ) return head;
        auto last = reverseListRec( head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        //std::cout << "head:" << head -> val << " last" << last -> val << std::endl;
        return last;
    }


    // 1 2 3 4
    // 2 1 4 3
    ListNode* swapPairs(ListNode* head) {
        auto curr = head;
        auto r = ( head && head -> next ) ? head -> next : head;

        ListNode* p = nullptr;

        while( curr && curr -> next ) {
            auto n = curr -> next;
            curr -> next = n -> next;
            n-> next = curr;
            if( p ) {
                p -> next = n;
            }

            p = curr;
            curr = curr -> next;
        }

        return r;
    }




    int pairSum(ListNode* head){
        auto curr = head;

        auto mid = middleNode( head );
        auto rev = reverseList( mid);

        int a = 0;
        while( curr != mid || rev ) {
            //std::cout << " curr:" << curr -> val << " rev: " << rev -> val << std::endl;
            a = std::max( a, curr -> val + rev -> val );
            curr = curr -> next;
            rev = rev -> next;

        }

        return a;
    }


    std::pair<ListNode*, ListNode*> reverseN( ListNode* head, int n) {
        if( n == 1 ) {
            return { head, head -> next};
        }

        auto [last, succ] = reverseN( head -> next, n - 1 );
        head -> next -> next = head;
        head -> next = succ;
        return {last, succ};
    }


  ListNode* reverseBetween(ListNode* head, int left, int right) {
      auto curr = head;

      if( left == 1 ) {
          return reverseN( curr, right ).first;
      }

      curr -> next = reverseBetween( curr -> next, left - 1, right - 1);

      return curr;
  }


    ListNode* preMid(ListNode* head) {
        auto slow = head;

        // 1
        if( !head -> next ) return head;

        // 1 2
        if( head -> next && !head -> next -> next ) return head;

        auto fast = head -> next -> next;

        while( fast && fast -> next ) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if( !head -> next ) return nullptr;
        auto mid = preMid( head );
        mid -> next = mid -> next -> next;
        return head;

    }


   ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( !head -> next ) return nullptr;

        auto r = reverseListRec( head );

        auto r1 = r;
        while( r1 ) {
            std::cout << r1-> val << std::endl;
            r1 = r1 -> next;
        }

        if( n == 1 ) {
            r = r -> next;
        }
        else
        {
            auto curr = r;

            for( int i = 1; i < n - 1; i++ ) {
                curr = curr -> next;
            }
//            std::cout << "c:" << curr -> val <<std::endl;
            curr -> next = curr -> next -> next;
        }

        return reverseListRec( r );
    }



    // public ListNode removeNthFromEnd(ListNode head, int n) {
    //     ListNode dummy = new ListNode(0);
    //     dummy.next = head;
    //     ListNode first = dummy;
    //     ListNode second = dummy;
    //     // Advances first pointer so that the gap between first and second is n nodes apart
    //     for (int i = 1; i <= n + 1; i++) {
    //         first = first.next;
    //     }
    //     // Move first to the end, maintaining the gap
    //     while (first != null) {
    //         first = first.next;
    //         second = second.next;
    //     }
    //     second.next = second.next.next;
    //     return dummy.next;
    // }


   ListNode* removeNthFromEnd1(ListNode* head, int n) {
       auto first = head;
       auto second = head;

       for( int i = 0; i <= n; i++) {
           first = first -> next;
       }

       while( first ) {
           first = first -> next;
           second = second -> next;
       }

        std::cout << "s:" << second -> val << std::endl;

        second -> next = second -> next -> next;

        return head;
    }


    // !!!this is very cool solution = note a ref to n
    ListNode* removeNthFromEndImpl(ListNode* head, int& n) {
        if (head == nullptr) return head;
        ListNode* last = removeNthFromEndImpl(head->next, n);
        if (--n) {
            head->next = last;
            //std::cout << n << " head:" << head -> val << std::endl;
            return head;
        }
        else return last;
    }

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        int n1 = n;
        return removeNthFromEndImpl(head, n1);
    }



    // 1 2 3 3 4 4 5
    std::pair<ListNode*, int> deleteDuplicatesImpl(ListNode* head) {
        if( !head -> next ) return { head,   std::numeric_limits<int>::max() };
        auto [last, val] = deleteDuplicatesImpl( head -> next);
        //std::cout << head -> val << " " << last -> val << " " << val << std::endl;
        if( head -> val == last -> val ) {
            //std::cout << "drop:" << head -> val << " " << last -> val << std::endl;
            head -> next = last -> next;
            return { head, last -> val};
        }
        else if ( last -> val == val) {
            //std::cout << "drop2:" << head -> val << " " << last -> val << std::endl;
            head -> next = last -> next;
            return { head, last -> val};
        }
        else return { head, std::numeric_limits<int>::max() };
    }

    ListNode* deleteDuplicates2(ListNode* head) {
        auto [last, val] = deleteDuplicatesImpl(head -> next);
        //std::cout << last -> val << " " << val << std::endl;
        if( head -> val == last -> val) return last -> next;
        else if( val == last -> val) head -> next = last -> next;
        return head;

        //return deleteDuplicatesImpl( head ).first;
    }


    ListNode* deleteDuplicates3(ListNode* head) {
        auto sentinel = std::make_unique<ListNode>(ListNode( 0 ));
        sentinel.get() -> addNode( head );
        auto pred = sentinel.get();
        while( head ) {
            if( head -> next && head -> val == head -> next -> val ) {
                while( head -> next && head -> val == head -> next -> val ) {
                    head = head -> next;
                }
                pred -> next = head -> next;
            }
            else {
                pred = pred -> next;
            }

            head = head -> next;
        }

        return sentinel -> next;
    }

    ListNode* findKth(ListNode* head, int& k){
        if( !head -> next ) return head;
        auto last = findKth( head -> next, k);
        if( k >= 1  ) {
            k--;
            return head;
        }
        else return last;
    }

    // void swap( ListNode* a, ListNode* b ) {
    //     std::cout << " swap:" << a -> val << " " << a -> next -> val << " " << b -> val << " " << b -> next -> val << std::endl;
    //     auto tmp = a -> next -> next;
    //     auto tmp1 = a -> next;
    //     auto tmp2 = b -> next -> next;
    //     a -> next = b -> next;
    //     a -> next -> next = tmp;
    //     b -> next = tmp1;
    //     b -> next -> next = tmp2 -> next;

    //  }

    // std::pair<ListNode*, ListNode*> dropNext(ListNode* a ){
    //     if( !a -> next ) return {a, nullptr};
    //     auto t = a -> next;
    //     a -> next = a -> next -> next;
    //     return { a, t};
    // }

    // ListNode* insertAfter(ListNode* a, ListNode* b ){
    //     auto t = a -> next;
    //     a -> next = b;
    //     b -> next = t;
    //     return b;
    // }


    // Input: head = [1,2,3,4,5], k = 1
    // Output: [5,4,3,2,1]
     ListNode* swapNodes(ListNode* head, int k){
         std::vector< ListNode* > v;

         auto curr = head;
         while( curr ) {
             v.push_back( curr );
             curr = curr -> next;
         }

         auto tmp = v[ k - 1 ];
         v[ k - 1] = v[ v.size() - k] ;
         v[ v.size() - k] = tmp;

         auto s = std::make_unique< ListNode>( ListNode( 0 ));
         auto s1 = s.get();
         for( int i = 0; i < v.size(); i++ ) {
             s1 -> next = v[ i ];
             s1 = s1 -> next;
         }

         s1 -> next = nullptr;

         return s.get() -> next;
     }



}

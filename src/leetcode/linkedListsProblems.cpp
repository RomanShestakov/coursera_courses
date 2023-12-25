
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <limits>
#include <map>
#include <sstream>
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


    // ListNode successor = null;
    // ListNode reverseN(ListNode head, int n) {
    //     if (n == 1) {
    //         successor = head.next;
    //         return head;
    //     }
    //     ListNode last = reverseN(head.next, n - 1);
    //     head.next.next = head;
    //     head.next = successor;
    //     return last;
    // }


    // ublic ListNode reverseBetween(ListNode head, int m, int n) {
    //     if (m == 1) {
    //         // You can also expand the code here to get rid of the helper function 'reverseN'
    //         return reverseN(head, n);
    //     }
    //     head.next = reverseBetween(head.next, m - 1, n - 1);
    //     return head;
    // }

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


}

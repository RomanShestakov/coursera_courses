
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


}

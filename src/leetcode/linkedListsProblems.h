
#pragma once

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

namespace leetcode {

    struct ListNode {
        int val;
        ListNode* next = nullptr;
        ListNode( int x ) : val( x ) {}

        ListNode* addNode( ListNode* node ) {
            next = node;
            return node;
        }
    };



// 141 Liked List cycle

//     Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    bool hasCycle(ListNode *head);
    bool hasCycle1(ListNode *head);

}

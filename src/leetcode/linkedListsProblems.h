
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

        // ListNode* deleteNode( ListNode* node ) {
        // }
    };


    // 141 Liked List cycle
    //     Given head, the head of a linked list, determine if the linked list has a cycle in it.
    // There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is use    // d to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    // Return true if there is a cycle in the linked list. Otherwise, return false.
    // Example 1:
    // Input: head = [3,2,0,-4], pos = 1
    // Output: true
    // Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
    bool hasCycle(ListNode *head);
    bool hasCycle1(ListNode *head);


    // Given the head of a linked list and an integer k, return the
    // k
    // th
    //   node from the end.
    // For example, given the linked list that represents 1 -> 2 -> 3 -> 4 -> 5 and k = 2, return the node with value 4, as it is the 2nd node from the end.
    ListNode* kthNode(ListNode *head, int k);


    // Given the head of a singly linked list, return the middle node of the linked list.
    // If there are two middle nodes, return the second middle node.
    // Example 1:
    // Input: head = [1,2,3,4,5]
    // Output: [3,4,5]
    // Explanation: The middle node of the list is node 3.
    ListNode* middleNode(ListNode* head) ;

    //Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
    ListNode* deleteDuplicates(ListNode* head);


    // reverse list
    ListNode* reverseList(ListNode* head);



    //     Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., o    // nly nodes themselves may be changed.)
    // Example 1:
    // Input: head = [1,2,3,4]
    // Output: [2,1,4,3]
    // Example 2:

    // Input: head = []
    // Output: []
    // Example 3:

    // Input: head = [1]
    // Output: [1]

    ListNode* swapPairs(ListNode* head);


    // 2130 maximum twin sum of linked list
    // n a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

    // For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
    // The twin sum is defined as the sum of a node and its twin.

    // Given the head of a linked list with even length, return the maximum twin sum of the linked list.



    // Example 1:


    // Input: head = [5,4,2,1]
    // Output: 6
    int pairSum(ListNode* head);



    // Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right,     // and return the reversed list.
    // Example 1:
    // Input: head = [1,2,3,4,5], left = 2, right = 4
    // Output: [1,4,3,2,5]

    ListNode* reverseBetween(ListNode* head, int left, int right);

}

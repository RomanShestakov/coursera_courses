
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
    ListNode* reverseListRec(ListNode* head);

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



    // Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the li    //st from position left to position right,     // and return the reversed list.
    // Example 1:
    // Input: head = [1,2,3,4,5], left = 2, right = 4
    // Output: [1,4,3,2,5]

    std::pair<ListNode*,ListNode*> reverseN(ListNode* head, int n);
    ListNode* reverseBetween(ListNode* head, int left, int right);



    // 2095 delete the middle node of linekd list
    // You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

    // The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denot    //es the largest integer less than or equal to x.

    // For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.


    // Example 1:


    // Input: head = [1,3,4,7,1,2,6]
    // Output: [1,3,4,1,2,6]
    // Explanation:
    // The above figure represents the given linked list. The indices of the nodes are written below.
    // Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
    // We return the new list after removing this node.
    ListNode* deleteMiddle(ListNode* head);


    //19 -remove nth element from list
    //     Given the head of a linked list, remove the nth node from the end of the list and return its head.
    // Example 1:
    // Input: head = [1,2,3,4,5], n = 2
    // Output: [1,2,3,5]
    // Example 2:
    // Input: head = [1], n = 1
    // Output: []
    // Example 3:
    // Input: head = [1,2], n = 1
    // Output: [1]
    ListNode* removeNthFromEnd(ListNode* head, int n);
    ListNode* removeNthFromEnd1(ListNode* head, int n);

    // found on leetcode solution - this is insanely cool solution
    ListNode* removeNthFromEnd2(ListNode* head, int n);


    // 82 - remove dups from sorted list
    // Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers fro    //m the original list. Return the linked list sorted as well.
    // Example 1:
    // Input: head = [1,2,3,3,4,4,5]
    // Output: [1,2,5]
    // Example 2:
    // Input: head = [1,1,1,2,3]
    // Output: [2,3]
    ListNode* deleteDuplicates2(ListNode* head);

    // leetcode solution
    ListNode* deleteDuplicates3(ListNode* head);

}

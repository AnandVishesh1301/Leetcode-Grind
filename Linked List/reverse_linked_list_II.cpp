// 92. Reverse Linked List II  
// ---------------------------------------------------------
// Problem:
// Reverse a portion of a singly linked list from position `left` to `right` (1-based).
// Only the nodes between `left` and `right` (inclusive) should be reversed.
// Do not modify the values of the list nodes; only modify the pointers.
//
// ---------------------------------------------------------
// Approach: In-Place Reversal using Pointer Manipulation
// - Create a dummy node to handle edge cases (e.g., reversing from head).
// - Traverse to the node before `left` (`leftPrev`) and start reversing from `curr`.
// - Reverse the sublist of length (right - left + 1) using standard pointer reversal.
// - After reversal, reconnect the reversed portion:
//   - `leftPrev->next` now points to the end of the reversed sublist (which is `prev`).
//   - The node originally at position `left` (now tail of reversed sublist) connects to `curr`.
//
// Time Complexity: O(n) - Single traversal through the list  
// Space Complexity: O(1) - In-place reversal
//
// Runtime     : 0 ms      (Beats 100%)  
// Memory Usage: 11.32 MB  (Beats 4.83%)  
// ---------------------------------------------------------


// Solution:
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0); // Sentinel node to simplify edge cases
        dummy.next = head;
        ListNode* leftPrev = &dummy;
        ListNode* curr = head;
        for(int i=0; i<left-1; i++){
            leftPrev = curr;
            curr = curr-> next;

        }
        // Till here, curr = left, leftPrev = Node right before left
        // Now need to reverse from left ro right
        ListNode* prev = nullptr;
        for (int i=0; i<right-left+1; i++){
            ListNode* tempNext = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = tempNext;
        } 
        // Til here the reversed list is not attached to the main list, copz the left still points  to null and curr = the RightNode of the Right position and prev = right node
        // Updating the POinters
        leftPrev -> next -> next = curr; // curr is the node after right
        leftPrev -> next = prev; // prev is right

        return dummy.next;
       
    }
};

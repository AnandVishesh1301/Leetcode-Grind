// 143. Reorder List  
// ---------------------------------------------------------
// Problem:
// Given the head of a singly linked list, reorder it in-place so that
// it transforms from:  
//     L0 → L1 → … → Ln-1 → Ln  
// into:  
//     L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
//
// You may not change node values — only node pointers can be changed.
//
// Approach: Two Pointers + Reverse + Merge
// ---------------------------------------------------------
// 1. **Find the middle** of the list using slow and fast pointers.
//    - `slow` ends up at the midpoint of the list.
// 2. **Reverse the second half** of the list starting at slow->next.
//    - Reverse the links to allow easy merging.
// 3. **Merge the two halves**:
//    - Alternate nodes from the first half and the reversed second half.
//
// Key Insight:
// - The trick is reversing the second half, so we can simulate
//   the "end-to-front" order while merging.
//
// Time Complexity: O(n) — one pass to find mid, one to reverse, one to merge  
// Space Complexity: O(1) — in-place reordering, no extra data structures  
//
// Example:  
//   Input:  [1,2,3,4,5]  
//   Step 1: Split → [1,2,3] and [4,5]  
//   Step 2: Reverse second → [5,4]  
//   Step 3: Merge → [1,5,2,4,3]
//
// Runtime     : 0 ms     (Beats 100%)  
// Memory Usage: 22.67 MB (Beats 95.67%)  
// ---------------------------------------------------------

// Solution:
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;

        }
        ListNode* second = slow -> next; // Second half of the List
        // Reversing the links in this second half of the list to be able to traverse back
        slow -> next = nullptr;
        ListNode* prev = nullptr;
        while (second){
             
            ListNode* temp = second -> next;
            second -> next = prev;
            prev = second;
            second = temp;

        }


        // Merging the 2 halves
        ListNode* first = head;
        second = prev;  // Second and prev point to the head of the second reversed half

        while (second){
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;
            first -> next = second;
            second -> next = temp1;
            first = temp1;
            second = temp2;

        }
        
    }
};
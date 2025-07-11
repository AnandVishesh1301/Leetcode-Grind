// 25. Reverse Nodes in k-Group
// ---------------------------------------------------------
// Problem:
// Given the head of a linked list, reverse the nodes in groups of `k`.
// If the remaining nodes at the end are fewer than `k`, leave them unchanged.
// You must reverse the actual nodes, not just their values.
//
// ---------------------------------------------------------
// ✅ Approach: Iterative Group-by-Group Reversal
// ---------------------------------------------------------
// - Use a dummy node to simplify edge cases.
// - For each group of k nodes:
//   1. Use `getKth()` to find the k-th node from the current group's start.
//   2. Reverse the k nodes between groupPrev and groupNext.
//   3. Rewire pointers to stitch the reversed group back into the main list.
//
// - Helper `getKth()` function ensures we only reverse full k-sized groups.
//
// Time Complexity : O(n) — each node is visited and reversed at most once.
// Space Complexity: O(1) — in-place reversal using pointer manipulation.
//
// Runtime     : 0 ms     (Beats 100%)
// Memory Usage: 16.49 MB (Beats 71.25%)
// ---------------------------------------------------------


// Solution:
class Solution {
public:
    // Helper to find the k-th node from current position
    ListNode* getKth(ListNode* curr, int k){
        while(curr && k > 0){
            curr = curr -> next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true){
            ListNode* Kth = getKth(groupPrev, k);
            if (!Kth) break;  // less than k nodes left → don't reverse

            ListNode* groupNext = Kth -> next;

            // Reverse the current k-group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev -> next;

            while (curr != groupNext){
                ListNode* temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
            }

            // Reconnect reversed group with the main list
            ListNode* temp = groupPrev -> next; // store the start of current group
            groupPrev -> next = Kth;            // Kth is now the new head of this group
            groupPrev = temp;                   // move groupPrev to the end of reversed group
        }

        return dummy.next;
    }
};

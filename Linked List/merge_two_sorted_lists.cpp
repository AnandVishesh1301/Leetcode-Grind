// 21. Merge Two Sorted Lists

// Problem:
// Given two sorted linked lists `list1` and `list2`, merge them
// into one sorted list by splicing together nodes from both.
// Return the head of the new merged list.

// Approach: Iterative Merge into a new LL with Dummy Node
// - Use a dummy node to simplify head handling, and a `curr` pointer
//   to build the merged list node by node.
// - Traverse both lists while neither is null:
//     1. Compare values at current nodes of `list1` and `list2`.
//     2. Append the smaller one to `curr->next`.
//     3. Advance in the corresponding list and move `curr` forward.
// - After the loop, at most one list is non-empty — attach it directly
//   to the end of the merged list.
//
// How this works:
//   - Takes advantage of the fact that both input lists are already sorted.
//   - Efficiently builds the merged list in-place without allocating new nodes.
//
// Time Complexity : O(n + m), where n and m are the lengths of the input lists
// Space Complexity: O(1), in-place merge using existing nodes
//
// Example:
//   list1 = [1,2,4], list2 = [1,3,4] → output = [1,1,2,3,4,4]
//
// Runtime     : 0 ms  (Beats 100%)
// Memory Usage: 19.64 MB (Beats 11.29%)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);                // Dummy head to simplify merge
        ListNode* curr = &dummy;          // Pointer to build result list

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;            // Move to next node in result
        }

        // Attach any remaining nodes from either list
        if (list1 != nullptr) {
            curr->next = list1;
        } else if (list2 != nullptr) {
            curr->next = list2;
        }

        return dummy.next;                // Head of the merged list
    }
};

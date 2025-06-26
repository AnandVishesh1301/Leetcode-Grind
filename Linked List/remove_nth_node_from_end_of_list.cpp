// 19. Remove Nth Node From End of List
// ---------------------------------------------------------
// Problem:
// Given the head of a linked list, remove the nth node from the end,
// and return the updated head.
//

// Approach: Brute Force Approach(Len Count)
// ---------------------------------------------------------
// - First, we traverse the list to calculate the total number of nodes (count).
// - To remove the nth node from the end, we need to remove the (count - n)th node from the start.
//   • We traverse until (count - n - 1)th node to land before the node to delete.
// - Then, we skip the node to delete and reconnect the list.
//
// Why we traverse till (count - n - 1)?
//   - Because we want to stop at the node just before the one we want to delete.
//   - Example: For count = 5 and n = 2 → we stop at index 2 (0-based) to remove the 3rd node.
//
// Edge Case:
//   - If n equals count, the head is the node to be removed.
//     We return head->next and delete the current head.
//
// Time Complexity : O(n) — two passes: one to count, one to remove
// Space Complexity: O(1)

// Leetcode Stats:
// Runtime     : 0 ms      (Beats 100%)
// Memory Usage: 15.03 MB  (Beats 24.57%)
// ---------------------------------------------------------

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // First pass: Count total nodes
        ListNode* curr = head;
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            temp = temp->next;
            count++;
        }

        // If the head itself is to be removed
        if (n == count) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Second pass: Go to (count - n - 1)th node
        for (int i = 0; i < count - n - 1; i++) {
            curr = curr->next;
        }

        // Delete the nth node from end
        ListNode* nxt = curr->next;
        curr->next = nxt->next;
        delete nxt;

        return head;
    }
};

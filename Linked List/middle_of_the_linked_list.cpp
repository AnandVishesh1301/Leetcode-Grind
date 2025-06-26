// 876. Middle of the Linked List
// ---------------------------------------------------------
// Problem:
// Given the head of a singly linked list, return the middle node.
// If there are two middle nodes, return the second one.
//
// ---------------------------------------------------------
// Approach: Fast and Slow Pointers
// - Use two pointers:
//   • Slow moves one step at a time.
//   • Fast moves two steps at a time.
// - When fast reaches the end, slow will be at the middle.
// - This naturally handles both even and odd-length lists.
// - For even-length lists, it correctly returns the **second** middle.
//
// How this works:
//   - Fast pointer moves twice as quickly, so when it finishes,
//     slow has covered half the list.
//   - Efficient and elegant without requiring length calculation.
//
// Time Complexity : O(n)
// Space Complexity: O(1)

// Leetcode Stats:
// Runtime     : 0 ms   (Beats 100%)
// Memory Usage: 10.01 MB (Beats 25.34%)

 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            // No need to handle even edge case separately:
            // The condition ensures slow stops at the 2nd middle
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

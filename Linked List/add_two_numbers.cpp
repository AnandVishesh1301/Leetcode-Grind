// 2. Add Two Numbers
// ---------------------------------------------------------
// Problem:
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in **reverse order**, and each node contains a single digit.
// Return the sum as a new linked list (also in reverse order).
//
// Approach: Iterative Addition with Carry (Digit by Digit)
// - Use a dummy/sentinel node to simplify handling of the result list.
// - Use a `carry` variable to manage digit overflow across positions.
// - Traverse both linked lists simultaneously:
//     1. Extract digits from both lists (or 0 if null).
//     2. Compute the sum of both digits + carry.
//     3. Update carry and create a new node with sum % 10.
// - Continue the loop as long as either list has elements or there's a carry(edge case, if adding two single digit numbers).
//
// Why this works:
//   - This emulates the standard elementary-school addition logic from right to left.
//   - Handles different lengths of input lists, and final carry if needed.
//
// Time Complexity : O(max(n, m)) — where n and m are the lengths of l1 and l2
// Space Complexity: O(max(n, m)) — for storing the result list
//
// Runtime     : 3 ms      (Beats 34.64%)
// Memory Usage: 77.21 MB  (Beats 12.19%)
// ---------------------------------------------------------

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);            // Sentinel node to simplify return
        ListNode* curr = &dummy;

        int carry = 0;
        while (l1 || l2 || carry) {   // Continue while digits or carry remain
            int v1 = 0, v2 = 0;
            if (l1) { v1 = l1->val; l1 = l1->next; }  // Get digit from l1
            if (l2) { v2 = l2->val; l2 = l2->next; }  // Get digit from l2

            int sum = v1 + v2 + carry;
            carry = sum / 10;                         // Update carry
            int digit = sum % 10;                     // Extract new digit

            curr->next = new ListNode(digit);         // Append to result
            curr = curr->next;
        }

        return dummy.next; // Return result list, skipping dummy
    }
};


// 2. Add Two Numbers (In-Place, O(1) Space)
// ---------------------------------------------------------
// Optimized Approach: In-place addition using the longer list (l2)
// ---------------------------------------------------------
// - Ensure l2 is the longer (or equal) list so we can modify it directly.
// - Traverse both lists simultaneously and compute digit + carry.
// - Overwrite l2 nodes with result digits. If l2 runs out, append new nodes.
// - Use a helper `split` to get digit and carry from sum.
// - Finally, if there's any leftover carry, append it as a new node.
//
// ✔ Why this is better:
//   - Avoids creating a new result list → uses O(1) extra space.
//   - Same time complexity, but more space-efficient.
//
// Time Complexity : O(max(n, m))
// Space Complexity: O(1) — no extra list or map used
//

class Solution {
    static inline std::pair<int,int> split(int sum)   // {digit, carry}
    { return {sum % 10, sum / 10}; }
    static int length(ListNode* p) {
        int c = 0; while (p) { ++c; p = p->next; } return c;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /* ensure l2 is the longer (or equal) list so we can overwrite it */
        if (length(l1) > length(l2)) std::swap(l1, l2);

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* prev = nullptr;        // last node in list2 we have written
        int carry = 0;

        /* ➋  walk until both lists exhausted */
        while (p1 || p2) {
            int v1 = p1 ? p1->val : 0;   // if list shorter, contribute 0
            int v2 = p2 ? p2->val : 0;

            auto [digit, newCarry] = split(v1 + v2 + carry);
            carry = newCarry;

            if (p2) {                    // normal case: write into list2 node
                p2->val = digit;
                prev = p2;
                p2 = p2->next;
            } else {                     // ran out of nodes in list2 → append
                prev->next = new ListNode(digit);
                prev = prev->next;
            }

            if (p1) p1 = p1->next;
        }

        /* ➌  leftover carry becomes a new tail node */
        if (carry) prev->next = new ListNode(carry);

        return l2;                       // l2 now holds the summed number            
        
    }
};

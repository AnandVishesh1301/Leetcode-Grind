// 83. Remove Duplicates from Sorted List
// ---------------------------------------------------------
// Problem:
// Given the head of a **sorted** linked list, remove all duplicates so that each element appears only once.
// The final list should remain sorted.
//
// ---------------------------------------------------------
// ✅ Approach 1: Sliding Window with Two Pointers
// ---------------------------------------------------------
// - Use two pointers: `l` points to the start of a "block" of duplicates,
//   and `r` scans ahead looking for changes.
// - If `r->val == l->val`, it's a duplicate → remove `r` by skipping it and freeing memory.
// - If values differ, we move both `l` and `r` forward to the next distinct value.
//
// 🔁 Time Complexity : O(n)
// 💾 Space Complexity: O(1) – in-place removal
//
// Leetcode Stats:
// Runtime: 0 ms (Beats 100%)
// Memory : 16.16 MB (Beats 69.60%)
// ---------------------------------------------------------

//Approach 1: Sliding Window with Two Pointers

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* l = head;              // left pointer marks the current unique node
        ListNode* r = head->next;        // right pointer scans ahead for duplicates

        while (r) {
            if (r->val == l->val) {
                // Found duplicate: unlink and delete the duplicate node
                ListNode* dup = r;
                r = r->next;
                l->next = r;             // connect to next unique node
                delete dup;              // free memory (optional)
            } else {
                // Unique value: move both pointers forward
                l = r;
                r = r->next;
            }
        }
        return head;
    }
};

// Approach 2: Single Pointer Iteration
// ---------------------------------------------------------
// - Traverse the list with one pointer `curr`.
// - If `curr` and `curr->next` have the same value, skip the next node (duplicate).
// - Else, move `curr` forward.
// - Cleaner and more concise than sliding window; achieves same logic.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // Duplicate found → skip and delete it
                ListNode* dup = curr->next;
                curr->next = dup->next;
                delete dup;
            } else {
                curr = curr->next;  // advance only if current is unique
            }
        }
        return head;
    }
};

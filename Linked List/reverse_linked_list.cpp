// 206. Reverse Linked List

// Problem:
// Given the head of a singly linked list, reverse the list,
// and return the new head of the reversed list.
//
// ---------------------------------------------------------
// Approach: Iterative Pointer Manipulation
// ---------------------------------------------------------
// - Used three pointers to reverse the list in-place:
//     1. `curr`: current node being visited
//     2. `prev`: previous node (to which `curr->next` will point)
//     3. `nxt`: temporarily stores `curr->next` before overwriting it
// - In each iteration:
//     - Store the next node (`nxt = curr->next`)
//     - Reverse the pointer (`curr->next = prev`)
//     - Move `prev` and `curr` forward
// - Loop ends when `curr` becomes null (end of list), and
//   `prev` will point to the new head of the reversed list.
//
// Why this works:
//   - This efficiently reverses the list in **O(n)** time with **O(1)** space.
//   - We're not creating any new nodes or data structures.
//
// Time Complexity: O(n) - one pass through the list
// Space Complexity: O(1) - constant space usage
//
// Example:
//   head = [1,2,3,4,5] → output = [5,4,3,2,1]
//
// Runtime     : 0 ms  (Beats 100%)
// Memory Usage: 13.42 MB (Beats 40.09%)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;  // temporarily store next node
            curr->next = prev;           // reverse current node's pointer
            prev = curr;                 // move prev to current
            curr = nxt;                  // move to next node
        }

        return prev; // prev now points to new head
    }
};

// Approach 2: Hash Map to Track Visited Nodes (Less Space Efficient)
// ---------------------------------------------------------
// - Store each visited node in a map/set.
// - If a node is revisited, we found a cycle.
// - Otherwise, move forward until the end.
//
// Time Complexity : O(n)
// Space Complexity: O(n)
//
// Example: A -> B -> C -> D -> B (cycle at B)
// - As we traverse, we store nodes. When we reach B again, return true.
// ---------------------------------------------------------

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, bool> listMap;
        ListNode* curr = head;

        if (!head || !head->next) return false; // Edge case

        while (curr != nullptr) {
            if (listMap.find(curr) != listMap.end()) return true;
            listMap[curr] = true;
            curr = curr->next;
        }

        return false;
    }
};
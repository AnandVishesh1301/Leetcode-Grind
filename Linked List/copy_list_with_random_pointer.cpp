// 138. Copy List with Random Pointer
// ---------------------------------------------------------
// Problem:
// Given a linked list where each node has a `next` and a `random` pointer
// (which may point to any node or nullptr), return a deep copy of the list.
//
// A deep copy means new nodes should be created with the same values, and
// the `next` and `random` relationships must be replicated exactly,
// without pointing to any of the original nodes.
//
// ---------------------------------------------------------
// ✅ Approach: HashMap for Original → Cloned Node Mapping
// ---------------------------------------------------------
// - Use a hash map to associate each original node with its deep copy.
// - First pass: create all new nodes and store them in the map.
// - Second pass: assign each new node's `next` and `random` using the map.
//
// - The hash map `oldToCopy` holds mappings from original node addresses
//   to their newly cloned counterparts.
//   This helps ensure that both the `next` and `random` connections can be
//   reconstructed easily and accurately without modifying the original list.
//
// Time Complexity : O(n) — two passes over the list
// Space Complexity: O(n) — for the hash map
//
// Runtime     : 3 ms     (Beats 91.98%)  
// Memory Usage: 15.20 MB (Beats 45.48%)  
// ---------------------------------------------------------

// Solution:
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        std::unordered_map<Node*, Node*> oldToCopy;  // original → clone(node Values)
        Node* cur = head;

        /* Pass 1: cloning nodes deep copy from the original list(value only) */
        while(cur){
            oldToCopy[cur] = new Node(cur->val);
            cur = cur->next;
        }

        /* Pass 2: wire next and random pointers */
        for (Node* cur = head; cur; cur = cur->next) {
            Node* clone        = oldToCopy[cur];
            clone->next   = (cur->next   ? oldToCopy[cur->next]   : nullptr); // Check if next exists, if yes assign it to clone's next
            clone->random = (cur->random ? oldToCopy[cur->random] : nullptr); // Check if random exists, if yes assign it to clone's random
        }

        return oldToCopy[head];          // head of deep-copied list
        
    }
};
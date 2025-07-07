// 23. Merge k Sorted Lists
// ---------------------------------------------------------
// Problem:
// Given an array of `k` linked lists, each sorted in ascending order,
// merge them into one sorted linked list and return its head.
//
// ---------------------------------------------------------
// ✅ Approach: Pairwise Merge Using Divide and Conquer
// ---------------------------------------------------------
// - Repeatedly merge pairs of lists from the input vector using a helper function.
// - In each round, merge lists two at a time and collect the merged results.
// - Replace the original list of lists with the merged results, reducing size by half.
// - Repeat until only one list remains.
//
// - This is similar to the bottom-up merge sort pattern (log k merge rounds).
// - Use the standard "Merge Two Sorted Lists" approach for merging two lists.
// -------------------------------------------------------------------------
// Another Slower Approach would be to to merge only 2 lists at a time, which would take O(kN) time.
// - This approach is more efficient as it reduces the number of merge operations logarithmically.
// -------------------------------------------------------------------------
// Complexity Analysis:
// Time Complexity: O(N log k)
//   - N = total number of nodes
//   - log k merge rounds, each round touches all nodes
// Space Complexity: O(1) extra (ignoring output list), in-place merging
//
// Runtime     : 0 ms      (Beats 100%)  
// Memory Usage: 19.24 MB  (Beats 11.49%)  
// ---------------------------------------------------------

class Solution {
public:
    // Helper Function: Merges two sorted lists
    // Copied as-is from LeetCode Problem 21 (Merge Two Sorted Lists)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(list1!=nullptr && list2!=nullptr ){
            if(list1->val < list2 -> val){
                curr->next=list1;
                list1=list1->next;
            }
            else{
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }
        if (list1!=nullptr){
            curr->next = list1;
        }
        else if(list2!=nullptr){
            curr->next=list2;
        }

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        // Merging the lists in pairs of 2, like merge sort, to reduce the time by logk factor
        while(lists.size() > 1){
            vector<ListNode*> merged;

            for (size_t i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;

                merged.push_back(mergeTwoLists(l1, l2));
            }

            // Replace current list with merged list for the next round
            lists.swap(merged); // Basically lists = merged, but freaking c++ doesn't allow direct assignment of vectors
        }

        return lists.front();  // Final merged list
    }
};



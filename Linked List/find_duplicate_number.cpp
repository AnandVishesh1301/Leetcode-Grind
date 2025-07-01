// 287. Find the Duplicate Number  
// ---------------------------------------------------------
// Problem:
// Given an array `nums` of n + 1 integers where each value is in [1, n],
// return the one integer that appears more than once.
//
// Approach: Hash Freq Map
// ---------------------------------------------------------
// - We use an unordered_map to store the frequency of each number.
// - First loop populates the frequency map with each number’s count.
// - Second loop traverses the map to identify the number with a count > 1.
// - We return that number as it is the duplicate.
//
// How this works:
//   - Since only one number can repeat, checking frequency > 1 gives the result.
//   - This approach is straightforward and readable.
//
// Time Complexity: O(n) — one pass to build map, one pass to find duplicate
// Space Complexity: O(n) — for the hash map

// Leetcode Stats:
// Runtime: 119 ms, Beats 7.23% users, TF!?
// Memory Usage: 104.71 MB, Beats: 6.47% users
// ---------------------------------------------------------


// Solution:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;

        // Populate the hash freq map
        for(int i: nums){
            umap[i]++;
        }

        // Traversing throught the map to track teh max val
        int maxVal =INT_MIN;

        for(auto& it: umap){
            if(it.second>1){
                maxVal = it.first;
            }
            else{
                continue;
            }
            
        }
        return maxVal;
    
    }
};


//Approach 2: LinkedList + Floyd's Tortoise and Hare (Cycle Detection)
// ---------------------------------------------------------
// Two parts of the approach:
// 1. Detecting the cycle using two pointers (tortoise and hare).
// Using a slow(s1) and fast pointer to detect their intersection point, and then stopping both the pointers there.
// 2. Finding the starting point of the cycle(the one connected to the rest of the linear list)
// Starting another slow pointer(s2) from the head and then iterating both s1 and s2 equally until they meet. This intersection point is the starting point of the cycle. 
// This is because this sytarting point of the cycle is equidistant from s1(intersection of slow and fast pointer) and s2(start of the list)
// Now this start of the list is equivalent to the duplicate number in the list.
// Mathematical Proff of why s1 and s2 are equidistant. 
// Lets say the cycle start at length p frm the beginning, and then the s1 and fast meet at x. TP => p=x
// Lets say the whole length of the cycle is c, so the s1 and fast meet at length c-x of the cycle, after traversin the cycle one time(so it alr covered length c once). 
// We know: 2*slow = fast
// So, 2*(p+(c-x)) = p + 2c - x
//2p + 2c - 2x = p + 2c - x
// p = x
// This will be valid no matter the length of the cycle/LL

// Problem:
// Given an array `nums` of size n + 1 where all numbers are in [1, n],
// and only one number appears more than once (could appear multiple times).
// Return that duplicate number **without modifying** the array and using **O(1) space**.
//
// ---------------------------------------------------------
// Approach 2: Floyd’s Tortoise & Hare (Cycle Detection)
// ---------------------------------------------------------
// - The values in the array point to indices, forming a **linked list-like cycle**.
// - We treat each index as a node, and `nums[i]` as a pointer to the next node.
// - Since there is a duplicate, it must create a **cycle**.
// - Using Floyd’s algorithm, we first detect a cycle and then find its entry point,
//   which is the duplicate number.
//
// Why we can treat the array as a linked list:
// index (i)	value nums[i]
// 0	1
// 1	3
// 2	4
// 3	2
// 4	2

// Now interpret each array position as a node in a directed graph:

// node i  ──►  node  nums[i]
// So:

// index 0 stores 1 → draw an arrow from node 0 to node 1
// (0 ─► 1)

// index 1 stores 3 → arrow from node 1 to node 3
// (1 ─► 3)

// index 3 stores 2 → arrow from node 3 to node 2
// (3 ─► 2)

// index 2 stores 4 → arrow from node 2 to node 4
// (2 ─► 4)

// index 4 stores 2 → arrow from node 4 to node 2
// (4 ─► 2)

// - The list is a mapping of index → nums[i].
//   Example: nums = [1,3,4,2,2]
//   Interpreted as arrows (like a graph):
//
//     0 ─► 1 ─► 3 ─► 2 ─► 4
//                   ▲     │
//                   └─────┘
//
// - There is a cycle from index 2 → 4 → 2 (because 2 repeats).
// - The cycle’s entry point (where slow and fast meet) is the duplicate.
//
// Key Steps:
// 1. Use slow = nums[0], fast = nums[nums[0]] to find the intersection inside the cycle.
// 2. Start a new pointer `slow2` from 0 and move both `slow` and `slow2` one step at a time
//    until they meet — that meeting point is the duplicate.
//
// Time Complexity: O(n) — slow/fast pointers traverse at most 2n steps
// Space Complexity: O(1) — constant extra space used

// Leetcode Stats:
// Runtime: 10 ms, Beats 44.48% users, lfg
// Memory Usage: 65.10 MB, Beats: 41.62% users
// ---------------------------------------------------------


// Solution 2:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //P1 of Floyd's Algo - Finding the intersection of slow and fast(the cycle)
        int slow = nums[0];
        int fast = nums[nums[0]];          // two steps

        while (slow != fast) {
            slow = nums[slow];             // one step
            fast = nums[nums[fast]];       // two steps
        }

        //P2 of Floyd's Algo - Findig the start of the list/duplicate in the list
        int slow2 = 0;

        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;                       // duplicate number
    }

    
};
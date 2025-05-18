// Longest Consecutive Sequence
// Given an unsorted array of integers `nums`, return the length of the **longest consecutive elements sequence**.
// You must implement an algorithm that runs in **O(n)** time.
//
// Example 1:
//   Input : nums = [100,4,200,1,3,2]
//   Output: 4
//   Explanation: Longest consecutive sequence is [1, 2, 3, 4] → length = 4
//
// Example 2:
//   Input : nums = [0,3,7,2,5,8,4,6,0,1]
//   Output: 9
//
// Example 3:
//   Input : nums = [1,0,1,2]
//   Output: 3
//
// Approach:
// - The key idea is to **start building a sequence only from numbers that are the start of a sequence**,
//   i.e., numbers `x` such that `x - 1` does **not** exist in the array.
// - Step 1: Use an **unordered_map<int, bool>** to track each number and whether it has been visited.
// - Step 2: Iterate through each number in the map. If it has already been visited or is not a starting
//   point (`x - 1` exists), skip it.
// - Step 3: If it is a start, use a `while` loop to mark each consecutive number as visited and
//   count the length of this sequence.
// - Step 4: Track the maximum sequence length seen so far (`best`).
//
// Time Complexity: **O(N)** —
//   - Each number is visited at most once, and each lookup in the map is O(1).
//
// Space Complexity: **O(N)** —
//   - We store each number in an unordered map for constant-time access.
//
// Solution Stats (from LeetCode submission):
//   Runtime: 86 ms
//   Beats:  48.71 % of C++ users

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> seen;          // bool = visited flag
        for (int x : nums) seen[x] = false;

        int best = 0;

        for (auto& [x, visited] : seen) {
            if (visited || seen.count(x - 1)) continue;  // skip if not a left edge(the start of a sequence)

            int length = 0;
            int cur = x;
            while (seen.count(cur)) {
                seen[cur] = true;               // mark visited
                ++length;
                ++cur; 
            }
            best = max(best, length);
        }
        return best;
            
    }
};

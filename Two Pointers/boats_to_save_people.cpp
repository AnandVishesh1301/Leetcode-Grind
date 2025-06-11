// 881. Boats to Save People
// --------------------------
// Problem:
// You are given an array `people`, where each element represents a person's weight.
// Each boat can carry at most two people, and their combined weight must not exceed `limit`.
// Return the **minimum number of boats** required to save all the people.
//
// --------------------------------------------------------------
// Approach: Two Pointer Greedy + Sorting
// --------------------------------------------------------------
// Logic:
// - First, sort the `people` array so we can pair the lightest and heaviest persons efficiently.
// - Use two pointers: 
//   ➤ `l` starts at the beginning (lightest person)
//   ➤ `r` starts at the end (heaviest person)
// - Try to pair the lightest and heaviest persons. If their combined weight is ≤ limit, move both.
// - If not, the heaviest person must go alone (move `r--`).
// - Always increment `boats` count in each iteration.
// - Special case: if one person remains (`l == r`), they go alone in a boat.
//
// Why Sorting?
// - It allows us to try optimal pairings by always attempting to pair the lightest + heaviest remaining people.
// - This greedy strategy ensures we minimize the number of boats.
//
// Time Complexity:
//   O(n log n) – Sorting the array dominates the complexity.
// Space Complexity:
//   O(1) – Only uses constant extra space (pointers and counters).
//
// Time Stats (from LeetCode submission):
//   Runtime : 15 ms  
//   Beats   : 73.46 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 45.84 MB
//   Beats        : 36.88 % of C++ users


//Solution
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0;
        int r = people.size() - 1;
        int boats = 0;

        sort(people.begin(), people.end());  // Sort people by weight

        while (l <= r) {
            if (l == r) {        // Only one person left
                boats++;
                break;
            }

            if (people[l] + people[r] <= limit) {
                // Pair lightest and heaviest if they fit
                l++;
                r--;
            } else {
                // Heaviest person goes alone
                r--;
            }
            boats++; // Count this boat
        }

        return boats;
    }
};

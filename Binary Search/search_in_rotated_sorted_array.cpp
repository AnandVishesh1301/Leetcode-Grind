// 33. Search in Rotated Sorted Array
// Problem:
// Given a rotated sorted array of unique integers, find the index of a given target value.
// The array is rotated at an unknown pivot, e.g. [0,1,2,4,5,6,7] → [4,5,6,7,0,1,2].
// The goal is to find the target in O(log n) time, using binary search.
//
// Strategy:
// ✅ Use modified binary search to handle the pivot rotation.
// ✅ At each iteration, check whether the **left half** is sorted (nums[l] ≤ nums[m])
//     → If so, check if the target is in that sorted region (nums[l] ≤ target < nums[m])
//     → If yes, discard the right half (r = m - 1), else search right (l = m + 1)
// ✅ Else, the **right half** must be sorted
//     → Check if target ∈ (nums[m], nums[r]] → search right
//     → Else search left
//
// Key Insight:
// Even though the array is rotated, at least one half of the current search window
// will always be sorted — leverage that fact to perform efficient binary search.
//
// Time Complexity:
//   O(log n) – binary search on rotated array
// Space Complexity:
//   O(1) – constant space
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 15.12 MB
//   Beats        : 66.46 % of C++ users


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target) return m;  // found the target

            // Check if the left half is sorted
            if (nums[l] <= nums[m]) {
                // Is target within the left sorted portion?
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;  // discard right
                } else {
                    l = m + 1;  // discard left
                }
            } 
            // Else right half must be sorted
            else {
                // Is target within the right sorted portion?
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;  // discard left
                } else {
                    r = m - 1;  // discard right
                }
            }
        }

        return -1;  // not found
    }
};

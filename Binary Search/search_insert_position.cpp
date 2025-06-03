// 35. Search Insert Position
// ---------------------------
// Problem:
// Given a sorted array `nums` of distinct integers and a target integer `target`,
// return the index if the target is found. If not, return the index where it
// would be if it were inserted in order (to maintain sorted order).
//
// Strategy:
// ✅ Use binary search (O(log n)) to find either the exact position of the target,
//    or the correct insert position if it's not found.
// ✅ If target == nums[mid], return mid.
// ✅ If target < nums[mid], search the left half.
// ✅ If target > nums[mid], search the right half.
// ✅ When loop ends, `l` will point to the correct insert position, whether the
//    target exists or not.
//
// Why `l` is the correct insert position:
// - The binary search always narrows the range [l, r] such that:
//     - all values before `l` are strictly less than the target
//     - all values from `l` onward are ≥ target
// - So if target is not found, it belongs at index `l` to maintain order.
//
// Time Complexity:
//   O(log n) – classic binary search
// Space Complexity:
//   O(1) – constant space
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 13.52 MB
//   Beats        : 76.50 % of C++ users
// ---------------------------------------------------------------


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int m = 0;

        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target) {
                return m;  // target found
            }
            else if (target > nums[m]) {
                l = m + 1;  // search right half
            }
            else {
                r = m - 1;  // search left half
            }
        }

        // If not found, l is the correct insert position
        return l;
    }
};

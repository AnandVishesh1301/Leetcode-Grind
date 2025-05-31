// Find Minimum in Rotated Sorted Array
// A strictly-increasing array is rotated k times (0 ≤ k < n) producing `nums[]`.
// The array therefore consists of two sorted blocks: [pivot … end] and [0 … pivot-1].
// The minimum is exactly the **pivot element** (smallest value).
//
// Goal  : return that minimum in **O(log n)** time.
//
// -----------------------------------------------------------------------------
// Approach ➜  Binary-Search for the Pivot
// -----------------------------------------------------------------------------
// 1. Maintain two pointers  `l` (left) and `r` (right).
// 2. If the sub-array nums[l … r] is already sorted (`nums[l] < nums[r]`),
//    then `nums[l]` is the minimum – we can break early.
// 3. Otherwise, compute mid = (l + r) / 2.
//      • Record `result = min(result, nums[mid])`.
//      • Decide which half still contains the pivot:
//          ─ If nums[mid] ≥ nums[l],   mid is inside the LEFT sorted block
//            → the pivot lies right of mid →  l = mid + 1
//          ─ Else                       ,   mid is inside the RIGHT block
//            → the pivot lies left of mid  → r = mid − 1
//           Because:
//           All the elements to the left of inflection point > first element of the array.
//           All the elements to the right of inflection point < first element of the array.
// 4. Loop until the search window collapses; `result` stores the minimum.
//
// Time Complexity : **O(log n)** – classic binary search  
// Space Complexity: **O(1)** – only a few variables
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 14 MB
//   Beats        : 97.57 % of C++ users


// Solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];          // track smallest value seen
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            // If current window is already sorted, the leftmost element is the min
            if (nums[l] < nums[r]) {
                result = min(result, nums[l]);
                break;
            }

            int m = (l + r) / 2;
            result = min(result, nums[m]);   // update answer with middle

            // Determine which side still contains the unsorted (pivot) portion
            if (nums[m] >= nums[l])          // mid is in the left sorted block
                l = m + 1;                   // search right half
            else                             // mid is in the right block
                r = m - 1;                   // search left half
        }
        return result;
    }
};

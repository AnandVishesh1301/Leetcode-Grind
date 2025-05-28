// Binary Search
// Given a **sorted (ascending)** integer array `nums[]` and an integer `target`,
// return the index of `target` in `nums`; if it does not exist, return **-1**.
//
// The algorithm **must** run in **O(log n)** time.
//
// Example 1:
//   Input : nums = [-1,0,3,5,9,12], target = 9
//   Output: 4
//
// Example 2:
//   Input : nums = [-1,0,3,5,9,12], target = 2
//   Output: -1
//
// -----------------------------------------------------------------------------
// Approach  ➜  Classic Iterative Binary Search
// -----------------------------------------------------------------------------
// • Maintain two pointers:
//     • `l` = low  (start of search window)
//     • `h` = high (end   of search window)
// • While `l ≤ h`:
//     1. Compute middle index `mid = (l + h) / 2`.
//     2. If `nums[mid] == target`, return `mid`.
//     3. If `target < nums[mid]`, discard right half → `h = mid - 1`.
//     4. Else (`target > nums[mid]`), discard left half → `l = mid + 1`.
// • If loop ends, target not found → return -1.
//
// Time Complexity : **O(log n)** — search window halves each iteration  
// Space Complexity: **O(1)**   — only a few integer variables
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 31.39 MB  
//   Beats        : 45.78 % of C++ users
// -----------------------------------------------------------------------------

// Solution:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if (target==nums[mid]) return mid;
            else if(target<nums[mid]){
                h = mid-1;    
            }
            else{ // if target>nums[mid]
                l=mid+1;

            }

        }
        return -1;

        
    }
};
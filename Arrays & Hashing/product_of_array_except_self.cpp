// Product of Array Except Self
// Given an integer array `nums`, return an array `result` such that `result[i]`
// is the **product of all the elements of `nums` except `nums[i]`**.
//
// Constraints:
// - Do **not** use the division operator.
// - Solve in **O(n)** time.
// - Output array must not use extra space (besides the output itself).
//
// Example 1:
//   Input : nums = [1,2,4,6]
//   Output: [48,24,12,8]
//
// Example 2:
//   Input : nums = [-1,0,1,2,3]
//   Output: [0,-6,0,0,0]
//
// Approach:
// - We compute the result in two passes using two running products:
//   1. **Prefix pass**: from left to right, store the product of all elements **before** index `i`.
//   2. **Postfix pass**: from right to left, multiply the current result by the product of all elements **after** index `i`.
// - Initialize result vector with 1s.
// - `prefix` tracks the cumulative product before index `i` (left-side).
// - `postfix` tracks the cumulative product after index `i` (right-side).
//
// Time Complexity: **O(N)** — one pass for prefix and one for postfix = O(n) total.
// Space Complexity: **O(1)** extra space — output array excluded, and no additional arrays used.
//
// Solution Stats (from LeetCode submission):
//   Runtime : 0  ms
//   Beats   :  100 % of C++ users



//Solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);

        int prefix=1;
        int postfix =1;
        for (int i=0; i<nums.size();i++){
            result[i]=prefix; // Store product of all elements before i
            prefix*= nums[i];
        }
        for(int i=nums.size()-1; i>=0; i--){
            result[i]*=postfix; // Multiply by product of all elements after i
            postfix *= nums[i];
        }

        return result;


    }
};

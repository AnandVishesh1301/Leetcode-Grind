// 3Sum
// Given an integer array `nums`, return all **unique triplets** [nums[i], nums[j], nums[k]]
// such that:
//    - i ≠ j, i ≠ k, j ≠ k
//    - nums[i] + nums[j] + nums[k] == 0
// The solution set **must not contain duplicate triplets**.
//
// Example 1:
//   Input : nums = [-1, 0, 1, 2, -1, -4]
//   Output: [[-1, -1, 2], [-1, 0, 1]]
//
// Example 2:
//   Input : nums = [0, 1, 1]
//   Output: []
//
// Example 3:
//   Input : nums = [0, 0, 0]
//   Output: [[0, 0, 0]]
//
// Approach:
// - First, **sort** the array to make duplicate handling and two-pointer strategy easier.
// - Loop through the array using index `i`, and for each `nums[i]`, find two numbers (using 2 pointers)
//   such that `nums[i] + nums[l] + nums[r] == 0`.
// - Use two pointers (`l = i + 1`, `r = n - 1`) to find the complement pair.
//   - If the sum is too small: move `l++`
//   - If the sum is too big : move `r--`
//   - If sum is zero     : store the triplet, then skip duplicates by moving `l` forward
// - Skip duplicates for `nums[i]` itself to ensure triplets are unique.
//
// Time Complexity: **O(N^2)** —
//   - Sorting: O(N log N)
//   - Outer loop runs N times, inner two-pointer scan takes O(N) in total per outer iteration.
// Space Complexity: **O(1)** extra — excluding the space for result
//
// Solution Stats (from LeetCode submission):
//   Runtime : 50 ms  
//   Beats   : 57.21 % of C++ users


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum;

        for(int i=0; i<nums.size();i++){
            if (i>0 && nums[i-1]==nums[i]) continue;  // Skip Duplicated 'i' values
            int l=i+1;
            int r=n-1;
            while(r>l){
                sum = nums[i] + nums[l] + nums[r];
                if(sum>0) r--;
                else if(sum<0) l++;
                else{  // when sum ==0;
                    result.push_back({nums[i],nums[l],nums[r]}); // Found a valid triplet
                    l+=1;     // Move left pointer forward
                    while(nums[l]==nums[l-1] && l<r){         // Skip duplicate 'l' values
                        l+=1;
                    }
                }
                
            }

        }
        return result;
    }
};
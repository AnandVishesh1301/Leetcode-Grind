// Two Sum

// Given an array of integers `nums` and an integer `target`, return the indices of the
// two numbers such that they add up to `target`.
// - You may assume that each input would have **exactly one** solution.
// - You may **not** use the same element twice.
// - The answer can be returned in any order.
//
// Example 1:
//   Input : nums = [2,7,11,15], target = 9
//   Output: [0,1]      // because nums[0] + nums[1] == 9
//
// Example 2:
//   Input : nums = [3,2,4], target = 6
//   Output: [1,2]
//
// Example 3:
//   Input : nums = [3,3], target = 6
//   Output: [0,1]
//
// Approach:
// - We need to find two distinct indices i and j such that nums[i] + nums[j] == target.
// - Use an **unordered_map<int,int>** to map **value → index** of each element.
//   1. **First pass** — populate the hash map with each array element’s value and index.
//   2. **Second pass** — for every element nums[j], compute its complement
//      `second_addend = target - nums[j]` and check if that complement exists in the map
//      *and* is not the same index.  
//      – If found, return `{j, map[second_addend]}` immediately; the problem guarantees
//        this will be the unique answer.
//
// Time Complexity: **O(N)** — each element is processed at most twice (insert + lookup).  
// Space Complexity: **O(N)** — the hash map stores up to N value→index pairs.
//
// Solution Stats (from LeetCode submission):
//   Runtime : 4 ms
//   Beats   : 7.15 % of C++ users

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> result;
        // Populate the Hash Map with the Array contents
        for (int i=0; i<nums.size(); i++){
            umap[nums[i]] = i;
        }  

        for(int j=0; j<nums.size(); j++){

            int second_addend = target - nums[j];
            if(umap.find(second_addend)!=umap.end() && (j!=umap[second_addend]) ){
                result.push_back(j);
                result.push_back(umap[second_addend]);
                return result;
            }
            
        }
        return result;
    }
};
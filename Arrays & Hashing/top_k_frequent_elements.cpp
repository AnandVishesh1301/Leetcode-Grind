// Top K Frequent Elements
// Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.
// The answer can be returned in **any order**.
//
// Example 1:
//   Input : nums = [1,1,1,2,2,3], k = 2
//   Output: [1,2]
//
// Example 2:
//   Input : nums = [1], k = 1
//   Output: [1]
//
// Constraints:
// - Time complexity must be better than O(n log n)
//
// Approach:
// - Step 1: Use an **unordered_map<int,int>** to count the **frequency** of each number.
//           - Key = number in the array
//           - Value = number of times it appears (frequency)
// - Step 2: Use a **bucket sort** idea where index represents the frequency,
//           and each bucket[index] stores a list of numbers with that frequency.
//           - This takes O(n) extra space since max frequency is at most `n`.
// - Step 3: Reverse iterate from the back of the bucket (highest frequency),
//           collecting elements until we've found the top `k` most frequent ones.
//
// Time Complexity: **O(N)** —
//   - O(N) to build the frequency map
//   - O(N) to fill the bucket
//   - O(N) to collect the top `k` frequent elements
//
// Space Complexity: **O(N)** —
//   - O(N) for frequency map + O(N) for bucket array
//
// Solution Stats (from LeetCode submission):
//   Runtime : 6 ms
//   Beats   : 21.75 % of C++ users


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector<vector<int>> bucket(nums.size()+1);
        unordered_map<int,int> umap;
        //Populated Hash Map with Keys as the nums elements, and the values as their frequencies
        for (int i=0; i<nums.size(); i++){
            umap[nums[i]]++;
        }

        // Creating the bucket array
        for (const auto& pair:umap){
            bucket[pair.second].push_back(pair.first); 
        }
        // Reverse Iterate over the bucket array and push to result array.
       // int elements_pushed=0;

        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) { // Time Complexity for this for loop is O(N), because we are iterating over the bucket array and the subarray inside it only has k elements, and n>>k.
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }
        return result;
        
    }
};
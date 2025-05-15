// Contains Duplicate
// Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.
// Example 1:
// Input: nums = [1, 2, 3, 3]
// Output: true
// Example 2:
// Input: nums = [1, 2, 3, 4]
// Output: false

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;

        for (int i=0; i< nums.size(); i++){
            if((umap.find(nums[i])) != umap.end()){
                return true;
            }
            else{
                umap[nums[i]] = nums[i];
            }
            
        }
        return false;
    }
};

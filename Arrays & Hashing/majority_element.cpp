// 169. Majority Element
// ---------------------------------------------------------
// Problem:
// Given an array `nums` of size `n`, return the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element **always exists** in the array.
//
// ---------------------------------------------------------
// ✅ Approach: Hash Map (Frequency Counter)
// ---------------------------------------------------------
// - Traverse the array while building a frequency map of occurrences.
// - Maintain the current element with the highest count (`maxElement`).
// - Since a majority element is guaranteed to exist, return that tracked element.
//
// 🔁 Time Complexity : O(n) – single pass through the array
// 💾 Space Complexity: O(n) – due to hash map
//
// Leetcode Stats:
// Runtime: 3 ms (Beats 29.05%)
// Memory : 28.41 MB (Beats 6.69%)
// ---------------------------------------------------------


// Solution:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;   // value → count
        int maxCount   = 0;
        int maxElement = nums[0];      // any initial value

        for (int x : nums) {
            int cnt = ++freq[x];       // increment & fetch new count, cnt stores the value(count from the freq map)
            if (cnt > maxCount) {      // keep track of best so far
                maxCount   = cnt;
                maxElement = x;
            }
        }
        return maxElement;             // majority element
    }
};
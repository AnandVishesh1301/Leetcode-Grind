// 219. Contains Duplicate II
// ---------------------------------------------------------
// Problem:
// Given an array `nums` and an integer `k`, check if there are
// any two distinct indices `i` and `j` such that:
//     - nums[i] == nums[j]
//     - abs(i - j) <= k
// Return true if such a pair exists, otherwise false.
//
// Approach: Hash Map (value → latest index)
// ---------------------------------------------------------
// - We use an unordered_map to store the **most recent index** at which
//   each number was seen.
// - As we iterate through the array:
//    1. If the number has been seen before, we check the **distance** between
//       the current index `i` and the last recorded index.
//    2. If that distance is ≤ `k`, we return true immediately.
//    3. If not, we update the index of that number in the map.
//
// Why this works:
//   - The map always keeps the latest index of each number, so we only compare
//     with the most recent duplicate (if it exists).
//   - Time Complexity: O(n)
//   - Space Complexity: O(n) for the map
//
// Example:
//   nums = [1,2,3,1], k = 3
//   At i=3, nums[i]=1 → seen before at index 0 → abs(3 - 0) = 3 → ✅ return true
//
// Runtime     : 78 ms  (Beats 41.87%)
// Memory Usage: 98.54 MB (Beats 62.97%)
// 


// Solution:
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;  // maps number → last index it was seen at

        for (int i = 0; i < nums.size(); ++i) {
            auto it = lastIndex.find(nums[i]);
            if (it != lastIndex.end()) {                     // number seen before
                if (i - it->second <= k) return true;        // check distance ≤ k
            }
            lastIndex[nums[i]] = i;                          // update index
        }

        return false;  // no valid pair found
    }
};

// Approach: Sliding Window(Hash Set + Both L and R Pointers)
// Another approach uses a sliding window with a hash set: 
// keep a window of size ≤ k using two pointers. As you iterate, 
// check if the current element exists in the set—if yes, return true. 
// If the window exceeds size k, remove the leftmost element. This is cleaner 
// and also runs in O(n) time.

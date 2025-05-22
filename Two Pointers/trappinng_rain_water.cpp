// Trapping Rain Water
// Given an array `height[]` representing an elevation map where the width of each bar is 1,
// compute how much water can be trapped **after raining** between the bars.
//
// Water trapped at index `i` is based on the minimum of:
//   - the **tallest bar to the left** of `i`, and
//   - the **tallest bar to the right** of `i`
//   → Water[i] = max(0, min(maxLeft[i], maxRight[i]) - height[i])
//
// To compute this efficiently:
// - We precompute two arrays:
//   1. `maxLeft[i]`: Maximum height to the **left** of index `i` (excluding `i` itself)
//   2. `maxRight[i]`: Maximum height to the **right** of index `i` (excluding `i` itself)
//
// Example:
//   Input  : height = [0,1,0,2,1,0,1,3,2,1,2,1]
//
//   maxLeft:  [0,0,1,1,2,2,2,2,3,3,3,3]
//   maxRight:[3,3,3,3,3,3,3,2,2,2,1,0]
//
//   Trapped water at index `i` = max(0, min(maxLeft[i], maxRight[i]) - height[i])
//   Total trapped water = 6
//
// Approach:
// - Step 1: Populate `maxLeft[]` from left to right.
// - Step 2: Populate `maxRight[]` from right to left.
// - Step 3: Traverse once more to compute water at each index using the min of maxLeft & maxRight.
//
// Time Complexity: **O(N)** — 3 linear passes over the array
// Space Complexity: **O(N)** — for `maxLeft[]` and `maxRight[]` arrays
//
// Solution Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
//   Memory  : 28.55 MB
//   Beats   : 5.30 % of C++ users


// Approach 1:Using separate arrays to store maxLeft and maxRight, which leads to O(n) space complexity.
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        int maxL = 0, maxR = 0;
        int sumTrappedWater = 0;

        // Step 1: Populate maxLeft[i] — max height to the left of index i
        for (int i = 1; i < n; i++) {
            maxL = max(maxL, height[i - 1]);
            maxLeft[i] = maxL;
        }

        // Step 2: Populate maxRight[i] — max height to the right of index i
        for (int i = n - 2; i >= 0; i--) {
            maxR = max(maxR, height[i + 1]);
            maxRight[i] = maxR;
        }

        // Step 3: Calculate water trapped at each index
        for (int i = 0; i < n; ++i) {
            int minLR = min(maxLeft[i], maxRight[i]);
            if (minLR > height[i]) {
                sumTrappedWater += minLR - height[i];  // Water trapped at index i
            }
        }

        return sumTrappedWater;
    }
};


// Approach 2: Using two pointers to calculate the trapped water, which leads to O(1) space complexity.
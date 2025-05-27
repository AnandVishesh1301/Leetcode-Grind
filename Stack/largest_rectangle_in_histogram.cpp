// Largest Rectangle in Histogram
// Given an array `heights[]`, each element represents the height of a bar in a histogram
// (each bar has width = 1).  Return the **maximum area** of a rectangle that can be
// formed entirely of bars in this histogram.
//
// Example 1:
//   Input : heights = [2,1,5,6,2,3]
//   Output: 10
//
// Example 2:
//   Input : heights = [2,4]
//   Output: 4
//
// -----------------------------------------------------------------------------
// Approach  ➜ **Monotonic-Increasing Stack**
// -----------------------------------------------------------------------------
// • Idea
//   – While scanning from left to right, maintain a stack whose heights
//     are **monotonically increasing**.  
//   – Each stack element stores `(startIndex, height)` where
//       • `height`  = bar height
//       • `startIndex` = furthest index to the **left** this bar can extend
//         without encountering a shorter bar.
//
// • Why it works
//   1. When the current bar `heights[i]` is **≥** the bar on the stack-top,
//      it can extend the rectangle of that bar, so we keep pushing.
//   2. When we meet a bar **shorter** than the stack-top,
//      the rectangle that used the taller height must **end at i – 1**.
//      We pop the taller bar, compute its area, and update `maxArea`.
//      However, the **shorter bar** could still extend back to the popped
//      bar’s `startIndex`, so we remember that index (variable `start`)
//      before pushing the new shorter bar.
// • Final pass
//   – After the left-to-right scan, every bar left in the stack extends
//     to the array’s end (`n – 1`).  Pop them and update `maxArea`.
//
// Time Complexity : **O(N)**  (each bar pushed & popped at most once)  
// Space Complexity: **O(N)**  (stack)
//
// -----------------------------------------------------------------------------
// Time Stats (from LeetCode submission):
//   Runtime : 25 ms  
//   Beats   : 51.70 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 83.72 MB  
//   Beats        : 55.81 % of C++ users
// -----------------------------------------------------------------------------

//Solution
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        stack<pair<int,int>> st;          // (startIndex, height)

        for (int i = 0; i < n; ++i) {
            int start = i;                // leftmost index this bar may reach

            // Pop all taller bars; their rectangle ends at i-1
            while (!st.empty() && st.top().second > heights[i]) {
                auto [idx, h] = st.top(); st.pop();
                maxArea = max(maxArea, h * (i - idx));   // width = i - idx
                start = idx;                             // new bar can extend back
            }

            st.push({start, heights[i]});  // push (possibly shifted) current bar
        }

        // Any bars left extend to n-1, in the stack that were not popped
        while (!st.empty()) {
            auto [idx, h] = st.top(); st.pop();
            maxArea = max(maxArea, h * (n - idx));       // width = n - idx
        }

        return maxArea;
    }
};

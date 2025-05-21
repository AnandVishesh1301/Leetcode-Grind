// Container With Most Water
// You are given an array `height[]` where each element represents the height of a vertical line drawn at index `i`.
// The goal is to find **two lines** that, together with the x-axis, form a container that can store the **most water**.
//
// Important Constraints:
// - The container must be formed using vertical lines (no slanting).
// - Width of the container is the distance between the two lines (indices).
// - Area = min(height[left], height[right]) * (right - left)
//
// Example 1:
//   Input : height = [1,8,6,2,5,4,8,3,7]
//   Output: 49
//   Explanation: Use lines at index 1 and 8 → height = 7, width = 8 - 1 = 7 → area = 49
//
// Example 2:
//   Input : height = [1,1]
//   Output: 1
//
// Approach:
// - Use **two pointers**: one starting from the left (`l`) and one from the right (`r`).
// - At every step, calculate the area using the current two lines: `area = min(height[l], height[r]) * (r - l)`
// - Update the maximum area if the current one is larger.
// - Move the **shorter** line inward, since that’s the limiting factor for height.
//   - If height[l] < height[r], move `l++`
//   - Else, move `r--`
// - This ensures all possible widest containers are checked in linear time.
//
// Time Complexity: **O(N)** — each element is visited at most once
// Space Complexity: **O(1)** — only a few variables used for tracking indices and area
//
// Solution Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int l = 0;
        int r = n-1;
        int area =0;

        while(r>l){
            int h = min(height[l], height[r]); // Use the shorter height as limiting wall
            int w = r - l;         // Width between the two lines
            area = max(area, h * w);  // Update max area if current is greater

            // Move the pointer with the shorter height inward
            // Move the shorter line inward to explore a potentially taller container

            if (height[l] < height[r]) l++;
            else r--;
        
        }
        return area;

    }
};
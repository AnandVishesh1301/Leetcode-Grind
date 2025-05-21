// Two Sum II - Input Array Is Sorted
// Given a **1-indexed** array `numbers` sorted in **non-decreasing order**,
// return the indices `[index1, index2]` of two numbers such that:
//   - `numbers[index1] + numbers[index2] == target`
//   - `1 <= index1 < index2 <= numbers.length`
//   - Exactly **one solution** is guaranteed.
//   - Cannot use the same element twice.
//   - Must use **constant extra space**.
//
// Example 1:
//   Input : numbers = [2,7,11,15], target = 9
//   Output: [1,2]
//
// Example 2:
//   Input : numbers = [2,3,4], target = 6
//   Output: [1,3]
//
// Example 3:
//   Input : numbers = [-1,0], target = -1
//   Output: [1,2]
//
// Approach:
// - Use the **two-pointer technique**, leveraging the fact that the array is **sorted**.
// - Initialize two pointers: `l = 0` (start) and `r = n - 1` (end).
// - While `l < r`, compute `curSum = numbers[l] + numbers[r]`:
//   1. If `curSum > target`, move right pointer left (`r--`) to decrease the sum.
//   2. If `curSum < target`, move left pointer right (`l++`) to increase the sum.
//   3. If `curSum == target`, return the 1-indexed positions `[l+1, r+1]`.
// - This works in **O(n)** time and **O(1)** space.
//
// Time Complexity: **O(N)** — each element is visited at most once by either pointer.
// Space Complexity: **O(1)** — only a fixed number of variables used; no extra memory.
//
// Solution Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int n = numbers.size();
        int l = 0;
        int r = n-1;

        while(l<r){
            int curSum=numbers[l] + numbers[r];
            if (curSum>target) r-=1;
            else if (curSum<target) l+=1;
            else{
                result.push_back(l+1);
                result.push_back(r+1);
                return result;
            }

        }
        return result;

        
    }
};


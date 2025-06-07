// 344. Reverse String
// --------------------
// Problem:
// Given a character array `s`, reverse the array in-place using O(1) extra memory.
//
// --------------------------------------------------------------
// Approach: Two-Pointer Swap (In-Place)
// --------------------------------------------------------------
// Logic:
// - We use two pointers: one starting from the beginning (`l`) and one from the end (`r`).
// - While `l <= r`, we swap the characters at these indices and move both pointers inward.
// - This ensures the characters are reversed without using any extra space.
//In-place means:
//   - We directly modify the input array instead of creating a new one.
//
// Why O(1) space?
//   - Because we only use two integer pointers and no additional data structures.
//
// Time Complexity:
//   O(n) – We touch each character exactly once from both ends.
// Space Complexity:
//   O(1) – No extra space used, only two pointers.
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 27.33 MB
//   Beats        : 17.65 % of C++ users
// --------------------------------------------------------------


// Solution:
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;                   // Left pointer
        int r = s.size() - 1;        // Right pointer

        while (l <= r) {
            swap(s[l], s[r]);       // Swap the characters at left and right
            l++;                    // Move left pointer forward
            r--;                    // Move right pointer backward
        }
    }
};

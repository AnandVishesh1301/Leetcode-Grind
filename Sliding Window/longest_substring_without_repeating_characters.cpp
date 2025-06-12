// 3. Longest Substring Without Repeating Characters
// Problem:
// Given a string `s`, return the **length** of the longest substring that contains **no repeated characters**.
//
// 
// Approach: Sliding Window + HashMap
// --------------------------------------------------
// - Use a dynamic sliding window with two pointers:
//   ➤ `l` is the **left** of the current window (start of substring)
//   ➤ `right` iterates through each character in the string
// - Maintain a hashmap (`umap`) to store characters **currently in the window**
// - If the current char is already in the map (i.e., duplicate), move `l` forward
//   ➤ At each step, **erase s[l] from the map** and increment `l` until the duplicate is removed
// - After handling duplicates, add the new character and update the length of the longest valid window
//
// Mian logic dry-run Example:
// s = "abcabcbb"
// → When `right = 3` (char = 'a'), 'a' is already in the map from index 0
//   ➤ So we slide `l` from 0 to 1, removing 'a' from the map → Now the window is valid again
//
// Time Complexity:
//   O(n) – Each character is added and removed from map at most once
// Space Complexity:
//   O(min(n, m)) – Where `m` is the size of the character set (usually 128 for ASCII)
//
// Time Stats (from LeetCode submission):
//   Runtime : 22 ms  
//   Beats   : 21.94 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 14.32 MB
//   Beats        : 22.48 % of C++ users
// --------------------------------------------------


// Soltuion:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;  // map to store characters currently in the window
        int l = 0;                     // left boundary of window
        int length = 0;               // result for max substring length

        for (int right = 0; right < s.size(); right++) {
            // While there's a duplicate in the current window
            while (umap.find(s[right]) != umap.end()) {
                umap.erase(s[l]);     // remove from window start
                l++;                  // move left pointer forward
            }
            umap[s[right]] = 1;       // include current character in window
            length = max(length, right - l + 1); // update max length
        }
        return length;
    }
};

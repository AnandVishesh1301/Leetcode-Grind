// 424. Longest Repeating Character Replacement

// Problem:
// You are given a string `s` and an integer `k`. You can perform **at most `k` character replacements**
// to make a substring with all the same letter.
// Return the length of the longest such substring.
//
// ---------------------------------------------
// Approach: Sliding Window + Frequency Count
// - Maintain a sliding window with left (`l`) and right (`r`) pointers.
// - Use an unordered_map to **track frequency** of each character in the current window.
// - The key idea is: to make the entire window consist of one character, 
//   you only need to **change (window length - max frequency character)**.
//   ➤ If that value is ≤ `k`, then it's valid.
//   ➤ Else, shrink the window from the left.
//
// Why does the condition `(r - l + 1) - maxFreq > k` work?
//   - (r - l + 1) = total characters in window
//   - maxFreq = frequency of most common character
//   - So the rest must be changed => if more than `k`, window is invalid.
//
// Example 1:
//   s = "AABABBA", k = 1
//   maxFreq = 3 ('A')
//   When r=5, window = "ABABB", (length = 5), (5 - 3 = 2 > k) → Invalid → shrink
//
// Inner loop over map:
//   Although we loop over all characters in `umap`, there are only 26 uppercase letters,
//   so this step is O(26) ≈ constant, and total time is still linear.
//
// Runtime  : 14 ms (Beats 22.01%)
// Memory   : 11.04 MB (Beats 19.64%)


//Solution:
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> umap;  // frequency of characters in current window
        int result = 0;
        int l = 0;                      // left boundary of window
        int maxValue = 0;              // frequency of the most common character in the window

        for (int r = 0; r < s.size(); r++) {
            umap[s[r]]++;              // build/update the frequency map

            // Update the most frequent character count
            for (const auto& pair : umap) {  // At most 26 iterations (A-Z)
                if (pair.second > maxValue) {
                    maxValue = pair.second;
                }
            }

            // If characters to replace exceed k, shrink window from the left
            while ((r - l + 1) - maxValue > k) {
                umap[s[l]]--;          // remove the leftmost char from window
                l++;                   // slide window to the right
            }

            // Update result with the valid window size
            result = max(result, r - l + 1);
        }

        return result;
    }
};

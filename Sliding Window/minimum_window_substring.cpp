// 76. Minimum Window Substring

// Problem:
// Given two strings `s` and `t`, return the smallest window in `s` 
// that contains all the characters of `t` (including duplicates).
// If no such window exists, return an empty string.
//
// Approach: Sliding Window + Hash Maps

// - Build a frequency map (`countT`) for string `t`.
// - Use another map (`window`) to track characters in the current window in `s`.
// - Initialize two pointers `l` and `r` for the sliding window.
// - Expand the window by moving `r` to the right.
// - For every new character added:
//     1. Update the `window` count.
//     2. If it matches `countT`, increase `have`.
// - When `have == need` (i.e., all required characters are in window):
//     1. Try to shrink from the left to get the smallest valid window.
//     2. Update result if this window is smaller than previous best.
//     3. Reduce the count of the leftmost character and slide `l`.
// - After traversing, return the minimum substring if found.
//
// How it works:
//   - We maintain exact frequency matches and only contract the window when valid.
//   - Ensures correctness while optimizing for minimal window length.
//   - Time Complexity: O(s.length() + t.length())
//   - Space Complexity: O(t.length()) for frequency maps
//
// Example:
//   s = "ADOBECODEBANC", t = "ABC"
//   Result is "BANC" — smallest substring that contains 'A', 'B', and 'C'
//
// Runtime     : 12 ms  (Beats 48.02%)
// Memory Usage: 11.54 MB (Beats 44.64%)
// ---------------------------------------------------------

//SOltuion:
class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") return "";

        unordered_map<char, int> countT;  // Frequency map for characters in t
        unordered_map<char, int> window;  // Frequency map for current window in s

        for (char c : t) {  // Build frequency map for t
            countT[c]++;
        }

        int have = 0;                     // Number of characters meeting required frequency
        int need = countT.size();         // Total unique characters we need to match
        int resLen = INT_MAX;            // Track length of smallest valid window
        int resStart = 0;                // Start index of the smallest window found
        int l = 0;                       // Left pointer of the sliding window

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;  // Add current character to the window

            // If character is part of t and its required frequency is met
            if (countT.find(c) != countT.end() && window[c] == countT[c]) {
                have++;
            }

            // When current window satisfies all character requirements
            while (have == need) {
                // Update result if this window is smaller
                if (r - l + 1 < resLen) {
                    resStart = l;
                    resLen = r - l + 1;
                }

                // Shrink window from the left
                window[s[l]]--;
                // If character is in t and frequency is now less than needed
                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;  // Move left pointer forward
            }
        }

        return (resLen == INT_MAX) ? "" : s.substr(resStart, resLen);
    }
};


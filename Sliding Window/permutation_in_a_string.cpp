
// 567. Permutation in String
// Problem:
// Given two strings s1 and s2, return true if any substring of s2 
// is a permutation of s1. Otherwise, return false.
//
// Approach: Sliding Window + Frequency Map
// - We use two hash maps:
//     • `umap1` stores the frequency count of s1.
//     • `umap2` dynamically tracks the frequency of characters in the 
//        current window in s2 of length equal to s1.
//
// - We slide a window over s2 and update `umap2` as we go:
//     1. Add the current character to the window.
//     2. If the window size exceeds s1's length, remove the leftmost character.
//     3. If `umap1` == `umap2`, we found a valid permutation → return true.
//
// How this works:
//   - By maintaining a window of exactly the same size as s1, we ensure that
//     any match in character frequencies means we found a permutation.
//   - Frequency maps allow constant time comparison of character counts.
//
// Example:
//   s1 = "ab", s2 = "eidbaooo"
//   At window "ba" → matches s1 → return true
//
// - Time Complexity: O(n), where n = length of s2
// - Space Complexity: O(1), bounded by alphabet size (26 lowercase letters)
//
// Runtime     : 3 ms  (Beats 68.29%)
// Memory Usage: 10.78 MB (Beats 27.59%)
// ---------------------------------------------------------


// Solution: 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> umap1, umap2;
        int l = 0;
        
        // Count character frequencies in s1
        for(char c : s1) {
            umap1[c]++;
        }
        
        for(int r = 0; r < s2.size(); r++) {
            umap2[s2[r]]++;  // Add current character to window
            
            // Maintain window size equal to s1's length
            if(r - l + 1 > s1.size()) {
                if(umap2[s2[l]] == 1) {
                    umap2.erase(s2[l]);
                } else {
                    umap2[s2[l]]--;
                }
                l++;
            }
            
            // Compare frequency maps
            if(umap1 == umap2) {
                return true;
            }
        }
        return false;
    }
};
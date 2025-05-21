// Valid Palindrome
// A string is a **palindrome** if it reads the same forward and backward **after**:
//   - Converting all uppercase letters to lowercase
//   - Removing all **non-alphanumeric** characters (only letters and digits remain)
//
// Return `true` if the input string is a valid palindrome, else return `false`.
//
// Example 1:
//   Input : s = "A man, a plan, a canal: Panama"
//   Output: true
//   Explanation: Becomes "amanaplanacanalpanama", which is a valid palindrome
//
// Example 2:
//   Input : s = "race a car"
//   Output: false
//   Explanation: Becomes "raceacar", which is not a palindrome
//
// Approach:
// - Use two pointers: one from the start (`left`), one from the end (`right`).
// - Move the pointers inward while skipping non-alphanumeric characters.
// - At each step, compare lowercase versions of the characters at `left` and `right`.
//   - If they differ, return false.
//   - If they match, continue moving inward.
// - Use a helper function `isalphanum(char c)` to check for alphanumeric characters.
//
// Time Complexity: **O(N)** — each character is visited at most once
// Space Complexity: **O(1)** — only pointers and local variables used (no extra space)
//
// Solution Stats (from LeetCode submission):
//   Runtime : 4 ms  
//   Beats   : 17.28 % of C++ users


class Solution {
public:
    static bool isalphanum(char c) {          // helper remains the same
        return (('A' <= c && c <= 'Z') ||
                ('a' <= c && c <= 'z') ||
                ('0' <= c && c <= '9'));
    }
    
    bool isPalindrome(string s) {
        int left  = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {

            // move left forward until it hits an alphanumeric char
            while (left < right && !isalphanum(s[left])) ++left;

            // move right backward until it hits an alphanumeric char
            while (left < right && !isalphanum(s[right])) --right;

            // compare, ignoring case
            if (std::tolower(static_cast<unsigned char>(s[left])) !=
                std::tolower(static_cast<unsigned char>(s[right])))
                return false;

            ++left;
            --right;
        }
        return true;
        
    }
};

// Apprach 02: Using Address Pointers and not indices. 

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string filteredString = "";
            
//         for (char c : s) {
//             // Skip punctuation and spaces and convert to lowercase
//             if (!ispunct(c) && !isspace(c)) {
//                 filteredString += (char)tolower(c);
//             }
//         }
//         int n= filteredString.size();
//         char *f = &filteredString[0];
//         char *e = &filteredString[0] + n-1;

//         if(filteredString.size()<2) return true;

//         while(e>f){
//             if(*e!=*f) return false;
//             ++f;
//             --e;
//         }
//         return true;

//     }
// };
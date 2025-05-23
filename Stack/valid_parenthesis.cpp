// Valid Parentheses
// Given a string `s` containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is **valid**.
//
// A string is valid if:
//   - Every open bracket is closed by the same type of bracket
//   - Brackets are closed in the correct order
//   - Each closing bracket has a corresponding unmatched opening bracket
//
// Example 1:
//   Input : s = "()"
//   Output: true
//
// Example 2:
//   Input : s = "()[]{}"
//   Output: true
//
// Example 3:
//   Input : s = "(]"
//   Output: false
//
// Example 4:
//   Input : s = "([])"
//   Output: true
//
// Approach:
// - Use a **stack** to keep track of open brackets.
// - Use a **hash map** to map each closing bracket to its corresponding opening bracket.
// - Traverse the string:
//     - If the character is an opening bracket, push it to the stack.
//     - If it's a closing bracket, check if the top of the stack is its corresponding opening bracket.
//       - If yes, pop from stack
//       - If no, return false immediately
// - After traversal, if the stack is empty, the string is valid.
//
// Time Complexity: **O(N)** — each character is processed once
// Space Complexity: **O(N)** — in the worst case, the stack may hold all characters (e.g., "((((((((")
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 8.87 MB
//   Beats        : 35.13 % of C++ users

// Approach 1 : Using Stack and Hash Map
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parenthesisPair = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> brackets;

        for (char c : s) {
            if (!parenthesisPair.count(c)) {
                // Opening bracket — push to stack
                brackets.push(c);
            } else {
                // Closing bracket — check top of stack
                if (!brackets.empty() && brackets.top() == parenthesisPair[c]) {
                    brackets.pop(); // Valid match
                } else {
                    return false; // Mismatch or empty stack
                }
            }
        }

        // Valid if no unmatched opening brackets remain
        return brackets.empty();
    }
};

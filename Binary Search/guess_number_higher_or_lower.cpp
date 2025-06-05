// 374. Guess Number Higher or Lower
// ----------------------------------
// Problem:
// We need to guess a number chosen from the range [1, n].
// After each guess, we receive a hint from the pre-defined `guess(int num)` API:
//   - returns  0 if num == pick
//   - returns -1 if num > pick
//   - returns  1 if num < pick
// Our goal is to find the correct number with the fewest guesses.
//
// Approach:
// ✅ Use Binary Search to minimize the number of guesses:
//    - Start with bounds: l = 1, r = n.
//    - At each step, guess the middle number `m = (l + r) / 2`.
//    - Use `guess(m)` to check the hint:
//        ▸ If guess(m) == 0 → we found the correct number.
//        ▸ If guess(m) == 1 → the target is greater → search right half (l = m + 1).
//        ▸ If guess(m) == -1 → the target is smaller → search left half (r = m - 1).
// ✅ We repeat until the number is found.
//
// Note:
// - Using `long long` for `l` and `r` helps avoid integer overflow when n is near 2³¹.
//
// Time Complexity:
//   O(log n) – classic binary search
// Space Complexity:
//   O(1) – constant space
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 8 MB
//   Beats        : 39.88 % of C++ users

// Solution 
class Solution {
public:
    int guessNumber(int n) {
        long long l = 1;
        long long r = n;

        while (l <= r) {
            int m = (l + r) / 2;
            int res = guess(m);  // Get the result of the guess

            if (res == 0) {
                return m;        // Correct guess
            }
            else if (res == 1) {
                l = m + 1;       // Target number is greater
            }
            else {
                r = m - 1;       // Target number is smaller
            }
        }

        return -1;  // Should never reach here if pick ∈ [1, n]
    }
};

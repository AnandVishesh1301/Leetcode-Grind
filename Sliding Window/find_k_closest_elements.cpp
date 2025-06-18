// 658. Find K Closest Elements
// ---------------------------------------------------------
// Problem:
// Given a **sorted** array `arr`, an integer `x`, and a number `k`,
// return the `k` elements that are closest to `x`. If there’s a tie
// (equal difference), prefer the **smaller element**.
//
// Approach: Binary Search + Two-Pointer Window Expansion
// 
// S 1: Use Binary Search to locate the closest element to `x`.
// - Track the index `currIndex` of the element with minimum difference.
// - If two elements have the same diff, prefer the smaller value.
//
// S 2: Expand outward from `currIndex` using two pointers (left & right)
// - Expand the window to include `k` elements:
//     • If left boundary is at start, shift right.
//     • If right boundary is at end, shift left.
//     • Else, compare abs(x - arr[l-1]) and abs(arr[r+1] - x) to decide which side to expand.
//
// - Finally, return the subarray from `l` to `r` (inclusive).
//
// Why it works:
//   - The array is sorted, so expanding from the closest center ensures
//     that the result remains sorted and contains the k closest values.
//   - Binary search narrows the search efficiently in O(log (n + k)).
//
// - Time Complexity:
//     • Binary Search: O(log n)
//     • Expanding Window: O(k)
//     • Final Subarray Construction: O(k)
//     → Total: O(log n + k)
// - Space Complexity: O(1) extra + O(k) for output
//
// Example:
//   arr = [1,2,3,4,5], k = 4, x = 3
//   Closest to x = 3 → expand around 3 → return [1,2,3,4]
//
// ---------------------------------------------------------
// Runtime      : 0 ms (Beats 100% of C++ users)
// Memory Usage : 35.68 MB (Beats 99.01% of C++ users)
// ---------------------------------------------------------


// Solution: 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        // P1: Binary Search to find the index of the element closest to x
        int l = 0;
        int r = arr.size() - 1;
        int val = arr[0];       // To track the closest value to x
        int currIndex = 0;      // To store the index of the closest value

        while (l <= r) {
            int m = (l + r) / 2;

            int currDiff = abs(arr[m] - x);   // Difference between current mid and x
            int resDiff = abs(val - x);       // Difference between previously stored closest value and x

            // Update if current is closer OR same distance but smaller value
            if ((currDiff < resDiff) || (currDiff == resDiff && arr[m] < val)) {
                val = arr[m];
                currIndex = m;
            }

            // Move binary search window
            if (arr[m] < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        // P2: Two-pointer expansion from the closest index to find k elements
        l = currIndex;
        r = currIndex;

        for (int i = 0; i < k - 1; i++) {  // We already count one element at currIndex, so expand k-1 times
            if (l == 0) {
                r++; // Left bound reached, expand to the right
            }
            else if (r == arr.size() - 1) {
                l--; // Right bound reached, expand to the left
            }
            else if (x - arr[l - 1] <= arr[r + 1] - x) {
                l--; // Expand left if it's closer or equal (prefers smaller number)
            }
            else {
                r++; // Expand right
            }
        }

        // Return subarray from l to r inclusive
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};

// Search a 2-D Matrix
// The matrix has two key properties:
//   1. Each **row** is sorted in non-decreasing order.
//   2. The **first** element of each row is greater than the **last** element
//      of the previous row.
// Goal
//   Return **true** if `target` exists, otherwise **false**, in **O(log (m·n))** time.
//Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// -----------------------------------------------------------------------------
// Why not “binary-search every row”?
// ──────────────────────────────────
//   • A two-step plan of “for each row do binary search” costs
//       O(m · log n)              (worst-case check every row)
//     or, if you first binary-search rows by their last element and then
//     binary-search within that row, you still spend
//       O(log m + log n)  =  O(log (m·n)).
//   • But iterating row-by-row with a **for-loop** + per-row binary search
//     is *not* O(log (m·n))*—it is O(m · log n).*  
//   • Exploiting property 2 lets us treat the whole matrix as **one**
//     sorted array and achieve **true logarithmic time** on m·n elements.
//
// -----------------------------------------------------------------------------
// Approach  ➜  Two-Phase Binary Search
// -----------------------------------------------------------------------------
// 1️⃣  **Row selection (binary search on rows)**
//     • Compare `target` with the first / last element of the middle row.
//     • Narrow the search to the single row that could contain `target`.
//
// 2️⃣  **Column search (binary search inside that row)**
//     • Classic binary search on the identified row.
//
// -----------------------------------------------------------------------------
// Time Complexity : **O(log m + log n) = O(log (m·n))**  
// Space Complexity: **O(1)** – only indices
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 13.29 MB  
//   Beats        : 75.80 % of C++ users
// -----------------------------------------------------------------------------

// Soltution

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        /* ---------- Phase 1 : locate the candidate row ---------- */
        int top = 0, bot = rows - 1, row = -1;

        while (top <= bot) {
            int mid = (top + bot) / 2;

            if (target > matrix[mid][cols - 1])        // target larger than last elem → go down
                top = mid + 1;
            else if (target < matrix[mid][0])          // target smaller than first elem → go up
                bot = mid - 1;
            else {                                     // target must be in this row
                row = mid;
                break;
            }
        }
        if (row == -1) return false;                   // no viable row

        /* ---------- Phase 2 : binary-search inside that row ---------- */
        int l = 0, r = cols - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (target > matrix[row][m])
                l = m + 1;
            else if (target < matrix[row][m])
                r = m - 1;
            else
                return true;                           // found it
        }
        return false;                                  // not found
    }
};

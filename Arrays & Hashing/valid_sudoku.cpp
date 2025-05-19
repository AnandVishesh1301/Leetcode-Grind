// Valid Sudoku
// Determine if a 9x9 partially filled Sudoku board is **valid**.
// A valid board must satisfy the following rules:
//   - Each **row** must contain the digits 1–9 **without repetition**
//   - Each **column** must contain the digits 1–9 **without repetition**
//   - Each **3x3 sub-box** (total 9 sub-boxes) must contain the digits 1–9 **without repetition**
//
// Note:
// - The board may be partially filled.
// - You only need to **validate** the current configuration; the board doesn't need to be solvable.
//
// Example 1 (Valid):
// Input:
// [["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]]
// Output: true
//
// Example 2 (Invalid):
// Input has two '8's in the same top-left sub-box → Output: false
//
// Approach:
// - Use three 2D boolean arrays to track occurrences of digits:
//   1. `row[i][num]` = true means digit `num+1` has appeared in row `i`
//   2. `col[j][num]` = true means digit `num+1` has appeared in column `j`
//   3. `subMatrix[k][num]` = true means digit `num+1` has appeared in 3x3 box `k`
//     - Sub-box index `k = (i / 3) * 3 + (j / 3)` maps (i, j) to one of the 9 sub-boxes
// - Each digit is converted to `num = board[i][j] - '1'` to get index 0–8
// - For every filled cell, check the three trackers. If any is already true, it's a duplicate → return false.
// - If not, mark the digit as seen in that row, column, and box.
//
// Time Complexity: **O(1)** — Fixed size board (9x9) = 81 cells max
// Space Complexity: **O(1)** — Three 9x9 arrays = constant space
//
// Solution Stats: 
//   Runtime : 4 ms  
//   Beats   : 54.35% of C++ users


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> subMatrix(9, vector<bool>(9, false));

        for(int i=0;i<row.size();i++){
            for(int j=0;j<col.size();j++){
                if(board[i][j]=='.') continue;

                int num = board[i][j] - '1';
                int boxIndex = (i/3)*3 + j/3; // Map (i, j) to 0–8 sub-box index as there are 9 rows and columns in the subMatrix as well, each row depicting an individual submatrix in the sudoku box

                if(row[i][num] || col[j][num] || subMatrix[boxIndex][num]){
                    return false;
                }

                row[i][num]= true;
                col[j][num]= true;
                subMatrix[boxIndex][num]= true;

            }
        }

        return true;

    }
};
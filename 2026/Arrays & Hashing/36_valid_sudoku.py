class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        """
        VALID SUDOKU - Hash Set 
        ============================================================
        
        BOARD STRUCTURE (9x9 Grid):
        ----------------------------------------
           Col: 0   1   2 | 3   4   5 | 6   7   8
        Row  ═════════════╪═══════════╪═══════════
         0   │           │           │
         1   │  Box 0    │  Box 1    │  Box 2
         2   │           │           │
            ─────────────┼───────────┼───────────
         3   │           │           │
         4   │  Box 3    │  Box 4    │  Box 5
         5   │           │           │
            ─────────────┼───────────┼───────────
         6   │           │           │
         7   │  Box 6    │  Box 7    │  Box 8
         8   │           │           │
        ============================================================
        
        3 HASH SETS TRACKING:
        ----------------------
        1. rows[r]       → Tracks digits in Row r
        2. cols[c]       → Tracks digits in Column c  
        3. squares[(r//3, c//3)] → Tracks digits in 3x3 Sub-Square
        
        SUB-SQUARE CALCULATION (r//3, c//3):
        ------------------------------------
        - Row 0-2, Col 0-2 → (0,0) = Box 0
        - Row 0-2, Col 3-5 → (0,1) = Box 1
        - Row 0-2, Col 6-8 → (0,2) = Box 2
        - Row 3-5, Col 0-2 → (1,0) = Box 3
        - Row 3-5, Col 3-5 → (1,1) = Box 4
        - Row 3-5, Col 6-8 → (1,2) = Box 5
        - Row 6-8, Col 0-2 → (2,0) = Box 6
        - Row 6-8, Col 3-5 → (2,1) = Box 7
        - Row 6-8, Col 6-8 → (2,2) = Box 8

            Row => { 0 : { elements in Row 0 }
                      { 1 : { elements in Row 1 }
                      { 2 : { elements in Row 2 }
                      ...
                      { 8 : { elements in Row 8 } }
                
            Col => { 0 : { elements in Col 0 }
                    { 1 : { elements in Col 1 }
                    { 2 : { elements in Col 2 }
                    ...
                    { 8 : { elements in Col 8 } }
                
            Square => { (0,0) : { elements in 0x0 sq - 1st sq block }
                        { (0,1) : { elements in 0x1 sq - 2nd sq block }
                        { (0,2) : { elements in 0x2 sq - 3rd sq block }
                        { (1,0) : { elements in 1x0 sq - 4th sq block }
                        { (1,1) : { elements in 1x1 sq - 5th sq block }
                        { (1,2) : { elements in 1x2 sq - 6th sq block }
                        { (2,0) : { elements in 2x0 sq - 7th sq block }
                        { (2,1) : { elements in 2x1 sq - 8th sq block }
                        { (2,2) : { elements in 2x2 sq - 9th sq block } }
                         
                         
        If ANY duplicate found → return False
        If NO duplicates after checking all cells → return True
        ============================================================
        """
        
        # Hash-Sets for Rows, Cols, and Sub Squares
        rows = defaultdict(set)
        cols = defaultdict(set)
        squares = defaultdict(set)


        for r in range(len(board)):
            for c in range(len(board[0])):

                # Skip if empty spot
                if board[r][c] == ".":
                    continue
                
                # Return False if:
                # - Duplicate in the same Row
                # - Duplicate in the same Col
                # - Duplicate in the same Sub Square

                if (board[r][c] in rows[r] or 
                    board[r][c] in cols[c] or 
                    board[r][c] in squares[(r//3,c//3)]):

                    return False
                
                # Else, add to all the above corresponding hash-sets
                rows[r].add(board[r][c])
                cols[c].add(board[r][c])
                squares[(r//3,c//3)].add(board[r][c])

        return True

                

        
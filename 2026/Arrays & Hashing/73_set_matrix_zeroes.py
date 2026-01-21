class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        row = [False] * len(matrix)
        col = [False] * len(matrix[0])

        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c]==0:
                    row[r] = True
                    col[c] = True

                else:
                    continue
    
        # Now the row and col arrays have corresponding zeroes
        # Applying those to matrix now
        # col = [_,0,0]. row = [0,0,_]

        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if row[r] or col[c]:
                    matrix[r][c]=0

        








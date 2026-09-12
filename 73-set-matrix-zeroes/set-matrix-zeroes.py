class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        row,col = [],[]
        m,n = len(matrix),len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row.append(i)
                    col.append(j)
        
        for r in row:
            for i in range(n):
                matrix[r][i] = 0

        for c in col:
            for j in range(m):
                matrix[j][c] = 0
        
        

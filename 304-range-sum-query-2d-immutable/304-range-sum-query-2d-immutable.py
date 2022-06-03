class NumMatrix(object):
   
    def __init__(self, matrix):
        n= len(matrix)
        m= len(matrix[0])        
        mat = [[0]*(m+1)]        
        print(n,m)
        for i in range(0,n):
            mat.append([0]+matrix[i])
            
        self.matrix = mat
   
        for i in range(1,n+1):
            for j in range(1,m+1):
                self.matrix[i][j] += (self.matrix[i][j-1]+self.matrix[i-1][j])-self.matrix[i-1][j-1]
        print(self.matrix)

    def sumRegion(self, row1, col1, row2, col2):
        row1+=1
        col1+=1
        row2+=1
        col2+=1
        return self.matrix[row2][col2]-self.matrix[row1-1][col2]-self.matrix[row2][col1-1]+self.matrix[row1-1][col1-1]
        return 0;
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
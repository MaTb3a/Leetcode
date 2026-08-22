class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        r1 = c1 = 0
        r2 = len(matrix)-1
        c2 = len(matrix[0])-1

        ans = []
        while r1 <= r2 and c1 <= c2:
            for i in range(c1,c2+1) : ans.append(matrix[r1][i])
            for j in range(r1+1,r2+1) : ans.append(matrix[j][c2])
            if r1 < r2 and c1 < c2:
                for i in range(c2-1,c1-1,-1) : ans.append(matrix[r2][i])
                for j in range(r2-1,r1,-1) : ans.append(matrix[j][c1])
            r1+=1
            c1+=1
            r2-=1
            c2-=1
        return ans
        
       

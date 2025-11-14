class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        
        mat =   [ [0 for _ in range(n)] for _ in range(n)]

        for q in queries:
            x1,y1,x2,y2 = q[0],q[1],q[2],q[3]
            mat[x1][y1]+=1
            if y2+1 < n:
                mat[x1][y2+1]-=1
            if x2+1 < n:
                mat[x2+1][y1]-=1
            if x2+1 < n and y2+1 < n:
                mat[x2+1][y2+1]+=1
        
        for i in range(n):
            for j in range(n):

                if i > 0:
                    mat[i][j] += mat[i - 1][j]

                if j > 0:
                    mat[i][j] += mat[i][j - 1]

                if i > 0 and j > 0:
                    mat[i][j] -= mat[i - 1][j - 1]


        return mat

                    

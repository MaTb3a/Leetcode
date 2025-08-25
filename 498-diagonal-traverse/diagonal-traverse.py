class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ans = []
        i,j=0,0,
        n,m = len(mat),len(mat[0])
        up = 1 
        while len(ans) < n*m:
            while i >= 0 and j >= 0 and i < n and j < m:
                ans.append(mat[i][j])
                if up:
                    i-=1
                    j+=1
                else:
                    i+=1
                    j-=1
          
            if up:
                if j < m:
                    i =0
                else:
                    i+=2
                    j =m-1
            else:
                if i < n:
                    j =0
                else:
                    i = n -1
                    j+=2
           
            up = 1 - up
        return ans


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ans = []
        i,j,idx,idx2=0,0,0,0
        n,m = len(mat),len(mat[0])
        print(n,m)
        up = 1 # 1 up(x-1,y+1) 0 down (x+1,y-1)

        # 0,0 - 0 1 - 1 0 - 2 0 - 1 1 - 0 2
        while len(ans) < n*m:
            while i >= 0 and j >= 0 and i < n and j < m:
                ans.append(mat[i][j])
                if up:
                    i-=1
                    j+=1
                else:
                    i+=1
                    j-=1
          
            #print(i,j,ans)
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
            # if 2*len(ans) < n*m:
            #     if i < 0:
            #         i = 0
            #         if m == 1:
            #             i = 1
            #             j = 0
            #     if j < 0:
            #         j = 0
            # else:
            #     if j >= m:
            #         i+=2
            #         j = m -1
            #     else:
            #         i = n -1
            #         j+=2
                    
            up = 1 - up
        return ans


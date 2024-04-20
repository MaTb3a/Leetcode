class Solution:
    lX,lY=-1,-1
    
    def dfs(self,x,y,land):
        self.lX = max(x,self.lX)
        self.lY = max(y,self.lY)
        land[x][y] = 0
        if x+1 < len(land) and land[x+1][y] == 1:
            self.dfs(x+1,y,land)
        if y+1 < len(land[0]) and land[x][y+1] == 1:
            self.dfs(x,y+1,land)
    
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        ans = []
        for i in range(0,len(land)):
            for j in range(0,len(land[0])):
                if land[i][j]==1:
                    self.dfs(i,j,land)
                    ans.append([i,j,self.lX,self.lY])
                    self.lX,self.lY = -1,-1
        return ans

        
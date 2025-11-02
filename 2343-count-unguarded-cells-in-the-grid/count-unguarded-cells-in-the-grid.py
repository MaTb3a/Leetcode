class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        q = []
        vis = [[ 0 for _ in range(n)] for _ in range(m)]
        for i in range(len(guards)):
            q.append([guards[i][0],guards[i][1]])
        
        for i in range(len(walls)):
            vis[walls[i][0]][walls[i][1]] = 2
        
        def valid(x,y):
            return (x >= 0 and y >= 0 and x < m and y < n and vis[x][y] != 2 )

        def solve(x,y):
            vis[x][y] = 1
            # 3 up
            # 4 down
            # 5 left
            # 6 right
            l = x-1
            while valid(l,y) and vis[l][y] != 3:
                vis[l][y] = 3
                l-=1
            l = x+1
            while valid(l,y) and vis[l][y] != 4:
                vis[l][y] = 4
                l+=1
            r = y-1
            while valid(x,r) and vis[x][r] != 5:
                vis[x][r] = 5
                r-=1
            r = y+1
            while valid(x,r) and vis[x][r] != 6:
                vis[x][r] = 6
                r+=1
            

        q.sort()
        while len(q):
            x,y = q.pop()
            solve(x,y)
        cnt = sum(c == 0 for x in vis for c in x)
        return cnt



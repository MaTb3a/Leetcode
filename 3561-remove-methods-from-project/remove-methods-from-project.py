class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        vis = [False] * n 
        done = [False] * n
        g = [ [] for i in range(n)]

        for [x,y] in invocations:
            g[x].append(y)

        def virus(x):
            if vis[x]:
                return
            vis[x] = True
            for ch in g[x]:
                virus(ch)
        
        virus(k)
        def dfs(x):
            if done[x]:
                return False
            done[x] = True
            ret = False
            for ch in g[x]:
                if vis[ch] == True:
                    return True
                ret|=dfs(ch)
            return ret
        
        
        for i in range(n):
            if vis[i] == False:
                if dfs(i) == True :
                    return [i for i in range(n)]
        
        
        ans = []
        for i in range(n):
            if vis[i] == False:
                ans.append(i)
        return ans


                
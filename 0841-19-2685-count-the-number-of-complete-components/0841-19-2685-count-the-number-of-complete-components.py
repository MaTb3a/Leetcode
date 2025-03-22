class Solution:
    def countCompleteComponents(self, n: int, edges: list[list[int]]) -> int:
        vis = [False] * n
        adj = [[] for _ in range(n)]
        
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        
        def dfs(u):
            vis[u] = True
            ret = 1
            nonlocal sz
            sz &= len(adj[u])
            for ch in adj[u]:
                if not vis[ch]:
                    ret += dfs(ch)
            return ret
        
        cnt = 0
        for i in range(n):
            if vis[i]:
                continue
            sz = len(adj[i])
            cnt += (dfs(i) == sz + 1)
        
        return cnt
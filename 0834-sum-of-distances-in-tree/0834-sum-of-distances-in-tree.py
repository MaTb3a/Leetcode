class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        cnt = [1]*n
        ans =[0]*n
        def dfs(node,par):
            for child in adj[node]:
                if child == par:
                    continue
                dfs(child,node)
                cnt[node]+=cnt[child]
                ans[node] += cnt[child] + ans[child]
                
        def dfs2(node,par):
            for child in adj[node]:
                if child == par:
                    continue
                ans[child] = ans[node] + n - 2 * cnt[child]
                dfs2(child,node)
        dfs(0,-1)
        dfs2(0,-1)
        return ans
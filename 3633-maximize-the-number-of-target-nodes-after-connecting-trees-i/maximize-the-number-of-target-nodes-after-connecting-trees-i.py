class Solution(object):
    def buildList(self, edges):
        n = len(edges) + 1
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return adj

    def dfs(self, adj, u, p, k):
        if k < 0:
            return 0
        cnt = 1
        for v in adj[u]:
            if v != p:
                cnt += self.dfs(adj, v, u, k - 1)
        return cnt

    def maxTargetNodes(self, edges1, edges2, k):
        adj1 = self.buildList(edges1)
        adj2 = self.buildList(edges2)
        maxiB = 0
        for i in range(len(adj2)):
            maxiB = max(maxiB, self.dfs(adj2, i, -1, k - 1))
        res = []
        for i in range(len(adj1)):
            res.append(self.dfs(adj1, i, -1, k) + maxiB)
        return res
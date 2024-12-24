import math
from collections import deque

class Solution:
    def dfs(self, node, parent, adj, dep):
        if dep > self.d:
            self.d = dep
            self.lst = node
        for child in adj[node]:
            if child == parent:
                continue
            self.dfs(child, node, adj, dep + 1)
    
    def getDiameter(self, edges):
        n = len(edges) + 1
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        self.d, self.lst = 0, 0
        self.dfs(0, -1, adj, 0)
        self.d = 0
        self.dfs(self.lst, -1, adj, 0)
        return self.d

    def bfs(self, src, adj):
        n = len(adj)
        q = deque([src])
        vis = [False] * n
        lst, length = 0, 0
        while q:
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                vis[node] = True
                lst = node
                for child in adj[node]:
                    if not vis[child]:
                        q.append(child)
            length += 1
        return lst, length

    def getDiameter2(self, edges):
        n = len(edges) + 1
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        lst, _ = self.bfs(0, adj)
        _, length = self.bfs(lst, adj)
        return length - 1

    def minimumDiameterAfterMerge(self, edges1, edges2):
        d1 = self.getDiameter2(edges1)
        d2 = self.getDiameter2(edges2)
        d1d2 = math.ceil(d1 / 2.0) + math.ceil(d2 / 2.0) + 1
        return max(d1, d2, d1d2)

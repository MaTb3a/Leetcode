from collections import deque

class Solution:
    def dfs(self, node, c, adj, color, v):
        color[node] = c
        v.append(node)
        for child in adj[node]:
            if color[child] == c:
                return False
            if color[child] == -1 and not self.dfs(child, not c, adj, color, v):
                return False
        return True

    def bfs(self, v, adj, n):
        mx = 0
        for st in v:
            q = deque([st])
            dist = [-1] * (n + 1)
            dist[st] = 0
            while q:
                node = q.popleft()
                for child in adj[node]:
                    if dist[child] != -1:
                        continue
                    dist[child] = dist[node] + 1
                    mx = max(mx, dist[child])
                    q.append(child)
        return mx + 1

    def magnificentSets(self, n, edges):
        adj = [[] for _ in range(n + 1)]
        color = [-1] * (n + 1)

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        ans = 0
        for i in range(1, n + 1):
            if color[i] != -1:
                continue
            v = []
            if not self.dfs(i, 0, adj, color, v):
                return -1
            ans += self.bfs(v, adj, n)

        return ans

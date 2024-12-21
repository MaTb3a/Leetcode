from collections import defaultdict, deque

class Solution:
    def maxKDivisibleComponents(self, n: int, edges: list[list[int]], values: list[int], k: int) -> int:
        if n == 1:
            return 1
        
        adj = defaultdict(list)
        degree = [0] * n
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            degree[u] += 1
            degree[v] += 1
        
        q = deque()
        for i in range(n):
            if degree[i] == 1:
                q.append(i)
        
        ans = 0
        while q:
            node = q.popleft()
            degree[node] -= 1
            if values[node] % k == 0:
                ans += 1
            
            for child in adj[node]:
                degree[child] -= 1
                values[child] += values[node]
                values[child] %= k
                if degree[child] == 1:
                    q.append(child)
        
        return ans

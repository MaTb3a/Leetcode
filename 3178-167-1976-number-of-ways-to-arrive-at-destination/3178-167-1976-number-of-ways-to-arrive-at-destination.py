import heapq

class Solution:
    def countPaths(self, n: int, roads: list[list[int]]) -> int:
        mod = 10**9 + 7
        adj = [[] for _ in range(n)]
        
        for u, v, t in roads:
            adj[u].append((v, t))
            adj[v].append((u, t))
        
        dist = [float('inf')] * n
        ways = [0] * n
        dist[0] = 0
        ways[0] = 1
        
        pq = [(0, 0)]  
        
        while pq:
            time, u = heapq.heappop(pq)
            
            if time > dist[u]:
                continue
                
            for v, t in adj[u]:
                if dist[v] > time + t:
                    dist[v] = time + t
                    heapq.heappush(pq, (dist[v], v))
                    ways[v] = ways[u]
                elif dist[v] == time + t:
                    ways[v] = (ways[v] + ways[u]) % mod
        
        return ways[n-1]
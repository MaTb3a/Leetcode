from collections import deque, defaultdict

class Solution:
    def shortestDistanceAfterQueries(self, n, queries):
        adj = defaultdict(list)
        
        # Initialize the initial connections
        for i in range(1, n):
            adj[i - 1].append(i)
        
        def BFS(n):
            q = deque([0])
            dist = [float('inf')] * n
            dist[0] = 0
            
            while q:
                city = q.popleft()
                if city == n - 1:
                    return dist[city]
                
                for child in adj[city]:
                    if dist[child] > dist[city] + 1:
                        dist[child] = dist[city] + 1
                        q.append(child)
            
            return -1
        
        result = []
        for bridge in queries:
            adj[bridge[0]].append(bridge[1])
            result.append(BFS(n))
        
        return result

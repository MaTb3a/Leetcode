class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def bfs(src,edges,n):
            dist = [float("inf")]*n
            q = []
            q.append(src)
            dist[src] = 0
            while q:
                cur = q.pop()
                for child in edges[cur]:
                    if dist[child] == float("inf"):
                        dist[child] = dist[cur]+1
                        q.append(child)
            return dist

        n = len(edges)
        n_edges = [[] for _ in range(0,n)]
        for i in range(0,n):
            if edges[i] != -1:
                n_edges[i].append(edges[i])
        
        
        d1 = bfs(node1,n_edges,n)
        d2 = bfs(node2,n_edges,n)

        node,dist = -1,float("inf")
        for i in range(0,n):
            if max(d1[i],d2[i]) < dist:
                dist = max(d1[i],d2[i])
                node = i
        return node
                    
                    

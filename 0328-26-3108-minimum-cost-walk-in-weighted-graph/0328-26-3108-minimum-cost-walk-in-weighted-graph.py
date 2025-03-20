class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        parent = list(range(n))      
        costs = [-1]*n
        
        def find(u):
            if parent[u] != u:
                parent[u] = find(parent[u])
            return parent[u]

        def join(u,v,w):
            u = find(u)
            v = find(v)
            costs[u] = costs[v] = costs[u] & costs[v] & w
            parent[v] = u
            
        def calc(u,v):
            u = find(u)
            v = find(v)
            if u != v:
                return -1
            return costs[u]
        
        for u, v, w in edges:
            join(u, v, w)
            
        result = []
        
        for u, v in query:
            result.append(calc(u, v))
        return result

                
        
        
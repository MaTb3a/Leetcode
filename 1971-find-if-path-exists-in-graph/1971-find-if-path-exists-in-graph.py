class Solution:
    def dfs(self,source,destination,graph,vis):
        if source == destination:
            return True
        vis[source] = True
        ret = False
        for cur in graph[source]:
            if not vis[cur]:
                ret|=self.dfs(cur,destination,graph,vis)
        return ret
        
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        vis = [False]*(n)
        graph =[[] for _ in range(0,n)]
        for node in edges:
            graph[node[0]].append(node[1])
            graph[node[1]].append(node[0])
        return self.dfs(source,destination,graph,vis)
        
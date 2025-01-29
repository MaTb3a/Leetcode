from itertools import accumulate

class Solution:
    def findRedundantConnection(self, edges):
        par = list(range(1001))

        def find(u):
            if par[u] != u:
                par[u] = find(par[u])
            return par[u]

        def join(u, v):
            pu, pv = find(u), find(v)
            if pu != pv:
                par[pu] = pv

        for u, v in edges:
            if find(u) == find(v):
                return [u, v]
            join(u, v)

        return []

from typing import List

class Solution:
    def __init__(self):
        self.BobT = []
        self.parent = []

    def BobDfs(self, n: int, p: int, adj: List[List[int]]):
        self.parent[n] = p
        for ch in adj[n]:
            if ch == p:
                continue
            self.BobDfs(ch, n, adj)

    def AliceDfs(self, n: int, p: int, adj: List[List[int]], AliceT: int, amount: List[int]) -> int:
        AliceM = 0
        if AliceT < self.BobT[n]:
            AliceM = amount[n]
        elif AliceT == self.BobT[n]:
            AliceM = amount[n] // 2

        if len(adj[n]) == 1 and n != 0:
            return AliceM

        mx = -1e9
        for ch in adj[n]:
            if ch == p:
                continue
            mx = max(mx, self.AliceDfs(ch, n, adj, AliceT + 1, amount))
        return mx + AliceM

    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        n = len(edges) + 1
        adj = [[] for _ in range(n)]
        for it in edges:
            adj[it[0]].append(it[1])
            adj[it[1]].append(it[0])

        self.BobT = [1e9] * n
        self.parent = [1e9] * n
        self.BobDfs(0, -1, adj)

        time = 0
        i = bob
        while i != -1:
            self.BobT[i] = time
            time += 1
            i = self.parent[i]

        return self.AliceDfs(0, -1, adj, 0, amount)
class Solution:
    def dfs(self, u, graph, state):
        if state[u] != 0:
            return state[u] == 1
        state[u] = 2
        for child in graph[u]:
            if not self.dfs(child, graph, state):
                return False
        state[u] = 1
        return True

    def eventualSafeNodes(self, graph):
        n = len(graph)
        state = [0] * n
        ans = []
        for i in range(n):
            if self.dfs(i, graph, state):
                ans.append(i)
        return ans

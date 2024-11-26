class Solution:
    def findChampion(self, n, edges):
        visited = [0] * n
        for u, v in edges:
            visited[v] = 1
        
        champion = -1
        for i in range(n):
            if visited[i] == 0:
                if champion == -1:
                    champion = i
                else:
                    return -1
        
        return champion

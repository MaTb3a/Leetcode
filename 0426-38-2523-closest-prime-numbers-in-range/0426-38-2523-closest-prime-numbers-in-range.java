class Solution:
    def closestPrimes(self, left: int, right: int) -> list[int]:
        vis = [False] * (right + 1)
        vis[0] = vis[1] = True
        for i in range(2, int(right**0.5) + 1):
            if not vis[i]:
                for j in range(i + i, right + 1, i):
                    vis[j] = True
        
        a, b = -1, -1
        lst = -1
        min_gap = float('inf')
        for i in range(left, right + 1):
            if vis[i]:
                continue
            if lst != -1 and i - lst < min_gap:
                min_gap = i - lst
                a, b = lst, i
            lst = i
        
        return [a, b]
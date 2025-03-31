class Solution:
    def putMarbles(self, weights: list[int], k: int) -> int:
        n = len(weights)
        v = []
        
        for i in range(1, n):
            v.append(weights[i-1] + weights[i])
        
        v.sort()
        ans = 0
        
        for i in range(k-1):
            ans += v[n-2-i] - v[i]
        
        return ans
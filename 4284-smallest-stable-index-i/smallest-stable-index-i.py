suf = [0] * 100
class Solution:
    def firstStableIndex(self, A: list[int], k: int) -> int:
        n = len(A)        
        suf[n - 1] = A[-1]

        for i in range(n - 2, -1, -1):
            suf[i] = min(suf[i + 1], A[i])

        mx = 0
        for i, x in enumerate(A):
            mx = max(mx, x)
            if mx - suf[i] <= k:
                return i

        return -1
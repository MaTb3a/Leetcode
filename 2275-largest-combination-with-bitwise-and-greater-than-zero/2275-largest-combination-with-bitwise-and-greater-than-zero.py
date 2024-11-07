class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        mx = 0
        for i in range(24):
            mx=max(mx,sum(1 for x in candidates if x & (1<<i) != 0 ))
        return mx
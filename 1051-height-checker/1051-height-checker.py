class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        cpy = heights.copy()
        cpy.sort()
        cnt = 0
        for i in range(len(cpy)):
            cnt+=(cpy[i]!=heights[i])
        return cnt
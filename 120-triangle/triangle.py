class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        @cache
        def solve(i,lst):
            if i == len(triangle):
                return 0
            if lst < 0 :
                return float("inf")
            return min(solve(i+1,lst),solve(i+1,lst+1))+triangle[i][lst]
        return solve(0,0)
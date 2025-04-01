class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        @cache
        def solve(i):
            if i >= n:
                return 0
            return max(solve(i+1),solve(i+questions[i][1]+1) +questions[i][0])
        return solve(0)
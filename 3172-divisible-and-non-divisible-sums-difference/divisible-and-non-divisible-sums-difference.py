class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        def solve(n):
            return n*(n+1)//2
        
        return solve(n) - 2*solve(n//m)*m
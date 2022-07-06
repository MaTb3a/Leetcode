class Solution:
    def fib(self, n: int) -> int:
        @cache
        def fibb(n):
            if(n<2):
                return n
            return fibb(n-1)+fibb(n-2)
        return fibb(n)
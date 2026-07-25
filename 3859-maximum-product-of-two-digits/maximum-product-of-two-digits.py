class Solution:
    def maxProduct(self, n: int) -> int:
        lst = list(map(int,str(n)))
        lst.sort()
        return lst[-1]*lst[-2]
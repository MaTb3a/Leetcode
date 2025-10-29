class Solution:
    def smallestNumber(self, n: int) -> int:
        x = int(len(bin(n))-2)
        return (1<<x)-1
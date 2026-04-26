class Solution:
    def reverseBits(self, n: int) -> int:
        n = bin(n)[2:]
        n = n[::-1]
        while len(n) < 32:
            n+='0'
        
        return int(n,2)
       
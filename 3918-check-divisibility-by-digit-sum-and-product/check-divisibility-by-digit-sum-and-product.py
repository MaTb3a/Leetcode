class Solution:
    def checkDivisibility(self, n: int) -> bool:
        s,p = 0,1
        x = n
        while x:
            s += x%10
            p *= x%10
            x//=10
        
        return n%(p+s) == 0 
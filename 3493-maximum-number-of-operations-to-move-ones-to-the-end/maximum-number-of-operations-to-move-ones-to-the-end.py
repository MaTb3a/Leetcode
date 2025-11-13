class Solution:
    def maxOperations(self, s: str) -> int:
        ans,one,zero = 0,0,0
        for x in s:
            if x == '0':
                zero = 1
            else:
                if zero:
                    ans+=one
                zero = 0
                one+=1
            
        ans += one if zero else 0
        return ans
        
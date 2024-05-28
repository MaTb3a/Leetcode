class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        def Calc(x,y):
            return abs(ord(x)-ord(y))
        
        l,r = 0,0
        mx,cur = 0,0
        n = len(s)
        while (r <= n):
            if cur <= maxCost:
                mx = max(mx,r-l)
                if r == n:
                    break
                cur = cur + Calc(s[r],t[r])
                r+=1
            else:
                cur = cur - Calc(s[l],t[l])
                l+=1
        return mx
                    
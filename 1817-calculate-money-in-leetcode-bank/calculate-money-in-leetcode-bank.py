class Solution:
    def totalMoney(self, n: int) -> int:
        def calc(n):
            return n*(n+1)//2
        l = 0
        r = 7
        ans = 0
        while n >= 7:
            ans+= calc(r)
            ans-= calc(l)
            l+=1
            r+=1
            n-=7
        if n > 0 :
            ans+= calc(l+n)
            ans-= calc(l)
        return ans

            
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        ans = ""
        rang = 3*(1<< (n-1))
        if k > rang:
            return ""
        while n > 0:
            rang = 1 << (n-1)
            for c in "abc":
                if ans and ans[-1] == c:
                    continue
                if k > rang:
                    k-=rang
                else:
                    ans+=c
                    break
            n-=1
        return ans

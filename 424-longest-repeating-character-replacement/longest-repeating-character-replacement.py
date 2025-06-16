class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = 0
        for x in range(0,26):
            kk = k
            c = chr(65+x)
            l,r = 0,0
            while r < len(s):
                if s[r] != c:
                    kk-=1
                while l < r and kk < 0:
                    if s[l] != c:
                        kk+=1
                    l+=1
                # print(c,l,r,kk)
                ans = max(ans,r-l+1)
                r+=1

        return ans
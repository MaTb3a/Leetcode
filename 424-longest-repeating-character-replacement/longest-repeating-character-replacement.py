class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        frqs = defaultdict(int)
        l,r,ans = 0,0,0

        while r < len(s):
            frqs[s[r]]+=1
            mxfrq = max(frqs.values())
            if r-l+1 - mxfrq > k:
                frqs[s[l]]-=1
                l+=1
            ans = max(ans,r-l+1)
            r+=1
        
        return ans

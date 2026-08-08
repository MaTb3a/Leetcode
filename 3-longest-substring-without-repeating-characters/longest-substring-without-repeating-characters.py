class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        r,n,ans = 0,len(s),0
        vis = {}
        for l in range(n):
            while r < n and s[r] not in vis:
                vis[s[r]] = True
                r+=1
                ans = max(ans,r-l)
            del vis[s[l]]
        return ans
            


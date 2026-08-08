class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = mx = 0
        vis = set()
        for r in range(len(s)):
            while s[r] in vis:
                vis.remove(s[l])
                l+=1
            
            vis.add(s[r])
            mx=max(mx,r-l+1)
        return mx
            


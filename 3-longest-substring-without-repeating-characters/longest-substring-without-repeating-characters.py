class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        vis = set()
        r = mx = 0
        for l in range(len(s)):
            while r < len(s) and s[r] not in vis: 
                vis.add(s[r])
                r+=1
                mx=max(mx,r-l) 
            vis.remove(s[l])
        return mx
            


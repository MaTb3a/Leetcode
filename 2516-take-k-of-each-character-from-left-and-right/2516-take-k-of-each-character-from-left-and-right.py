class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        n = len(s)
        vis = [0]*3
        
        for x in s:
            vis[ord(x)-ord('a')]+=1
        if min(vis) < k:
            return -1
        
        l,r,ans =0,0,0
      
        
        while r < n:
            vis[ord(s[r])-ord('a')]-=1
            while min(vis) < k:
                vis[ord(s[l])-ord('a')]+=1
                l+=1
            ans = max(ans,r-l+1)
            r+=1
        return n - ans;
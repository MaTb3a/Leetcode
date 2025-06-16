class Solution:
    def maxArea(self, height: List[int]) -> int:
        l,r,ans = 0,len(height)-1,0
        while l<=r:
            ans = max(ans,min(height[l],height[r]) * (r-l))
            if height[l] < height[r]:
                l+=1
            else:
                r-=1
        return ans


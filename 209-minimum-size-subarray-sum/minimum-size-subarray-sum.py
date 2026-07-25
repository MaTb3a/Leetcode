class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        def check(md):
            sm = 0
            for i in range(md): # 3 -> L R
                sm+=nums[i]
            if sm >= target:
                return True
            
            for i in range(md,len(nums)):
                sm+=nums[i]
                sm-=nums[i-md]
                if sm >= target:
                    return True
            return False 
           
            
        l,r,ans = 1,len(nums),0
        while l <= r:
            md = (l+r)//2
            if check(md):
                ans = md
                r = md -1
            else :
                l = md+1
        return ans


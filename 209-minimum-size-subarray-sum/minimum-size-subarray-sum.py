class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        
        for i in range(1,len(nums)):
            nums[i]+=nums[i-1]
        
        l,r,ans = 1,len(nums),0

        def check(md):
            if nums[md-1] >= target:
                return True
            for i in range(md,len(nums)):
                if nums[i] - nums[i-md] >= target:
                    return True
            return False
            

        while l <= r:
            md = (l+r)//2
            if check(md) == True:
                r = md -1
                ans = md
            else :
                l = md +1
            
        return 0 if ans == 1e9 else ans



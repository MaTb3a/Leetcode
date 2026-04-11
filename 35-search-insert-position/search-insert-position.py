class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l,r = 0,len(nums)-1
        while l <= r:
            md = (l+r)//2
            if nums[md] == target:
                return md
            if nums[md] < target:
                l = md+1
            else:
                r = md -1
        
        return l
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r,cur = 0,len(nums)-1,-1

        while l <= r:
            md = (l+r)//2
            if nums[l] <= nums[md] <= nums[r]:
                r = md -1
            elif nums[l] >= nums[md] >= nums[r]:
                l = md +1
            elif nums[l] <= nums[md] >= nums[r]:
                l = md
            elif nums[l] >= nums[md] <= nums[r]:
                r = md
            
        print(l,r,md)
        return nums[l]

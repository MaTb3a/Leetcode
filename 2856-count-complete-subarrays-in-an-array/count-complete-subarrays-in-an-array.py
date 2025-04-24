class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        sz = len(set(nums))
        cnt = 0
        l = 0
        for r in range(0,len(nums)):
            while len(set(nums[l:r+1])) == sz:
                print(l,r,nums[l:r+1])
                cnt+=len(nums)-r
                l+=1
        return cnt
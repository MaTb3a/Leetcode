class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        ans = 0
        for i in range(n-1):
            for j in range(i+1,n):
                idx = bisect.bisect_left(nums, nums[i]+nums[j]) -1
                if idx > j:
                    ans+=idx-j
        return ans
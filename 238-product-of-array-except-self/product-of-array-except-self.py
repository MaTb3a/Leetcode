class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l = nums[:]
        r = nums[:]
        ans = [1]*n
        for i in range(1,n):
            l[i]*=l[i-1]
            r[n-i-1]*=r[n-i]
        ans[0] = r[1]
        ans[n-1] = l[n-2]
        for i in range(1,n-1):
            ans[i] = l[i-1] * r[i+1]
        return ans

        
        
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        
        ans = inf
        n = len(nums)
        if nums.count(1):
            return n - nums.count(1)
        for i in range(n):
            g = nums[i]
            for j in range(i+1,n):
                g = gcd(g,nums[j])
                if g == 1:
                    ans = min(ans,j-i)
        
        if ans == inf:
            return -1
        return ans+n-1        

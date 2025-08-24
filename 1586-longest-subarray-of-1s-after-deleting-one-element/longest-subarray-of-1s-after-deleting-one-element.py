class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        a,b,mx = 0,0,0
        for x in nums:
            if x == 1:
                a+=1
            else:
                mx = max(mx,a+b)
                b = a
                a = 0
        if a == len(nums):
            return a-1
        return max(mx,a+b)
        # 0,1,1,1,0,1,1,0,1
        # 0 1 2 3 3 4 5 5 6
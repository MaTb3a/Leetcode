class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        
        n = len(nums)
        lst = [1]*n
        mx = 1
        for i in range(1,n):
            if nums[i] > nums[i-1]:
                lst[i] = lst[i-1]+1
            if i - lst[i] >= 0  and lst[i] <= lst[i - lst[i]]:
                mx=max(mx,lst[i])
            else:
                mx=max(mx,lst[i]//2)
        return mx      
        # 2,5,7,8,9,2,3,4,3,1
        # 1 2 3 4 5 1 2 3 1 1

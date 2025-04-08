class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        frq = [-1]*101
        for i in range(n-1,-1,-1):
            if frq[nums[i]] != -1:
                return (i+3)//3
            frq[nums[i]] = i
        return 0

       


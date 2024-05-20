class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        @lru_cache
        def solve(idx,cur):
            if idx == len(nums):
                return cur
            ret = 0
            ret +=solve(idx+1,cur)
            ret +=solve(idx+1,cur^nums[idx])
            return ret
        return solve(0,0)
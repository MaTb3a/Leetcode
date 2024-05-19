class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        @lru_cache(maxsize=len(nums))
        def solve(idx,even):
            if idx == len(nums):
                return 0 if even == 1 else -float("inf")
            ret = 0
            ret = max(ret,solve(idx+1,even)+nums[idx])
            ret = max(ret,solve(idx+1,even^1)+(nums[idx]^k))
            return ret
        return solve(0,1)
        
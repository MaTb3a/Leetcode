class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        def valid(v,x):
            for i in v:
                if abs(i-x) == k :
                    return False
            return True
        @lru_cache(maxsize=None)
        def solve(i,v):
            v = list(v)
            if i == len(nums):
                if len(v) > 0:
                    return 1
                else:
                    return 0
            ret = 0
            if valid(v,nums[i]) :
                v.append(nums[i])
                ret+=solve(i+1,tuple(v))
                v.pop()

            ret+=solve(i+1,tuple(v))
            return ret
        return solve(0,())
        
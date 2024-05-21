class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def solve(idx,sub):
            if idx == len(nums):
                ans.append(sub[:])
                return
            sub.append(nums[idx])
            solve(idx+1,sub)
            sub.pop(-1)
            solve(idx+1,sub)
        ans = []
        solve(0,[])
        return ans
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        
        def solve(start,cur):
            ans.append(cur[:])
            for i in range(start,len(nums)):
                if i > start and nums[i] == nums[i-1]:
                    continue
                cur.append(nums[i])
                solve(i+1,cur)
                cur.pop()

        solve(0,[])
        return ans
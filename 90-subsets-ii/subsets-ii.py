class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        for i in range((1<<n)):
            cur = []
            for j in range(n):
                if i & (1<<j):
                    cur.append(nums[j])
            cur.sort()
            if cur not in ans : 
                ans.append(cur)

        return ans


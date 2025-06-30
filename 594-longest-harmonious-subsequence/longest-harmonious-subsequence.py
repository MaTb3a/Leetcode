class Solution:
    def findLHS(self, nums: List[int]) -> int:
        mp = Counter(nums)
        mx = 0
        for x in nums:
            if mp[x] and x+1 in mp:
                mx = max(mx,mp[x]+mp[x+1])
        return mx
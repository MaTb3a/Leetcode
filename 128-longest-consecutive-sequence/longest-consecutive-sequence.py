class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        nums.sort()

        # 100,4,200,1,3,2

        # 1 2 3 4 100 200
        mp = defaultdict(int)
        ans = 0
        for x in nums:
            mp[x] = mp[x-1]+1
            ans = max(ans,mp[x])
        return ans

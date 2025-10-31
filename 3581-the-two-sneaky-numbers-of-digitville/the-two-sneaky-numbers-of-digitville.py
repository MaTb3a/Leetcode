class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        mp = {}
        ans = []
        for x in nums:
            if x in mp:
                ans.append(x)
            mp[x] = True
        return ans
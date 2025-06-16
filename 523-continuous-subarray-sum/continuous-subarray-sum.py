class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        mp = {}
        mp[0] = -1
        s = 0

        for i in range(len(nums)):
            s+=nums[i]
            s%=k
            nums[i] = s
            if s in mp and i - mp[s] > 1:
                return True
            if s not in mp:
                mp[s] = i
        return False

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        mp = {0:-1}
        sm = 0
        for i in range(len(nums)):
            sm+=nums[i]
            sm%=k
            if sm in mp:
                if i - mp[sm] > 1:
                    return True
            else:
                mp[sm]=i
        return False
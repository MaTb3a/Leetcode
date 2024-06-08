class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
    
        mp = {0:-1}
        s = 0
        for i in range(len(nums)):
            s = (s+nums[i])%k
            if s in mp :
                if i - mp[s] > 1:
                    return True
            else:
                mp[s] = i
        return False
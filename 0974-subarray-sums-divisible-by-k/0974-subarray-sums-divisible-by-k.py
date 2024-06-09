class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        mp = {}
        mp[0] =1
        sm = 0
        ans = 0
        for i in range(len(nums)):
            sm+=nums[i]
            sm%=k
            if sm in mp:
                ans+=mp[sm]
                mp[sm]+=1
            else:
                mp[sm]=1
            
        return ans
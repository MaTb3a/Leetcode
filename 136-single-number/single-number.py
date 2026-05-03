class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        mp = {}
        for x in nums:
            if x in mp:
                mp[x]+=1
            else:
                mp[x] = 1
        for key,val in mp.items():
            if val != 2:
                return key
        return -1
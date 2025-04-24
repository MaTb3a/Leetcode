class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        sz = len(set(nums))
        l,cnt = 0,0
        mp = Counter()
        for r in range(0,len(nums)):
            mp[nums[r]]+=1
            while len(mp.keys()) == sz:
                cnt+=len(nums)-r
                mp[nums[l]]-=1
                if mp[nums[l]] == 0:
                    del mp[nums[l]]
                l+=1
        return cnt
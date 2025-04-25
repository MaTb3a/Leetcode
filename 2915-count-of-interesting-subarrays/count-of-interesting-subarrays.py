class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        ans,cnt = 0,0
        mp = defaultdict(int)
        mp[0] = 1
        for i,v in enumerate(nums):
            cnt+=(v%modulo==k)
            ans+=mp[(cnt+modulo-k)%modulo]
            mp[cnt%modulo]+=1
        return ans
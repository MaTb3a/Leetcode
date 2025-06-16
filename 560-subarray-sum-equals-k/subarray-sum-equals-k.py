class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        prefix,ans = 0,0
        mp[0]=1
        for x in nums:
            prefix+=x
            if prefix-k in mp:
                ans+=mp[prefix-k]
            mp[prefix]+=1
        return ans

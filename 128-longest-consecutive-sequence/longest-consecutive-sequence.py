class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        # nums.sort() # nlog(n)
        # mp = defaultdict(int)
        # ans = 0
        # for x in nums:
        #     mp[x] = mp[x-1]+1
        #     ans = max(ans,mp[x])
        # return ans


        nums = set(nums)
        ans = 0 
        for l in nums:
            if l-1 not in nums:
                r = l+1 # 2
                while r in nums:
                    r+=1
                ans = max(ans,r-l)
        return ans



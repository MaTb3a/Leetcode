class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        sum,mx = 0,0
        dic = defaultdict(int)
        for i in range(k):
            sum+=nums[i]
            dic[nums[i]]+=1
        if len(dic) == k:
            mx = sum
        for i in range(k,len(nums)):
            sum+=nums[i]-nums[i-k]
            dic[nums[i]]+=1
            dic[nums[i-k]]-=1
            if dic[nums[i-k]] == 0:
                del dic[nums[i-k]]
            if len(dic) == k:
                mx = max(mx,sum)
        return mx

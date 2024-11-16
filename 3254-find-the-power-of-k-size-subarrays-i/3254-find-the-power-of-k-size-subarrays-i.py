class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        cnt = 1
        ans = [-1] * (n-k+1)
        for i in range(1,k):
            if nums[i] == nums[i-1]+1:
                cnt+=1
            else:
                cnt=1
        if cnt == k:
            ans[0] = nums[k-1]
        for i in range(k,n):
            if nums[i] == nums[i-1]+1:
                cnt+=1
            else:
                cnt=1
            if cnt >= k:
                ans[i-k+1] = nums[i]
        return ans
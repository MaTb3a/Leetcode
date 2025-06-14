class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans,cnt = 0,0
        for x in nums:
            if cnt == 0:
                ans,cnt = x,1
            elif ans == x:
                cnt+=1
            else:
                cnt-=1
        return ans
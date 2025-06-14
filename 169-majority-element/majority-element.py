class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = {}
        ans,cnt = 0,0
        for x in nums:
            if x not in dic:
                dic[x] = 1
            else:
                dic[x]+=1
            if dic[x] > cnt:
                cnt = dic[x]
                ans = x

        return ans
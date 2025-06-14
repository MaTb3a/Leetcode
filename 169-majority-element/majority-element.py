class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = defaultdict(lambda:0)
        ans,cnt = 0,0
        for x in nums:
            dic[x]+=1
            if dic[x] > cnt:
                cnt = dic[x]
                ans = x
                
        return ans
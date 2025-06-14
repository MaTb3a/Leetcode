class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = defaultdict(lambda:0)
        for x in nums:
            dic[x]+=1
        
        ans,cnt = 0,0
        for key,value in dic.items():
            if value > cnt:
                cnt = value
                ans = key
        return ans
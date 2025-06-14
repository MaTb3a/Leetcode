class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        ans1,cnt1,ans2,cnt2 = 0,0,0,0
        for x in nums:
            if ans1 == x:
                cnt1 += 1
            elif ans2 == x:
                cnt2 += 1
            elif cnt1 == 0:
                ans1 = x
                cnt1+=1
            elif cnt2 == 0:
                cnt2+=1
                ans2= x
            else:
                cnt1-=1
                cnt2-=1
        
        cnt1,cnt2 = 0,0
        for x in nums:
            if x == ans1:
                cnt1+=1
            if x == ans2:
                cnt2+=1
            
        ans = []
        if cnt1 > len(nums)//3:
            ans.append(ans1)
        if cnt2 > len(nums)//3 and ans1 != ans2:
            ans.append(ans2)
        return ans
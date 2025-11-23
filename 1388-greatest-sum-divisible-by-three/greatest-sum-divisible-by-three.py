class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        one,two = [],[]
        ans = 0
        for x in nums:
            if x %3==1:
                one.append(x)
            elif x%3==2:
                two.append(x)
            ans+=x
        
        if ans %3 ==0:
            return ans
        one.sort()
        two.sort()
        op1,op2=-1,-1
        if ans%3 == 1:
            if len(one):
                op1 = ans-one[0]
            if len(two)>1:
                op2 = ans-two[0]-two[1]
        if ans%3 == 2:
            if len(two):
                op1 = ans-two[0]
            if len(one)>1:
                op2 = ans-one[0]-one[1]
        return max(op1,op2)


        # 2 2 2 7
        # 6 

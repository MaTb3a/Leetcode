class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        preMx = 0
        curMx , curMn = nums[0],nums[0]
        for i in range(1,len(nums)):
            if nums[i].bit_count() != nums[i-1].bit_count():
                if preMx > curMn:
                    return False
                preMx = curMx
                curMx = curMn = nums[i]
            else :
                curMn=min(curMn,nums[i])
                curMx=max(curMx,nums[i])
        return preMx <= curMn


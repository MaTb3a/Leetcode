class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        xr,xr2=0,0
        for x in nums:
            xr^=x
            xr2^=(x+1)
        return xr == 0 and xr2== 0
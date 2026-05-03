class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        x = 0
        for y in nums: x^=y
        return x

       

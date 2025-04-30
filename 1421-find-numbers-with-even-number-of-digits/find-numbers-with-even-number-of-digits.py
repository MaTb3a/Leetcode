class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum(1 for x in nums if len(str(x))%2==0)
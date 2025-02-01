from itertools import pairwise

class Solution:
    def isArraySpecial(self, nums):
        return all(a % 2 != b % 2 for a, b in pairwise(nums))

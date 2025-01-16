from functools import reduce
from operator import ixor

class Solution:
    def xorAllNums(self, nums1: list[int], nums2: list[int]) -> int:
        xor1 = reduce(ixor, nums1, 0) if len(nums2) % 2 else 0
        xor2 = reduce(ixor, nums2, 0) if len(nums1) % 2 else 0
        return xor1 ^ xor2

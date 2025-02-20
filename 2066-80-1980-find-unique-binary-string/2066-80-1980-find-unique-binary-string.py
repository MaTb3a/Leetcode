from typing import List

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        return "".join(str(int(nums[i][i]) ^ 1) for i in range(len(nums)))

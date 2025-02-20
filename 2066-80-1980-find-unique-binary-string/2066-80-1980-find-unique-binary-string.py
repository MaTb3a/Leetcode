class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        s=""
        for i in range(len(nums)):
            s+=str(1-int(nums[i][i]))
        return s
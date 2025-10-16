class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        mex = 0
        mp = Counter(x%value for x in nums)
        while mp[mex%value] > 0:
            mp[mex%value]-=1
            mex+=1
        return mex
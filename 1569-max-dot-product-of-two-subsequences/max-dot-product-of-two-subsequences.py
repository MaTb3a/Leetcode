class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        @cache
        def solve(i,j,ok):
            if i == len(nums1) or j == len(nums2):
                return 0 if ok else -9999999
            ret = -9999999
            ret = max(ret,solve(i+1,j+1,1) +nums1[i]*nums2[j])
            ret = max(ret,solve(i+1,j,ok))
            ret = max(ret,solve(i,j+1,ok))
            return ret
        return solve(0,0,0)
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if not k: return 0 if nums1 == nums2 else -1
        s,op = 0,0
        for i in range(len(nums1)):
            if abs(nums1[i] - nums2[i])%k != 0:
                return -1
            s += nums1[i] - nums2[i]
            op += abs(nums1[i] - nums2[i])//k
        return op//2 if s == 0 else -1
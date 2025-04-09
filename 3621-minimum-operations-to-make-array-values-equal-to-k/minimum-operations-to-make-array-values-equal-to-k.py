class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        if min(nums) < k:
            return -1
        st = set(nums)
        st.add(k)
        return len(st)-1
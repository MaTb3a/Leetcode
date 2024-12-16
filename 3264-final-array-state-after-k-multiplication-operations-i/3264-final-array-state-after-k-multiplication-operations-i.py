from sortedcontainers import SortedList

class Solution:
    def getFinalState(self, nums: list[int], k: int, multiplier: int) -> list[int]:
        st = SortedList((val, idx) for idx, val in enumerate(nums))
        
        for _ in range(k):
            val, idx = st.pop(0)
            nums[idx] *= multiplier
            st.add((nums[idx], idx))
        
        return nums

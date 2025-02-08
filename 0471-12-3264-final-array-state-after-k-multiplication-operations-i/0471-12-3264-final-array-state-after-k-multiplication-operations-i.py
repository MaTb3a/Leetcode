from sortedcontainers import SortedSet

class Solution:
    def getFinalState(self, nums, k, multiplier):
        st = SortedSet((num, i) for i, num in enumerate(nums))

        for _ in range(k):
            val, idx = st.pop(0)  
            nums[idx] *= multiplier
            st.add((nums[idx], idx)) 

        return nums

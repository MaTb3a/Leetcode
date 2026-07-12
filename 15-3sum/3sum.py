class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        st = set()
        nums.sort()
        n = len(nums)
        for i in range(n):
            j = i+1
            k = n-1
            while j < k:
                if nums[i] + nums[j] + nums[k] == 0:
                    st.add((nums[i],nums[j],nums[k]))
                    j+=1
                elif nums[i] + nums[j] + nums[k] < 0:
                    j+=1
                else:
                    k-=1
        return [list(t) for t in st]
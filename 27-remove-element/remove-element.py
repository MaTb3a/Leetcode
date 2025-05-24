class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        arr = []
        for i in range(len(nums)):
            if nums[i] != val:
                arr.append(nums[i])
        nums[:] = arr

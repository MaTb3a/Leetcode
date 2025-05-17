class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero = nums.count(0)
        one = nums.count(1)
        two = nums.count(2)
        for i in range(len(nums)):
            if zero:
                nums[i] = 0
                zero-=1
            elif one:
                nums[i] = 1
                one-=1
            else:
                nums[i] = 2
                two-=1
        print(zero)
        
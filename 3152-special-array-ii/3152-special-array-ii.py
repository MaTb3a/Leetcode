class Solution:
    def isArraySpecial(self, nums: list[int], queries: list[list[int]]) -> list[bool]:
        n = len(nums)

        # Preprocess the nums array
        for i in range(1, n):
            if (nums[i] & 1) == (nums[i - 1] & 1):
                nums[i - 1] = 1
            else:
                nums[i - 1] = 0

        # Compute prefix sums
        for i in range(1, n):
            nums[i] += nums[i - 1]

        # Process queries
        ans = []
        for l, r in queries:
            if l == r:
                ans.append(True)
            else:
                res = (nums[r - 1] if r > 0 else nums[r]) - (nums[l - 1] if l > 0 else 0)
                ans.append(res == 0)

        return ans

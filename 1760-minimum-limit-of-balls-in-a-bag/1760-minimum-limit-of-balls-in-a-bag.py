class Solution:
    def minimumSize(self, nums: list[int], maxOperations: int) -> int:
        def canDivide(mid):
            operations = 0
            for bag in nums:
                operations += (bag - 1) // mid
            return operations <= maxOperations

        left, right = 1, max(nums)
        result = -1

        while left <= right:
            mid = (left + right) // 2
            if canDivide(mid):
                result = mid
                right = mid - 1
            else:
                left = mid + 1

        return result
